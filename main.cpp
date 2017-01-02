#include <iostream>
#include <string>
#include "slau.hpp"

void prompt();

int main()
{
    std::cout << "Welcome to the best SLAU solver ever!\n";

    prompt();

    std::cout << "Thanks for using Leonid Solution's SLAU solver!\n";

    return 0;
}

void prompt()
{
    slau* problem = new slau(0);

    /*
    delete problem;
    problem = new slau(4);
    problem->randomize();
    problem->print();
    problem->solve();

    std::cin.ignore();
    return;
    */

    while (true)
    {
        std::cout << "$ ";

        std::string command;

        std::cin >> command;

        if (command == "exit")
        {
            return;
        }

        else if (command == "print")
        {
            problem->print();
        }

        else if (command == "new")
        {
            int height;

            std::cin >> height;

            delete problem;
            problem = new slau(height);
        }

        else if (command == "rand")
        {
            problem->randomize();
        }

        else if (command == "rnew")
        {
            int height;

            std::cin >> height;

            delete problem;
            problem = new slau(height);
            problem->randomize();
            if (height < 5) problem->print();
        }

        else if (command == "solve")
        {
            problem->solve();
        }

        else if (command == "check")
        {
            problem->check();
        }

        else if (command == "change")
        {
            std::string target;

            std::cin >> target;

            if (target == "A")
            {
                int line;
                int item;
                double value;

                std::cin >> line >> item >> value;

                if (line >= problem->size() || item >= problem->size())
                {
                        std::cout << "Indexes out of range!\n";
                        continue;
                }

                std::cout << "Changing A at (" << line << ',' << item << ") from " << problem->get_A(line, item) << " to " << value << '\n';

                problem->change_A(line, item, value);
            }
            else if (target == "b")
            {
                int item;
                double value;

                std::cin >> item >> value;

                if (item >= problem->size())
                {
                        std::cout << "Index out of range!\n";
                        continue;
                }

                std::cout << "Changing b at (" << item << ") from " << problem->get_b(item) << " to " << value << '\n';

                problem->change_b(item, value);
            }
        }

        else
        {
            std::cout << "Unknown command \"" << command << "\", use \"exit\" to exit\n";
        }

    }
    return;
}
