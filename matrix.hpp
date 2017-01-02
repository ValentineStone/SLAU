#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <Windows.h>

#ifndef _MATRIX_HPP
#define _MATRIX_HPP

#define EPS 0.0001

namespace matrix
{
    std::vector< std::vector<double> > multiply(const std::vector< std::vector<double> >& _matrix1, const std::vector< std::vector<double> >& _matrix2)
    {
        int height = _matrix1.size();

        std::vector< std::vector<double> > result = _matrix1;

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < height; j++)
            {
                result[i][j] = 0;
                for (int k = 0; k < height; k++)
                {
                    result[i][j] += _matrix1[i][k] * _matrix2[k][j];
                }
            }
        }

        return result;
    }

    void colomn_to_matrix(std::vector< std::vector<double> >& _matrix, const std::vector<double>& _vector)
    {
        int height = _vector.size();
        _matrix.clear();
        _matrix.resize(height);

        for (int i = 0; i < height; i++)
        {
            _matrix[i].resize(1);
            _matrix[i][0] = _vector[i];
        }
    }


    void print(const std::vector< std::vector<double> >& _matrix)
    {
        int height = _matrix.size();
        int width;

        if (!height)
        {
            std::cout << "Empty vector.\n";
            return;
        }
        else
        {
            width = _matrix[0].size();
        }

        for (int i = 0; i < height; i++)
        {
            std::cout << "( ";

            for (int j = 0; j < width; j++)
            {
                std::printf("% .1E ", _matrix[i][j]);
            }
            std::cout << ")\n";
        }
        std::cout << "------------------------------------------------------------\n";
    }

    void print(const std::vector<double>& _vector)
    {
        std::vector< std::vector<double> > matrix;
        colomn_to_matrix(matrix, _vector);

        print(matrix);
    }

    void solve(std::vector< std::vector<double> >& _matrix)
    {
        int height = _matrix.size();
        int width;

        if (height)
        {
            width = _matrix[0].size();
        }

        for (int i = 0; i < height; i++)
        {
            double devider = _matrix[i][i];
            for (int k = 0; k < width; k++)
            {
                _matrix[i][k] /= devider;
            }

            //print(_matrix);

            for (int j = 0; j < height; j++)
            {
                if (i == j)
                {
                    continue;
                }

                double multiplyer = _matrix[j][i];

                for (int k = 0; k < width; k++)
                {
                    //std::cout << "_matrix[j][k] " << _matrix[j][k] << " _matrix[i][k] " << _matrix[i][k] << " _matrix[j][i] " << _matrix[j][i] << "\n";
                    _matrix[j][k] -= _matrix[i][k] * multiplyer;
                }

            }

            //print(_matrix);
        }

        //print(_matrix);
    }

    void attach(std::vector< std::vector<double> >& _matrix, const std::vector< std::vector<double> >& _matrix2)
    {
        int height = _matrix.size();
        int width = _matrix2[0].size();

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                _matrix[i].push_back(_matrix2[i][j]);
            }
        }
    }

    void attach(std::vector< std::vector<double> >& _matrix, const std::vector<double>& _vector)
    {
        std::vector< std::vector<double> > matrix2;
        colomn_to_matrix(matrix2, _vector);

        attach(_matrix, matrix2);
    }

    void extract_colomn(const std::vector< std::vector<double> >& _matrix, const int _colomn_n, std::vector<double>& _vector)
    {
        int height = _matrix.size();
        _vector.resize(height);

        for (int i = 0; i < height; i++)
        {
            _vector[i] = _matrix[i][_colomn_n];
        }
    }

    void extract_matrix(const std::vector< std::vector<double> >& _matrix, const int _colomn_n, const int _width, std::vector< std::vector<double> >& _matrix2)
    {
        int height = _matrix.size();
        _matrix2.resize(height);

        for (int i = 0; i < height; i++)
        {
            _matrix2[i].resize(_width);
            for (int j = 0; j < _width; j++)
            {
                _matrix2[i][j] = _matrix[i][j + _colomn_n];
            }
        }
    }

    void make_diagonal_matrix(std::vector< std::vector<double> >& _matrix, const int _size)
    {
        _matrix.resize(_size);

        for (int i = 0; i < _size; i++)
        {
            _matrix[i].resize(_size, 0);
            _matrix[i][i] = 1;
        }
    }

    void apply_operator(const std::vector< std::vector<double> >& _operator, std::vector<double>& _vector)
    {
        std::vector<double> original_vector = _vector;

        int height = _operator.size();

        for (int i = 0; i < height; i++)
        {
            _vector[i] = 0;

            for (int j = 0; j < height; j++)
            {
                _vector[i] += _operator[i][j] * original_vector[j];
            }
        }
    }

    double normalize_vector(std::vector<double>& _vector)
    {
        int height = _vector.size();

        double devider = 0;

        for (int i = 0; i < height; i++)
        {
            devider += _vector[i] * _vector[i];
        }

        devider = std::pow(devider, 0.5);
        double lenght = 0;

        for (int i = 0; i < height; i++)
        {
            _vector[i] /= devider;
            lenght += _vector[i] * _vector[i];
        }

        return std::pow(lenght, 0.5);
    }

    std::vector< std::vector<double> > generate_symmetrical_matrix(const std::vector< std::vector<double> >& _matrix)
    {
        std::vector< std::vector<double> > diagonalized = _matrix;

        int height = _matrix.size();

        for (int i = 0; i < height; i++)
        for (int j = 0; j < height; j++)
        {
            diagonalized[j][i] = (diagonalized[j][i] + _matrix[i][j]) / 2;
        }

        return diagonalized;
    }

    double determine_worth(const std::vector< std::vector<double> >& _matrix, const std::vector< std::vector<double> >& _matrix_reversed)
    {
        int height = _matrix.size();

        double step_difference;

        std::vector<double> testificate1;
        std::vector<double> testificate2;
        testificate2.resize(height, 1);


        std::vector<std::vector<double>> symmetrical_operator_matrix = generate_symmetrical_matrix(_matrix);
        normalize_vector(testificate2);

        do
        {
            testificate1 = testificate2;

            apply_operator(symmetrical_operator_matrix, testificate2);
            normalize_vector(testificate2);
            //std::cout << testificate2[0] << "\n";
            step_difference = std::fabs(std::fabs(testificate1[0]) - std::fabs(testificate2[0]));
        }
        while (step_difference > EPS);

        double high_number = 0;
        testificate1 = testificate2;
        apply_operator(symmetrical_operator_matrix, testificate2);
        for (int i = 0; i < height; i++)
        {
            double current_number = std::fabs(testificate2[i] / testificate1[i]);
            //if (high_number < current_number) std::cout << i << "high\n";
            high_number = high_number < current_number ? current_number : high_number;
        }


        std::vector<std::vector<double>> symmetrical_operator_matrix_reversed = generate_symmetrical_matrix(_matrix_reversed);
        normalize_vector(testificate2);

        do
        {
            testificate1 = testificate2;

            apply_operator(symmetrical_operator_matrix_reversed, testificate2);
            normalize_vector(testificate2);
            //std::cout << testificate2[height] << "\n";
            step_difference = std::fabs(std::fabs(testificate1[height]) - std::fabs(testificate2[height]));
        }
        while (step_difference > EPS);

        double low_number = 0;
        testificate1 = testificate2;
        apply_operator(symmetrical_operator_matrix_reversed, testificate2);
        for (int i = 0; i < height; i++)
        {
            double current_number = std::fabs(testificate2[i] / testificate1[i]);
            //if (low_number < current_number) std::cout << i << "low\n";
            low_number = low_number < current_number ? current_number : low_number;
        }

        low_number = 1 / low_number;

        double goodness_number = high_number / low_number;

        std::cout << "The matrix is " << goodness_number << " good.\n";

        return goodness_number;
    }

    /*
    double find_least_self_value(const std::vector< std::vector<double> >& _matrix)
    {
        std::cout << "ls\n";
        int height = _matrix.size();
        std::vector< std::vector<double> > operator_matrix = generate_symmetrical_operator(_matrix);

        std::vector<double> testificate1;
        std::vector<double> testificate2;
        testificate2.resize(height, 1);

        normalize_vector(testificate2);

        do
        {
            testificate1 = testificate2;

            apply_operator(operator_matrix, testificate2);
            normalize_vector(testificate2);
            print(testificate2);
        }
        while (std::fabs(testificate1[height - 1] - testificate2[height - 1]) > EPS);

        double devider = testificate2[height - 1];
        apply_operator(operator_matrix, testificate2);

        return 1 / devider;
    }
    */

}

#endif _MATRIX_HPP
