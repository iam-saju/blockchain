#pragma once
#include "block.h"

inline bool proofofwork(const block &b,int difficulty){
    for(int i=0 ; i<difficulty ; i++){
        if (i >= (int)b.hash.size() || b.hash[i] != '0') return false;
    }
    return true;
}