#include "toy/Dialect.h"

using namespace mlir;
using namespace mlir::toy;

// This will be generated from your Dialect.td
#include "toy/Dialect.cpp.inc"

// Initialize the dialect
void ToyDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "toy/Ops.cpp.inc"
    >();
}

// This will pull in all the auto-generated operation definitions
#define GET_OP_CLASSES
#include "toy/Ops.cpp.inc"
