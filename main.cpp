#include <iostream>
#include "blockchain.h"

int main(){
    blockchain b1(3);
    b1.addBlock("eth-transaction");
    b1.addBlock("sol-transaction");
    b1.addBlock("doge-transaction");
    b1.addBlock("shib-transaction");
    b1.addBlock("ltc-transaction");

    b1.showChain();
}