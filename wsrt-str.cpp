// wstr-str.cpp
#include "wstr-str.hpp"
#include <locale>
#include <codecvt>

wstr utf8_to_wstring(const str& s) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter; // deprecated, ok por ahora
    return converter.from_bytes(s);
}

str wstring_to_utf8(const wstr& ws) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter; // deprecated
    return converter.to_bytes(ws);
}
