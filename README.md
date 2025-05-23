Example plugins for the wasm_xpl plugin host.

http://github.com/benrussell/wasm_xpl/


The source code here will show you how to create a WASM plugin.

The API is similar to a full fledged C-API X-Plane plugin but differs in subtle ways.


- There is no OpenGL.

- Disk IO is sandboxed in a VFS.

- There is no direct access to the X-Plane SDK.


# Getting Started

You will need to install clang and the clang WASI extensions to build these examples as WASM bytecode.



