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

#include <gandiva/precompiled/testing.h>
#include <gtest/gtest.h>
#include <math.h>

#include "gandiva/execution_context.h"
#include "gandiva/precompiled/types.h"

namespace gandiva {

TEST(TestExtendedMathOps, TestSine) {
  VerifyFuzzyEquals(sin_float32(M_PI_2), 1);
  VerifyFuzzyEquals(sin_float64(M_PI_2), 1);
  VerifyFuzzyEquals(sin_float32(M_PI_4), 0.7071);
  VerifyFuzzyEquals(sin_float64(M_PI_4), 0.7071);
}

TEST(TestExtendedMathOps, TestCosine) {
  VerifyFuzzyEquals(cos_float32(M_PI_2), 0);
  VerifyFuzzyEquals(cos_float64(M_PI_2), 0);
  VerifyFuzzyEquals(cos_float32(M_PI_4), 0.7071);
  VerifyFuzzyEquals(cos_float64(M_PI_4), 0.7071);
}

TEST(TestExtendedMathOps, TestTangent) {
  VerifyFuzzyEquals(tan_float32(M_PI / 3.), 1.73205);
  VerifyFuzzyEquals(tan_float64(M_PI / 3.), 1.73205);
  VerifyFuzzyEquals(tan_float32(M_PI_4), 1);
  VerifyFuzzyEquals(tan_float64(M_PI_4), 1);
}

TEST(TestExtendedMathOps, TestASine) {
  VerifyFuzzyEquals(asin_float32(1), M_PI_2);
  VerifyFuzzyEquals(asin_float64(1), M_PI_2);
  VerifyFuzzyEquals(asin_float32(0.7071), M_PI_4);
  VerifyFuzzyEquals(asin_float64(0.7071), M_PI_4);
}

TEST(TestExtendedMathOps, TestACosine) {
  VerifyFuzzyEquals(acos_float32(0), M_PI_2);
  VerifyFuzzyEquals(acos_float64(0), M_PI_2);
  VerifyFuzzyEquals(acos_float32(0.7071), M_PI_4);
  VerifyFuzzyEquals(acos_float64(0.7071), M_PI_4);
}

TEST(TestExtendedMathOps, TestATangent) {
  VerifyFuzzyEquals(atan_float32(1.73205), M_PI / 3.);
  VerifyFuzzyEquals(atan_float64(1.73205), M_PI / 3.);
  VerifyFuzzyEquals(atan_float32(1), M_PI_4);
  VerifyFuzzyEquals(atan_float64(1), M_PI_4);
}
}  // namespace gandiva
