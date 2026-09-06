// rev-c3d90e-20260902 Core.h
// Mythos 5.1 Desktop - Core types
#pragma once
#include <string>
#include <vector>
#include <functional>
#include <atomic>
#include <ctime>
#include <windows.h>

namespace M5 {

struct Msg {
    std::string role;
    std::string body;
    std::time_t ts = 0;
    std::vector<std::string> images;
};

struct TraceEntry {
    std::string text;
    int depth = 0;
    bool final = false;
    std::time_t ts = 0;
};

class ReasonStream {
public:
    using StepFn = std::function<void(const TraceEntry&)>;
    void Feed(const std::string& chunk, bool thinking);
    void Reset();
    void OnStep(StepFn fn) { m_onStep = fn; }
private:
    std::vector<Msg> m_messages;
    std::vector<TraceEntry> m_trace;
    StepFn m_onStep;
};

class ImageQueue {
public:
    bool Add(const std::string& path);
    void Clear() { m_paths.clear(); }
    int Count() const { return (int)m_paths.size(); }
private:
    std::string ToBase64(const std::string& path);
    std::vector<std::string> m_paths;
};

class NetClient {
public:
    void Post(const std::string& payload);
    void Abort();
private:
    std::atomic<bool> m_active{false};
};

class TraceView {
public:
    void Paint(HDC hdc, const RECT& rc, const std::vector<TraceEntry>& trace);
};

class Core {
public:
    bool Init(HINSTANCE hInst);
    int Loop();
private:
    ReasonStream m_stream;
    ImageQueue m_images;
    NetClient m_net;
    TraceView m_traceView;
};

} // namespace M5
