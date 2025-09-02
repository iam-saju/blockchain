#pragma once
#include "blockutils.h"
#include "pow.h"

inline void mineBlock(block &b,int difficulty){
    std::string target(difficulty,'0');
    
    // Calculate initial hash
    b.hash = calculateHash(b);
    
    // Mine until we find a hash that starts with the required number of zeros
    while(true){
        b.hash = calculateHash(b);
        if(proofofwork(b,difficulty))break;
        b.nonce++;
    }
    
    std::cout << "Block mined! Hash: " << b.hash << " (Nonce: " << b.nonce << ")" << std::endl;
}