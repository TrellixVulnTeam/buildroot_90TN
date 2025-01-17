-- EFL LuaJIT bindings: efl_canvas_object_event_grabber.eo (class Efl.Canvas.Object.Event.Grabber)
-- For use with Elua; automatically generated, do not modify

local cutil = require("cutil")
local util  = require("util")
local ffi   = require("ffi")
local eo    = require("eo")

local M, __lib = ...

local __class
local __body

local init = function()
    __class = __lib.efl_canvas_object_event_grabber_class_get()
    eo.class_register("Efl_Canvas_Object_Event_Grabber", {"Efl_Canvas_Group"}, nil, __body, __class)
end

cutil.init_module(init, function() end)

ffi.cdef [[
    const Eo_Class *efl_canvas_object_event_grabber_class_get(void);
    void efl_canvas_object_event_grabber_freeze_when_visible_set(Eina_Bool set);
    Eina_Bool efl_canvas_object_event_grabber_freeze_when_visible_get(void);
]]

local __M = util.get_namespace(M, { "canvas", "object", "event" })
__body = {
    __eo_ctor = function(self, __func)
        if __func then __func() end
    end,

    freeze_when_visible_set = function(self, set)
        eo.__do_start(self, __class)
        __lib.efl_canvas_object_event_grabber_freeze_when_visible_set(set)
        eo.__do_end()
    end,

    freeze_when_visible_get = function(self)
        eo.__do_start(self, __class)
        local v = __lib.efl_canvas_object_event_grabber_freeze_when_visible_get()
        eo.__do_end()
        return ((v) ~= 0)
    end,

    __properties = {
        ["freeze_when_visible"] = { 0, 0, 1, 1, true, true }
    }
}

__M.Grabber = function(parent, ...)
    return eo.__ctor_common(__class, parent, eo.class_get("Efl_Canvas_Object_Event_Grabber").__eo_ctor,
                            1, ...)
end

return M
