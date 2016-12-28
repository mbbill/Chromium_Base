// billming

#include <string>

#include "base/trace_event/easy_trace.h"

#include "base/files/file_util.h"
#include "base/logging.h"
#include "base/memory/ref_counted_memory.h"
#include "base/run_loop.h"
#include "base/trace_event/trace_buffer.h"
#include "base/trace_event/trace_event.h"
#include "base/trace_event/trace_log.h"
using namespace std;
using namespace base;

namespace base {

namespace trace_event {

// leaking this object is fine.
static const FilePath& path_ = *(new FilePath(FILE_PATH_LITERAL("trace.json")));

static void OnTraceDataCollected(
    Closure quit_closure,
    trace_event::TraceResultBuffer* buffer,
    const scoped_refptr<RefCountedString>& json_events_str,
    bool has_more_events) {
    buffer->AddFragment(json_events_str->data());
    if (!has_more_events) {
        quit_closure.Run();
    }
}

static void TraceOutputCallback(const std::string& data) {
    AppendToFile(path_, data.c_str(), data.length());
}

void traceStart(const string& categories) {

    trace_event::TraceLog::GetInstance()->SetEnabled(
        trace_event::TraceConfig(categories, trace_event::RECORD_CONTINUOUSLY),
        trace_event::TraceLog::RECORDING_MODE);
}

void traceStop() {
    const string _begin = "{\"traceEvents\": [";
    const string _end = "]}";

    WriteFile(path_, _begin.c_str(), _begin.length());

    trace_event::TraceLog::GetInstance()->SetDisabled();

    trace_event::TraceResultBuffer buffer;
    buffer.SetOutputCallback(Bind(&TraceOutputCallback));

    RunLoop run_loop;
    trace_event::TraceLog::GetInstance()->Flush(
        Bind(&OnTraceDataCollected, run_loop.QuitClosure(), Unretained(&buffer)));

    run_loop.Run();
    AppendToFile(path_, _end.c_str(), _end.length());
}

} // namespace trace_event
} // namespace base

