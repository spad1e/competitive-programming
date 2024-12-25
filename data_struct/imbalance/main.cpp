#include <iostream>
#include "map_bst.h"
using namespace std;

int main()
{
    CP::map_bst<int, int> m;
    m[5] = 1;
    m[2] = 1;
    m[8] = 1;
    m[6] = 1;
    m[4] = 1;
    m[3] = 1;
    m[10] = 1;
    m[9] = 1;
    m[7] = 1;
    m[1] = 1;
    m.print();
    std::cout<<m.getValueOfMostImbalanceNode()<<endl;
    return 0;
}
