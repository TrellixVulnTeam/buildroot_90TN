
Eina_Bool _elm_sys_notify_servers_set(Eo *obj, Elm_Sys_Notify_Data *pd, Elm_Sys_Notify_Server servers);

EOAPI EFL_FUNC_BODYV(elm_obj_sys_notify_servers_set, Eina_Bool, 0, EFL_FUNC_CALL(servers), Elm_Sys_Notify_Server servers);

Elm_Sys_Notify_Server _elm_sys_notify_servers_get(Eo *obj, Elm_Sys_Notify_Data *pd);

EOAPI EFL_FUNC_BODY_CONST(elm_obj_sys_notify_servers_get, Elm_Sys_Notify_Server, 0);

Elm_Sys_Notify *_elm_sys_notify_singleton_get(Eo *obj, void *pd);

EOAPI EFL_FUNC_BODY_CONST(elm_obj_sys_notify_singleton_get, Elm_Sys_Notify *, NULL);

Efl_Object *_elm_sys_notify_efl_object_constructor(Eo *obj, Elm_Sys_Notify_Data *pd);


void _elm_sys_notify_efl_object_destructor(Eo *obj, Elm_Sys_Notify_Data *pd);


void _elm_sys_notify_elm_sys_notify_interface_send(const Eo *obj, Elm_Sys_Notify_Data *pd, unsigned int replaces_id, const char *icon, const char *summary, const char *body, Elm_Sys_Notify_Urgency urgency, int timeout, Elm_Sys_Notify_Send_Cb cb, const void *cb_data);


void _elm_sys_notify_elm_sys_notify_interface_simple_send(const Eo *obj, Elm_Sys_Notify_Data *pd, const char *icon, const char *summary, const char *body);


void _elm_sys_notify_elm_sys_notify_interface_close(const Eo *obj, Elm_Sys_Notify_Data *pd, unsigned int id);


static Eina_Bool
_elm_sys_notify_class_initializer(Efl_Class *klass)
{
   const Efl_Object_Ops *opsp = NULL, *copsp = NULL;

#ifndef ELM_SYS_NOTIFY_EXTRA_OPS
#define ELM_SYS_NOTIFY_EXTRA_OPS
#endif

   EFL_OPS_DEFINE(ops,
      EFL_OBJECT_OP_FUNC(elm_obj_sys_notify_servers_set, _elm_sys_notify_servers_set),
      EFL_OBJECT_OP_FUNC(elm_obj_sys_notify_servers_get, _elm_sys_notify_servers_get),
      EFL_OBJECT_OP_FUNC(efl_constructor, _elm_sys_notify_efl_object_constructor),
      EFL_OBJECT_OP_FUNC(efl_destructor, _elm_sys_notify_efl_object_destructor),
      EFL_OBJECT_OP_FUNC(elm_obj_sys_notify_interface_send, _elm_sys_notify_elm_sys_notify_interface_send),
      EFL_OBJECT_OP_FUNC(elm_obj_sys_notify_interface_simple_send, _elm_sys_notify_elm_sys_notify_interface_simple_send),
      EFL_OBJECT_OP_FUNC(elm_obj_sys_notify_interface_close, _elm_sys_notify_elm_sys_notify_interface_close),
      ELM_SYS_NOTIFY_EXTRA_OPS
   );
   opsp = &ops;

#ifndef ELM_SYS_NOTIFY_EXTRA_CLASS_OPS
#define ELM_SYS_NOTIFY_EXTRA_CLASS_OPS
#endif

   EFL_OPS_DEFINE(cops,
      EFL_OBJECT_OP_FUNC(elm_obj_sys_notify_singleton_get, _elm_sys_notify_singleton_get),
      ELM_SYS_NOTIFY_EXTRA_CLASS_OPS
   );
   copsp = &cops;

   return efl_class_functions_set(klass, opsp, copsp);
}

static const Efl_Class_Description _elm_sys_notify_class_desc = {
   EO_VERSION,
   "Elm.Sys_Notify",
   EFL_CLASS_TYPE_REGULAR,
   sizeof(Elm_Sys_Notify_Data),
   _elm_sys_notify_class_initializer,
   _elm_sys_notify_class_constructor,
   NULL
};

EFL_DEFINE_CLASS(elm_sys_notify_class_get, &_elm_sys_notify_class_desc, EFL_OBJECT_CLASS, ELM_SYS_NOTIFY_INTERFACE_INTERFACE, NULL);

EAPI Eina_Bool
elm_sys_notify_servers_set(Elm_Sys_Notify *obj, Elm_Sys_Notify_Server servers)
{
   return elm_obj_sys_notify_servers_set(obj, servers);
}

EAPI Elm_Sys_Notify_Server
elm_sys_notify_servers_get(const Elm_Sys_Notify *obj)
{
   return elm_obj_sys_notify_servers_get(obj);
}

EAPI Elm_Sys_Notify *
elm_sys_notify_singleton_get()
{
   return elm_obj_sys_notify_singleton_get(ELM_SYS_NOTIFY_CLASS);
}
