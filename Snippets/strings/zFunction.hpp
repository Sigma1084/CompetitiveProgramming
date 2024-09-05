#pragma once

#include <string>
#include <vector>
#include <algorithm>

std::vector<unsigned int> zFunction(const std::string &s) {
    unsigned int n = static_cast<int>(s.size());
    std::vector<unsigned int> z(s.size());
    for (unsigned int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) z[i] = std::min(r - i + 1, z[i - l]);
        while (i + z[i] < n and s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}
