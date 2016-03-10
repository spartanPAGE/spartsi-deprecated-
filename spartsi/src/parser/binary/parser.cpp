#include "parser.hpp"

#include <cstdint>
#include <string>
#include <array>

namespace spartsi {
    namespace parser {
        namespace binary {

            struct node {
                std::string name;
                std::string comment;

                /* todo: attributes */
                /* todo: child nodes */
                /* todo: links */

                void read(buffer &buff) {
                    name = read_string(buff);
                    comment = read_string(buff);
                }
            };

            struct header {
                std::array<char, 14> signature;
                std::array<char, 1> major;
                std::array<char, 1> minor;

                node root;

                void read(buffer &buff) {
                    buff.read(signature.data(), signature.size());
                    buff.read(major.data(), major.size());
                    buff.read(minor.data(), minor.size());

                    root.read(buff);
                }
            };

            void parse(buffer buff) {
                header hdr;
                hdr.read(buff);
                //buff.good()?
            }
        }
    }
}