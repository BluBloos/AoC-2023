// file: main.c
// author: Noah Cabral
// Copyright 2023, Noah Cabral. All rights reserved.

#include <stdio.h>
#include <assert.h>

// PROBLEM DESCRIPTION:
// combine the first and last digit to create a single two digit number.
// we want to get the sum of all the calibration values.

int main()
{
    FILE *f = fopen("input.txt", "r");

    // NOTE: we're pulling out digits. they will never be negative.
    // hence, we are free to use -1 to indicate something special.
    int d1=-1;
    int d2=-1;
    int c;
    unsigned int s=0;

    // NOTE: we require that input.txt has a newline after the last line, then the EOF.
    // otherwise we won't catch the last line.
    while( (c=getc(f))!=EOF )
    {
        // NOTE: this program will only work with files where they are LF.
        if ( c=='\n' ) {
            d2 = (d2==-1)?d1:d2;
            s += d1 * 10 + d2;
            d1=-1;
            d2=-1;
        }
        else if ( c >= '0' && c <='9' )
        {
            if ( d1!=-1 ) d2 = c-'0';
            else d1=c-'0'; 
        }   
    }

    printf("sum: %d\n", s);
    fclose(f);
    return 0;
}