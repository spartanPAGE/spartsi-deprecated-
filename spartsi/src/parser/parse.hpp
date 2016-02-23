#pragma once

#include "node/node.hpp"


namespace spartsi{

    template<typename Str>
    node<Str>::shared parse(Str lines[]) {
        //todo;
        return node<Str>::spawn_root("", "", "");
    }
}