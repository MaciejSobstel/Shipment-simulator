#include <iostream>
#include <fstream>
#include "game.cpp"

int main(){
    HQ hq(1232.7);
    hq.buy_delivery_man();
    hq.buy_delivery_man();
    hq.buy_mailbox();
    hq.buy_parcel_locker();
    hq.saveState();
    HQ hq1(0);
    hq1.loadState();
    hq1.saveState("HQ2.txt");
}