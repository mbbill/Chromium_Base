// billming

#ifndef BASE_TRACE_EVENT_EASY_TRACE_H
#define BASE_TRACE_EVENT_EASY_TRACE_H

#include <string>

#include "base/base_export.h"

namespace base {

namespace trace_event {

BASE_EXPORT void traceStart(const std::string& categories);

BASE_EXPORT void traceStop();

} // namespace trace_event
} // namespace base

#endif //BASE_TRACE_EVENT_EASY_TRACE_H
