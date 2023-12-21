// file: main2.c
// author: Noah Cabral
// Copyright 2023, Noah Cabral. All rights reserved.

#include <stdio.h>
#include <assert.h>

// PROBLEM DESCRIPTION:
// same as last but this time need to consider that
// one, two, three, four, five, six, seven, eight, and nine also count as valid "digits"

/*
one
two
three
four
five
six
seven
eight
nine

it looks like if we just go across and linearly compare, then fail,
there is no need to backtrack.

*/

int main()
{
    FILE *f = fopen("input.txt", "r");

    // NOTE: we're pulling out digits. they will never be negative.
    // hence, we are free to use -1 to indicate something special.
    int d1=-1;
    int d2=-1;
    int c;
    unsigned int s=0;

    #define WORD_COUNT 9

    static int match_limits[WORD_COUNT] = {2, 2, 4, 3, 3, 2, 4, 4, 3}; 
    static char *nums[WORD_COUNT] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}; 
    int matches[WORD_COUNT] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    // NOTE: we require that input.txt has a newline after the last line, then the EOF.
    // otherwise we won't catch the last line.
    while( (c=getc(f))!=EOF )
    {
        // NOTE: this program will only work with files where they are LF.
        if ( c=='\n' ) {
            d2 = (d2==-1)?d1:d2;
            printf("d1,d2 %d,%d\n", d1, d2);
            s += d1 * 10 + d2;
            d1=-1;
            d2=-1;
        }
        else if ( c >= '0' && c <='9' )
        {
            if ( d1!=-1 ) d2 = c-'0';
            else d1=c-'0'; 
        }

        for ( int i=0;i<WORD_COUNT;i++ )
        {
            char cc = nums[i][ matches[i] ];
            int m;
            if (cc == c) m=++matches[i];
            else m=(matches[i]= (c==nums[i][0])?1:0);
            if ( m==(match_limits[i]+1) ) {
                if ( d1!=-1 ) d2 = i+1;
                else d1=i+1;
            }
        }  
    }

    printf("sum: %d\n", s);
    fclose(f);
    return 0;
}