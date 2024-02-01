//
//  cmdline.cpp
//  MSDscript
//
//  Created by Thanmay Reddy Lakkireddy on 1/16/24.
//

#define CATCH_CONFIG_RUNNER

#include <iostream>
#include "catch.h"
#include "cmdline.hpp"


using namespace std;

void use_arguments(int argc, char *argv []) {
    
    if (argc > 1) {

        // first flag
        bool firstTestFlag = true;

        for( int i = 1; i < argc; i++) {
            
            // --help
            if (strcmp(argv[i], "--help") == 0) {
                std::cout << "Help Text!" << endl;
                exit(0);
                
            //--test
            }
            else if (strcmp(argv[i], "--test") == 0) {
                
                if (firstTestFlag) {
                    std::cout << "Tests Passed!" << endl;
                    firstTestFlag = false;
                    
                    if (Catch::Session().run() != 0) {
                        exit(1);
                    }
                    
                } else{
                    std::cerr << "ERROR!" << endl;
                    exit(1);
                }
                
            // --
            } else {
                std::cerr << "Not Allowed!" << endl;
                exit(1);
            }
                        
        }

    }

}
