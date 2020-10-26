// Copyright 2018 Google LLC
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

// This entire file is excluded from Copybara since it contains code that
// is only used when the agent is built in Blaze.

#include "src/globals.h"

#include "third_party/absl/base/builddata.h"

namespace cloud {
namespace profiler {

// When built in blaze, use build data to determine a meaningful version string.
// Set to "blaze:unknown" if required information is not available.
std::string GetProfilerVersion() {
  if (!BuildData::BuildLabel().empty()) {
    return absl::StrCat("blaze:", BuildData::BuildLabel());
  } else if (BuildData::ChangelistAsInt() != -1) {
    return absl::StrCat("blaze:", BuildData::Changelist());
  } else {
    return ("blaze:unknown");
  }
}

}  // namespace profiler
}  // namespace cloud
