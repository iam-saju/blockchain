#pragma once
#include <string>
#include <functional>
#include "sha256.h"

inline std::string simpleHash(const std::string &input) {

    // simple hash
    std::hash<std::string> hasher;
    size_t hashValue = hasher(input);

    //sha256 hash
    std::string sha256hash=sha256(input);


    // Add forced zeros for mining to work
    return sha256hash;
}
