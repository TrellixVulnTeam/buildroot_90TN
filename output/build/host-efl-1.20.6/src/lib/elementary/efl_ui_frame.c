#ifdef HAVE_CONFIG_H
# include "elementary_config.h"
#endif

#define ELM_INTERFACE_ATSPI_ACCESSIBLE_PROTECTED
#define ELM_LAYOUT_PROTECTED

#include <Elementary.h>
#include "elm_priv.h"
#include "efl_ui_widget_frame.h"
#include "elm_widget_layout.h"

#define MY_CLASS EFL_UI_FRAME_CLASS
#define MY_CLASS_NAME "Efl.Ui.Frame"
#define MY_CLASS_NAME_LEGACY "elm_frame"

static const char SIG_CLICKED[] = "clicked";

static const Evas_Smart_Cb_Description _smart_callbacks[] = {
   {SIG_CLICKED, ""},
   {SIG_WIDGET_LANG_CHANGED, ""}, /**< handled by elm_widget */
   {SIG_WIDGET_ACCESS_CHANGED, ""}, /**< handled by elm_widget */
   {NULL, NULL}
};

static const Elm_Layout_Part_Alias_Description _content_aliases[] =
{
   {"default", "elm.swallow.content"},
   {NULL, NULL}
};

static const Elm_Layout_Part_Alias_Description _text_aliases[] =
{
   {"default", "elm.text"},
   {NULL, NULL}
};

static void
_sizing_eval(Evas_Object *obj,
             Efl_Ui_Frame_Data *sd EINA_UNUSED)
{
   ELM_WIDGET_DATA_GET_OR_RETURN(obj, wd);
   Evas_Coord minw = -1, minh = -1;
   Evas_Coord cminw = -1, cminh = -1;

   edje_object_size_min_calc(wd->resize_obj, &minw, &minh);
   evas_object_size_hint_min_get(obj, &cminw, &cminh);
   if ((minw == cminw) && (minh == cminh)) return;

   evas_object_size_hint_min_set(obj, minw, minh);
   evas_object_size_hint_max_set(obj, -1, -1);
}

EOLIAN static Eina_Bool
_efl_ui_frame_elm_widget_focus_next_manager_is(Eo *obj EINA_UNUSED, Efl_Ui_Frame_Data *_pd EINA_UNUSED)
{
   return EINA_TRUE;
}

EOLIAN static Eina_Bool
_efl_ui_frame_elm_widget_focus_next(Eo *obj EINA_UNUSED, Efl_Ui_Frame_Data *_pd EINA_UNUSED, Elm_Focus_Direction dir, Evas_Object **next, Elm_Object_Item **next_item)
{
   Evas_Object *content;

   content = elm_layout_content_get(obj, NULL);

   if (!content) return EINA_FALSE;

   else
     {
        /* attempt to follow focus cycle into sub-object */
        return elm_widget_focus_next_get(content, dir, next, next_item);
     }
}

EOLIAN static Eina_Bool
_efl_ui_frame_elm_widget_focus_direction_manager_is(Eo *obj EINA_UNUSED, Efl_Ui_Frame_Data *_pd EINA_UNUSED)
{
   return EINA_TRUE;
}

EOLIAN static Eina_Bool
_efl_ui_frame_elm_widget_focus_direction(Eo *obj EINA_UNUSED, Efl_Ui_Frame_Data *_pd EINA_UNUSED, const Evas_Object *base, double degree, Evas_Object **direction, Elm_Object_Item **direction_item, double *weight)
{
   Evas_Object *content;

   content = elm_layout_content_get(obj, NULL);

   if (!content) return EINA_FALSE;

   else
     {
        /* Try to cycle focus on content */
        return elm_widget_focus_direction_get
           (content, base, degree, direction, direction_item, weight);
     }
}

static void
_recalc(void *data, const Efl_Event *event EINA_UNUSED)
{
   elm_layout_sizing_eval(data);
}

static void
_on_recalc_done(void *data,
                Evas_Object *obj EINA_UNUSED,
                const char *sig EINA_UNUSED,
                const char *src EINA_UNUSED)
{
   EFL_UI_FRAME_DATA_GET(data, sd);
   ELM_WIDGET_DATA_GET_OR_RETURN(data, wd);

   efl_event_callback_del
     (wd->resize_obj, EDJE_OBJECT_EVENT_RECALC, _recalc, data);
   sd->anim = EINA_FALSE;

   elm_layout_sizing_eval(data);
}

static void
_on_frame_clicked(void *data,
                  Evas_Object *obj EINA_UNUSED,
                  const char *sig EINA_UNUSED,
                  const char *src EINA_UNUSED)
{
   EFL_UI_FRAME_DATA_GET(data, sd);
   ELM_WIDGET_DATA_GET_OR_RETURN(data, wd);

   if (sd->anim) return;

   if (sd->collapsible)
     {
        efl_event_callback_add(wd->resize_obj, EDJE_OBJECT_EVENT_RECALC, _recalc, data);
        elm_layout_signal_emit(data, "elm,action,toggle", "elm");
        sd->collapsed++;
        sd->anim = EINA_TRUE;
        elm_widget_tree_unfocusable_set(data, sd->collapsed);
     }
   efl_event_callback_legacy_call
     (data, EFL_UI_EVENT_CLICKED, NULL);
}

/* using deferred sizing evaluation, just like the parent */
EOLIAN static void
_efl_ui_frame_efl_canvas_group_group_calculate(Eo *obj, Efl_Ui_Frame_Data *sd)
{
   ELM_LAYOUT_DATA_GET(obj, ld);

   if (ld->needs_size_calc)
     {
        /* calling OWN sizing evaluate code here */
        _sizing_eval(obj, sd);
        ld->needs_size_calc = EINA_FALSE;
     }
}

EOLIAN static void
_efl_ui_frame_efl_canvas_group_group_add(Eo *obj, Efl_Ui_Frame_Data *_pd EINA_UNUSED)
{
   ELM_WIDGET_DATA_GET_OR_RETURN(obj, wd);

   efl_canvas_group_add(efl_super(obj, MY_CLASS));
   elm_widget_sub_object_parent_add(obj);

   edje_object_signal_callback_add
     (wd->resize_obj, "elm,anim,done", "elm",
     _on_recalc_done, obj);
   edje_object_signal_callback_add
     (wd->resize_obj, "elm,action,click", "elm",
     _on_frame_clicked, obj);

   elm_widget_can_focus_set(obj, EINA_FALSE);

   if (!elm_layout_theme_set(obj, "frame", "base", elm_widget_style_get(obj)))
     CRI("Failed to set layout!");

   elm_layout_sizing_eval(obj);
}

EOLIAN static const Elm_Layout_Part_Alias_Description*
_efl_ui_frame_elm_layout_content_aliases_get(Eo *obj EINA_UNUSED, Efl_Ui_Frame_Data *_pd EINA_UNUSED)
{
   return _content_aliases;
}

EOLIAN static const Elm_Layout_Part_Alias_Description*
_efl_ui_frame_elm_layout_text_aliases_get(Eo *obj EINA_UNUSED, Efl_Ui_Frame_Data *_pd EINA_UNUSED)
{
   return _text_aliases;
}

EAPI Evas_Object *
elm_frame_add(Evas_Object *parent)
{
   EINA_SAFETY_ON_NULL_RETURN_VAL(parent, NULL);
   return efl_add(MY_CLASS, parent, efl_canvas_object_legacy_ctor(efl_added));
}

EOLIAN static Eo *
_efl_ui_frame_efl_object_constructor(Eo *obj, Efl_Ui_Frame_Data *_pd EINA_UNUSED)
{
   obj = efl_constructor(efl_super(obj, MY_CLASS));
   efl_canvas_object_type_set(obj, MY_CLASS_NAME_LEGACY);
   evas_object_smart_callbacks_descriptions_set(obj, _smart_callbacks);
   elm_interface_atspi_accessible_role_set(obj, ELM_ATSPI_ROLE_FRAME);

   return obj;
}

EOLIAN static void
_efl_ui_frame_autocollapse_set(Eo *obj EINA_UNUSED, Efl_Ui_Frame_Data *sd, Eina_Bool autocollapse)
{

   sd->collapsible = !!autocollapse;
}

EOLIAN static Eina_Bool
_efl_ui_frame_autocollapse_get(Eo *obj EINA_UNUSED, Efl_Ui_Frame_Data *sd)
{
   return sd->collapsible;
}

EOLIAN static void
_efl_ui_frame_collapse_set(Eo *obj, Efl_Ui_Frame_Data *sd, Eina_Bool collapse)
{
   ELM_WIDGET_DATA_GET_OR_RETURN(obj, wd);

   collapse = !!collapse;
   if (sd->collapsed == collapse) return;

   elm_layout_signal_emit(obj, "elm,action,switch", "elm");
   edje_object_message_signal_process(wd->resize_obj);
   sd->collapsed = !!collapse;
   sd->anim = EINA_FALSE;

   elm_widget_tree_unfocusable_set(obj, sd->collapsed);
   _sizing_eval(obj, sd);
}

EOLIAN static void
_efl_ui_frame_collapse_go(Eo *obj, Efl_Ui_Frame_Data *sd, Eina_Bool collapse)
{
   ELM_WIDGET_DATA_GET_OR_RETURN(obj, wd);

   collapse = !!collapse;
   if (sd->collapsed == collapse) return;

   elm_layout_signal_emit(obj, "elm,action,toggle", "elm");
   efl_event_callback_legacy_call
     (wd->resize_obj, EDJE_OBJECT_EVENT_RECALC, obj);
   sd->collapsed = collapse;
   elm_widget_tree_unfocusable_set(obj, sd->collapsed);
   sd->anim = EINA_TRUE;
}

EOLIAN static Eina_Bool
_efl_ui_frame_collapse_get(Eo *obj EINA_UNUSED, Efl_Ui_Frame_Data *sd)
{
   return sd->collapsed;
}

EOLIAN static void
_efl_ui_frame_class_constructor(Efl_Class *klass)
{
      evas_smart_legacy_type_register(MY_CLASS_NAME_LEGACY, klass);
}

/* Internal EO APIs and hidden overrides */

#define EFL_UI_FRAME_EXTRA_OPS \
   EFL_CANVAS_GROUP_ADD_OPS(efl_ui_frame)

#include "efl_ui_frame.eo.c"
