#ifndef _EFL_GFX_GRADIENT_LINEAR_EO_H_
#define _EFL_GFX_GRADIENT_LINEAR_EO_H_

#ifndef _EFL_GFX_GRADIENT_LINEAR_EO_CLASS_TYPE
#define _EFL_GFX_GRADIENT_LINEAR_EO_CLASS_TYPE

typedef Eo Efl_Gfx_Gradient_Linear;

#endif

#ifndef _EFL_GFX_GRADIENT_LINEAR_EO_TYPES
#define _EFL_GFX_GRADIENT_LINEAR_EO_TYPES


#endif
/** Efl graphics gradient linear interface
 *
 * @ingroup Efl_Gfx_Gradient_Linear
 */
#define EFL_GFX_GRADIENT_LINEAR_INTERFACE efl_gfx_gradient_linear_interface_get()

EWAPI const Efl_Class *efl_gfx_gradient_linear_interface_get(void);

/**
 * @brief Sets the start point of this linear gradient.
 *
 * @param[in] x X co-ordinate of start point
 * @param[in] y Y co-ordinate of start point
 *
 * @ingroup Efl_Gfx_Gradient_Linear
 */
EOAPI void efl_gfx_gradient_linear_start_set(Eo *obj, double x, double y);

/**
 * @brief Gets the start point of this linear gradient.
 *
 * @param[out] x X co-ordinate of start point
 * @param[out] y Y co-ordinate of start point
 *
 * @ingroup Efl_Gfx_Gradient_Linear
 */
EOAPI void efl_gfx_gradient_linear_start_get(const Eo *obj, double *x, double *y);

/**
 * @brief Sets the end point of this linear gradient.
 *
 * @param[in] x X co-ordinate of end point
 * @param[in] y Y co-ordinate of end point
 *
 * @ingroup Efl_Gfx_Gradient_Linear
 */
EOAPI void efl_gfx_gradient_linear_end_set(Eo *obj, double x, double y);

/**
 * @brief Gets the end point of this linear gradient.
 *
 * @param[out] x X co-ordinate of end point
 * @param[out] y Y co-ordinate of end point
 *
 * @ingroup Efl_Gfx_Gradient_Linear
 */
EOAPI void efl_gfx_gradient_linear_end_get(const Eo *obj, double *x, double *y);

#endif
