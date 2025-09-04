#pragma once
#include <unordered_map>
#include <vector>


struct txOut{
    uint64_t value;
    std::string public_key;
};

struct outpoint{
    std::string txid;
    uint32_t index;
};

struct txIn{
    outpoint prev;
    std::string sign;
    std::string public_key;
};


struct tx{
    std::vector<txIn> tx_in;
    std::vector<txOut> tx_out;
    bool coinbase=false;
};


using UTXOkey=std::string;
inline UTXOkey key(const outpoint& p){return p.txid+"|"+std::to_string(p.index);} 

struct UTXO{
    std::unordered_map<UTXOkey,txOut> map;
    bool exists(const outpoint& p) const { return map.find(key(p)) != map.end(); }
    void spend(const outpoint &p){map.erase(key(p));}
    void add(const std::string& txid, const txOut& o, uint32_t idx){ map[txid+"|"+std::to_string(idx)] = o; }

};

