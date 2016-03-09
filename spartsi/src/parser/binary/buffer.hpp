#pragma once

#include <sstream>
#include <iterator>
#include <algorithm>
#include <vector>

namespace spartsi {
    namespace parser {
        namespace binary {
            using buffer = std::stringstream;

            std::string read_string(buffer &buff) {

                uint32_t size;
                buff.read(reinterpret_cast<char*>(&size), 4);

                std::vector<char> data(size);

                buff.read(&data[0], size);

                return { begin(data), end(data) };
            }
        }
    }
}