-- EFL LuaJIT bindings: efl_ui_grid_static.eo (class Efl.Ui.Grid.Static)
-- For use with Elua; automatically generated, do not modify

local cutil = require("cutil")
local util  = require("util")
local ffi   = require("ffi")
local eo    = require("eo")

local M, __lib = ...

local __class
local __body

local init = function()
    __class = __lib.efl_ui_grid_static_class_get()
    eo.class_register("Efl_Ui_Grid_Static", {"Efl_Ui_Grid"}, nil, __body, __class)
end

cutil.init_module(init, function() end)

ffi.cdef [[
    const Eo_Class *efl_ui_grid_static_class_get(void);
]]

local __M = util.get_namespace(M, { "ui", "grid" })
__body = {
    __eo_ctor = function(self, __func)
        if __func then __func() end
    end
}

__M.Static = function(parent, ...)
    return eo.__ctor_common(__class, parent, eo.class_get("Efl_Ui_Grid_Static").__eo_ctor,
                            1, ...)
end

return M
