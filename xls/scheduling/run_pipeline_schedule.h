// Copyright 2023 The XLS Authors
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

#ifndef XLS_SCHEDULING_RUN_PIPELINE_SCHEDULE_H_
#define XLS_SCHEDULING_RUN_PIPELINE_SCHEDULE_H_

#include "absl/status/statusor.h"
#include "xls/delay_model/delay_estimator.h"
#include "xls/fdo/synthesizer.h"
#include "xls/ir/function_base.h"
#include "xls/scheduling/pipeline_schedule.h"
#include "xls/scheduling/scheduling_options.h"

namespace xls {

// Produces a pipeline schedule using the given delay model and scheduling
// options. The synthesizer argument should be non-null when we are doing
// feedback-directed scheduling.
absl::StatusOr<PipelineSchedule> RunPipelineSchedule(
    FunctionBase* f, const DelayEstimator& delay_estimator,
    const SchedulingOptions& options,
    const synthesis::Synthesizer* synthesizer = nullptr);

}  // namespace xls

#endif  // XLS_SCHEDULING_RUN_PIPELINE_SCHEDULE_H_
