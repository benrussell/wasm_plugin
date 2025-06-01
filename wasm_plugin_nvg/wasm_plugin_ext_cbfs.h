#ifndef WASM_PLUGIN_EXT_CBFS_H
#define WASM_PLUGIN_EXT_CBFS_H

#include <cstring>
#include <iostream>
#include <cstdio>

#include "host_api.h"





#include "nanovg.h"
extern NVGcontext* g_ctx;
    




float test_cbf( 
                float inElapsedSinceLastCall, 
                float inElapsedTimeSinceLastFlightLoop, 
                int inCounter, 
                void *inRefcon
 ){
    printf("wasm/ test_cbf2 BBBB(),  since call: %f,  time since last fl: %f,  counter: %i,  refcon: %p\n", 
        inElapsedSinceLastCall,
        inElapsedTimeSinceLastFlightLoop,
        inCounter,
        inRefcon
    );
    // return 1.5f;

    return 0.f;
}



void test_cbfs(){
    
    printf("wasm_nvg/ calling cb_reg cbf: rc:%p\n", nullptr);
    cb_reg( (int32_t) &test_cbf, (int32_t)nullptr );

}





int draw_callback( int phase, int is_before, void* refcon ){

    static int xp=120;
    static int yp=100;

    static int y_dir=1;
    static int x_dir=-1;

    const int container_width=1000;
    const int container_height=1000;
    
    const int box_w=200;
    const int box_h=100;

    // Update position with step size 5
    xp += x_dir * 5;
    yp += y_dir * 5;

    // Reverse direction if the demo box hits the horizontal boundaries
    if (xp < 0) {
        xp = 0;
        x_dir = -x_dir;
    } else if (xp + box_w > container_width) {
        xp = container_width - box_w;
        x_dir = -x_dir;
    }

    // Reverse direction if the demo box hits the vertical boundaries
    if (yp < 0) {
        yp = 0;
        y_dir = -y_dir;
    } else if (yp + box_h > container_height) {
        yp = container_height - box_h;
        y_dir = -y_dir;
    }

    gfx_draw_dbg_tri( xp, yp );








    auto lam_drawRose = [](auto vg){
// Draw tick marks around a circle
		float centerX = 800 / 2;
		float centerY = 600 / 2;
		float radius = 200;
		float tickLength = 20;


		// Save the current transformation state
		nvgSave(vg);

		// Translate to the center of the circle
		nvgTranslate(vg, centerX, centerY);

		// Apply the rotation transformation
		//nvgRotate(vg, dr_heading->getFloat());
        nvgRotate(vg, 7.f);

		// Translate back to the original position
		nvgTranslate(vg, -centerX, -centerY);

		for (int i = 0; i < 12; ++i) {
			float angle = (i / 12.0f) * NVG_PI * 2;
			float x1 = centerX + cos(angle) * radius;
			float y1 = centerY + sin(angle) * radius;
			float x2 = centerX + cos(angle) * (radius - tickLength);
			float y2 = centerY + sin(angle) * (radius - tickLength);

			nvgBeginPath(vg);
			nvgMoveTo(vg, x1, y1);
			nvgLineTo(vg, x2, y2);
			nvgStrokeColor(vg, nvgRGBA(255, 192, 0, 255));
			nvgStrokeWidth(vg, 5.0f);
			nvgStroke(vg);
		}

		nvgRestore(vg);

	};

    
    nvgBeginFrame( g_ctx, 800, 600, 1.f );
        lam_drawRose(g_ctx);
    nvgEndFrame( g_ctx );













    //printf("wasm/ draw_callback fired\n");
    return 1; //ret 1 to keep drawing.
}



void test_draw_cbs(){
    printf("wasm/ calling cb_reg_draw.. ***************\n");
    cb_reg_draw( (int32_t)&draw_callback, NULL );
}





#endif
