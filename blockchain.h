#pragma once
#include <iostream>
#include <vector>
#include "block.h"
#include "mine.h"
#include "transc.h"

class blockchain{
    private:
    std::vector<block> chain;
    int difficulty;
    UTXO utxo;

    block createGenesisBlock(){
        tx genesistx;
        genesistx.tx_out.push_back(txOut{100,"coinbase _transc"});
        genesistx.coinbase=true;
        utxo.add("genesis",genesistx.tx_out[0],0);
        
        std::vector<tx> genesistxs;
        genesistxs.push_back(genesistx);
        block genesis(0,"null",genesistxs);
        mineBlock(genesis,difficulty);
        return genesis;

    }

    public:
    blockchain(int diff):difficulty(diff){
        chain.push_back(createGenesisBlock());
    }

    void addBlock(const std::vector<tx> &txs){ 
        for(auto &transc :txs){
            for(auto &input : transc.tx_in){
                if(!utxo.exists(input.prev)){
                    utxo.spend(input.prev);
                }
            }
            for (size_t i = 0; i < transc.tx_out.size(); i++)
                utxo.add("tx" + std::to_string(rand()), transc.tx_out[i], i);
        }

        block newBlock(chain.size(),chain.back().hash,txs);
        mineBlock(newBlock,difficulty);
        chain.push_back(newBlock);
    }

    void showChain() {
        std::cout << "--------------------------------\n";
        for (const auto &b : chain)
            std::cout << "Block " << b.index << " mined, hash: " << b.hash << "\n";
        
    }

    void showUTXO(){
        std::cout << "--------------------------------\n";
        for(const auto &utxo : utxo.map){
            std::cout << "UTXO: " << utxo.first << " value: " << utxo.second.value << " public key: " << utxo.second.public_key << "\n";
        }
    }
};