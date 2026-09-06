// rev-c3d90e-20260902 ReasonStream.cpp
// Mythos 5.1 Desktop - Reasoning stream handler
#include "../include/Core.h"
#include <ctime>

namespace M5 {

void ReasonStream::Feed(const std::string& chunk, bool thinking) {
    if (thinking) {
        TraceEntry e;
        e.text = chunk;
        e.ts = std::time(nullptr);
        e.final = chunk.find("[done]") != std::string::npos;
        m_trace.push_back(e);
        if (m_onStep) m_onStep(e);
    } else if (!m_messages.empty()) {
        m_messages.back().body += chunk;
    }
}

void ReasonStream::Reset() {
    m_messages.clear();
    m_trace.clear();
}

} // namespace M5
