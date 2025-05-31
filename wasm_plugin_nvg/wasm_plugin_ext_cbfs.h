#ifndef WASM_PLUGIN_EXT_CBFS_H
#define WASM_PLUGIN_EXT_CBFS_H

#include <cstring>
#include <iostream>
#include <cstdio>

#include "host_api.h"






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

    //printf("wasm/ draw_callback fired\n");
    return 1; //ret 1 to keep drawing.
}



void test_draw_cbs(){
    printf("wasm/ calling cb_reg_draw.. ***************\n");
    cb_reg_draw( (int32_t)&draw_callback, NULL );
}





#endif
