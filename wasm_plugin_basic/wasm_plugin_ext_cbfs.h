#ifndef WASM_PLUGIN_EXT_CBFS_H
#define WASM_PLUGIN_EXT_CBFS_H

#include <cstring>
#include <iostream>
#include <cstdio>

#include "host_api.h"




struct TestStructure{
    std::string snafu;
    std::string fubar;
};




char* fn_a_data;
char* fn_b_data;




float test_cbf1( 
                float inElapsedSinceLastCall, 
                float inElapsedTimeSinceLastFlightLoop, 
                int inCounter, 
                void *inRefcon
 ){

    printf("wasm/ fn_a rc: %p  global: %p\n", inRefcon, fn_a_data);

    //printf("fn_a refcon: [%s]\n", (char*)inRefcon);
    //printf("fn_a glob: [%s]\n", fn_a_data);

    // printf("wasm/ test_cbf1 AAAA()\n  since last call: %f\n  since last fl: %f\n  counter: %i\n  refcon: %p\n", 
    //     inElapsedSinceLastCall,
    //     inElapsedTimeSinceLastFlightLoop,
    //     inCounter,
    //     inRefcon
    // );
    // return 0.5f;

    return 0.f;
}


float test_cbf2( 
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

    TestStructure s; //FIXME: rename this struct def
    s.snafu = "situ normal";
    s.fubar = "fouled up";
    //printf("wasm/ stack ptr for some_str instance: %p\n", &s);

    TestStructure* ptr_s = new TestStructure();
    //printf("wasm/ heap ptr for some_str instance: %p\n", ptr_s);
    delete( ptr_s );
    

    fn_a_data = (char*)malloc( 1024 );
    fn_b_data = (char*)malloc( 1024'024 );

    snprintf(fn_a_data, 1024, "function_a_data_block");
    snprintf(fn_b_data, 1024, "function_B_data_block_big");
    
    
    printf("wasm/ calling cb_reg cbf1: rc:%p\n", fn_a_data);
    cb_reg( (int32_t) &test_cbf1, (int32_t)fn_a_data );

    printf("wasm/ calling cb_reg cbf2: rc:%p\n", fn_b_data);
    cb_reg( (int32_t) &test_cbf2, (int32_t)fn_b_data );

    
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
