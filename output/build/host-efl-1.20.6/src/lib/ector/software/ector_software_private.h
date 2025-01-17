#ifndef ECTOR_SOFTWARE_PRIVATE_H_
# define ECTOR_SOFTWARE_PRIVATE_H_

#include "Ector_Software.h"
#include "sw_ft_raster.h"
#include "sw_ft_stroker.h"
#include "../ector_private.h"

typedef struct _Ector_Software_Surface_Data Ector_Software_Surface_Data;

// Gradient related structure
typedef struct _Software_Gradient_Linear_Data
{
   float x1, y1, x2, y2;
   float dx, dy, l, off;
} Software_Gradient_Linear_Data;

typedef struct _Software_Gradient_Radial_Data
{
   float cx, cy, fx, fy, cradius, fradius;
   float dx, dy, dr, sqrfr, a, inv2a;
   Eina_Bool extended;
} Software_Gradient_Radial_Data;

typedef struct _Ector_Renderer_Software_Gradient_Data
{
   Ector_Software_Surface_Data *surface;
   Ector_Renderer_Gradient_Data *gd;
   union {
      Ector_Renderer_Gradient_Linear_Data *gld;
      Ector_Renderer_Gradient_Radial_Data *grd;
   };
   union {
      Software_Gradient_Linear_Data linear;
      Software_Gradient_Radial_Data radial;
   };
   Eina_Bool alpha;
   uint32_t* color_table;
} Ector_Renderer_Software_Gradient_Data;

typedef struct _Shape_Rle_Data
{
   Eina_Rectangle   bbox;
   unsigned short   alloc;
   unsigned short   size;
   SW_FT_Span      *spans;// array of Scanlines.
} Shape_Rle_Data;

typedef struct _Clip_Data
{
   Eina_Array           *clips; //Eina_Rectangle
   Shape_Rle_Data       *path;
   unsigned int          enabled : 1;
   unsigned int          has_rect_clip : 1;
   unsigned int          has_path_clip : 1;
} Clip_Data;


typedef enum _Span_Data_Type {
  None,
  Solid,
  LinearGradient,
  RadialGradient,
} Span_Data_Type;

typedef struct _Span_Data
{
   Ector_Software_Buffer_Base_Data *raster_buffer;
   SW_FT_SpanFunc   blend;
   SW_FT_SpanFunc   unclipped_blend;

   int              offx, offy;
   Clip_Data        clip;
   Eina_Matrix3     inv;
   Span_Data_Type   type;
   Eina_Bool        fast_matrix ;
   uint32_t         mul_col;
   Efl_Gfx_Render_Op        op;
   union {
      uint32_t color;
      Ector_Renderer_Software_Gradient_Data *gradient;
      Ector_Software_Buffer_Base_Data *buffer;
   };
} Span_Data;

typedef struct _Software_Rasterizer
{
   SW_FT_Raster     raster;
   SW_FT_Stroker    stroker;

   Span_Data        fill_data;
   Eina_Matrix3    *transform;
   Eina_Rectangle   system_clip;

} Software_Rasterizer;

struct _Ector_Software_Surface_Data
{
   Software_Rasterizer *rasterizer;
   int x;
   int y;
};


int  ector_software_gradient_init(void);
void ector_software_rasterizer_init(Software_Rasterizer *rasterizer);
void ector_software_rasterizer_done(Software_Rasterizer *rasterizer);

void ector_software_rasterizer_stroke_set(Software_Rasterizer *rasterizer, double width,
                                          Efl_Gfx_Cap cap_style, Efl_Gfx_Join join_style, Eina_Matrix3 *m);

void ector_software_rasterizer_transform_set(Software_Rasterizer *rasterizer, Eina_Matrix3 *t);
void ector_software_rasterizer_color_set(Software_Rasterizer *rasterizer, int r, int g, int b, int a);
void ector_software_rasterizer_linear_gradient_set(Software_Rasterizer *rasterizer, Ector_Renderer_Software_Gradient_Data *linear);
void ector_software_rasterizer_radial_gradient_set(Software_Rasterizer *rasterizer, Ector_Renderer_Software_Gradient_Data *radial);
void ector_software_rasterizer_clip_rect_set(Software_Rasterizer *rasterizer, Eina_Array *clips);
void ector_software_rasterizer_clip_shape_set(Software_Rasterizer *rasterizer, Shape_Rle_Data *clip);



Shape_Rle_Data * ector_software_rasterizer_generate_rle_data(Software_Rasterizer *rasterizer, SW_FT_Outline *outline);
Shape_Rle_Data * ector_software_rasterizer_generate_stroke_rle_data(Software_Rasterizer *rasterizer, SW_FT_Outline *outline, Eina_Bool closePath);

void ector_software_rasterizer_draw_rle_data(Software_Rasterizer *rasterizer, int x, int y, uint32_t mul_col, Efl_Gfx_Render_Op op, Shape_Rle_Data* rle);

void ector_software_rasterizer_destroy_rle_data(Shape_Rle_Data *rle);



// Gradient Api
void update_color_table(Ector_Renderer_Software_Gradient_Data *gdata);
void destroy_color_table(Ector_Renderer_Software_Gradient_Data *gdata);
void fetch_linear_gradient(uint32_t *buffer, Span_Data *data, int y, int x, int length);
void fetch_radial_gradient(uint32_t *buffer, Span_Data *data, int y, int x, int length);

#endif
