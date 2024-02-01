//
//  run.cpp
//  Test
//
//  Created by 陳肜樺 on 2/1/24.
//

extern "C" {
     #include "run.hpp"
     };
#define CATCH_CONFIG_RUNNER
#include "../codeCoverageL8/catch.h"
bool run_tests() {
const char *argv[] = { "test" };
return (Catch::Session().run(1, argv) == 0);
}
