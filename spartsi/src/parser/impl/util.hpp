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
            extern const std::string whitespaces;

            std::regex weak_reg(const std::string &);

            std::string extract_captured(const std::string &);
        }
    }
}