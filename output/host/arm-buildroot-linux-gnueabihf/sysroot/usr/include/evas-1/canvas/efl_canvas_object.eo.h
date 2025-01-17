#ifndef _EFL_CANVAS_OBJECT_EO_H_
#define _EFL_CANVAS_OBJECT_EO_H_

#ifndef _EFL_CANVAS_OBJECT_EO_CLASS_TYPE
#define _EFL_CANVAS_OBJECT_EO_CLASS_TYPE

typedef Eo Efl_Canvas_Object;

#endif

#ifndef _EFL_CANVAS_OBJECT_EO_TYPES
#define _EFL_CANVAS_OBJECT_EO_TYPES


#endif
/** Efl canvas object abstract class
 *
 * @ingroup Efl_Canvas_Object
 */
#define EFL_CANVAS_OBJECT_CLASS efl_canvas_object_class_get()

EWAPI const Efl_Class *efl_canvas_object_class_get(void);

/**
 * @brief Low-level pointer behaviour by device. See
 * @ref efl_canvas_object_pointer_mode_get and
 * @ref efl_canvas_object_pointer_mode_set for more explanation.
 *
 * @param[in] dev The pointer device to set/get the mode. Use @c null for the
 * default pointer.
 * @param[in] pointer_mode The pointer mode
 *
 * @since 1.19
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI Eina_Bool efl_canvas_object_pointer_mode_by_device_set(Eo *obj, Efl_Input_Device * dev, Efl_Input_Object_Pointer_Mode pointer_mode);

/**
 * @brief Low-level pointer behaviour by device. See
 * @ref efl_canvas_object_pointer_mode_get and
 * @ref efl_canvas_object_pointer_mode_set for more explanation.
 *
 * @param[in] dev The pointer device to set/get the mode. Use @c null for the
 * default pointer.
 *
 * @return The pointer mode
 *
 * @since 1.19
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI Efl_Input_Object_Pointer_Mode efl_canvas_object_pointer_mode_by_device_get(const Eo *obj, Efl_Input_Device * dev);

/**
 * @brief Low-level pointer behaviour.
 *
 * This function has a direct effect on event callbacks related to pointers
 * (mouse, ...).
 *
 * If the value is @ref EFL_INPUT_OBJECT_POINTER_MODE_AUTO_GRAB (default), then
 * when mouse is pressed down over this object, events will be restricted to it
 * as source, mouse moves, for example, will be emitted even when the pointer
 * goes outside this objects geometry.
 *
 * If the value is @ref EFL_INPUT_OBJECT_POINTER_MODE_NO_GRAB, then events will
 * be emitted just when inside this object area.
 *
 * The default value is @ref EFL_INPUT_OBJECT_POINTER_MODE_AUTO_GRAB. See also:
 * @ref efl_canvas_object_pointer_mode_by_device_get and
 * @ref efl_canvas_object_pointer_mode_by_device_set Note: This function will
 * only set/get the mode for the default pointer.
 *
 * @param[in] pointer_mode Input pointer mode
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI Eina_Bool efl_canvas_object_pointer_mode_set(Eo *obj, Efl_Input_Object_Pointer_Mode pointer_mode);

/**
 * @brief Low-level pointer behaviour.
 *
 * This function has a direct effect on event callbacks related to pointers
 * (mouse, ...).
 *
 * If the value is @ref EFL_INPUT_OBJECT_POINTER_MODE_AUTO_GRAB (default), then
 * when mouse is pressed down over this object, events will be restricted to it
 * as source, mouse moves, for example, will be emitted even when the pointer
 * goes outside this objects geometry.
 *
 * If the value is @ref EFL_INPUT_OBJECT_POINTER_MODE_NO_GRAB, then events will
 * be emitted just when inside this object area.
 *
 * The default value is @ref EFL_INPUT_OBJECT_POINTER_MODE_AUTO_GRAB. See also:
 * @ref efl_canvas_object_pointer_mode_by_device_get and
 * @ref efl_canvas_object_pointer_mode_by_device_set Note: This function will
 * only set/get the mode for the default pointer.
 *
 * @return Input pointer mode
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI Efl_Input_Object_Pointer_Mode efl_canvas_object_pointer_mode_get(const Eo *obj);

/**
 * @brief Read-only value indicating whether the main pointer is in the object.
 *
 * This shall be true between pointer,in and pointer,out events (coming in
 * matching numbers). Note that group objects may receive multiple pointer,in
 * in a row. See algo @ref efl_canvas_object_pointer_device_in_get
 *
 * @return If @c true the main pointer has entered this object.
 *
 * @since 1.19
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI Eina_Bool efl_canvas_object_pointer_in_get(const Eo *obj);

/**
 * @brief Read-only value indicating whether a pointer is in the object.
 *
 * This shall be true between pointer,in and pointer,out events (coming in
 * matching numbers). Note that group objects may receive multiple pointer,in
 * in a row.
 *
 * @param[in] pointer The pointer. Use @c null for the defaul pointer
 *
 * @return If @c true the pointer has entered this object.
 *
 * @since 1.19
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI Eina_Bool efl_canvas_object_pointer_device_in_get(const Eo *obj, Efl_Input_Device * pointer);

/**
 * @brief Render mode to be used for compositing the Evas object.
 *
 * Only two modes are supported: - @ref EFL_GFX_RENDER_OP_BLEND means the
 * object will be merged on top of objects below it using simple alpha
 * compositing. - @ref EFL_GFX_RENDER_OP_COPY means this object's pixels will
 * replace everything that is below, making this object opaque.
 *
 * Please do not assume that @ref EFL_GFX_RENDER_OP_COPY mode can be used to
 * "poke" holes in a window (to see through it), as only the compositor can
 * ensure that. Copy mode should only be used with otherwise opaque widgets, or
 * inside non-window surfaces (eg. a transparent background inside a buffer
 * canvas).
 *
 * @param[in] render_op Blend or copy.
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI void efl_canvas_object_render_op_set(Eo *obj, Efl_Gfx_Render_Op render_op);

/**
 * @brief Render mode to be used for compositing the Evas object.
 *
 * Only two modes are supported: - @ref EFL_GFX_RENDER_OP_BLEND means the
 * object will be merged on top of objects below it using simple alpha
 * compositing. - @ref EFL_GFX_RENDER_OP_COPY means this object's pixels will
 * replace everything that is below, making this object opaque.
 *
 * Please do not assume that @ref EFL_GFX_RENDER_OP_COPY mode can be used to
 * "poke" holes in a window (to see through it), as only the compositor can
 * ensure that. Copy mode should only be used with otherwise opaque widgets, or
 * inside non-window surfaces (eg. a transparent background inside a buffer
 * canvas).
 *
 * @return Blend or copy.
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI Efl_Gfx_Render_Op efl_canvas_object_render_op_get(const Eo *obj);

/**
 * @brief Set whether an Evas object is to freeze (discard) events.
 *
 * If @c freeze is @c true, it will make events on @c obj to be discarded.
 * Unlike @ref efl_canvas_object_pass_events_set, events will not be passed to
 * next lower object. This API can be used for blocking events while @c obj is
 * on transiting.
 *
 * If @c freeze is @c false, events will be processed on that object as normal.
 *
 * @warning If you block only key/mouse up events with this API, we won't
 * guarantee the state of the object, that only had key/mouse down events, will
 * be.
 *
 * @param[in] freeze Pass when @c obj is to freeze events ($true) or not
 * ($false).
 *
 * @since 1.1
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI void efl_canvas_object_freeze_events_set(Eo *obj, Eina_Bool freeze);

/**
 * @brief Determine whether an object is set to freeze (discard) events.
 *
 * @return Pass when @c obj is to freeze events ($true) or not ($false).
 *
 * @since 1.1
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI Eina_Bool efl_canvas_object_freeze_events_get(const Eo *obj);

/**
 * @brief Clip one object to another.
 *
 * This function will clip the object @c obj to the area occupied by the object
 * @c clip. This means the object @c obj will only be visible within the area
 * occupied by the clipping object ($clip).
 *
 * The color of the object being clipped will be multiplied by the color of the
 * clipping one, so the resulting color for the former will be "RESULT = (OBJ *
 * CLIP) / (255 * 255)", per color element (red, green, blue and alpha).
 *
 * Clipping is recursive, so clipping objects may be clipped by others, and
 * their color will in term be multiplied. You may not set up circular clipping
 * lists (i.e. object 1 clips object 2, which clips object 1): the behavior of
 * Evas is undefined in this case.
 *
 * Objects which do not clip others are visible in the canvas as normal; those
 * that clip one or more objects become invisible themselves, only affecting
 * what they clip. If an object ceases to have other objects being clipped by
 * it, it will become visible again.
 *
 * The visibility of an object affects the objects that are clipped by it, so
 * if the object clipping others is not shown (as in @ref evas_object_show),
 * the objects clipped by it will not be shown  either.
 *
 * If @c obj was being clipped by another object when this function is  called,
 * it gets implicitly removed from the old clipper's domain and is made now to
 * be clipped by its new clipper.
 *
 * If @c clip is @c null, this call will disable clipping for the object i.e.
 * its visibility and color get detached from the previous clipper. If it
 * wasn't, this has no effect.
 *
 * @note Only rectangle and image (masks) objects can be used as clippers.
 * Anything else will result in undefined behaviour.
 *
 * @param[in] clip The object to clip @c obj by.
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI void efl_canvas_object_clip_set(Eo *obj, Efl_Canvas_Object *clip) EINA_ARG_NONNULL(2);

/**
 * @brief Get the object clipping @c obj (if any).
 *
 * This function returns the object clipping @c obj. If @c obj is not being
 * clipped at all, @c null is returned. The object @c obj must be a valid
 * Evas_Object.
 *
 * @return The object to clip @c obj by.
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI Efl_Canvas_Object *efl_canvas_object_clip_get(const Eo *obj);

/**
 * @brief Set whether an Evas object is to repeat events.
 *
 * If @c repeat is @c true, it will make events on @c obj to also be repeated
 * for the next lower object in the objects' stack (see see @ref
 * evas_object_below_get).
 *
 * If @c repeat is @c false, events occurring on @c obj will be processed only
 * on it.
 *
 * @param[in] repeat Whether @c obj is to repeat events ($true) or not
 * ($false).
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI void efl_canvas_object_repeat_events_set(Eo *obj, Eina_Bool repeat);

/**
 * @brief Determine whether an object is set to repeat events.
 *
 * @return Whether @c obj is to repeat events ($true) or not ($false).
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI Eina_Bool efl_canvas_object_repeat_events_get(const Eo *obj);

/**
 * @brief Sets the scaling factor for an Evas object. Does not affect all
 * objects.
 *
 * This will multiply the object's dimension by the given factor, thus altering
 * its geometry (width and height). Useful when you want scalable UI elements,
 * possibly at run time.
 *
 * @note Only text and textblock objects have scaling change handlers. Other
 * objects won't change visually on this call.
 *
 * @param[in] scale The scaling factor. 1.0 means no scaling, default size.
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI void efl_canvas_object_scale_set(Eo *obj, double scale);

/**
 * @brief Retrieves the scaling factor for the given Evas object.
 *
 * @return The scaling factor. 1.0 means no scaling, default size.
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI double efl_canvas_object_scale_get(const Eo *obj);

/**
 * @brief Indicates that this object is the keyboard event receiver on its
 * canvas.
 *
 * Changing focus only affects where (key) input events go. There can be only
 * one object focused at any time. If @c focus is @c true, @c obj will be set
 * as the currently focused object and it will receive all keyboard events that
 * are not exclusive key grabs on other objects. See also
 * @ref efl_canvas_object_seat_focus_check,
 * @ref efl_canvas_object_seat_focus_add,
 * @ref efl_canvas_object_seat_focus_del.
 *
 * @param[in] focus @c true when set as focused or @c false otherwise.
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI void efl_canvas_object_key_focus_set(Eo *obj, Eina_Bool focus);

/**
 * @brief Indicates that this object is the keyboard event receiver on its
 * canvas.
 *
 * Changing focus only affects where (key) input events go. There can be only
 * one object focused at any time. If @c focus is @c true, @c obj will be set
 * as the currently focused object and it will receive all keyboard events that
 * are not exclusive key grabs on other objects. See also
 * @ref efl_canvas_object_seat_focus_check,
 * @ref efl_canvas_object_seat_focus_add,
 * @ref efl_canvas_object_seat_focus_del.
 *
 * @return @c true when set as focused or @c false otherwise.
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI Eina_Bool efl_canvas_object_key_focus_get(const Eo *obj);

/**
 * @brief Check if this object is focused.
 *
 * @return @c true if focused by at least one seat or @c false otherwise.
 *
 * @since 1.19
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI Eina_Bool efl_canvas_object_seat_focus_get(const Eo *obj);

/**
 * @brief Check if this object is focused by a given seat
 *
 * @param[in] seat The seat to check if the object is focused. Use @c null for
 * the default seat.
 *
 * @return @c true if focused or @c false otherwise.
 *
 * @since 1.19
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI Eina_Bool efl_canvas_object_seat_focus_check(Eo *obj, Efl_Input_Device *seat);

/**
 * @brief Add a seat to the focus list.
 *
 * Evas supports that an Efl.Canvas.Object may be focused by multiple seats at
 * the same time. This function adds a new seat to the focus list, in other
 * words, after the seat is added to the list this object will now be also
 * focused by this new seat.
 *
 * This function generates an @ref EFL_CANVAS_OBJECT_EVENT_FOCUS_DEVICE_IN
 * event.
 *
 * @note The old focus APIs ( @ref evas_object_focus_get, @ref
 * evas_object_focus_set, @ref efl_canvas_object_key_grab) will still work,
 * however they will only act on the default seat.
 *
 * @param[in] seat The seat that should be added to the focus list. Use @c null
 * for the default seat.
 *
 * @return @c true if the focus has been set or @c false otherwise.
 *
 * @since 1.19
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI Eina_Bool efl_canvas_object_seat_focus_add(Eo *obj, Efl_Input_Device *seat);

/**
 * @brief Remove a seat from the focus list.
 *
 * Removing an seat from the focus list is an unfocus operation, thus it will
 * generate an @ref EFL_CANVAS_OBJECT_EVENT_FOCUS_DEVICE_OUT event.
 *
 * @param[in] seat The seat that should be removed from the focus list. Use
 * @c null for the default seat.
 *
 * @return @c true if the seat was removed from the focus list or @c false
 * otherwise.
 *
 * @since 1.19
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI Eina_Bool efl_canvas_object_seat_focus_del(Eo *obj, Efl_Input_Device *seat);

/**
 * @brief If @c true the object belongs to the window border decorations.
 *
 * This will be @c false by default, and should be @c false for all objects
 * created by the application, unless swallowed in some very specific parts of
 * the window.
 *
 * It is very unlikely that an application needs to call this manually, as the
 * window will handle this feature automatically.
 *
 * @param[in] is_frame @c true if the object is a frame, @c false otherwise
 *
 * @since 1.2
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI void efl_canvas_object_is_frame_object_set(Eo *obj, Eina_Bool is_frame);

/**
 * @brief If @c true the object belongs to the window border decorations.
 *
 * This will be @c false by default, and should be @c false for all objects
 * created by the application, unless swallowed in some very specific parts of
 * the window.
 *
 * It is very unlikely that an application needs to call this manually, as the
 * window will handle this feature automatically.
 *
 * @return @c true if the object is a frame, @c false otherwise
 *
 * @since 1.2
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI Eina_Bool efl_canvas_object_is_frame_object_get(const Eo *obj);

/**
 * @brief Set whether to use precise (usually expensive) point collision
 * detection for a given Evas object.
 *
 * Use this function to make Evas treat objects' transparent areas as not
 * belonging to it with regard to mouse pointer events. By default, all of the
 * object's boundary rectangle will be taken in account for them.
 *
 * @warning By using precise point collision detection you'll be making Evas
 * more resource intensive.
 *
 * @param[in] precise Whether to use precise point collision detection or not.
 * The default value is false.
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI void efl_canvas_object_precise_is_inside_set(Eo *obj, Eina_Bool precise);

/**
 * @brief Determine whether an object is set to use precise point collision
 * detection.
 *
 * @return Whether to use precise point collision detection or not. The default
 * value is false.
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI Eina_Bool efl_canvas_object_precise_is_inside_get(const Eo *obj);

/**
 * @brief Set whether events on a smart object's member should get propagated
 * up to its parent.
 *
 * This function has no effect if @c obj is not a member of a smart object.
 *
 * If @c prop is @c true, events occurring on this object will be propagated on
 * to the smart object of which @c obj is a member. If @c prop is @c false,
 * events occurring on this object will not be propagated on to the smart
 * object of which @c obj is a member. The default value is @c true.
 *
 * See also @ref efl_canvas_object_repeat_events_set,
 * @ref efl_canvas_object_pass_events_set,
 * @ref efl_canvas_object_freeze_events_set.
 *
 * @param[in] propagate Whether to propagate events ($true) or not ($false).
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI void efl_canvas_object_propagate_events_set(Eo *obj, Eina_Bool propagate);

/**
 * @brief Retrieve whether an Evas object is set to propagate events.
 *
 * See also @ref efl_canvas_object_repeat_events_get,
 * @ref efl_canvas_object_pass_events_get,
 * @ref efl_canvas_object_freeze_events_get.
 *
 * @return Whether to propagate events ($true) or not ($false).
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI Eina_Bool efl_canvas_object_propagate_events_get(const Eo *obj);

/**
 * @brief Set whether an Evas object is to pass (ignore) events.
 *
 * If @c pass is @c true, it will make events on @c obj to be ignored. They
 * will be triggered on the next lower object (that is not set to pass events),
 * instead (see @ref evas_object_below_get).
 *
 * If @c pass is @c false, events will be processed on that object as normal.
 *
 * See also @ref efl_canvas_object_repeat_events_set,
 * @ref efl_canvas_object_propagate_events_set,
 * @ref efl_canvas_object_freeze_events_set.
 *
 * @param[in] pass Whether @c obj is to pass events ($true) or not ($false).
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI void efl_canvas_object_pass_events_set(Eo *obj, Eina_Bool pass);

/**
 * @brief Determine whether an object is set to pass (ignore) events.
 *
 * See also @ref efl_canvas_object_repeat_events_get,
 * @ref efl_canvas_object_propagate_events_get,
 * @ref efl_canvas_object_freeze_events_get.
 *
 * @return Whether @c obj is to pass events ($true) or not ($false).
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI Eina_Bool efl_canvas_object_pass_events_get(const Eo *obj);

/**
 * @brief Sets whether or not the given Evas object is to be drawn
 * anti-aliased.
 *
 * @param[in] anti_alias @c true if the object is to be anti_aliased, @c false
 * otherwise.
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI void efl_canvas_object_anti_alias_set(Eo *obj, Eina_Bool anti_alias);

/**
 * @brief Retrieves whether or not the given Evas object is to be drawn
 * anti_aliased.
 *
 * @return @c true if the object is to be anti_aliased, @c false otherwise.
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI Eina_Bool efl_canvas_object_anti_alias_get(const Eo *obj);

/**
 * @brief Return a list of objects currently clipped by @c obj.
 *
 * This returns the internal list handle that contains all objects clipped by
 * the object @c obj. If none are clipped by it, the call returns @c null. This
 * list is only valid until the clip list is changed and should be fetched
 * again with another call to this function if any objects being clipped by
 * this object are unclipped, clipped by a new object, deleted or get the
 * clipper deleted. These operations will invalidate the list returned, so it
 * should not be used anymore after that point. Any use of the list after this
 * may have undefined results, possibly leading to crashes.
 *
 * See also @ref efl_canvas_object_clip_get.
 *
 * @return An iterator over the list of objects clipped by @c obj.
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI Eina_Iterator *efl_canvas_object_clipees_get(const Eo *obj) EINA_WARN_UNUSED_RESULT;

#ifdef EFL_CANVAS_OBJECT_PROTECTED
/**
 * @brief Gets the parent smart object of a given Evas object, if it has one.
 *
 * This can be different from @ref efl_parent_get because this one is used
 * internally for rendering and the normal parent is what the user expects to
 * be the parent.
 *
 * @return The parent smart object of @c obj or @c null.
 *
 * @since 1.18
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI Efl_Canvas_Object *efl_canvas_object_render_parent_get(const Eo *obj);
#endif

/**
 * @brief This handles text paragraph direction of the given object. Even if
 * the given object is not textblock or text, its smart child objects can
 * inherit the paragraph direction from the given object. The default paragraph
 * direction is @c inherit.
 *
 * @param[in] dir Paragraph direction for the given object.
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI void efl_canvas_object_paragraph_direction_set(Eo *obj, Efl_Text_Bidirectional_Type dir);

/**
 * @brief This handles text paragraph direction of the given object. Even if
 * the given object is not textblock or text, its smart child objects can
 * inherit the paragraph direction from the given object. The default paragraph
 * direction is @c inherit.
 *
 * @return Paragraph direction for the given object.
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI Efl_Text_Bidirectional_Type efl_canvas_object_paragraph_direction_get(const Eo *obj);

/**
 * @brief Test if any object is clipped by @c obj.
 *
 * @return @c true if any object is clipped by @c obj, @c false otherwise
 *
 * @since 1.8
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI Eina_Bool efl_canvas_object_clipees_has(const Eo *obj) EINA_WARN_UNUSED_RESULT;

/**
 * @brief Requests @c keyname key events be directed to @c obj.
 *
 * Key grabs allow one or more objects to receive key events for specific key
 * strokes even if other objects have focus. Whenever a key is grabbed, only
 * the objects grabbing it will get the events for the given keys.
 *
 * @c keyname is a platform dependent symbolic name for the key pressed (see
 * @ref Evas_Keys for more information).
 *
 * @c modifiers and @c not_modifiers are bit masks of all the modifiers that
 * must and mustn't, respectively, be pressed along with @c keyname key in
 * order to trigger this new key grab. Modifiers can be things such as Shift
 * and Ctrl as well as user defined types via @ref evas_key_modifier_add.
 * Retrieve them with @ref evas_key_modifier_mask_get or use 0 for empty masks.
 *
 * @c exclusive will make the given object the only one permitted to grab the
 * given key. If given @c true, subsequent calls on this function with
 * different @c obj arguments will fail, unless the key is ungrabbed again.
 *
 * @warning Providing impossible modifier sets creates undefined behavior.
 *
 * See also @ref efl_canvas_object_key_ungrab,
 * @ref efl_canvas_object_key_focus_get, @ref efl_canvas_object_key_focus_set,
 * @ref evas_focus_get, @ref evas_key_modifier_add.
 *
 * @param[in] keyname The key to request events for.
 * @param[in] modifiers A combinaison of modifier keys that must be present to
 * trigger the event.
 * @param[in] not_modifiers A combinaison of modifier keys that must not be
 * present to trigger the event.
 * @param[in] exclusive Request that the @c obj is the only object receiving
 * the @c keyname events.
 *
 * @return @c true if the call succeeded, @c false otherwise.
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI Eina_Bool efl_canvas_object_key_grab(Eo *obj, const char *keyname, Efl_Input_Modifier modifiers, Efl_Input_Modifier not_modifiers, Eina_Bool exclusive) EINA_WARN_UNUSED_RESULT EINA_ARG_NONNULL(2);

/**
 * @brief Removes the grab on @c keyname key events by @c obj.
 *
 * Removes a key grab on @c obj if @c keyname, @c modifiers, and
 * @c not_modifiers match.
 *
 * See also @ref efl_canvas_object_key_grab,
 * @ref efl_canvas_object_key_focus_get, @ref efl_canvas_object_key_focus_set,
 * and the legacy API evas_focus_get.
 *
 * @param[in] keyname The key the grab is set for.
 * @param[in] modifiers A mask of modifiers that must be present to trigger the
 * event.
 * @param[in] not_modifiers A mask of modifiers that must not not be present to
 * trigger the event.
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI void efl_canvas_object_key_ungrab(Eo *obj, const char *keyname, Efl_Input_Modifier modifiers, Efl_Input_Modifier not_modifiers) EINA_ARG_NONNULL(2);

/**
 * @brief Disable all rendering on the canvas.
 *
 * This flag will be used to indicate to Evas that this object should never be
 * rendered on the canvas under any circurmstances. In particular, this is
 * useful to avoid drawing clipper objects (or masks) even when they don't clip
 * any object. This can also be used to replace the old source_visible flag
 * with proxy objects.
 *
 * This is different to the visible property, as even visible objects marked as
 * "no-render" will never appear on screen. But those objects can still be used
 * as proxy sources or clippers. When hidden, all "no-render" objects will
 * completely disappear from the canvas, and hide their clippees or be
 * invisible when used as proxy sources.
 *
 * @param[in] enable Enable "no-render" mode.
 *
 * @since 1.15
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI void efl_canvas_object_no_render_set(Eo *obj, Eina_Bool enable);

/**
 * @brief Returns the state of the "no-render" flag, which means, when true,
 * that an object should never be rendered on the canvas.
 *
 * This flag can be used to avoid rendering visible clippers on the canvas,
 * even if they currently don't clip any object.
 *
 * @return Enable "no-render" mode.
 *
 * @since 1.15
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI Eina_Bool efl_canvas_object_no_render_get(const Eo *obj);

/**
 * @brief Returns whether the mouse pointer is logically inside the object.
 *
 * @param[in] dev The pointer device.
 *
 * @return @c true if the pointer is inside, @c false otherwise.
 *
 * @since 1.20
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI Eina_Bool efl_canvas_object_pointer_inside_by_device_get(const Eo *obj, Efl_Input_Device * dev);

/**
 * @brief Returns whether the default mouse pointer is logically inside the
 * object.
 *
 * When this function is called it will return a value of either @c false or
 * @c true, depending on if event_feed_mouse_in or event_feed_mouse_out have
 * been called to feed in a mouse enter event into the object.
 *
 * A return value of @c true indicates the mouse is logically inside the
 * object, and @c false implies it is logically outside the object.
 *
 * If @c e is not a valid object, the return value is undefined.
 *
 * @return @c true if the mouse pointer is inside the object, @c false
 * otherwise
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI Eina_Bool efl_canvas_object_pointer_inside_get(const Eo *obj) EINA_WARN_UNUSED_RESULT;

/**
 * @brief Returns whether the coords are logically inside the object.
 *
 * When this function is called it will return a value of either @c false or
 * @c true, depending on if the coords are inside the object's current
 * geometry.
 *
 * A return value of @c true indicates the position is logically inside the
 * object, and @c false implies it is logically outside the object.
 *
 * If @c e is not a valid object, the return value is undefined.
 *
 * @param[in] x The canvas-relative x coordinate.
 * @param[in] y The canvas-relative y coordinate.
 *
 * @return @c true if the coords are inside the object, @c false otherwise
 *
 * @ingroup Efl_Canvas_Object
 */
EOAPI Eina_Bool efl_canvas_object_pointer_coords_inside_get(Eo *obj, int x, int y) EINA_WARN_UNUSED_RESULT;

#endif
