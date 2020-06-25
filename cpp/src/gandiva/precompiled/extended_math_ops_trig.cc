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

#include "gandiva/precompiled/decimal_ops.h"

extern "C" {

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./types.h"

// Expand the inner fn for types that support extended math.
#define ENUMERIC_TYPES_UNARY(INNER, OUT_TYPE) \
  INNER(int32, OUT_TYPE)                      \
  INNER(uint32, OUT_TYPE)                     \
  INNER(int64, OUT_TYPE)                      \
  INNER(uint64, OUT_TYPE)                     \
  INNER(float32, OUT_TYPE)                    \
  INNER(float64, OUT_TYPE)

#define ENUMERIC_TYPES_UNARY_FLOAT(INNER, OUT_TYPE) \
  INNER(int32, OUT_TYPE)                            \
  INNER(uint32, OUT_TYPE)                           \
  INNER(int64, OUT_TYPE)                            \
  INNER(uint64, OUT_TYPE)                           \
  INNER(float32, OUT_TYPE)

// Trigonometric functions
// Sine
#define SINF(IN_TYPE, OUT_TYPE)                                    \
  FORCE_INLINE                                                     \
  gdv_##OUT_TYPE sinf_##IN_TYPE(gdv_##IN_TYPE in) {                \
    return static_cast<gdv_float32>(sinf(static_cast<float>(in))); \
  }
#define SIN(IN_TYPE, OUT_TYPE)                                           \
  FORCE_INLINE                                                           \
  gdv_##OUT_TYPE sin_##IN_TYPE(gdv_##IN_TYPE in) {                       \
    return static_cast<gdv_float64>(sinl(static_cast<long double>(in))); \
  }

ENUMERIC_TYPES_UNARY_FLOAT(SINF, float32)
ENUMERIC_TYPES_UNARY(SIN, float64)

// Cosine
#define COSF(IN_TYPE, OUT_TYPE)                                    \
  FORCE_INLINE                                                     \
  gdv_##OUT_TYPE cosf_##IN_TYPE(gdv_##IN_TYPE in) {                \
    return static_cast<gdv_float32>(cosf(static_cast<float>(in))); \
  }
#define COS(IN_TYPE, OUT_TYPE)                                           \
  FORCE_INLINE                                                           \
  gdv_##OUT_TYPE cos_##IN_TYPE(gdv_##IN_TYPE in) {                       \
    return static_cast<gdv_float64>(cosl(static_cast<long double>(in))); \
  }

ENUMERIC_TYPES_UNARY_FLOAT(COSF, float32)
ENUMERIC_TYPES_UNARY(COS, float64)

// Tangent
#define TANF(IN_TYPE, OUT_TYPE)                                    \
  FORCE_INLINE                                                     \
  gdv_##OUT_TYPE tanf_##IN_TYPE(gdv_##IN_TYPE in) {                \
    return static_cast<gdv_float32>(tanf(static_cast<float>(in))); \
  }
#define TAN(IN_TYPE, OUT_TYPE)                                           \
  FORCE_INLINE                                                           \
  gdv_##OUT_TYPE tan_##IN_TYPE(gdv_##IN_TYPE in) {                       \
    return static_cast<gdv_float64>(tanl(static_cast<long double>(in))); \
  }

ENUMERIC_TYPES_UNARY_FLOAT(TANF, float32)
ENUMERIC_TYPES_UNARY(TAN, float64)

// Arc sine
#define ASINF(IN_TYPE, OUT_TYPE)                                    \
  FORCE_INLINE                                                      \
  gdv_##OUT_TYPE asinf_##IN_TYPE(gdv_##IN_TYPE in) {                \
    return static_cast<gdv_float32>(asinf(static_cast<float>(in))); \
  }
#define ASIN(IN_TYPE, OUT_TYPE)                                           \
  FORCE_INLINE                                                            \
  gdv_##OUT_TYPE asin_##IN_TYPE(gdv_##IN_TYPE in) {                       \
    return static_cast<gdv_float64>(asinl(static_cast<long double>(in))); \
  }

ENUMERIC_TYPES_UNARY_FLOAT(ASINF, float32)
ENUMERIC_TYPES_UNARY(ASIN, float64)

// Arc cosine
#define ACOSF(IN_TYPE, OUT_TYPE)                                    \
  FORCE_INLINE                                                      \
  gdv_##OUT_TYPE acosf_##IN_TYPE(gdv_##IN_TYPE in) {                \
    return static_cast<gdv_float32>(acosf(static_cast<float>(in))); \
  }
#define ACOS(IN_TYPE, OUT_TYPE)                                           \
  FORCE_INLINE                                                            \
  gdv_##OUT_TYPE acos_##IN_TYPE(gdv_##IN_TYPE in) {                       \
    return static_cast<gdv_float64>(acosl(static_cast<long double>(in))); \
  }

ENUMERIC_TYPES_UNARY_FLOAT(ACOSF, float32)
ENUMERIC_TYPES_UNARY(ACOS, float64)

// Arc tangent
#define ATANF(IN_TYPE, OUT_TYPE)                                    \
  FORCE_INLINE                                                      \
  gdv_##OUT_TYPE atanf_##IN_TYPE(gdv_##IN_TYPE in) {                \
    return static_cast<gdv_float32>(atanf(static_cast<float>(in))); \
  }
#define ATAN(IN_TYPE, OUT_TYPE)                                           \
  FORCE_INLINE                                                            \
  gdv_##OUT_TYPE atan_##IN_TYPE(gdv_##IN_TYPE in) {                       \
    return static_cast<gdv_float64>(atanl(static_cast<long double>(in))); \
  }

ENUMERIC_TYPES_UNARY_FLOAT(ATANF, float32)
ENUMERIC_TYPES_UNARY(ATAN, float64)
}  // extern "C"
