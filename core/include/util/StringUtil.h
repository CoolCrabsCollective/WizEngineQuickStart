//
// Created by Alexander Winter on 2022-02-10.
//

#ifndef GAMETEMPLATE_STRINGUTIL_H
#define GAMETEMPLATE_STRINGUTIL_H

#include <string>

inline bool ends_with(const std::string& value, const std::string& ending) {
    if(ending.size() > value.size())
        return false;

    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

#endif //GAMETEMPLATE_STRINGUTIL_H
