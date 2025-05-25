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

    printf("fn_a rc: %p  glob: %p\n", inRefcon, fn_a_data);

    printf("fn_a refcon: [%s]\n", (char*)inRefcon);
    printf("fn_a glob: [%s]\n", fn_a_data);

    // printf("wasm/ test_cbf1 AAAA()\n  since last call: %f\n  since last fl: %f\n  counter: %i\n  refcon: %p\n", 
    //     inElapsedSinceLastCall,
    //     inElapsedTimeSinceLastFlightLoop,
    //     inCounter,
    //     inRefcon
    // );
    return 0.5f;
}


float test_cbf2( 
                float inElapsedSinceLastCall, 
                float inElapsedTimeSinceLastFlightLoop, 
                int inCounter, 
                void *inRefcon
 ){
    printf("wasm/ test_cbf2 BBBB()\n  since last call: %f\n  since last fl: %f\n  counter: %i\n  refcon: %p\n", 
        inElapsedSinceLastCall,
        inElapsedTimeSinceLastFlightLoop,
        inCounter,
        inRefcon
    );
    return 1.5f;
}



void test_cbfs(){

    TestStructure s; //FIXME: rename this struct def
    s.snafu = "situ normal";
    s.fubar = "fouled up";
    printf("wasm/ stack ptr for some_str instance: %p\n", &s);

    TestStructure* ptr_s = new TestStructure();
    printf("wasm/ heap ptr for some_str instance: %p\n", ptr_s);
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

#endif
