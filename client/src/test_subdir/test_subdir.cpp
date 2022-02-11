//
// Created by Alexander Winter on 2022-02-10.
//

#include <iostream>
#include <logging/Logger.h>

#ifdef OS_SWITCH
#include <switch.h>
#endif

void testFunction(const Logger& logger) {
    logger.info("Testing sub directories");
}