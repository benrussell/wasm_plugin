#ifndef WASM_PLUGIN_EXT_VFS_H
#define WASM_PLUGIN_EXT_VFS_H

#include <cstring>
#include <iostream>
#include <cstdio>

#include <dirent.h>


#include "host_api.h"





void list_dir( const char* target ){

    printf("wasm/ list_dir(%s)\n", target);


     DIR* dir = opendir( target );
        if (dir == nullptr) {
            printf("wasm/ vfs 404:[%s]\n", target);
            perror("opendir");
            return;
        }

        struct dirent* entry;
        while ((entry = readdir(dir)) != nullptr) {

            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            printf("wasm/  vfs:/%s/%s\n", target, entry->d_name);
        }

        closedir(dir);

}




void test_vfs(){

    // List all files in the current folder using filesystem APIs
    printf("wasm/ test_vfs()\n");

    list_dir("/");

    // list_dir("/X-Plane");
    // list_dir("/X-Plane/Aircraft");
    // list_dir("/X-Plane/Resources/plugins");
    
    // list_dir("/Aircraft");
    // list_dir("/Aircraft/plugins");

}





#endif
