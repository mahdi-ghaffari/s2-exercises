#include <iostream>

using namespace std;

bool isPositiveNumber(char number[]);
bool isPrime(int num);


int main(int argc, char* argv[])
{
    char p_char, n_char;
    int  width{0}, height{0};

    argc--;
    if(argc==0)
    {
        p_char = 'X';
        n_char = '-';
        width  = 20;
        height = 10;
    }
    else if ((argc==4) && isPositiveNumber(argv[1]) && isPositiveNumber(argv[2]))
    {
        p_char = *argv[3];
        n_char = *argv[4];
        width  = atoi(argv[1]);
        height = atoi(argv[2]);
    }
    else
    {
        cout<<"error: Invalid Arguments!\n";
        return 1;
    }

    for(int h=1; h<height; h++)
    {
        for(int w=1; w<=width; w++)
        {
            int num{width*(h-1)+ w};

            if(isPrime(num))
            {
                cout<<p_char;
            }
            else{
                cout<<n_char;
            }
        }
        cout<<'\n';
    }
    return 0;
}


bool isPositiveNumber(char number[])
{
    int i = 0;

    // checking for negative numbers
    if ((number[0] == '-') || (number[0] == '0'))
        return false;
    for (; number[i] != 0; i++)
    {
        // if (number[i] > '9' || number[i] < '0')
        if (!isdigit(number[i]))
            return false;
    }
    return true;
}

bool isPrime(int num)
{
    if(num==1)
        return false;

    for (size_t i = 2; i < num; i++)
    {
        if(num%i == 0)
        {
            return false;
        }
    }
    return true;   
}