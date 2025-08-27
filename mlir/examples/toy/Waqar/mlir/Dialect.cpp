//===- Dialect.cpp - Toy IR Dialect registration in MLIR ------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements the dialect for the Toy IR: custom type parsing and
// operation verification.
//
//===----------------------------------------------------------------------===//

#include "toy/Dialect.h"

#include "mlir/IR/Attributes.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/OpImplementation.h"
#include "mlir/IR/Operation.h"
#include "mlir/IR/OperationSupport.h"
#include "mlir/IR/Value.h"
#include "mlir/Interfaces/FunctionImplementation.h"
#include "mlir/Support/LLVM.h"
#include "llvm/ADT/ArrayRef.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/Support/Casting.h"
#include <algorithm>
#include <string>

using namespace mlir;
using namespace mlir::toy;

#include "toy/Dialect.cpp.inc"

//===----------------------------------------------------------------------===//
// ToyDialect
//===----------------------------------------------------------------------===//

/// Dialect initialization, the instance will be owned by the context. This is
/// the point of registration of types and operations for the dialect.
void ToyDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "toy/Ops.cpp.inc"
      >();
}

//===----------------------------------------------------------------------===//
// Toy Operations
//===----------------------------------------------------------------------===//
//===----------------------------------------------------------------------===//
// ConstantOp
//===----------------------------------------------------------------------===//


// void ConstantOp::print(mlir::OpAsmPrinter &printer) {
//   printer << " ";
//   printer.printOptionalAttrDict((*this)->getAttrs(), /*elidedAttrs=*/{"value"});
//   printer << getValue();
// }
// llvm::LogicalResult ConstantOp::verify() {
//   auto resultType = llvm::dyn_cast<mlir::RankedTensorType>(getResult().getType());
//   if(!resultType)
//     return success();
  
//     auto attrType = llvm::cast<mlir::RankedTensorType>(getValue().getType());
//     if(attrType.getRank() != resultType.getRank()){
//       return omitOpError("return type must match the one of the attached value "
//                          "attribute: ")
//            << attrType.getRank() << " != " << resultType.getRank();
//     }
    
//     for(int dim = 0, dimE = attType.getRank(); dim<dimE; ++dim){
//      if(attrType.getShape()[dim] != resultType.getShape()[dim]){
//        return emitOpError(
//                  "return type shape mismatches its attribute at dimension ")
//              << dim << ": " << attrType.getShape()[dim]
//              << " != " << resultType.getShape()[dim];
//      }
//     }
    
//     return mlir::success();
// }
