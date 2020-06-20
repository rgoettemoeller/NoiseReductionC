#include "dataStructure.h"

void fillTimeArray(values *ValuesElement, unsigned long long timeValue, short p)
{
    for(int i = 0; i < sizeof(ValuesElement->t); i++)
    {
        if(ValuesElement->t[i] == 0)
        {
            ValuesElement->t[i] = timeValue;
            ValuesElement->p = ((ValuesElement->p) << 1) | p;
            break;
        }
    }
}