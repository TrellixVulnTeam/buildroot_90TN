
void _elm_slideshow_item_show(Eo *obj, Elm_Slideshow_Item_Data *pd);

EOAPI EFL_VOID_FUNC_BODY(elm_obj_slideshow_item_show);

Efl_Canvas_Object *_elm_slideshow_item_object_get(const Eo *obj, Elm_Slideshow_Item_Data *pd);

EOAPI EFL_FUNC_BODY_CONST(elm_obj_slideshow_item_object_get, Efl_Canvas_Object *, NULL);

Efl_Object *_elm_slideshow_item_efl_object_constructor(Eo *obj, Elm_Slideshow_Item_Data *pd);


void _elm_slideshow_item_efl_object_destructor(Eo *obj, Elm_Slideshow_Item_Data *pd);


static Eina_Bool
_elm_slideshow_item_class_initializer(Efl_Class *klass)
{
   const Efl_Object_Ops *opsp = NULL, *copsp = NULL;

#ifndef ELM_SLIDESHOW_ITEM_EXTRA_OPS
#define ELM_SLIDESHOW_ITEM_EXTRA_OPS
#endif

   EFL_OPS_DEFINE(ops,
      EFL_OBJECT_OP_FUNC(elm_obj_slideshow_item_show, _elm_slideshow_item_show),
      EFL_OBJECT_OP_FUNC(elm_obj_slideshow_item_object_get, _elm_slideshow_item_object_get),
      EFL_OBJECT_OP_FUNC(efl_constructor, _elm_slideshow_item_efl_object_constructor),
      EFL_OBJECT_OP_FUNC(efl_destructor, _elm_slideshow_item_efl_object_destructor),
      ELM_SLIDESHOW_ITEM_EXTRA_OPS
   );
   opsp = &ops;

#ifdef ELM_SLIDESHOW_ITEM_EXTRA_CLASS_OPS
   EFL_OPS_DEFINE(cops, ELM_SLIDESHOW_ITEM_EXTRA_CLASS_OPS);
   copsp = &cops;
#endif

   return efl_class_functions_set(klass, opsp, copsp);
}

static const Efl_Class_Description _elm_slideshow_item_class_desc = {
   EO_VERSION,
   "Elm.Slideshow.Item",
   EFL_CLASS_TYPE_REGULAR,
   sizeof(Elm_Slideshow_Item_Data),
   _elm_slideshow_item_class_initializer,
   NULL,
   NULL
};

EFL_DEFINE_CLASS(elm_slideshow_item_class_get, &_elm_slideshow_item_class_desc, ELM_WIDGET_ITEM_CLASS, NULL);

EAPI void
elm_slideshow_item_show(Elm_Slideshow_Item *obj)
{
   elm_obj_slideshow_item_show(obj);
}

EAPI Efl_Canvas_Object *
elm_slideshow_item_object_get(const Elm_Slideshow_Item *obj)
{
   return elm_obj_slideshow_item_object_get(obj);
}
