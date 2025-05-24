## Welcome

Here you will find Example WASM plugins for the [wasm_host_xpl](http://github.com/benrussell/wasm_host_xpl/) plugin.


The examples here show how to create a WASM plugin that wasm_host_xpl can load inside X-Plane.


At the moment the API is only experimental PoC stubs.

Important long term limitations to be aware of as a WASM plugin author:
- There is no OpenGL.
- Disk IO is sandboxed in a VFS.
- There is no direct access to the X-Plane SDK.


## Compiling to WASM bytecode

You will need to install clang and the clang WASI extensions to build these examples as WASM bytecode.


Please review wasm_plugin_basic/build_cmake.sh for more info.



__Todo/ Detailed instructions for clang and clang WASI extension install.__

