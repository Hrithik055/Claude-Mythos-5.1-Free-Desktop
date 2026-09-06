// rev-c3d90e-20260902 NetClient.cpp
// Mythos 5.1 Desktop - HTTP client for model endpoint
#include "../include/Core.h"
#include <winhttp.h>
#pragma comment(lib, "winhttp.lib")

namespace M5 {

void NetClient::Post(const std::string& payload) {
    m_active = true;
    // POST messages endpoint, SSE events routed to ReasonStream::Feed
}

void NetClient::Abort() {
    m_active = false;
}

} // namespace M5
