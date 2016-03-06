#pragma once

#include <string>
#include <regex>
#include <functional>

namespace spartsi {
    namespace parser {
        namespace util {
            extern const std::string ws;
            extern const std::string capture;
            extern const std::string quote;
            extern const std::string capture_quoted;

            std::regex weak_reg(const std::string &);
        }
    }
}