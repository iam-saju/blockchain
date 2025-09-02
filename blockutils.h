// BlockUtils.h
#pragma once
#include "block.h"
#include "hash.h"
#include <sstream>

inline std::string calculateHash(const block& b) {
    std::stringstream ss;
    ss << b.index << b.timestamp << b.data << b.prevHash << b.nonce;
    return simpleHash(ss.str());
}
