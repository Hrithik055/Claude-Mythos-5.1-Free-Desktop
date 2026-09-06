// rev-c3d90e-20260902 TraceView.cpp
// Mythos 5.1 Desktop - Trace renderer for reasoning panel
#include "../include/Core.h"
#include <windows.h>

namespace M5 {

void TraceView::Paint(HDC hdc, const RECT& rc, const std::vector<TraceEntry>& trace) {
    int y = rc.top + 16;
    for (const auto& e : trace) {
        if (y > rc.bottom - 20) break;
        SetTextColor(hdc, e.final ? RGB(100,200,150) : RGB(120,140,170));
        SetBkMode(hdc, TRANSPARENT);
        RECT tr = {rc.left + 16 + e.depth * 14, y, rc.right - 16, y + 90};
        DrawTextA(hdc, e.text.c_str(), -1, &tr, DT_LEFT | DT_WORDBREAK);
        y += (int)(e.text.size() / 60 + 1) * 18 + 8;
    }
}

} // namespace M5
