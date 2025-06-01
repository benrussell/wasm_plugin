

#include "../wasm_plugin_nvg/nanovg.h"


#include <cstdint>

extern "C" {

    #define NVGP_IMPORT(ret_type, name, ...) \
        __attribute__((import_module("waxi_nvg@1"))) \
        __attribute__((import_name(#name))) \
        ret_type nvg_proxy_##name(__VA_ARGS__);

    #if 0
        int (*renderCreate)(void* uptr);
        int (*renderCreateTexture)(void* uptr, int type, int w, int h, int imageFlags, const unsigned char* data);
        int (*renderDeleteTexture)(void* uptr, int image);
        int (*renderUpdateTexture)(void* uptr, int image, int x, int y, int w, int h, const unsigned char* data);
        int (*renderGetTextureSize)(void* uptr, int image, int* w, int* h);
        void (*renderViewport)(void* uptr, float width, float height, float devicePixelRatio);
        void (*renderCancel)(void* uptr);
        void (*renderFlush)(void* uptr);
        void (*renderFill)(void* uptr, NVGpaint* paint, NVGcompositeOperationState compositeOperation, NVGscissor* scissor, float fringe, const float* bounds, const NVGpath* paths, int npaths);
        void (*renderStroke)(void* uptr, NVGpaint* paint, NVGcompositeOperationState compositeOperation, NVGscissor* scissor, float fringe, float strokeWidth, const NVGpath* paths, int npaths);
        void (*renderTriangles)(void* uptr, NVGpaint* paint, NVGcompositeOperationState compositeOperation, NVGscissor* scissor, const NVGvertex* verts, int nverts, float fringe);
        void (*renderDelete)(void* uptr);
    #endif

    NVGP_IMPORT(int, xpRenderCreate, uint64_t uptr)
    NVGP_IMPORT(int, xpRenderCreateTexture, uint64_t uptr, int type, int w, int h, int imageFlags, const unsigned char* data)
    NVGP_IMPORT(int, xpRenderDeleteTexture, uint64_t uptr, int image)
    NVGP_IMPORT(int, xpRenderUpdateTexture, uint64_t uptr, int image, int x, int y, int w, int h, const unsigned char* data);
    NVGP_IMPORT(int, xpRenderGetTextureSize, uint64_t uptr, int image, int* w, int* h);
    NVGP_IMPORT(void, xpRenderViewport, uint64_t uptr, float width, float height, float devicePixelRatio);
    NVGP_IMPORT(void, xpRenderCancel, uint64_t uptr);
    NVGP_IMPORT(void, xpRenderFlush, uint64_t uptr);
    NVGP_IMPORT(void, xpRenderFill, uint64_t uptr, NVGpaint* paint, NVGcompositeOperationState compositeOperation, NVGscissor* scissor, float fringe, const float* bounds, const NVGpath* paths, int npaths);
    NVGP_IMPORT(void, xpRenderStroke, uint64_t uptr, NVGpaint* paint, NVGcompositeOperationState compositeOperation, NVGscissor* scissor, float fringe, float strokeWidth, const NVGpath* paths, int npaths);
    NVGP_IMPORT(void, xpRenderTriangles, uint64_t uptr, NVGpaint* paint, NVGcompositeOperationState compositeOperation, NVGscissor* scissor, const NVGvertex* verts, int nverts, float fringe);
    NVGP_IMPORT(void, xpRenderDelete, uint64_t uptr);


}

#undef NVGP_IMPORT