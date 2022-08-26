#include <iostream>
#include <cmath>

// int main(int argc, char* argv[])
// {
//     std::cout<<"Hello World!"<<std::endl;
//     return 0;
// }

#define OR ||
#define AND &&

#define _2PI 2 * M_PI

const int ENTRIES_ARGV_IDX = 1;
const int BITSIZE_ARGV_IDX = 2;
const int IQ_INDC_ARGV_IDX = 3;

const int MAX_ENTRIES_NUM = 100;
const int MAX_BIT_SIZE = 64;

enum error
{
    invalid_arg_num,
    invalid_arg_values,
    invalid_arg_range,
    invalid_arg_iq
};

void gen_error(error err);
bool isPositiveNumber(char number[]);

int main(int argc, char *argv[])
{
    argc--;
    if ((argc != 2) and (argc != 3))
    {
        gen_error(invalid_arg_num);
        return 1;
    }

    if (!isPositiveNumber(argv[ENTRIES_ARGV_IDX]) OR !isPositiveNumber(argv[BITSIZE_ARGV_IDX]))
    {
        gen_error(invalid_arg_values);
        return 1;
    }

    int entries_num = atoi(argv[ENTRIES_ARGV_IDX]);
    int num_bits = atoi(argv[BITSIZE_ARGV_IDX]);

    if ((entries_num > MAX_ENTRIES_NUM) OR(num_bits > MAX_BIT_SIZE))
    {
        gen_error(invalid_arg_range);
        return 1;
    }

    float sin_values[MAX_ENTRIES_NUM];
    for (int ii = 0; ii < entries_num; ii++)
    {
        sin_values[ii] = sin(_2PI * (float)ii / (float)entries_num);
    }

    int max_range_val = (1 << (num_bits - 1)) - 1;

    int sin_lut[MAX_ENTRIES_NUM];
    for (int ii = 0; ii < entries_num; ii++)
    {
        sin_lut[ii] = (int)(sin_values[ii] * max_range_val);
    }
    if (argc == 2)
    {
        for (int ii = 0; ii < entries_num; ii++)
        {
            std::cout << sin_lut[ii] << std::endl;
        }
    }
    else if (*argv[IQ_INDC_ARGV_IDX] == 'c')
    {
        float cos_values[MAX_ENTRIES_NUM];
        for (int ii = 0; ii < entries_num; ii++)
        {
            cos_values[ii] = cos(_2PI * (float)ii / (float)entries_num);
        }

        int max_range_val = (1 << (num_bits - 1)) - 1;

        int cos_lut[MAX_ENTRIES_NUM];
        for (int ii = 0; ii < entries_num; ii++)
        {
            cos_lut[ii] = (int)(cos_values[ii] * max_range_val);
        }

        for (int ii = 0; ii < entries_num; ii++)
        {
            std::cout << sin_lut[ii] << '\t' << cos_lut[ii] << std::endl;
        }
    }
    else
    {
        gen_error(invalid_arg_iq);
        return 1;
    }

    return 0;
}

void gen_error(error err)
{
    switch (err)
    {
    case invalid_arg_num:
        std::cout << "There is not enough or more input argument!\n";
        break;

    case invalid_arg_values:
        std::cout << "Input Arguments have invalid values!\n";
        break;

    case invalid_arg_range:
        std::cout << "Input Arguments have invalid ranges!\n";
        break;

    case invalid_arg_iq:
        std::cout << "If there is third argument, it should be (c)!\n";
        break;

    default:
        break;
    }
}

bool isPositiveNumber(char number[])
{
    int i = 0;

    // checking for negative numbers
    if ((number[0] == '-') OR(number[0] == '0'))
        return false;
    for (; number[i] != 0; i++)
    {
        // if (number[i] > '9' || number[i] < '0')
        if (!isdigit(number[i]))
            return false;
    }
    return true;
}