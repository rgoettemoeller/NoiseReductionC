#include <stdio.h>
#include <stdbool.h>

int main() {

    short num = 47;
    short temp = 0; //num >> 2;
    short newNum = 0;

//get binary from decimal number
    // for(int i = 0; i < 16; i++)
    // {
    //     int var = (num >> i) & 1;
    //     printf("%d ", var);
    // }
    // fill up the variable
    newNum = (newNum << 1) | 1;
    newNum = (newNum << 1) | 0;
    newNum = (newNum << 1) | 1;
    newNum = (newNum << 1) | 1;
    newNum = (newNum << 1) | 1;
    newNum = (newNum << 1) | 1;

    printf("%d\n", newNum);

short var = 0;

//get the 1s and 0s from the variable
    for(int i = 10; i >= 0; i--)
    {
        var = (newNum >> i) & 1;
        printf("%d ", var);
    }

   return 0;
}