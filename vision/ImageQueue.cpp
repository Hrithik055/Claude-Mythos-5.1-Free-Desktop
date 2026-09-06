// rev-c3d90e-20260902 ImageQueue.cpp
// Mythos 5.1 Desktop - Image attachment handler
#include "../include/Core.h"
#include <fstream>
#include <sstream>

namespace M5 {

bool ImageQueue::Add(const std::string& path) {
    if (m_paths.size() >= 20) return false;
    std::ifstream f(path, std::ios::binary | std::ios::ate);
    if (!f.is_open()) return false;
    if (f.tellg() > 25LL * 1024 * 1024) return false;
    m_paths.push_back(path);
    return true;
}

std::string ImageQueue::ToBase64(const std::string& path) {
    std::ifstream f(path, std::ios::binary);
    std::stringstream ss;
    ss << f.rdbuf();
    std::string data = ss.str();
    static const char t[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::string out;
    int v = 0, vb = -6;
    for (unsigned char c : data) {
        v = (v << 8) + c;
        vb += 8;
        while (vb >= 0) { out.push_back(t[(v >> vb) & 0x3F]); vb -= 6; }
    }
    if (vb > -6) out.push_back(t[((v << 8) >> (vb + 8)) & 0x3F]);
    while (out.size() % 4) out.push_back('=');
    return out;
}

} // namespace M5
