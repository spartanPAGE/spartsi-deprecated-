#include "parser.hpp"

#include <cstdint>
#include <string>
#include <array>

namespace spartsi {
    namespace parser {
        namespace binary {

            struct header {
                std::array<char, 14> signature;
                uint8_t major;
                uint8_t minor;

                std::string name;
                std::string comment;

                /* <todo: root  node> */
                /* // */

                header(buffer &buff) {
                    buff.read(signature.data(), signature.size());
                    buff.read(reinterpret_cast<char*>(&major), sizeof(major));
                    buff.read(reinterpret_cast<char*>(&minor), sizeof(minor));

                    name    = read_string(buff);
                    comment = read_string(buff);
                }
            };

            void parse(buffer buff) {
                header hdr(buff);
                //buff.good()?
            }
        }
    }
}