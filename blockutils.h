// BlockUtils.h
#pragma once
#include "block.h"
#include "hash.h"
#include <sstream>

inline std::string calculateHash(const block& b) {
    return simpleHash(b.serialize());
}
