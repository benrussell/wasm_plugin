


#include <cstdint>

extern "C" {

    #define GFX_IMPORT(ret_type, name, ...) \
        __attribute__((import_module("waxi_gfx@1"))) \
        __attribute__((import_name(#name))) \
        ret_type gfx_##name(__VA_ARGS__);

    GFX_IMPORT(void, draw_dbg_tri, int x, int y)
    
}

#undef GFX_IMPORT