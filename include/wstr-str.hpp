// wstr-str.hpp
#pragma once
#include <string>

using str = std::string;
using wstr = std::wstring;

wstr utf8_to_wstring(const str& s);
str wstring_to_utf8(const wstr& ws);
