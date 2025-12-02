#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
template <typename Container, typename T>
bool contains(const Container& c, const T& value) {
    return std::find(c.begin(), c.end(), value) != c.end();
}