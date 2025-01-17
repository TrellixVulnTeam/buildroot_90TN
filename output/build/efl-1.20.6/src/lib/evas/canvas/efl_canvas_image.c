#include "evas_image_private.h"
#include "efl_canvas_image.eo.h"

#define MY_CLASS EFL_CANVAS_IMAGE_CLASS
#define MY_CLASS_NAME efl_class_name_get(MY_CLASS)

Eina_Bool
_evas_image_mmap_set(Eo *eo_obj, const Eina_File *f, const char *key)
{
   Evas_Object_Protected_Data *obj = efl_data_scope_get(eo_obj, EFL_CANVAS_OBJECT_CLASS);
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);
   Evas_Image_Load_Opts lo;

   if (o->cur->u.f == f)
     {
        if ((!o->cur->key) && (!key))
          return EINA_FALSE;
        if ((o->cur->key) && (key) && (!strcmp(o->cur->key, key)))
          return EINA_FALSE;
     }
   evas_object_async_block(obj);
   _evas_image_init_set(f, NULL, key, eo_obj, obj, o, &lo);
   o->engine_data = ENFN->image_mmap(ENDT, o->cur->u.f, o->cur->key, &o->load_error, &lo);
   o->buffer_data_set = EINA_FALSE;
   _evas_image_done_set(eo_obj, obj, o);
   o->file_size.w = o->cur->image.w;
   o->file_size.h = o->cur->image.h;

   return EINA_TRUE;
}

EOLIAN static Eina_Bool
_efl_canvas_image_efl_file_mmap_set(Eo *eo_obj, void *_pd EINA_UNUSED EINA_UNUSED,
                                    const Eina_File *f, const char *key)
{
   return _evas_image_mmap_set(eo_obj, f, key);
}

void
_evas_image_mmap_get(const Eo *eo_obj, const Eina_File **f, const char **key)
{
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);

   if (f)
     *f = o->cur->mmaped_source ? o->cur->u.f : NULL;
   if (key)
     *key = o->cur->key;
}

EOLIAN static void
_efl_canvas_image_efl_file_mmap_get(Eo *eo_obj, void *_pd EINA_UNUSED EINA_UNUSED,
                                    const Eina_File **f, const char **key)
{
   _evas_image_mmap_get(eo_obj, f, key);
}

Eina_Bool
_evas_image_file_set(Eo *eo_obj, const char *file, const char *key)
{
   Evas_Object_Protected_Data *obj = efl_data_scope_get(eo_obj, EFL_CANVAS_OBJECT_CLASS);
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);
   Evas_Image_Load_Opts lo;
   const char *file2;

   if ((o->cur->u.file) && (file) && (!strcmp(o->cur->u.file, file)))
     {
        if ((!o->cur->key) && (!key))
          return EINA_FALSE;
        if ((o->cur->key) && (key) && (!strcmp(o->cur->key, key)))
          return EINA_FALSE;
     }

   evas_object_async_block(obj);
   _evas_image_init_set(NULL, file, key, eo_obj, obj, o, &lo);
   if (o->file_obj) efl_del(o->file_obj);
   o->file_obj = NULL;
   file2 = o->cur->u.file;
   if (file2)
     {
        o->file_obj = efl_vpath_manager_fetch(EFL_VPATH_MANAGER_CLASS, file2);
        efl_vpath_file_do(o->file_obj);
        // XXX:FIXME: allow this to be async
        efl_vpath_file_wait(o->file_obj);
        file2 = efl_vpath_file_result_get(o->file_obj);
     }
   o->engine_data = ENFN->image_load(ENDT, file2, o->cur->key, &o->load_error, &lo);
   o->buffer_data_set = EINA_FALSE;
   _evas_image_done_set(eo_obj, obj, o);
   o->file_size.w = o->cur->image.w;
   o->file_size.h = o->cur->image.h;
   if ((o->file_obj) && (!efl_vpath_file_keep_get(o->file_obj)))
     {
        efl_del(o->file_obj);
        o->file_obj = NULL;
     }
   return EINA_TRUE;
}

EOLIAN static Eina_Bool
_efl_canvas_image_efl_file_file_set(Eo *eo_obj, void *_pd EINA_UNUSED EINA_UNUSED,
                                    const char *file, const char *key)
{
   return _evas_image_file_set(eo_obj, file, key);
}

void
_evas_image_file_get(const Eo *eo_obj, const char **file, const char **key)
{
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);

   if (file)
     {
        if (o->cur->mmaped_source)
          *file = eina_file_filename_get(o->cur->u.f);
        else
           *file = o->cur->u.file;
     }
   if (key) *key = o->cur->key;
}

EOLIAN static void
_efl_canvas_image_efl_file_file_get(Eo *eo_obj, void *_pd EINA_UNUSED EINA_UNUSED,
                                    const char **file, const char **key)
{
   _evas_image_file_get(eo_obj, file, key);
}

Efl_Image_Load_Error
_evas_image_load_error_get(const Eo *eo_obj)
{
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);

   return o->load_error;
}

EOLIAN static Efl_Image_Load_Error
_efl_canvas_image_efl_image_load_load_error_get(Eo *eo_obj, void *_pd EINA_UNUSED EINA_UNUSED)
{
   return _evas_image_load_error_get(eo_obj);
}

static void
_image_preload_internal(Eo *eo_obj, Evas_Image_Data *o, Eina_Bool cancel)
{
   if (!o->engine_data)
     {
        o->preloading = EINA_TRUE;
        evas_object_inform_call_image_preloaded(eo_obj);
        return;
     }
   // FIXME: if already busy preloading, then dont request again until
   // preload done
   Evas_Object_Protected_Data *obj = efl_data_scope_get(eo_obj, EFL_CANVAS_OBJECT_CLASS);
   if (cancel)
     {
        if (o->preloading)
          {
             o->preloading = EINA_FALSE;
             ENFN->image_data_preload_cancel(ENDT, o->engine_data, eo_obj);
          }
     }
   else
     {
        if (!o->preloading)
          {
             o->preloading = EINA_TRUE;
             ENFN->image_data_preload_request(ENDT, o->engine_data, eo_obj);
          }
     }
}

void
_evas_image_load_async_start(Eo *eo_obj)
{
   Evas_Object_Protected_Data *obj = efl_data_scope_get(eo_obj, EFL_CANVAS_OBJECT_CLASS);
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);

   evas_object_async_block(obj);
   _image_preload_internal(eo_obj, o, EINA_FALSE);
}

EOLIAN static void
_efl_canvas_image_efl_image_load_load_async_start(Eo *eo_obj, void *_pd EINA_UNUSED EINA_UNUSED)
{
   _evas_image_load_async_start(eo_obj);
}

void
_evas_image_load_async_cancel(Eo *eo_obj)
{
   Evas_Object_Protected_Data *obj = efl_data_scope_get(eo_obj, EFL_CANVAS_OBJECT_CLASS);
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);

   evas_object_async_block(obj);
   _image_preload_internal(eo_obj, o, EINA_TRUE);
}

EOLIAN static void
_efl_canvas_image_efl_image_load_load_async_cancel(Eo *eo_obj, void *_pd EINA_UNUSED EINA_UNUSED)
{
   _evas_image_load_async_cancel(eo_obj);
}

void
_evas_image_load_dpi_set(Eo *eo_obj, double dpi)
{
   Evas_Object_Protected_Data *obj = efl_data_scope_get(eo_obj, EFL_CANVAS_OBJECT_CLASS);
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);

   if (EINA_DBL_EQ(dpi, o->load_opts->dpi)) return;
   evas_object_async_block(obj);
   EINA_COW_LOAD_OPTS_WRITE_BEGIN(o, low)
     low->dpi = dpi;
   EINA_COW_LOAD_OPTS_WRITE_END(o, low);

   if (o->cur->u.file)
     {
        _evas_image_unload(eo_obj, obj, 0);
        evas_object_inform_call_image_unloaded(eo_obj);
        _evas_image_load(eo_obj, obj, o);
        o->changed = EINA_TRUE;
        evas_object_change(eo_obj, obj);
     }
}

EOLIAN static void
_efl_canvas_image_efl_image_load_load_dpi_set(Eo *eo_obj, void *_pd EINA_UNUSED EINA_UNUSED, double dpi)
{
   _evas_image_load_dpi_set(eo_obj, dpi);
}

double
_evas_image_load_dpi_get(const Eo *eo_obj)
{
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);

   return o->load_opts->dpi;
}

EOLIAN static double
_efl_canvas_image_efl_image_load_load_dpi_get(Eo *eo_obj, void *_pd EINA_UNUSED EINA_UNUSED)
{
   return _evas_image_load_dpi_get(eo_obj);
}

void
_evas_image_load_size_set(Eo *eo_obj, int w, int h)
{
   Evas_Object_Protected_Data *obj = efl_data_scope_get(eo_obj, EFL_CANVAS_OBJECT_CLASS);
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);

   if ((o->load_opts->w == w) && (o->load_opts->h == h)) return;
   evas_object_async_block(obj);
   EINA_COW_LOAD_OPTS_WRITE_BEGIN(o, low)
   {
      low->w = w;
      low->h = h;
   }
   EINA_COW_LOAD_OPTS_WRITE_END(o, low);

   if (o->cur->u.file)
     {
        _evas_image_unload(eo_obj, obj, 0);
        evas_object_inform_call_image_unloaded(eo_obj);
        _evas_image_load(eo_obj, obj, o);
        o->changed = EINA_TRUE;
        evas_object_change(eo_obj, obj);
     }
   o->proxyerror = 0;
}

EOLIAN static void
_efl_canvas_image_efl_image_load_load_size_set(Eo *eo_obj, void *_pd EINA_UNUSED EINA_UNUSED, int w, int h)
{
   _evas_image_load_size_set(eo_obj, w, h);
}

void
_evas_image_load_size_get(const Eo *eo_obj, int *w, int *h)
{
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);

   if (w) *w = o->load_opts->w;
   if (h) *h = o->load_opts->h;
}

EOLIAN static void
_efl_canvas_image_efl_image_load_load_size_get(Eo *eo_obj, void *_pd EINA_UNUSED EINA_UNUSED, int *w, int *h)
{
   _evas_image_load_size_get(eo_obj, w, h);
}

void
_evas_image_load_scale_down_set(Eo *eo_obj, int scale_down)
{
   Evas_Object_Protected_Data *obj = efl_data_scope_get(eo_obj, EFL_CANVAS_OBJECT_CLASS);
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);

   if (o->load_opts->scale_down_by == scale_down) return;
   evas_object_async_block(obj);
   EINA_COW_LOAD_OPTS_WRITE_BEGIN(o, low)
     low->scale_down_by = scale_down;
   EINA_COW_LOAD_OPTS_WRITE_END(o, low);

   if (o->cur->u.file)
     {
        _evas_image_unload(eo_obj, obj, 0);
        evas_object_inform_call_image_unloaded(eo_obj);
        _evas_image_load(eo_obj, obj, o);
        o->changed = EINA_TRUE;
        evas_object_change(eo_obj, obj);
     }
}

EOLIAN static void
_efl_canvas_image_efl_image_load_load_scale_down_set(Eo *eo_obj, void *_pd EINA_UNUSED EINA_UNUSED, int scale_down)
{
   _evas_image_load_scale_down_set(eo_obj, scale_down);
}

int
_evas_image_load_scale_down_get(const Eo *eo_obj)
{
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);

   return o->load_opts->scale_down_by;
}

EOLIAN static int
_efl_canvas_image_efl_image_load_load_scale_down_get(Eo *eo_obj, void *_pd EINA_UNUSED EINA_UNUSED)
{
   return _evas_image_load_scale_down_get(eo_obj);
}

void
_evas_image_load_head_skip_set(const Eo *eo_obj, Eina_Bool skip)
{
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);
   o->skip_head = skip;
}

EOLIAN static void
_efl_canvas_image_efl_image_load_load_skip_header_set(Eo *eo_obj, void *_pd EINA_UNUSED, Eina_Bool skip)
{
   _evas_image_load_head_skip_set(eo_obj, skip);
}

Eina_Bool
_evas_image_load_head_skip_get(const Eo *eo_obj)
{
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);
   return o->skip_head;
}

EOLIAN static Eina_Bool
_efl_canvas_image_efl_image_load_load_skip_header_get(Eo *eo_obj, void *_pd EINA_UNUSED)
{
   return _evas_image_load_head_skip_get(eo_obj);
}

void
_evas_image_load_region_set(Eo *eo_obj, int x, int y, int w, int h)
{
   Evas_Object_Protected_Data *obj = efl_data_scope_get(eo_obj, EFL_CANVAS_OBJECT_CLASS);
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);

   if ((o->load_opts->region.x == x) && (o->load_opts->region.y == y) &&
       (o->load_opts->region.w == w) && (o->load_opts->region.h == h)) return;
   evas_object_async_block(obj);
   EINA_COW_LOAD_OPTS_WRITE_BEGIN(o, low)
   {
      low->region.x = x;
      low->region.y = y;
      low->region.w = w;
      low->region.h = h;
   }
   EINA_COW_LOAD_OPTS_WRITE_END(o, low);

   if (o->cur->u.file)
     {
        _evas_image_unload(eo_obj, obj, 0);
        evas_object_inform_call_image_unloaded(eo_obj);
        _evas_image_load(eo_obj, obj, o);
        o->changed = EINA_TRUE;
        evas_object_change(eo_obj, obj);
     }
}

EOLIAN static void
_efl_canvas_image_efl_image_load_load_region_set(Eo *eo_obj, void *_pd EINA_UNUSED EINA_UNUSED, int x, int y, int w, int h)
{
   _evas_image_load_region_set(eo_obj, x, y, w, h);
}

void
_evas_image_load_region_get(const Eo *eo_obj, int *x, int *y, int *w, int *h)
{
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);

   if (x) *x = o->load_opts->region.x;
   if (y) *y = o->load_opts->region.y;
   if (w) *w = o->load_opts->region.w;
   if (h) *h = o->load_opts->region.h;
}

EOLIAN static void
_efl_canvas_image_efl_image_load_load_region_get(Eo *eo_obj, void *_pd EINA_UNUSED EINA_UNUSED, int *x, int *y, int *w, int *h)
{
   _evas_image_load_region_get(eo_obj, x, y, w, h);
}

void
_evas_image_load_orientation_set(Eo *eo_obj, Eina_Bool enable)
{
   Evas_Object_Protected_Data *obj = efl_data_scope_get(eo_obj, EFL_CANVAS_OBJECT_CLASS);
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);

   if (o->load_opts->orientation == !!enable) return;
   evas_object_async_block(obj);

   EINA_COW_LOAD_OPTS_WRITE_BEGIN(o, low)
         low->orientation = !!enable;
   EINA_COW_LOAD_OPTS_WRITE_END(o, low);
}

EOLIAN static void
_efl_canvas_image_efl_image_load_load_orientation_set(Eo *eo_obj, void *_pd EINA_UNUSED EINA_UNUSED, Eina_Bool enable)
{
   _evas_image_load_orientation_set(eo_obj, enable);
}

Eina_Bool
_evas_image_load_orientation_get(const Eo *eo_obj)
{
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);

   return o->load_opts->orientation;
}

EOLIAN static Eina_Bool
_efl_canvas_image_efl_image_load_load_orientation_get(Eo *eo_obj, void *_pd EINA_UNUSED EINA_UNUSED)
{
   return _evas_image_load_orientation_get(eo_obj);
}

Eina_Bool
_evas_image_load_region_support_get(const Eo *eo_obj)
{
   Evas_Object_Protected_Data *obj = efl_data_scope_get(eo_obj, EFL_CANVAS_OBJECT_CLASS);
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);

   return ENFN->image_can_region_get(ENDT, o->engine_data);
}

EOLIAN static Eina_Bool
_efl_canvas_image_efl_image_load_load_region_support_get(Eo *eo_obj, void *_pd EINA_UNUSED EINA_UNUSED)
{
   return _evas_image_load_region_support_get(eo_obj);
}

/* animated feature */
Eina_Bool
_evas_image_animated_get(const Eo *eo_obj)
{
   Evas_Object_Protected_Data *obj = efl_data_scope_get(eo_obj, EFL_CANVAS_OBJECT_CLASS);
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);

   if (!ENFN->image_animated_get)
     return EINA_FALSE;

   return ENFN->image_animated_get(ENDT, o->engine_data);
}

EOLIAN static Eina_Bool
_efl_canvas_image_efl_image_animated_animated_get(Eo *eo_obj, void *_pd EINA_UNUSED EINA_UNUSED)
{
   return _evas_image_animated_get(eo_obj);
}

int
_evas_image_animated_frame_count_get(const Eo *eo_obj)
{
   Evas_Object_Protected_Data *obj = efl_data_scope_get(eo_obj, EFL_CANVAS_OBJECT_CLASS);
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);

   if (!ENFN->image_animated_frame_count_get ||
       !evas_object_image_animated_get(eo_obj))
     return -1;

   obj = efl_data_scope_get(eo_obj, EFL_CANVAS_OBJECT_CLASS);
   return ENFN->image_animated_frame_count_get(ENDT, o->engine_data);
}

EOLIAN static int
_efl_canvas_image_efl_image_animated_animated_frame_count_get(Eo *eo_obj, void *_pd EINA_UNUSED EINA_UNUSED)
{
   return _evas_image_animated_frame_count_get(eo_obj);
}

Efl_Image_Animated_Loop_Hint
_evas_image_animated_loop_type_get(const Eo *eo_obj)
{
   Evas_Object_Protected_Data *obj = efl_data_scope_get(eo_obj, EFL_CANVAS_OBJECT_CLASS);
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);

   if (!ENFN->image_animated_loop_type_get ||
       !evas_object_image_animated_get(eo_obj))
     return EFL_IMAGE_ANIMATED_LOOP_HINT_NONE;

   return (Efl_Image_Animated_Loop_Hint) ENFN->image_animated_loop_type_get(ENDT, o->engine_data);
}

EOLIAN static Efl_Image_Animated_Loop_Hint
_efl_canvas_image_efl_image_animated_animated_loop_type_get(Eo *eo_obj, void *_pd EINA_UNUSED EINA_UNUSED)
{
   return _evas_image_animated_loop_type_get(eo_obj);
}

int
_evas_image_animated_loop_count_get(const Eo *eo_obj)
{
   Evas_Object_Protected_Data *obj = efl_data_scope_get(eo_obj, EFL_CANVAS_OBJECT_CLASS);
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);

   if (!ENFN->image_animated_loop_count_get ||
       !evas_object_image_animated_get(eo_obj))
     return -1;

   return ENFN->image_animated_loop_count_get(ENDT, o->engine_data);
}

EOLIAN static int
_efl_canvas_image_efl_image_animated_animated_loop_count_get(Eo *eo_obj, void *_pd EINA_UNUSED EINA_UNUSED)
{
   return _evas_image_animated_loop_count_get(eo_obj);
}

double
_evas_image_animated_frame_duration_get(const Eo *eo_obj, int start_frame, int frame_num)
{
   Evas_Object_Protected_Data *obj = efl_data_scope_get(eo_obj, EFL_CANVAS_OBJECT_CLASS);
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);
   int frame_count = 0;

   if (!ENFN->image_animated_frame_count_get ||
       !ENFN->image_animated_frame_duration_get)
     return -1.0;

   frame_count = ENFN->image_animated_frame_count_get(ENDT, o->engine_data);
   if ((start_frame + frame_num) > frame_count)
     return -1.0;

   return ENFN->image_animated_frame_duration_get(ENDT, o->engine_data, start_frame, frame_num);
}

EOLIAN static double
_efl_canvas_image_efl_image_animated_animated_frame_duration_get(Eo *eo_obj, void *_pd EINA_UNUSED EINA_UNUSED, int start_frame, int frame_num)
{
   return _evas_image_animated_frame_duration_get(eo_obj, start_frame, frame_num);
}

Eina_Bool
_evas_image_animated_frame_set(Eo *eo_obj, int frame_index)
{
   Evas_Object_Protected_Data *obj = efl_data_scope_get(eo_obj, EFL_CANVAS_OBJECT_CLASS);
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);
   int frame_count = 0;

   if (!o->cur->u.file) return EINA_FALSE;
   if (o->cur->frame == frame_index) return EINA_TRUE;

   if (!evas_object_image_animated_get(eo_obj)) return EINA_FALSE;
   evas_object_async_block(obj);
   frame_count = evas_object_image_animated_frame_count_get(eo_obj);

   /* limit the size of frame to FRAME_MAX */
   if ((frame_count > FRAME_MAX) || (frame_count < 0) || (frame_index > frame_count))
     return EINA_FALSE;

   if (!ENFN->image_animated_frame_set) return EINA_FALSE;
   ENFN->image_animated_frame_set(ENDT, o->engine_data, frame_index);
   //   if (!ENFN->image_animated_frame_set(ENDT, o->engine_data, frame_index)) return;

   EINA_COW_WRITE_BEGIN(evas_object_image_state_cow, o->prev, Evas_Object_Image_State, prev_write)
     prev_write->frame = o->cur->frame;
   EINA_COW_WRITE_END(evas_object_image_state_cow, o->prev, prev_write);

   EINA_COW_IMAGE_STATE_WRITE_BEGIN(o, state_write)
         state_write->frame = frame_index;
   EINA_COW_IMAGE_STATE_WRITE_END(o, state_write);

   o->changed = EINA_TRUE;
   evas_object_change(eo_obj, obj);

   return EINA_TRUE;
}

EOLIAN static Eina_Bool
_efl_canvas_image_efl_image_animated_animated_frame_set(Eo *eo_obj, void *_pd EINA_UNUSED EINA_UNUSED, int frame_index)
{
   return _evas_image_animated_frame_set(eo_obj, frame_index);
}

int
_evas_image_animated_frame_get(const Eo *eo_obj)
{
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);

   if (!o->cur->u.file) return EINA_FALSE;
   if (!evas_object_image_animated_get(eo_obj)) return EINA_FALSE;
   return o->cur->frame;
}

EOLIAN static int
_efl_canvas_image_efl_image_animated_animated_frame_get(Eo *eo_obj, void *_pd EINA_UNUSED EINA_UNUSED)
{
   return _evas_image_animated_frame_get(eo_obj);
}

EOLIAN static void
_efl_canvas_image_efl_gfx_buffer_buffer_size_get(Eo *eo_obj, void *_pd EINA_UNUSED EINA_UNUSED, int *w, int *h)
{
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);

   if (w) *w = o->cur->image.w;
   if (h) *h = o->cur->image.h;
}

static Eina_Bool
_image_pixels_set(Evas_Object_Protected_Data *obj,
                  Evas_Image_Data *o, const Eina_Slice *slice,
                  int w, int h, int stride, Efl_Gfx_Colorspace cspace, int plane,
                  Eina_Bool copy)
{
   Eina_Bool resized = EINA_FALSE, ret = EINA_FALSE;
   int int_stride = 0;

   // FIXME: buffer border support is not implemented

   if (ENFN->image_data_maps_get)
     {
        if (ENFN->image_data_maps_get(ENDT, o->engine_data, NULL) > 0)
          {
             ERR("can not set pixels when there are open memory maps");
             return EINA_FALSE;
          }
     }

   if (o->pixels_checked_out)
     {
        // is there anything to do?
        ERR("Calling efl_gfx_buffer_%s_set after evas_object_image_data_get is "
            "not valid.", copy ? "copy" : "managed");
        return EINA_FALSE;
     }

   if (o->file_obj)
     {
        efl_del(o->file_obj);
        o->file_obj = NULL;
     }

   if (o->engine_data)
     {
        Evas_Colorspace ics;
        int iw = 0, ih = 0;
        Eina_Bool alpha;

        ENFN->image_size_get(ENDT, o->engine_data, &iw, &ih);
        ics = ENFN->image_colorspace_get(ENDT, o->engine_data);
        alpha = ENFN->image_alpha_get(ENDT, o->engine_data);
        if ((w != iw) || (h != ih) || (ics != cspace) || (alpha != o->cur->has_alpha))
          {
             ENFN->image_free(ENDT, o->engine_data);
             o->engine_data = NULL;
          }
     }

   if (!slice || !slice->mem)
     {
        // note: we release all planes at once
        if (o->engine_data)
          ENFN->image_free(ENDT, o->engine_data);
        o->engine_data = ENFN->image_new_from_copied_data(ENDT, w, h, NULL, o->cur->has_alpha, cspace);
     }
   else
     {
        o->buffer_data_set = EINA_TRUE;
        o->engine_data = ENFN->image_data_slice_add(ENDT, o->engine_data,
                                                    slice, copy, w, h, stride,
                                                    cspace, plane, o->cur->has_alpha);
     }

   if (!o->engine_data)
     {
        ERR("Failed to create internal image");
        goto end;
     }

   if ((o->cur->image.w != w) || (o->cur->image.h != h))
     resized = EINA_TRUE;

   if (ENFN->image_scale_hint_set)
     ENFN->image_scale_hint_set(ENDT, o->engine_data, o->scale_hint);

   if (ENFN->image_content_hint_set)
     ENFN->image_content_hint_set(ENDT, o->engine_data, o->content_hint);

   if (ENFN->image_stride_get)
     ENFN->image_stride_get(ENDT, o->engine_data, &int_stride);

   if (resized || o->cur->u.file || o->cur->key ||
       (o->cur->image.stride != int_stride) || (cspace != o->cur->cspace))
     {
        EINA_COW_IMAGE_STATE_WRITE_BEGIN(o, cur)
        {
           cur->u.f = NULL;
           cur->key = NULL;
           cur->cspace = cspace;
           cur->image.w = w;
           cur->image.h = h;
           cur->image.stride = int_stride;
        }
        EINA_COW_IMAGE_STATE_WRITE_END(o, cur)
     }

   ret = EINA_TRUE;

end:
   o->written = EINA_TRUE;
   if (resized)
     evas_object_inform_call_image_resize(obj->object);

   efl_gfx_buffer_update_add(obj->object, 0, 0, w, h);
   return ret;
}

EOLIAN static Eina_Bool
_efl_canvas_image_efl_gfx_buffer_buffer_managed_set(Eo *eo_obj, void *_pd EINA_UNUSED,
                                                    const Eina_Slice *slice,
                                                    int w, int h, int stride,
                                                    Efl_Gfx_Colorspace cspace,
                                                    int plane)
{
   Evas_Object_Protected_Data *obj = efl_data_scope_get(eo_obj, EFL_CANVAS_OBJECT_CLASS);
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);

   return _image_pixels_set(obj, o, slice, w, h, stride, cspace, plane, EINA_FALSE);
}

EOLIAN static Eina_Bool
_efl_canvas_image_efl_gfx_buffer_buffer_copy_set(Eo *eo_obj, void *_pd EINA_UNUSED,
                                                 const Eina_Slice *slice, int w, int h, int stride,
                                                 Efl_Gfx_Colorspace cspace, int plane)
{
   Evas_Object_Protected_Data *obj = efl_data_scope_get(eo_obj, EFL_CANVAS_OBJECT_CLASS);
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);

   return _image_pixels_set(obj, o, slice, w, h, stride, cspace, plane, EINA_TRUE);
}

EOLIAN static Eina_Bool
_efl_canvas_image_efl_gfx_buffer_buffer_managed_get(Eo *eo_obj, void *_pd EINA_UNUSED EINA_UNUSED,
                                                    Eina_Slice *slice, int plane)
{
   Evas_Object_Protected_Data *obj = efl_data_scope_get(eo_obj, EFL_CANVAS_OBJECT_CLASS);
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);
   Evas_Colorspace cspace = EVAS_COLORSPACE_ARGB8888;

   EINA_SAFETY_ON_NULL_RETURN_VAL(slice, EINA_FALSE);

   slice->len = 0;
   slice->mem = NULL;

   if (!o->buffer_data_set || !o->engine_data || !ENFN->image_data_direct_get)
     return EINA_FALSE;

   return ENFN->image_data_direct_get(ENDT, o->engine_data, plane, slice, &cspace, EINA_FALSE);
}

EOLIAN static Eina_Bool
_efl_canvas_image_efl_gfx_buffer_buffer_map(Eo *eo_obj, void *_pd EINA_UNUSED,
                                            Eina_Rw_Slice *slice,
                                            Efl_Gfx_Buffer_Access_Mode mode,
                                            int x, int y, int w, int h,
                                            Efl_Gfx_Colorspace cspace,
                                            int plane, int *stride)
{
   Evas_Object_Protected_Data *obj = efl_data_scope_get(eo_obj, EFL_CANVAS_OBJECT_CLASS);
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);
   int s = 0, width = 0, height = 0;
   Eina_Bool ret = EINA_FALSE;

   EINA_SAFETY_ON_NULL_RETURN_VAL(slice, EINA_FALSE);

   slice->len = 0;
   slice->mem = NULL;

   if (!ENFN->image_data_map)
     goto end; // not implemented

   if (o->engine_data)
     ENFN->image_size_get(ENDT, o->engine_data, &width, &height);

   if (!o->engine_data || !width || !height)
     {
        // TODO: Create a map_surface and draw there. Maybe. This could
        // depend on the flags (eg. add a "force render" flag).
        WRN("This image image has no data available");
        goto end;
     }

   if (!w) w = width;
   if (!h) h = height;

   if ((x < 0) || (y < 0) || ((x + w) > width) || ((y + h) > height))
     {
        ERR("Invalid map dimensions: %dx%d +%d,%d. Image is %dx%d.",
            w, h, x, y, width, height);
        goto end;
     }

   if (ENFN->image_data_map(ENDT, &o->engine_data, slice, &s, x, y, w, h, cspace, mode, plane))
     {
        DBG("map(%p, %d,%d %dx%d plane:%d) -> " EINA_SLICE_FMT,
            eo_obj, x, y, w, h, plane, EINA_SLICE_PRINT(*slice));
        ret = EINA_TRUE;
     }
   else DBG("map(%p, %d,%d %dx%d plane:%d) -> (null)", eo_obj, x, y, w, h, plane);

end:
   if (stride) *stride = s;
   return ret;
}

EOLIAN static Eina_Bool
_efl_canvas_image_efl_gfx_buffer_buffer_unmap(Eo *eo_obj, void *_pd EINA_UNUSED,
                                              const Eina_Rw_Slice *slice)
{
   Evas_Object_Protected_Data *obj = efl_data_scope_get(eo_obj, EFL_CANVAS_OBJECT_CLASS);
   Evas_Image_Data *o = efl_data_scope_get(eo_obj, EFL_CANVAS_IMAGE_INTERNAL_CLASS);

   if (!slice || !ENFN->image_data_unmap || !o->engine_data)
     return EINA_FALSE;

   if (!ENFN->image_data_unmap(ENDT, o->engine_data, slice))
     return EINA_FALSE;

   return EINA_TRUE;
}

EOLIAN static void
_efl_canvas_image_efl_object_dbg_info_get(Eo *obj, void *pd EINA_UNUSED, Efl_Dbg_Info *root)
{
   efl_dbg_info_get(efl_super(obj, MY_CLASS), root);

   if ((efl_image_load_error_get(obj) != EFL_IMAGE_LOAD_ERROR_NONE) &&
       (root))
     {
        Efl_Dbg_Info *group = EFL_DBG_INFO_LIST_APPEND(root, MY_CLASS_NAME);
        Evas_Load_Error error = EVAS_LOAD_ERROR_GENERIC;

        error = (Evas_Load_Error) _evas_image_load_error_get(obj);
        EFL_DBG_INFO_APPEND(group, "Load Error", EINA_VALUE_TYPE_STRING,
                            evas_load_error_str(error));
     }
}

#define EFL_CANVAS_IMAGE_EXTRA_OPS \
   EFL_OBJECT_OP_FUNC(efl_dbg_info_get, _efl_canvas_image_efl_object_dbg_info_get)

#include "efl_canvas_image.eo.c"
