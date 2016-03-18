#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>

#ifndef SLAU_HPP_INCLUDED
#define SLAU_HPP_INCLUDED

class slau
{
private:
    int height = 0;

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

    void change_A(int _line, int _item, double _value)
    {
        A[_line][_item] = _value;
    }

    void change_b(int _item, double _value)
    {
        b[_item] = _value;
    }

    double get_A(int _line, int _item)
    {
        return A[_line][_item];
    }

    double get_b(int _item)
    {
        return b[_item];
    }

    int size()
    {
        return height;
    }

    void print()
    {
        if (!height) std::cout << "Empty vector.\n";

        for (int i = 0; i < height; i++)
        {
            std::cout << "( ";

            for (int j = 0; j < height; j++)
            {
                std::printf("% .1E ", A[i][j]);
            }

            std::cout << ") * (";

            if (is_solved)
            {
               std::printf("% .1E ", x[i]);
            }
            else
            {
                std::printf(" x%-6d ", i);
            }

            std::cout << ") = (";
            std::printf("% .1E ", b[i]);
            std::cout << ")\n";
        }
    }

    void randomize()
    {
        std::srand(std::time(NULL));

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < height; j++)
            {
                A[i][j] = (std::rand() % 2 ? 1 : -1) * (std::rand() / (double)RAND_MAX);
            }

            b[i] = (std::rand() % 2 ? 1 : -1) * (std::rand() / (double)RAND_MAX);
        }
    }

    void solve()
    {
        if (!height) std::cout << "Can't solve that: empty vector.\n";

        std::vector<std::vector<double>> A_calculated = A;
        std::vector<double> b_calculated = b;

        double devider;
        double multiplier;

        for (int i = 0; i < height; i++)
        {
            devider = A_calculated[i][i];

            for (int j = 0; j < height; j++)
            {
                if (j == i) continue;

                multiplier = A_calculated[j][i] / devider;

                for (int k = 0; k < height; k++)
                {
                    A_calculated[j][k] -= A_calculated[i][k] * multiplier;
                }

                b_calculated[j] -= b_calculated[i] * multiplier;
            }
        }

        for (int i = 0; i < height; i++)
        {
            x[i] = b_calculated[i] / A_calculated[i][i];
        }

        is_solved = true;

        print();
    }

    void check()
    {
        if (!is_solved || !height)
        {
            std::cout << "Not solved yet.";
            return;
        }

        std::vector<double> b_calculated;

        b_calculated.resize(height);

        std::vector<double> b_difference;

        b_difference.resize(height);

        double difference_lenght = 0;

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < height; j++)
            {
                b_calculated[i] += A[i][j] * x[j];
            }

            b_difference[i] = b[i] - b_calculated[i];

            difference_lenght += b_difference[i] * b_difference[i];
        }

        difference_lenght += std::pow(difference_lenght, 0.5);

        std::cout << "Difference lenght: " << difference_lenght << "\n\n";

        std::cout
            << "|          ORIGINAL          |         CALCULATED         |         DIFFERENCE         |\n"
            << "|----------------------------|----------------------------|----------------------------|\n";
        for (int i = 0; i < height; i++)
        {
            std::printf("|% .20E", b[i]);
            std::cout << " |";
            std::printf("% .20E", b_calculated[i]);
            std::cout << " |";
            std::printf("% .20E |\n", b_difference[i]);
        }
    }
};


#endif // SLAU_HPP_INCLUDED
