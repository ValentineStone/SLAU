#include <iostream>
#include "slau.hpp"

int edit(slau*);

int main()
{
    std::cout << "Welcome to the best SLAU solver ever!\n\n";

    std::cout << "How many equations we require?: ";

    int height;

    std::cin >> height;



    slau* problem = new slau(height);

    problem->randomize();

    std::cout << "Here is your randomized SLAU:\n\n";

    problem->print();



    std::cout << "\nWanna change it? (y/n): ";

    char reply;
    bool is_input_valid = false;

    while (!is_input_valid)
    {
        std::cin >> reply;

        switch (reply)
        {
            case 'y':
            case 'Y':
            {
                edit(problem);
                is_input_valid = true;
                break;
            }
            case 'n':
            case 'N':
            {
                is_input_valid = true;
                break;
            }
            default:
            {
                std::cout << "Unsure what you ment, wanna change the matrix? (y/n): ";
            }
        }
    }



    std::cout << "\nHere is how we solved it:\n\n";

    problem->solve();



    std::cout << "\nHere is how we checked it:\n\n";

    problem->check();



    return 0;
}

int edit(slau* _problem)
{
    std::cout << "Changed it!\n\n";
    return 0;
}
