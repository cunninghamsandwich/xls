// Copyright 2021 The XLS Authors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Tests for various sizes of binary operations.
// Simple test of these ops and that wide data types work...
// and as a starting point for debugging they don't.

import xls.build_rules.tests.c

pub fn d() -> u32 {
  c::c() + u32:0
}

#![test]
fn d_test() {
  let _ = assert_eq(u32:3, d());
  ()
}