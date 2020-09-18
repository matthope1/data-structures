#include <stdio.h>
#include <stdlib.h>


void perm(char s)
{
    
}


int main()
{
    char A[] = "findinggf";
    long int H = 0, x = 0;

    for (int i = 0; A[i] != '\0'; i ++)
    {
        x = 1;
        x = x << (A[i] - 97);

        if ((x & H) > 0)
        {
            printf("%c is duplicate\n", A[i]);
        }
        else 
        {
            H = (x | H);
        }
    }

}
