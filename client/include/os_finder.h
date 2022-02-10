//
// Created by Alexander Winter on 2022-02-08.
//

#ifndef GAMETEMPLATE_OS_FINDER_H
#define GAMETEMPLATE_OS_FINDER_H

#if !defined(OS_WINDOWS) && !defined(OS_MAC) && !defined(OS_UNIX)
#define OS_SWITCH
#endif

#endif //GAMETEMPLATE_OS_FINDER_H
