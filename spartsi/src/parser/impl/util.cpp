#include "util.hpp"

namespace spartsi {
    namespace parser {
        namespace util {
            const std::string ws = "\\s";
            const std::string capture = "(.+)";
            const std::string quote = "\\\"";
            const std::string capture_quoted = quote+ws+"*"+capture+ws+"*"+quote;
            const std::string whitespaces = " \t\f\v\n\r";

            std::regex weak_reg(const std::string &dat) {
                return std::regex{"^\\s*"+dat+"\\s*$"};
            }
        }
    }
}