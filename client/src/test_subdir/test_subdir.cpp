//
// Created by Alexander Winter on 2022-02-10.
//

#include <iostream>

#ifdef OS_SWITCH
#include <switch.h>
#endif

void testFunction() {
    std::cout << "Testing sub directories" << std::endl;
}