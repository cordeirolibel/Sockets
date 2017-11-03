#include <iostream>
#include <string>

using namespace std;

string ascii_to_bin(string data)
{
    string mensagemBin;
    int n, r;
    for(int i=0;i<(int)data.length();i++)
    {
        for(int j=7; j>= 0; j--)
        {
            n = (int)data[i];

            r = n >> j;

            if(r&1)
            {
                mensagemBin += '1';
            }
            else
            {
                mensagemBin += '0';
            }
        }
    }

    return mensagemBin;
}

string bin_to_ami(string data)
{
    string ami;
    char prev = '-';


    for(int i=0; i<(int)data.length();i++)
    {
        if(data[i] == '1')
        {
            if(prev == '-')
            {
                ami += '+';
                prev = '+';
            }
            else
            {
                ami += '-';
                prev = '-';
            }
        }
        else
        {
            ami += '0';
        }
    }


    return ami;
}

string ami_to_bin(string data)
{
    string bin;

    for(int i=0;i<(int)data.length();i++)
    {
        if(data[i] == '+' || data[i] == '-')
        {
            bin += '1';
        }
        else
        {
            bin += '0';
        }
    }

    return bin;
}

string bin_to_ascii(string data)
{
    string ascii;
    string binChar;
    int pos = 0, decChar=0, pot2 = 128;

    for(int i=0;i<=(int)data.length();i++)
    {
            if(data[i] == '1')
            {
                decChar += pot2;
                pot2 = pot2/2;
                pos++;
                if(pos == 8)
                {
                    ascii += char(decChar);
                    decChar = 0;
                    pot2 = 128;
                    pos = 0;
                }
            }
            else
            {
                pot2 = pot2/2;
                pos++;
                if(pos == 8)
                {
                    ascii += char(decChar);
                    decChar = 0;
                    pot2 = 128;
                    pos = 0;
                }
            }
    }

    return ascii;
}
