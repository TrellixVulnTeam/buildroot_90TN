
Elm_Widget_Item *_elm_gengrid_item_prev_get(Eo *obj, Elm_Gen_Item *pd);

EOAPI EFL_FUNC_BODY_CONST(elm_obj_gengrid_item_prev_get, Elm_Widget_Item *, NULL);

Elm_Widget_Item *_elm_gengrid_item_next_get(Eo *obj, Elm_Gen_Item *pd);

EOAPI EFL_FUNC_BODY_CONST(elm_obj_gengrid_item_next_get, Elm_Widget_Item *, NULL);

void _elm_gengrid_item_selected_set(Eo *obj, Elm_Gen_Item *pd, Eina_Bool selected);

EOAPI EFL_VOID_FUNC_BODYV(elm_obj_gengrid_item_selected_set, EFL_FUNC_CALL(selected), Eina_Bool selected);

Eina_Bool _elm_gengrid_item_selected_get(Eo *obj, Elm_Gen_Item *pd);

EOAPI EFL_FUNC_BODY_CONST(elm_obj_gengrid_item_selected_get, Eina_Bool, 0);

const Elm_Gengrid_Item_Class *_elm_gengrid_item_item_class_get(Eo *obj, Elm_Gen_Item *pd);

EOAPI EFL_FUNC_BODY_CONST(elm_obj_gengrid_item_class_get, const Elm_Gengrid_Item_Class *, NULL);

int _elm_gengrid_item_index_get(Eo *obj, Elm_Gen_Item *pd);

EOAPI EFL_FUNC_BODY_CONST(elm_obj_gengrid_item_index_get, int, -1 /* +1 */);

void _elm_gengrid_item_pos_get(Eo *obj, Elm_Gen_Item *pd, unsigned int *x, unsigned int *y);

EOAPI EFL_VOID_FUNC_BODYV_CONST(elm_obj_gengrid_item_pos_get, EFL_FUNC_CALL(x, y), unsigned int *x, unsigned int *y);

void _elm_gengrid_item_select_mode_set(Eo *obj, Elm_Gen_Item *pd, Elm_Object_Select_Mode mode);

EOAPI EFL_VOID_FUNC_BODYV(elm_obj_gengrid_item_select_mode_set, EFL_FUNC_CALL(mode), Elm_Object_Select_Mode mode);

Elm_Object_Select_Mode _elm_gengrid_item_select_mode_get(Eo *obj, Elm_Gen_Item *pd);

EOAPI EFL_FUNC_BODY_CONST(elm_obj_gengrid_item_select_mode_get, Elm_Object_Select_Mode, 4 /* Elm.Object.Select_Mode.max */);

void _elm_gengrid_item_custom_size_set(Eo *obj, Elm_Gen_Item *pd, int w, int h);

EOAPI EFL_VOID_FUNC_BODYV(elm_obj_gengrid_item_custom_size_set, EFL_FUNC_CALL(w, h), int w, int h);

void _elm_gengrid_item_custom_size_get(Eo *obj, Elm_Gen_Item *pd, int *w, int *h);

EOAPI EFL_VOID_FUNC_BODYV_CONST(elm_obj_gengrid_item_custom_size_get, EFL_FUNC_CALL(w, h), int *w, int *h);

void _elm_gengrid_item_show(Eo *obj, Elm_Gen_Item *pd, Elm_Gengrid_Item_Scrollto_Type type);

EOAPI EFL_VOID_FUNC_BODYV(elm_obj_gengrid_item_show, EFL_FUNC_CALL(type), Elm_Gengrid_Item_Scrollto_Type type);

void _elm_gengrid_item_bring_in(Eo *obj, Elm_Gen_Item *pd, Elm_Gengrid_Item_Scrollto_Type type);

EOAPI EFL_VOID_FUNC_BODYV(elm_obj_gengrid_item_bring_in, EFL_FUNC_CALL(type), Elm_Gengrid_Item_Scrollto_Type type);

void _elm_gengrid_item_update(Eo *obj, Elm_Gen_Item *pd);

EOAPI EFL_VOID_FUNC_BODY(elm_obj_gengrid_item_update);

void _elm_gengrid_item_fields_update(Eo *obj, Elm_Gen_Item *pd, const char *parts, Elm_Gengrid_Item_Field_Type itf);

EOAPI EFL_VOID_FUNC_BODYV(elm_obj_gengrid_item_fields_update, EFL_FUNC_CALL(parts, itf), const char *parts, Elm_Gengrid_Item_Field_Type itf);

void _elm_gengrid_item_item_class_update(Eo *obj, Elm_Gen_Item *pd, const Elm_Gengrid_Item_Class *itc);

EOAPI EFL_VOID_FUNC_BODYV(elm_obj_gengrid_item_class_update, EFL_FUNC_CALL(itc), const Elm_Gengrid_Item_Class *itc);

void _elm_gengrid_item_all_contents_unset(Eo *obj, Elm_Gen_Item *pd, Eina_List **l);

EOAPI EFL_VOID_FUNC_BODYV(elm_obj_gengrid_item_all_contents_unset, EFL_FUNC_CALL(l), Eina_List **l);

Efl_Object *_elm_gengrid_item_efl_object_constructor(Eo *obj, Elm_Gen_Item *pd);


Eina_Bool _elm_gengrid_item_elm_widget_item_del_pre(Eo *obj, Elm_Gen_Item *pd);


void _elm_gengrid_item_elm_widget_item_disable(Eo *obj, Elm_Gen_Item *pd);


void _elm_gengrid_item_elm_widget_item_signal_emit(Eo *obj, Elm_Gen_Item *pd, const char *emission, const char *source);


void _elm_gengrid_item_elm_widget_item_focus_set(Eo *obj, Elm_Gen_Item *pd, Eina_Bool focused);


Eina_Bool _elm_gengrid_item_elm_widget_item_focus_get(Eo *obj, Elm_Gen_Item *pd);


const char *_elm_gengrid_item_elm_widget_item_part_text_get(Eo *obj, Elm_Gen_Item *pd, const char *part);


Efl_Canvas_Object *_elm_gengrid_item_elm_widget_item_part_content_get(Eo *obj, Elm_Gen_Item *pd, const char *part);


void _elm_gengrid_item_elm_widget_item_tooltip_text_set(Eo *obj, Elm_Gen_Item *pd, const char *text);


void _elm_gengrid_item_elm_widget_item_tooltip_style_set(Eo *obj, Elm_Gen_Item *pd, const char *style);


const char *_elm_gengrid_item_elm_widget_item_tooltip_style_get(Eo *obj, Elm_Gen_Item *pd);


Eina_Bool _elm_gengrid_item_elm_widget_item_tooltip_window_mode_set(Eo *obj, Elm_Gen_Item *pd, Eina_Bool disable);


Eina_Bool _elm_gengrid_item_elm_widget_item_tooltip_window_mode_get(Eo *obj, Elm_Gen_Item *pd);


void _elm_gengrid_item_elm_widget_item_tooltip_content_cb_set(Eo *obj, Elm_Gen_Item *pd, Elm_Tooltip_Item_Content_Cb func, const void *data, Evas_Smart_Cb del_cb);


void _elm_gengrid_item_elm_widget_item_tooltip_unset(Eo *obj, Elm_Gen_Item *pd);


void _elm_gengrid_item_elm_widget_item_cursor_set(Eo *obj, Elm_Gen_Item *pd, const char *cursor);


void _elm_gengrid_item_elm_widget_item_cursor_unset(Eo *obj, Elm_Gen_Item *pd);


const char *_elm_gengrid_item_elm_interface_atspi_accessible_name_get(Eo *obj, Elm_Gen_Item *pd);


Elm_Atspi_State_Set _elm_gengrid_item_elm_interface_atspi_accessible_state_set_get(Eo *obj, Elm_Gen_Item *pd);


static Eina_Bool
_elm_gengrid_item_class_initializer(Efl_Class *klass)
{
   const Efl_Object_Ops *opsp = NULL, *copsp = NULL;

#ifndef ELM_GENGRID_ITEM_EXTRA_OPS
#define ELM_GENGRID_ITEM_EXTRA_OPS
#endif

   EFL_OPS_DEFINE(ops,
      EFL_OBJECT_OP_FUNC(elm_obj_gengrid_item_prev_get, _elm_gengrid_item_prev_get),
      EFL_OBJECT_OP_FUNC(elm_obj_gengrid_item_next_get, _elm_gengrid_item_next_get),
      EFL_OBJECT_OP_FUNC(elm_obj_gengrid_item_selected_set, _elm_gengrid_item_selected_set),
      EFL_OBJECT_OP_FUNC(elm_obj_gengrid_item_selected_get, _elm_gengrid_item_selected_get),
      EFL_OBJECT_OP_FUNC(elm_obj_gengrid_item_class_get, _elm_gengrid_item_item_class_get),
      EFL_OBJECT_OP_FUNC(elm_obj_gengrid_item_index_get, _elm_gengrid_item_index_get),
      EFL_OBJECT_OP_FUNC(elm_obj_gengrid_item_pos_get, _elm_gengrid_item_pos_get),
      EFL_OBJECT_OP_FUNC(elm_obj_gengrid_item_select_mode_set, _elm_gengrid_item_select_mode_set),
      EFL_OBJECT_OP_FUNC(elm_obj_gengrid_item_select_mode_get, _elm_gengrid_item_select_mode_get),
      EFL_OBJECT_OP_FUNC(elm_obj_gengrid_item_custom_size_set, _elm_gengrid_item_custom_size_set),
      EFL_OBJECT_OP_FUNC(elm_obj_gengrid_item_custom_size_get, _elm_gengrid_item_custom_size_get),
      EFL_OBJECT_OP_FUNC(elm_obj_gengrid_item_show, _elm_gengrid_item_show),
      EFL_OBJECT_OP_FUNC(elm_obj_gengrid_item_bring_in, _elm_gengrid_item_bring_in),
      EFL_OBJECT_OP_FUNC(elm_obj_gengrid_item_update, _elm_gengrid_item_update),
      EFL_OBJECT_OP_FUNC(elm_obj_gengrid_item_fields_update, _elm_gengrid_item_fields_update),
      EFL_OBJECT_OP_FUNC(elm_obj_gengrid_item_class_update, _elm_gengrid_item_item_class_update),
      EFL_OBJECT_OP_FUNC(elm_obj_gengrid_item_all_contents_unset, _elm_gengrid_item_all_contents_unset),
      EFL_OBJECT_OP_FUNC(efl_constructor, _elm_gengrid_item_efl_object_constructor),
      EFL_OBJECT_OP_FUNC(elm_wdg_item_del_pre, _elm_gengrid_item_elm_widget_item_del_pre),
      EFL_OBJECT_OP_FUNC(elm_wdg_item_disable, _elm_gengrid_item_elm_widget_item_disable),
      EFL_OBJECT_OP_FUNC(elm_wdg_item_signal_emit, _elm_gengrid_item_elm_widget_item_signal_emit),
      EFL_OBJECT_OP_FUNC(elm_wdg_item_focus_set, _elm_gengrid_item_elm_widget_item_focus_set),
      EFL_OBJECT_OP_FUNC(elm_wdg_item_focus_get, _elm_gengrid_item_elm_widget_item_focus_get),
      EFL_OBJECT_OP_FUNC(elm_wdg_item_part_text_get, _elm_gengrid_item_elm_widget_item_part_text_get),
      EFL_OBJECT_OP_FUNC(elm_wdg_item_part_content_get, _elm_gengrid_item_elm_widget_item_part_content_get),
      EFL_OBJECT_OP_FUNC(elm_wdg_item_tooltip_text_set, _elm_gengrid_item_elm_widget_item_tooltip_text_set),
      EFL_OBJECT_OP_FUNC(elm_wdg_item_tooltip_style_set, _elm_gengrid_item_elm_widget_item_tooltip_style_set),
      EFL_OBJECT_OP_FUNC(elm_wdg_item_tooltip_style_get, _elm_gengrid_item_elm_widget_item_tooltip_style_get),
      EFL_OBJECT_OP_FUNC(elm_wdg_item_tooltip_window_mode_set, _elm_gengrid_item_elm_widget_item_tooltip_window_mode_set),
      EFL_OBJECT_OP_FUNC(elm_wdg_item_tooltip_window_mode_get, _elm_gengrid_item_elm_widget_item_tooltip_window_mode_get),
      EFL_OBJECT_OP_FUNC(elm_wdg_item_tooltip_content_cb_set, _elm_gengrid_item_elm_widget_item_tooltip_content_cb_set),
      EFL_OBJECT_OP_FUNC(elm_wdg_item_tooltip_unset, _elm_gengrid_item_elm_widget_item_tooltip_unset),
      EFL_OBJECT_OP_FUNC(elm_wdg_item_cursor_set, _elm_gengrid_item_elm_widget_item_cursor_set),
      EFL_OBJECT_OP_FUNC(elm_wdg_item_cursor_unset, _elm_gengrid_item_elm_widget_item_cursor_unset),
      EFL_OBJECT_OP_FUNC(elm_interface_atspi_accessible_name_get, _elm_gengrid_item_elm_interface_atspi_accessible_name_get),
      EFL_OBJECT_OP_FUNC(elm_interface_atspi_accessible_state_set_get, _elm_gengrid_item_elm_interface_atspi_accessible_state_set_get),
      ELM_GENGRID_ITEM_EXTRA_OPS
   );
   opsp = &ops;

#ifdef ELM_GENGRID_ITEM_EXTRA_CLASS_OPS
   EFL_OPS_DEFINE(cops, ELM_GENGRID_ITEM_EXTRA_CLASS_OPS);
   copsp = &cops;
#endif

   return efl_class_functions_set(klass, opsp, copsp);
}

static const Efl_Class_Description _elm_gengrid_item_class_desc = {
   EO_VERSION,
   "Elm.Gengrid.Item",
   EFL_CLASS_TYPE_REGULAR,
   sizeof(Elm_Gen_Item),
   _elm_gengrid_item_class_initializer,
   NULL,
   NULL
};

EFL_DEFINE_CLASS(elm_gengrid_item_class_get, &_elm_gengrid_item_class_desc, ELM_WIDGET_ITEM_CLASS, NULL);

EAPI Elm_Widget_Item *
elm_gengrid_item_prev_get(const Elm_Gengrid_Item *obj)
{
   return elm_obj_gengrid_item_prev_get(obj);
}

EAPI Elm_Widget_Item *
elm_gengrid_item_next_get(const Elm_Gengrid_Item *obj)
{
   return elm_obj_gengrid_item_next_get(obj);
}

EAPI void
elm_gengrid_item_selected_set(Elm_Gengrid_Item *obj, Eina_Bool selected)
{
   elm_obj_gengrid_item_selected_set(obj, selected);
}

EAPI Eina_Bool
elm_gengrid_item_selected_get(const Elm_Gengrid_Item *obj)
{
   return elm_obj_gengrid_item_selected_get(obj);
}

EAPI const Elm_Gengrid_Item_Class *
elm_gengrid_item_item_class_get(const Elm_Gengrid_Item *obj)
{
   return elm_obj_gengrid_item_class_get(obj);
}

EAPI int
elm_gengrid_item_index_get(const Elm_Gengrid_Item *obj)
{
   return elm_obj_gengrid_item_index_get(obj);
}

EAPI void
elm_gengrid_item_pos_get(const Elm_Gengrid_Item *obj, unsigned int *x, unsigned int *y)
{
   elm_obj_gengrid_item_pos_get(obj, x, y);
}

EAPI void
elm_gengrid_item_select_mode_set(Elm_Gengrid_Item *obj, Elm_Object_Select_Mode mode)
{
   elm_obj_gengrid_item_select_mode_set(obj, mode);
}

EAPI Elm_Object_Select_Mode
elm_gengrid_item_select_mode_get(const Elm_Gengrid_Item *obj)
{
   return elm_obj_gengrid_item_select_mode_get(obj);
}

EAPI void
elm_gengrid_item_custom_size_set(Elm_Gengrid_Item *obj, int w, int h)
{
   elm_obj_gengrid_item_custom_size_set(obj, w, h);
}

EAPI void
elm_gengrid_item_custom_size_get(const Elm_Gengrid_Item *obj, int *w, int *h)
{
   elm_obj_gengrid_item_custom_size_get(obj, w, h);
}

EAPI void
elm_gengrid_item_show(Elm_Gengrid_Item *obj, Elm_Gengrid_Item_Scrollto_Type type)
{
   elm_obj_gengrid_item_show(obj, type);
}

EAPI void
elm_gengrid_item_bring_in(Elm_Gengrid_Item *obj, Elm_Gengrid_Item_Scrollto_Type type)
{
   elm_obj_gengrid_item_bring_in(obj, type);
}

EAPI void
elm_gengrid_item_update(Elm_Gengrid_Item *obj)
{
   elm_obj_gengrid_item_update(obj);
}

EAPI void
elm_gengrid_item_fields_update(Elm_Gengrid_Item *obj, const char *parts, Elm_Gengrid_Item_Field_Type itf)
{
   elm_obj_gengrid_item_fields_update(obj, parts, itf);
}

EAPI void
elm_gengrid_item_item_class_update(Elm_Gengrid_Item *obj, const Elm_Gengrid_Item_Class *itc)
{
   elm_obj_gengrid_item_class_update(obj, itc);
}

EAPI void
elm_gengrid_item_all_contents_unset(Elm_Gengrid_Item *obj, Eina_List **l)
{
   elm_obj_gengrid_item_all_contents_unset(obj, l);
}
