#pragma once
#include "blockutils.h"

inline void mineBlock(block &b,int difficulty){
    std::string target(difficulty,'0');
    
    // Calculate initial hash
    b.hash = calculateHash(b);
    
    // Mine until we find a hash that starts with the required number of zeros
    while(b.hash.substr(0,difficulty)!= target){
        b.nonce++;
        b.hash = calculateHash(b);
    }
    
    std::cout << "Block mined! Hash: " << b.hash << " (Nonce: " << b.nonce << ")" << std::endl;
}