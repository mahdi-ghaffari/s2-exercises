#include <iostream>
#include <vector>
#include <bits/stdc++.h>

enum err_t
{
    no_data_provide,
    invalid_data_arg
};

using namespace std;
bool is_number(char number[]);
void gen_err(err_t err);
void print_table(vector<int> values);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        gen_err(no_data_provide);
        return (-1);
    }

    vector<int> values;
    for (int arg = 1; arg < argc; arg++)
    {
        if (!is_number(argv[arg]))
        {
            gen_err(invalid_data_arg);
            return (-1);
        }

        values.push_back(atoi(argv[arg]));
    }

    print_table(values);

    return 0;
}

void print_table(vector<int> values)
{
    // find min and max
    int min_val{*min_element(values.begin(), values.end())};
    int max_val{*max_element(values.begin(), values.end())};

    if (min_val > 0)
    {
        min_val = 0;
    }
    if (max_val < 0)
    {
        max_val = 0;
    }

    cout << "^\n";

    for (int yy = max_val; yy >= min_val; yy--)
    {
        if (yy == 0)
            cout << "+  ";
        else
            cout << "|  ";

        for (int xx = 0; xx < values.size(); xx++)
        {
            if (yy == 0)
            {
                cout << '#';
                continue;
            }

            if (((values[xx] >= yy) && (yy > 0)) || ((values[xx] <= yy) && (yy < 0)))
                cout << '#';
            else
                cout << ' ';
        }
        cout << '\n';
    }

    cout << "v\n";
}

bool is_number(char number[])
{
    int i = 0;
    if (number[i] == 0)
        return false;

    if (number[i] == '-')
        i++;

    while (number[i] != 0)
    {
        if (!isdigit(number[i]))
            return false;

        i++;
    }

    return true;
}

void gen_err(err_t err)
{
    switch (err)
    {
    case no_data_provide:
        cout << "Please add data for drawing bar table!\n";
        break;

    case invalid_data_arg:
        cout << "Please only write integer argument!\n";
        break;
    default:
        break;
    }
}