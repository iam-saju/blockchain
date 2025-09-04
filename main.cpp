#include <iostream>
#include "blockchain.h"
#include "transc.h"

int main(){
    blockchain bc(3);

    //bc.showChain();
    //bc.showUTXO();

    tx t1;
    outpoint input1{"genesis", 0}; // spending genesis output
    t1.tx_in.push_back({input1, ""});
    t1.tx_out.push_back({20, "Bob"});
    t1.tx_out.push_back({30, "miner1"}); // change back

    bc.addBlock({t1});

    bc.showChain();
    //bc.showUTXO();
}