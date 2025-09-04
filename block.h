#pragma once
#include <ctime>
#include <string>
#include <vector>
#include "transc.h"
#include <sstream>


struct block{

    int index;
    std::time_t timestamp;
    std::vector<tx> txs;
    std::string prevHash;
    std::string hash;
    int nonce;

    block(int idx,const std::string &prev,const std::vector<tx> &transactions):index(idx),timestamp(std::time(nullptr)),txs(transactions),prevHash(prev),nonce(0),hash(""){}

    std::string serialize() const {
        std::stringstream ss;
    
        // Add basic block info
        ss << index << timestamp << prevHash;
    
        // Add every transaction
        for (auto &t : txs) {
            // Add inputs
            for (auto &in : t.tx_in)
                ss << in.prev.txid << in.prev.index;
    
            // Add outputs
            for (auto &out : t.tx_out)
                ss << out.public_key << out.value;
        }
    
        // Add nonce (used in mining)
        ss << nonce;
    
        return ss.str();
    }
    
};

