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

            std::string extract_captured(const std::string &str) {
                auto beg_seq = str.find_first_not_of(whitespaces);
                auto end_seq = str.find_last_not_of(whitespaces);

                if(beg_seq == end_seq == std::string::npos) {
                    return "";
                }

                return std::string(str.begin()+beg_seq, str.begin()+end_seq+1);
            }
        }
    }
}