
// Bare bones test harness

#include <cstring>
#include <iostream>
#include <cstdio>


#include "wasm_plugin_nvg.h"


#include "host_api.h"


// optional extras to test parts of the WASM host api
#include "wasm_plugin_ext_cbfs.h"
#include "wasm_plugin_ext_cmd.h"
#include "wasm_plugin_ext_dref.h"
#include "wasm_plugin_ext_vfs.h"





int main(void){
    //printf("wasm_nvg/ main() is required by WASI _start()\n");
    return 0;
}



int plugin_start(char* outName, char* outSig, char* outDesc) {

    snprintf(outName, 256, "NanoVG WASM Plugin Example");
    snprintf(outSig,  256, "waxi/examples/wasm_plugin_nvg");
    snprintf(outDesc, 256, "NanoVG Drawing API Test");

    log_raw("wasm_nvg/ plugin_start()\n");
    
    return 1;
}


// We use this to proxy into the WASM flat memory block.
void plugin_flcb_proxy( int32_t fptr ){
    printf("wasm_nvg/ plugin_flcb_proxy() fptr: %i\n", fptr);
    ((void(*)())fptr)();
}


void plugin_stop(){
    printf("wasm_nvg/ plugin_stop()\n");
    
}


int plugin_enable(){
    printf("wasm_nvg/ plugin_enable()");

    
    test_nvg();


    return 1;
}


void plugin_disable(){
    printf("wasm_nvg/ plugin_disable()\n");
}


void plugin_message( int64_t inFromWho, int64_t inMessage, int32_t inParam ){
    
    printf("wasm_nvg/ plugin_message: from: %lld, msg: %lld, param: %i\n", inFromWho, inMessage, inParam);
    
}

