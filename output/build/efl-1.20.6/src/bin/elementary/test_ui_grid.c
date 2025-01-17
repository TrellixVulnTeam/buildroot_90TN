#ifdef HAVE_CONFIG_H
# include "elementary_config.h"
#endif

#define EFL_PACK_LAYOUT_PROTECTED
#include <Elementary.h>

static void _custom_layout_update(Eo *pack, void *_pd EINA_UNUSED);

static Evas_Object *objects[7] = {};

typedef enum {
   NONE,
   NONE_BUT_FILL,
   EQUAL,
   ONE,
   TWO,
   CUSTOM
} Weight_Mode;

static void
weights_cb(void *data, const Efl_Event *event)
{
   EFL_OPS_DEFINE(custom_layout_ops,
                  EFL_OBJECT_OP_FUNC(efl_pack_layout_update, _custom_layout_update));

   Weight_Mode mode = elm_radio_state_value_get(event->object);
   Eo *grid = data;

   if (mode != CUSTOM)
     efl_object_override(grid, NULL);

   switch (mode)
     {
      case NONE:
        efl_gfx_size_hint_align_set(grid, 0.5, 0.5);
        for (int i = 0; i < 7; i++)
          efl_gfx_size_hint_weight_set(objects[i], 0, 0);
        break;
      case NONE_BUT_FILL:
        efl_gfx_size_hint_align_set(grid, -1, -1);
        for (int i = 0; i < 7; i++)
          efl_gfx_size_hint_weight_set(objects[i], 0, 0);
        break;
      case EQUAL:
        efl_gfx_size_hint_align_set(grid, 0.5, 0.5);
        for (int i = 0; i < 7; i++)
          efl_gfx_size_hint_weight_set(objects[i], 1, 1);
        break;
      case ONE:
        efl_gfx_size_hint_align_set(grid, 0.5, 0.5);
        for (int i = 0; i < 6; i++)
          efl_gfx_size_hint_weight_set(objects[i], 0, 0);
        efl_gfx_size_hint_weight_set(objects[6], 1, 1);
        break;
      case TWO:
        efl_gfx_size_hint_align_set(grid, 0.5, 0.5);
        for (int i = 0; i < 5; i++)
          efl_gfx_size_hint_weight_set(objects[i], 0, 0);
        efl_gfx_size_hint_weight_set(objects[5], 1, 1);
        efl_gfx_size_hint_weight_set(objects[6], 1, 1);
        break;
      case CUSTOM:
        efl_object_override(grid, &custom_layout_ops);
        break;
     }
}

static void
user_min_slider_cb(void *data EINA_UNUSED, const Efl_Event *event)
{
   int val = elm_slider_value_get(event->object);
   for (int i = 0; i < 6; i++)
     efl_gfx_size_hint_min_set(objects[i], val, val);
}

static void
padding_slider_cb(void *data, const Efl_Event *event)
{
   int val = elm_slider_value_get(event->object);
   efl_pack_padding_set(data, val, val, EINA_TRUE);
}

static void
margin_slider_cb(void *data, const Efl_Event *event)
{
   int val = elm_slider_value_get(event->object);
   efl_gfx_size_hint_margin_set(data, val, val, val, val);
}

static void
btnmargins_slider_cb(void *data, const Efl_Event *event)
{
   int val = elm_slider_value_get(event->object);
   for (int i = 1; i < 7; i++)
     efl_gfx_size_hint_margin_set(data, val, val, val, val);
}

static void
layout_updated_cb(void *data, const Efl_Event *event)
{
   Elm_Label *o = data;
   char buf[64];
   int rows, cols, count;

   efl_pack_grid_size_get(event->object, &cols, &rows);
   count = efl_content_count(event->object);
   sprintf(buf, "%d items (%dx%d)", count, cols, rows);
   elm_object_text_set(o, buf);
}

static void
child_evt_cb(void *data, const Efl_Event *event)
{
   Elm_Label *o = data;
   Efl_Gfx *it = event->info;
   int col, row, colspan, rowspan;
   char buf[64];

   efl_pack_grid_position_get(event->object, it, &col, &row, &colspan, &rowspan);
   if (event->desc == EFL_CONTAINER_EVENT_CONTENT_ADDED)
     sprintf(buf, "pack %d,%d %dx%d", col, row, colspan, rowspan);
   else
     sprintf(buf, "unpack %d,%d %dx%d", col, row, colspan, rowspan);
   elm_object_text_set(o, buf);
}

static void
_custom_layout_update(Eo *pack, void *_pd EINA_UNUSED)
{
   /* Example custom layout for grid:
    * divide space into regions of same size, place objects in center of their
    * cells using their min size
    * Note: This is a TERRIBLE layout function (disregards align, weight, ...)
    */

   int rows, cols, gw, gh, gx, gy, c, r, cs, rs, gmw = 0, gmh = 0;
   Eina_Iterator *it;
   Eo *item;

   efl_gfx_size_get(pack, &gw, &gh);
   efl_gfx_position_get(pack, &gx, &gy);

   efl_pack_grid_size_get(pack, &cols, &rows);
   if (!cols || !rows) goto end;

   it = efl_content_iterate(pack);
   EINA_ITERATOR_FOREACH(it, item)
     {
        if (efl_pack_grid_position_get(pack, item, &c, &r, &cs, &rs))
          {
             int x, y, mw, mh;

             efl_gfx_size_hint_combined_min_get(item, &mw, &mh);
             x = gx + c * gw / cols + (cs * gw / cols - mw) / 2;
             y = gy + r * gh / rows + (rs * gh / rows - mh) / 2;
             efl_gfx_size_set(item, mw, mh);
             efl_gfx_position_set(item, x, y);

             gmw = MAX(gmw, mw);
             gmh = MAX(gmh, mh);
          }
     }
   eina_iterator_free(it);

end:
   efl_gfx_size_hint_min_set(pack, gmw * cols, gmh * rows);
}

void
test_ui_grid(void *data EINA_UNUSED, Evas_Object *obj EINA_UNUSED, void *event_info EINA_UNUSED)
{
   Evas_Object *win, *bx, *o, *vbox, *f, *hbox, *chk, *grid;
   int i = 0;

   win = elm_win_util_standard_add("ui-grid", "Efl.Ui.Grid");
   elm_win_autodel_set(win, EINA_TRUE);
   efl_gfx_size_set(win, 600, 400);

   vbox = efl_add(EFL_UI_BOX_CLASS, win);
   efl_pack_padding_set(vbox, 10, 10, EINA_TRUE);
   efl_orientation_set(vbox, EFL_ORIENT_DOWN);
   efl_gfx_size_hint_weight_set(vbox, 1, 1);
   efl_gfx_size_hint_margin_set(vbox, 5, 5, 5, 5);
   elm_win_resize_object_add(win, vbox);
   efl_gfx_visible_set(vbox, 1);


   // create here to pass in cb
   grid = efl_add(EFL_UI_GRID_CLASS, win);


   /* controls */
   f = elm_frame_add(win);
   elm_object_text_set(f, "Controls");
   efl_gfx_size_hint_align_set(f, -1, -1);
   efl_gfx_size_hint_weight_set(f, 1, 0);
   efl_pack(vbox, f);
   efl_gfx_visible_set(f, 1);

   hbox = efl_add(EFL_UI_BOX_CLASS, win);
   elm_object_content_set(f, hbox);
   efl_pack_padding_set(hbox, 10, 0, EINA_TRUE);
   efl_gfx_visible_set(hbox, 1);


   /* weights radio group */
   bx = efl_add(EFL_UI_BOX_CLASS, win,
               efl_orientation_set(efl_added, EFL_ORIENT_DOWN));
   efl_gfx_size_hint_align_set(bx, 0, -1);
   efl_pack(hbox, bx);
   efl_gfx_visible_set(bx, 1);

   chk = o = elm_radio_add(win);
   elm_object_text_set(o, "No weight");
   efl_event_callback_add(o, EFL_UI_RADIO_EVENT_CHANGED, weights_cb, grid);
   efl_gfx_size_hint_align_set(o, 0, 0.5);
   elm_radio_state_value_set(o, NONE);
   efl_pack(bx, o);
   efl_gfx_visible_set(o, 1);

   o = elm_radio_add(win);
   elm_object_text_set(o, "No weight + grid fill");
   efl_event_callback_add(o, EFL_UI_RADIO_EVENT_CHANGED, weights_cb, grid);
   efl_gfx_size_hint_align_set(o, 0, 0.5);
   elm_radio_state_value_set(o, NONE_BUT_FILL);
   elm_radio_group_add(o, chk);
   efl_pack(bx, o);
   efl_gfx_visible_set(o, 1);

   o = elm_radio_add(win);
   elm_object_text_set(o, "Equal weights");
   efl_event_callback_add(o, EFL_UI_RADIO_EVENT_CHANGED, weights_cb, grid);
   efl_gfx_size_hint_align_set(o, 0, 0.5);
   elm_radio_state_value_set(o, EQUAL);
   elm_radio_group_add(o, chk);
   efl_pack(bx, o);
   efl_gfx_visible_set(o, 1);

   o = elm_radio_add(win);
   elm_object_text_set(o, "One weight only");
   efl_event_callback_add(o, EFL_UI_RADIO_EVENT_CHANGED, weights_cb, grid);
   efl_gfx_size_hint_align_set(o, 0, 0.5);
   elm_radio_state_value_set(o, ONE);
   elm_radio_group_add(o, chk);
   efl_pack(bx, o);
   efl_gfx_visible_set(o, 1);

   o = elm_radio_add(win);
   elm_object_text_set(o, "Two weights");
   efl_event_callback_add(o, EFL_UI_RADIO_EVENT_CHANGED, weights_cb, grid);
   efl_gfx_size_hint_align_set(o, 0, 0.5);
   elm_radio_state_value_set(o, TWO);
   elm_radio_group_add(o, chk);
   efl_pack(bx, o);
   efl_gfx_visible_set(o, 1);

   o = elm_radio_add(win);
   elm_object_text_set(o, "Custom layout");
   efl_event_callback_add(o, EFL_UI_RADIO_EVENT_CHANGED, weights_cb, grid);
   efl_gfx_size_hint_align_set(o, 0, 0.5);
   elm_radio_state_value_set(o, CUSTOM);
   elm_radio_group_add(o, chk);
   efl_pack(bx, o);
   efl_gfx_visible_set(o, 1);

   elm_radio_value_set(chk, EQUAL);


   /* min size setter */
   bx = efl_add(EFL_UI_BOX_CLASS, win,
               efl_orientation_set(efl_added, EFL_ORIENT_DOWN));
   efl_gfx_size_hint_align_set(bx, 0.5, -1);
   efl_gfx_size_hint_weight_set(bx, 0, 1);
   efl_pack(hbox, bx);
   efl_gfx_visible_set(bx, 1);

   o = elm_label_add(win);
   elm_object_text_set(o, "User min size");
   efl_pack(bx, o);
   efl_gfx_visible_set(o, 1);

   o = elm_slider_add(win);
   elm_slider_indicator_format_set(o, "%.0fpx");
   elm_slider_indicator_show_set(o, 1);
   elm_slider_horizontal_set(o, 0);
   efl_gfx_size_hint_align_set(o, 0.5, -1);
   efl_gfx_size_hint_weight_set(o, 1, 1);
   efl_event_callback_add(o, EFL_UI_SLIDER_EVENT_CHANGED, user_min_slider_cb, NULL);
   elm_slider_min_max_set(o, 0, 250);
   elm_slider_inverted_set(o, 1);
   elm_slider_value_set(o, 0);
   efl_pack(bx, o);
   efl_gfx_visible_set(o, 1);


   /* inner box padding */
   bx = efl_add(EFL_UI_BOX_CLASS, win,
               efl_orientation_set(efl_added, EFL_ORIENT_DOWN));
   efl_gfx_size_hint_align_set(bx, 0, -1);
   efl_gfx_size_hint_weight_set(bx, 0, 1);
   efl_pack(hbox, bx);
   efl_gfx_visible_set(bx, 1);

   o = elm_label_add(win);
   elm_object_text_set(o, "Padding");
   efl_pack(bx, o);
   efl_gfx_visible_set(o, 1);

   o = elm_slider_add(win);
   elm_slider_indicator_format_set(o, "%.0fpx");
   elm_slider_indicator_show_set(o, 1);
   elm_slider_horizontal_set(o, 0);
   efl_gfx_size_hint_align_set(o, 0.5, -1);
   efl_gfx_size_hint_weight_set(o, 1, 1);
   efl_event_callback_add(o, EFL_UI_SLIDER_EVENT_CHANGED, padding_slider_cb, grid);
   elm_slider_min_max_set(o, 0, 40);
   elm_slider_inverted_set(o, 1);
   elm_slider_value_set(o, 10);
   efl_pack(bx, o);
   efl_gfx_visible_set(o, 1);


   /* outer margin */
   bx = efl_add(EFL_UI_BOX_CLASS, win,
               efl_orientation_set(efl_added, EFL_ORIENT_DOWN));
   efl_gfx_size_hint_align_set(bx, 0, -1);
   efl_gfx_size_hint_weight_set(bx, 0, 1);
   efl_pack(hbox, bx);
   efl_gfx_visible_set(bx, 1);

   o = elm_label_add(win);
   elm_object_text_set(o, "Margin");
   efl_pack(bx, o);
   efl_gfx_visible_set(o, 1);

   o = elm_slider_add(win);
   elm_slider_indicator_format_set(o, "%.0fpx");
   elm_slider_indicator_show_set(o, 1);
   elm_slider_horizontal_set(o, 0);
   efl_gfx_size_hint_align_set(o, 0.5, -1);
   efl_gfx_size_hint_weight_set(o, 1, 1);
   efl_event_callback_add(o, EFL_UI_SLIDER_EVENT_CHANGED, margin_slider_cb, grid);
   elm_slider_min_max_set(o, 0, 40);
   elm_slider_inverted_set(o, 1);
   elm_slider_value_set(o, 10);
   efl_pack(bx, o);
   efl_gfx_visible_set(o, 1);


   /* button margins */
   bx = efl_add(EFL_UI_BOX_CLASS, win,
               efl_orientation_set(efl_added, EFL_ORIENT_DOWN));
   efl_gfx_size_hint_align_set(bx, 0, -1);
   efl_gfx_size_hint_weight_set(bx, 1, 1);
   efl_pack(hbox, bx);
   efl_gfx_visible_set(bx, 1);

   o = elm_label_add(win);
   elm_object_text_set(o, "Buttons margins");
   efl_pack(bx, o);
   efl_gfx_visible_set(o, 1);

   o = elm_slider_add(win);
   elm_slider_indicator_format_set(o, "%.0fpx");
   elm_slider_indicator_show_set(o, 1);
   elm_slider_horizontal_set(o, 0);
   efl_gfx_size_hint_align_set(o, 0.5, -1);
   efl_gfx_size_hint_weight_set(o, 1, 1);
   efl_event_callback_add(o, EFL_UI_SLIDER_EVENT_CHANGED, btnmargins_slider_cb, grid);
   elm_slider_min_max_set(o, 0, 40);
   elm_slider_inverted_set(o, 1);
   elm_slider_value_set(o, 10);
   efl_pack(bx, o);
   efl_gfx_visible_set(o, 1);


   /* ro info */
   bx = efl_add(EFL_UI_BOX_CLASS, win,
               efl_orientation_set(efl_added, EFL_ORIENT_DOWN));
   efl_gfx_size_hint_align_set(bx, 0, -1);
   efl_gfx_size_hint_weight_set(bx, 1, 1);
   efl_pack(hbox, bx);
   efl_gfx_visible_set(bx, 1);

   o = elm_label_add(win);
   elm_object_text_set(o, "<b>Properties</>");
   efl_pack(bx, o);
   efl_gfx_visible_set(o, 1);

   o = elm_label_add(win);
   efl_event_callback_add(grid, EFL_PACK_EVENT_LAYOUT_UPDATED, layout_updated_cb, o);
   efl_pack(bx, o);
   efl_gfx_visible_set(o, 1);

   o = elm_label_add(win);
   efl_event_callback_add(grid, EFL_CONTAINER_EVENT_CONTENT_ADDED, child_evt_cb, o);
   efl_event_callback_add(grid, EFL_CONTAINER_EVENT_CONTENT_REMOVED, child_evt_cb, o);
   efl_gfx_size_hint_align_set(o, 0.5, 0);
   efl_gfx_size_hint_weight_set(o, 1, 1);
   efl_pack(bx, o);
   efl_gfx_visible_set(o, 1);


   /* contents */
   f = elm_frame_add(win);
   elm_object_text_set(f, "Contents");
   efl_gfx_size_hint_align_set(f, -1, -1);
   efl_gfx_size_hint_weight_set(f, 1, 1);
   efl_pack(vbox, f);
   efl_gfx_visible_set(f, 1);

   efl_gfx_size_hint_weight_set(grid, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   elm_object_content_set(f, grid);
   efl_gfx_visible_set(grid, 1);

   objects[i++] = o = efl_add(EFL_CANVAS_RECTANGLE_CLASS, win);
   efl_gfx_size_hint_weight_set(o, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   efl_gfx_size_hint_align_set(o, EVAS_HINT_FILL, EVAS_HINT_FILL);
   efl_gfx_size_hint_min_set(o, 10, 10);
   efl_gfx_color_set(o, 64, 96, 128, 255);
   efl_pack_grid(grid, o, 0, 0, 3, 1);
   efl_gfx_visible_set(o, 1);

   objects[i++] = o = elm_button_add(win);
   elm_object_text_set(o, "Button 1");
   efl_gfx_size_hint_weight_set(o, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   efl_gfx_size_hint_align_set(o, EVAS_HINT_FILL, EVAS_HINT_FILL);
   efl_pack_grid(grid, o, 0, 0, 1, 1);
   efl_gfx_visible_set(o, 1);

   objects[i++] = o = elm_button_add(win);
   elm_object_text_set(o, "Button 2");
   efl_gfx_size_hint_weight_set(o, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   efl_gfx_size_hint_align_set(o, EVAS_HINT_FILL, EVAS_HINT_FILL);
   efl_pack_grid(grid, o, 1, 0, 1, 1);
   efl_gfx_visible_set(o, 1);

   objects[i++] = o = elm_button_add(win);
   elm_object_text_set(o, "Button 3");
   efl_gfx_size_hint_weight_set(o, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   efl_gfx_size_hint_align_set(o, EVAS_HINT_FILL, EVAS_HINT_FILL);
   efl_pack_grid(grid, o, 2, 0, 1, 1);
   efl_gfx_visible_set(o, 1);

   objects[i++] = o = elm_button_add(win);
   elm_object_text_set(o, "Button 4");
   efl_gfx_size_hint_weight_set(o, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   efl_gfx_size_hint_align_set(o, EVAS_HINT_FILL, EVAS_HINT_FILL);
   efl_pack_grid(grid, o, 0, 1, 2, 1);
   efl_gfx_visible_set(o, 1);

   objects[i++] = o = elm_button_add(win);
   elm_object_text_set(o, "Button 5");
   efl_gfx_size_hint_weight_set(o, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   efl_gfx_size_hint_align_set(o, EVAS_HINT_FILL, EVAS_HINT_FILL);
   efl_pack_grid(grid, o, 2, 1, 1, 2);
   efl_gfx_visible_set(o, 1);

   objects[i++] = o = elm_button_add(win);
   elm_object_text_set(o, "Button 6");
   efl_gfx_size_hint_weight_set(o, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   efl_gfx_size_hint_align_set(o, EVAS_HINT_FILL, EVAS_HINT_FILL);
   efl_pack_grid(grid, o, 0, 2, 2, 1);
   efl_gfx_visible_set(o, 1);

   efl_gfx_visible_set(win, 1);
}

static const char *
btn_text(const char *str)
{
   static char buf[64];
   static int id = 0;
   sprintf(buf, "%s %d", str ?: "item", ++id);
   return buf;
}

static void
remove_cb(void *data EINA_UNUSED, const Efl_Event *ev)
{
   efl_del(ev->object);
}

static void
append_cb(void *data, const Efl_Event *ev EINA_UNUSED)
{
   Eo *grid = data;
   Eo *o = elm_button_add(grid);
   elm_object_text_set(o, btn_text("appended"));
   efl_event_callback_add(o, EFL_UI_EVENT_CLICKED, remove_cb, NULL);
   elm_object_tooltip_text_set(o, "Click to unpack");
   efl_pack_end(grid, o);
   efl_gfx_visible_set(o, 1);
}

static void
clear_cb(void *data, const Efl_Event *ev EINA_UNUSED)
{
   Eo *grid = data;
   efl_pack_clear(grid);
}

void
test_ui_grid_linear(void *data EINA_UNUSED, Evas_Object *obj EINA_UNUSED,
                    void *event_info EINA_UNUSED)
{
   Evas_Object *win, *o, *vbox, *f, *hbox, *grid, *ico, *bx;

   win = elm_win_util_standard_add("ui-grid-linear", "Efl.Ui.Grid Linear APIs");
   elm_win_autodel_set(win, EINA_TRUE);
   efl_gfx_size_set(win, 600, 400);

   vbox = efl_add(EFL_UI_BOX_CLASS, win);
   efl_pack_padding_set(vbox, 10, 10, EINA_TRUE);
   efl_orientation_set(vbox, EFL_ORIENT_DOWN);
   efl_gfx_size_hint_weight_set(vbox, 1, 1);
   efl_gfx_size_hint_margin_set(vbox, 5, 5, 5, 5);
   elm_win_resize_object_add(win, vbox);
   efl_gfx_visible_set(vbox, 1);


   // create here to pass in cb
   grid = efl_add(EFL_UI_GRID_CLASS, win);


   /* controls */
   f = elm_frame_add(win);
   elm_object_text_set(f, "Controls");
   efl_gfx_size_hint_align_set(f, -1, -1);
   efl_gfx_size_hint_weight_set(f, 1, 0);
   efl_pack(vbox, f);
   efl_gfx_visible_set(f, 1);

   hbox = efl_add(EFL_UI_BOX_CLASS, win);
   elm_object_content_set(f, hbox);
   efl_pack_padding_set(hbox, 5, 0, EINA_TRUE);
   efl_gfx_visible_set(hbox, 1);

   ico = elm_icon_add(win);
   elm_icon_standard_set(ico, "list-add");
   o = elm_button_add(win);
   elm_object_content_set(o, ico);
   elm_object_text_set(o, "Append");
   efl_event_callback_add(o, EFL_UI_EVENT_CLICKED, append_cb, grid);
   efl_pack(hbox, o);
   efl_gfx_visible_set(o, 1);

   ico = elm_icon_add(win);
   elm_icon_standard_set(ico, "edit-clear-all");
   o = elm_button_add(win);
   elm_object_content_set(o, ico);
   elm_object_text_set(o, "Clear");
   efl_event_callback_add(o, EFL_UI_EVENT_CLICKED, clear_cb, grid);
   efl_pack(hbox, o);
   efl_gfx_visible_set(o, 1);


   /* ro info */
   bx = efl_add(EFL_UI_BOX_CLASS, win,
               efl_orientation_set(efl_added, EFL_ORIENT_DOWN));
   efl_gfx_size_hint_align_set(bx, 0, -1);
   efl_gfx_size_hint_weight_set(bx, 1, 1);
   efl_pack(hbox, bx);
   efl_gfx_visible_set(bx, 1);

   o = elm_label_add(win);
   elm_object_text_set(o, "<b>Properties</>");
   efl_pack(bx, o);
   efl_gfx_visible_set(o, 1);

   o = elm_label_add(win);
   efl_event_callback_add(grid, EFL_PACK_EVENT_LAYOUT_UPDATED, layout_updated_cb, o);
   efl_pack(bx, o);
   efl_gfx_visible_set(o, 1);

   o = elm_label_add(win);
   efl_event_callback_add(grid, EFL_CONTAINER_EVENT_CONTENT_ADDED, child_evt_cb, o);
   efl_event_callback_add(grid, EFL_CONTAINER_EVENT_CONTENT_REMOVED, child_evt_cb, o);
   efl_gfx_size_hint_align_set(o, 0.5, 0);
   efl_gfx_size_hint_weight_set(o, 1, 1);
   efl_pack(bx, o);
   efl_gfx_visible_set(o, 1);


   /* contents */
   f = elm_frame_add(win);
   elm_object_text_set(f, "Contents");
   efl_gfx_size_hint_align_set(f, -1, -1);
   efl_gfx_size_hint_weight_set(f, 1, 1);
   efl_pack(vbox, f);
   efl_gfx_visible_set(f, 1);

   efl_pack_grid_columns_set(grid, 4);
   efl_pack_grid_orientation_set(grid, EFL_ORIENT_RIGHT, EFL_ORIENT_DOWN);
   efl_gfx_size_hint_weight_set(grid, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   elm_object_content_set(f, grid);
   efl_gfx_visible_set(grid, 1);

   o = elm_button_add(win);
   elm_object_text_set(o, btn_text(NULL));
   efl_event_callback_add(o, EFL_UI_EVENT_CLICKED, remove_cb, NULL);
   efl_pack(grid, o);
   efl_gfx_visible_set(o, 1);

   o = elm_button_add(win);
   elm_object_text_set(o, btn_text(NULL));
   efl_event_callback_add(o, EFL_UI_EVENT_CLICKED, remove_cb, NULL);
   efl_pack(grid, o);
   efl_gfx_visible_set(o, 1);

   o = elm_button_add(win);
   elm_object_text_set(o, btn_text(NULL));
   efl_event_callback_add(o, EFL_UI_EVENT_CLICKED, remove_cb, NULL);
   efl_pack(grid, o);
   efl_gfx_visible_set(o, 1);

   efl_gfx_visible_set(win, 1);
}
