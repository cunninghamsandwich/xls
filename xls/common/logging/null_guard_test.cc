// Copyright 2020 The XLS Authors
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

#include "xls/common/logging/null_guard.h"

#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace xls {
namespace logging_internal {
namespace {

TEST(NullGuardTest, NonPointersAreReturnedAsIs) {
  EXPECT_EQ(NullGuard<char>::Guard('a'), 'a');
}

TEST(NullGuardTest, NonNullStringsAreReturnedAsIs) {
  std::string hello = "hello";

  EXPECT_EQ(NullGuard<char*>::Guard(hello.data()), hello.data());
  EXPECT_EQ(NullGuard<const char*>::Guard(hello.c_str()), hello.data());
}

TEST(NullGuardTest, NullStringsReturnNonNullString) {
  EXPECT_EQ(NullGuard<char*>::Guard(static_cast<char*>(nullptr)),
            std::string("(null)"));
  EXPECT_EQ(NullGuard<const char*>::Guard(static_cast<char*>(nullptr)),
            std::string("(null)"));
}

TEST(NullGuardTest, NullptrReturnsNonNullString) {
  EXPECT_EQ(NullGuard<std::nullptr_t>::Guard(nullptr), std::string("(null)"));
}

}  // namespace
}  // namespace logging_internal
}  // namespace xls
