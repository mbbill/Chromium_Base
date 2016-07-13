#include <iostream>
#include <string>
#include "base/logging.h"
#include "base/base64.h"
#include "base/run_loop.h"
#include "base/memory/ref_counted_memory.h"
#include "base/trace_event/trace_event.h"
#include "base/trace_event/trace_buffer.h"
#include "base/trace_event/trace_log.h"

using namespace std;
using namespace base;

static const char EVENT_CATEGORIES[] = "test_categories";

////////////////////////////////////////////////////////////////////////////////
void DemoLog() {
    TRACE_EVENT0(EVENT_CATEGORIES, "DemoLog");
    LOG(INFO) << "Demo INFO Log";
    LOG(ERROR) << "Demo ERROR Log";
}

////////////////////////////////////////////////////////////////////////////////
void DemoBase64() {
    TRACE_EVENT0(EVENT_CATEGORIES, "DemoBase64");
    StringPiece s = "Text to encode";
    string out;
    cout << s << " => ";
    Base64Encode(s, &out);
    cout << out << endl;
}

////////////////////////////////////////////////////////////////////////////////
void DemoTraceEventBegin() {
    cout << "{\"traceEvents\": [" << endl;

    string categories = EVENT_CATEGORIES;

    trace_event::TraceLog::GetInstance()->SetEnabled(
        trace_event::TraceConfig(categories, trace_event::RECORD_UNTIL_FULL),
        trace_event::TraceLog::RECORDING_MODE);
}


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
    cout << data << endl;
}

void DemoTraceEventEnd() {
    trace_event::TraceLog::GetInstance()->SetDisabled();

    trace_event::TraceResultBuffer buffer;
    buffer.SetOutputCallback(Bind(&TraceOutputCallback));

    RunLoop run_loop;
    trace_event::TraceLog::GetInstance()->Flush(
        Bind(&OnTraceDataCollected, run_loop.QuitClosure(), Unretained(&buffer)));

    run_loop.Run();
    cout << "]}" << endl;
}

////////////////////////////////////////////////////////////////////////////////
int main(void) {
    DemoTraceEventBegin();

    DemoLog();
    DemoBase64();

    DemoTraceEventEnd();
    return 0;
}
