#include <iostream>
#include "slau.hpp"

int main()
{
    slau* bob = new slau(10);
    bob->randomize();
    bob->print();

    return 0;
}
