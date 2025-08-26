# Toy Tutorial

This contains sample code to support the tutorial on using MLIR for
building a compiler for a simple Toy language.

See [docs/Tutorials/Toy](../../docs/Tutorials/Toy) at the root of
the project for more informations.

# Commands to build/run etc
- cmake --build . --target toyc-waqar -j 20
- Configure: cmake -G Ninja ../llvm \
   -DLLVM_ENABLE_PROJECTS=mlir \
   -DLLVM_BUILD_EXAMPLES=ON \
   -DLLVM_TARGETS_TO_BUILD="Native;NVPTX;AMDGPU" \
   -DCMAKE_BUILD_TYPE=Release \
   -DLLVM_ENABLE_ASSERTIONS=ON \
-DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DLLVM_CCACHE_BUILD=ON
"
- B
