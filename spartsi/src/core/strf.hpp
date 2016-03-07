#pragma once

#include <string>
#include <algorithm>

#define SPARTSI_STRF(delim, x) []{                           \
    std::string source = #x;                                 \
    std::replace(source.begin(), source.end(), delim, '\n'); \
    return source;                                           \
}()
