#include <iostream>
#include "Shipments.cpp"

using namespace std;

int main(){
    Letter letter1;
    float l_cost = letter1.get_cost();
    cout << l_cost << endl;

    Package pack1(6);
    float p_cost = pack1.get_cost();
    cout << p_cost << endl;
    return 0;
}
