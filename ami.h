#include <iostream>
#include "winsock2.h"

void AMIencode(int *dataout, int dataSize, int datain[])
{
    int prev;
    int dataout[0] = 5; // +5 Volts

    prev = dataout[0];

    for(int i=1; i<dataSize;i++)
    {
        if(datain[i] == 1)
        {
            dataout[i] = prev*(-1); // Inversão de sinal +5V/-5V
            prev = dataout[i];
        }
        else
        {
            dataout[i] = 0; // Sinal 0V
        }
    }
}

void AMIdecode(int *dataout, int dataSize, int datain[])
{
    for(int i=0;i<dataSize;i++)
    {
        if(datain[i] == 5 || datain[i] == -5)
        {
            dataout[i] = 1; // +5V ou -5V
        }
        else
        {
            dataout[i] = 0; // 0V
        }
    }
}
