#pragma once
#include <iostream>
#include <vector>
#include "block.h"
#include "mine.h"

class blockchain{
    private:
    std::vector<block> chain;
    int difficulty;

    block createGenesisBlock(){
        block genesis(0,"genesis","0");
        mineBlock(genesis,difficulty);
        return genesis;
    }

    public:
    blockchain(int diff):difficulty(diff){
        chain.push_back(createGenesisBlock());
    }

    void addBlock(const std::string &data){
        block newBlock(chain.size(),data,chain.back().hash);
        mineBlock(newBlock,difficulty);
        chain.push_back(newBlock);
    }

    void showChain(){
        for (const auto& block : chain) {
            std::cout << "Index: " << block.index << "\n"
                      << "Timestamp: " << block.timestamp << "\n"
                      << "Data: " << block.data << "\n"
                      << "Prev Hash: " << block.prevHash << "\n"
                      << "Hash: " << block.hash << "\n"
                      << "Nonce: " << block.nonce << "\n"
                      << "----------------------------\n";
        }

    }
};