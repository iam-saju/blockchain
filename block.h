#pragma once
#include <ctime>
#include <string>

struct block{

    int index;
    std::time_t timestamp;
    std::string data;
    std::string prevHash;
    std::string hash;
    int nonce;

    block(int idx,const std::string &d,const std::string &prev):index(idx),timestamp(std::time(nullptr)),data(d),prevHash(prev),nonce(0),hash(""){}
};

