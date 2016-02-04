#include <iostream>
#include "slau.hpp"

int main()
{
    std::cout << "===============================================================\n"
              << "|| ♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥ ||\n"
              << "|| ♥♡♥♡♥♡♥♡♥                                       ♥♡♥♡♥♡♥♡♥ ||\n"
              << "|| ♥♡♥♡♥♡♥♡♥ Welcome to the best SLAU solver ever! ♥♡♥♡♥♡♥♡♥ ||\n"
              << "|| ♥♡♥♡♥♡♥♡♥                                       ♥♡♥♡♥♡♥♡♥ ||\n"
              << "|| ♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥♡♥ ||\n"
              << "===============================================================\n";

    std::cout << "How many equasions we require?: ";

    int height;

    std::cin >> height;



    slau* problem = new slau(height);

    problem->randomize();

    std::cout << "Here is your randomized SLAU:\n\n";

    problem->print();

    std::cout << "\nHere is how we solved it:\n\n";

    problem->solve();

    std::cout << "\nHere is how we checked it:\n\n";

    problem->check();

    return 0;
}
