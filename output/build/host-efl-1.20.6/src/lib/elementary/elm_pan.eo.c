EWAPI const Efl_Event_Description _ELM_PAN_EVENT_CHANGED =
   EFL_EVENT_DESCRIPTION("changed");

void _elm_pan_pos_set(Eo *obj, Elm_Pan_Smart_Data *pd, int x, int y);

EOAPI EFL_VOID_FUNC_BODYV(elm_obj_pan_pos_set, EFL_FUNC_CALL(x, y), int x, int y);

void _elm_pan_pos_get(Eo *obj, Elm_Pan_Smart_Data *pd, int *x, int *y);

EOAPI EFL_VOID_FUNC_BODYV_CONST(elm_obj_pan_pos_get, EFL_FUNC_CALL(x, y), int *x, int *y);

void _elm_pan_content_size_get(Eo *obj, Elm_Pan_Smart_Data *pd, int *w, int *h);

EOAPI EFL_VOID_FUNC_BODYV_CONST(elm_obj_pan_content_size_get, EFL_FUNC_CALL(w, h), int *w, int *h);

void _elm_pan_pos_min_get(Eo *obj, Elm_Pan_Smart_Data *pd, int *x, int *y);

EOAPI EFL_VOID_FUNC_BODYV_CONST(elm_obj_pan_pos_min_get, EFL_FUNC_CALL(x, y), int *x, int *y);

void _elm_pan_pos_max_get(Eo *obj, Elm_Pan_Smart_Data *pd, int *x, int *y);

EOAPI EFL_VOID_FUNC_BODYV_CONST(elm_obj_pan_pos_max_get, EFL_FUNC_CALL(x, y), int *x, int *y);

Efl_Object *_elm_pan_efl_object_constructor(Eo *obj, Elm_Pan_Smart_Data *pd);


void _elm_pan_efl_gfx_visible_set(Eo *obj, Elm_Pan_Smart_Data *pd, Eina_Bool v);


void _elm_pan_efl_gfx_position_set(Eo *obj, Elm_Pan_Smart_Data *pd, int x, int y);


void _elm_pan_efl_gfx_size_set(Eo *obj, Elm_Pan_Smart_Data *pd, int w, int h);


static Eina_Bool
_elm_pan_class_initializer(Efl_Class *klass)
{
   const Efl_Object_Ops *opsp = NULL, *copsp = NULL;

#ifndef ELM_PAN_EXTRA_OPS
#define ELM_PAN_EXTRA_OPS
#endif

   EFL_OPS_DEFINE(ops,
      EFL_OBJECT_OP_FUNC(elm_obj_pan_pos_set, _elm_pan_pos_set),
      EFL_OBJECT_OP_FUNC(elm_obj_pan_pos_get, _elm_pan_pos_get),
      EFL_OBJECT_OP_FUNC(elm_obj_pan_content_size_get, _elm_pan_content_size_get),
      EFL_OBJECT_OP_FUNC(elm_obj_pan_pos_min_get, _elm_pan_pos_min_get),
      EFL_OBJECT_OP_FUNC(elm_obj_pan_pos_max_get, _elm_pan_pos_max_get),
      EFL_OBJECT_OP_FUNC(efl_constructor, _elm_pan_efl_object_constructor),
      EFL_OBJECT_OP_FUNC(efl_gfx_visible_set, _elm_pan_efl_gfx_visible_set),
      EFL_OBJECT_OP_FUNC(efl_gfx_position_set, _elm_pan_efl_gfx_position_set),
      EFL_OBJECT_OP_FUNC(efl_gfx_size_set, _elm_pan_efl_gfx_size_set),
      ELM_PAN_EXTRA_OPS
   );
   opsp = &ops;

#ifdef ELM_PAN_EXTRA_CLASS_OPS
   EFL_OPS_DEFINE(cops, ELM_PAN_EXTRA_CLASS_OPS);
   copsp = &cops;
#endif

   return efl_class_functions_set(klass, opsp, copsp);
}

static const Efl_Class_Description _elm_pan_class_desc = {
   EO_VERSION,
   "Elm.Pan",
   EFL_CLASS_TYPE_REGULAR,
   sizeof(Elm_Pan_Smart_Data),
   _elm_pan_class_initializer,
   _elm_pan_class_constructor,
   NULL
};

EFL_DEFINE_CLASS(elm_pan_class_get, &_elm_pan_class_desc, EFL_CANVAS_GROUP_CLIPPED_CLASS, NULL);

EAPI void
elm_pan_pos_set(Elm_Pan *obj, int x, int y)
{
   elm_obj_pan_pos_set(obj, x, y);
}

EAPI void
elm_pan_pos_get(const Elm_Pan *obj, int *x, int *y)
{
   elm_obj_pan_pos_get(obj, x, y);
}

EAPI void
elm_pan_content_size_get(const Elm_Pan *obj, int *w, int *h)
{
   elm_obj_pan_content_size_get(obj, w, h);
}

EAPI void
elm_pan_pos_min_get(const Elm_Pan *obj, int *x, int *y)
{
   elm_obj_pan_pos_min_get(obj, x, y);
}

EAPI void
elm_pan_pos_max_get(const Elm_Pan *obj, int *x, int *y)
{
   elm_obj_pan_pos_max_get(obj, x, y);
}
