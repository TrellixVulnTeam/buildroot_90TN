
Eina_Bool _ector_renderer_software_shape_ector_renderer_prepare(Eo *obj, Ector_Renderer_Software_Shape_Data *pd);


Eina_Bool _ector_renderer_software_shape_ector_renderer_draw(Eo *obj, Ector_Renderer_Software_Shape_Data *pd, Efl_Gfx_Render_Op op, Eina_Array *clips, unsigned int mul_col);


Eina_Bool _ector_renderer_software_shape_ector_renderer_software_fill(Eo *obj, Ector_Renderer_Software_Shape_Data *pd);


unsigned int _ector_renderer_software_shape_ector_renderer_crc_get(Eo *obj, Ector_Renderer_Software_Shape_Data *pd);


void _ector_renderer_software_shape_efl_gfx_path_path_set(Eo *obj, Ector_Renderer_Software_Shape_Data *pd, const Efl_Gfx_Path_Command_Type *op, const double *points);


Efl_Object *_ector_renderer_software_shape_efl_object_constructor(Eo *obj, Ector_Renderer_Software_Shape_Data *pd);


void _ector_renderer_software_shape_efl_object_destructor(Eo *obj, Ector_Renderer_Software_Shape_Data *pd);


static Eina_Bool
_ector_renderer_software_shape_class_initializer(Efl_Class *klass)
{
   const Efl_Object_Ops *opsp = NULL, *copsp = NULL;

#ifndef ECTOR_RENDERER_SOFTWARE_SHAPE_EXTRA_OPS
#define ECTOR_RENDERER_SOFTWARE_SHAPE_EXTRA_OPS
#endif

   EFL_OPS_DEFINE(ops,
      EFL_OBJECT_OP_FUNC(ector_renderer_prepare, _ector_renderer_software_shape_ector_renderer_prepare),
      EFL_OBJECT_OP_FUNC(ector_renderer_draw, _ector_renderer_software_shape_ector_renderer_draw),
      EFL_OBJECT_OP_FUNC(ector_renderer_software_fill, _ector_renderer_software_shape_ector_renderer_software_fill),
      EFL_OBJECT_OP_FUNC(ector_renderer_crc_get, _ector_renderer_software_shape_ector_renderer_crc_get),
      EFL_OBJECT_OP_FUNC(efl_gfx_path_set, _ector_renderer_software_shape_efl_gfx_path_path_set),
      EFL_OBJECT_OP_FUNC(efl_constructor, _ector_renderer_software_shape_efl_object_constructor),
      EFL_OBJECT_OP_FUNC(efl_destructor, _ector_renderer_software_shape_efl_object_destructor),
      ECTOR_RENDERER_SOFTWARE_SHAPE_EXTRA_OPS
   );
   opsp = &ops;

#ifdef ECTOR_RENDERER_SOFTWARE_SHAPE_EXTRA_CLASS_OPS
   EFL_OPS_DEFINE(cops, ECTOR_RENDERER_SOFTWARE_SHAPE_EXTRA_CLASS_OPS);
   copsp = &cops;
#endif

   return efl_class_functions_set(klass, opsp, copsp);
}

static const Efl_Class_Description _ector_renderer_software_shape_class_desc = {
   EO_VERSION,
   "Ector.Renderer.Software.Shape",
   EFL_CLASS_TYPE_REGULAR,
   sizeof(Ector_Renderer_Software_Shape_Data),
   _ector_renderer_software_shape_class_initializer,
   NULL,
   NULL
};

EFL_DEFINE_CLASS(ector_renderer_software_shape_class_get, &_ector_renderer_software_shape_class_desc, ECTOR_RENDERER_SOFTWARE_CLASS, ECTOR_RENDERER_SHAPE_MIXIN, NULL);
