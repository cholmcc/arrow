// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#include "gandiva/function_registry_math_ops_trig.h"

#include "gandiva/function_registry_common.h"

namespace gandiva {

#define MATH_UNARY_OPS(name, ALIASES)                           \
  UNARY_SAFE_NULL_IF_NULL(name, ALIASES, int32, float64),       \
      UNARY_SAFE_NULL_IF_NULL(name, ALIASES, int64, float64),   \
      UNARY_SAFE_NULL_IF_NULL(name, ALIASES, uint32, float64),  \
      UNARY_SAFE_NULL_IF_NULL(name, ALIASES, uint64, float64),  \
      UNARY_SAFE_NULL_IF_NULL(name, ALIASES, float32, float64), \
      UNARY_SAFE_NULL_IF_NULL(name, ALIASES, float64, float64)

#define MATH_UNARY_OPS_FLOAT(name, ALIASES)                    \
  UNARY_SAFE_NULL_IF_NULL(name, ALIASES, int32, float32),      \
      UNARY_SAFE_NULL_IF_NULL(name, ALIASES, uint32, float32), \
      UNARY_SAFE_NULL_IF_NULL(name, ALIASES, float32, float32)

std::vector<NativeFunction> GetMathOpsTrigFunctionRegistry() {
  static std::vector<NativeFunction> math_fn_registry_ = {
      MATH_UNARY_OPS(sin, {}),         MATH_UNARY_OPS(cos, {}),
      MATH_UNARY_OPS(tan, {}),         MATH_UNARY_OPS(asin, {}),
      MATH_UNARY_OPS(acos, {}),        MATH_UNARY_OPS(atan, {}),

      MATH_UNARY_OPS_FLOAT(sinf, {}),  MATH_UNARY_OPS_FLOAT(cosf, {}),
      MATH_UNARY_OPS_FLOAT(tanf, {}),  MATH_UNARY_OPS_FLOAT(asinf, {}),
      MATH_UNARY_OPS_FLOAT(acosf, {}), MATH_UNARY_OPS_FLOAT(atanf, {})};
  return math_fn_registry_;
}

#undef MATH_UNARY_OPS

#undef MATH_UNARY_OPS_FLOAT
}  // namespace gandiva
