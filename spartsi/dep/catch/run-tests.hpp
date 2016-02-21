#pragma once

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

int run_tests(int argc, const char *argv[]) {
    Catch::Session session;

    int returnCode = session.applyCommandLine(argc, argv);
    if(returnCode != 0) // Indicates a command line error
        return returnCode;

    return session.run();
}