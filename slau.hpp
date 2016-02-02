#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

#ifndef SLAU_HPP_INCLUDED
#define SLAU_HPP_INCLUDED

class slau
{
private:
    unsigned int height = 0;

    // Ax = b

    std::vector<std::vector<double>> A;
    std::vector<double> b;
    std::vector<double> x;

    bool is_solved = false;

public:

    slau(const int _height)
    {
        height = _height;

        A.resize(height);

        for (int i = 0; i < height; i++)
        {
            A[i].resize(height);
        }

        x.resize(height);
        b.resize(height);

    }



    void print()
    {
        if (!height) std::cout << "Empty vector.\n";

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < height; j++)
            {
                std::cout << A[i][j] << ' ';
            }

            std::cout << "   *    ";

            if (is_solved)
            {
               std::cout << x[i];
            }
            else
            {
                std::cout << 'x' << i;
            }

            std::cout << "    =    " << b[i] << '\n';
        }
    }

    void randomize()
    {
        std::srand(std::time(NULL));

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < height; j++)
            {
                A[i][j] = std::rand() % 10;
            }

            b[i] = std::rand() % 10;
        }
    }

    void solve()
    {

    }

};


#endif // SLAU_HPP_INCLUDED
