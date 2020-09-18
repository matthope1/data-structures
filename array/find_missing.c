#include <stdio.h>
#include <stdlib.h>

struct Array {
    int A[20];
    int size;
    int length;
};

void find_missing(struct Array arr)
{
    int sum = 0;
    int n = arr.A[arr.length - 1];
    int S = n * (n + 1) / 2;

    printf("sum: %d, n: %d S: %d\n", sum, n, S);

    for (int i = 0; i < arr.length; i ++)
        sum = sum + arr.A[i];

    printf("Missing no is %d\n", S - sum);

}

void find_m_missing(struct Array arr)
{
    int diff = arr.A[0];
    int currentDiff;

    for (int i = 0; i < arr.length; i ++)
    {
        currentDiff = arr.A[i] - i;
        if (currentDiff != diff)
        {
            while (diff < currentDiff)
            {
                printf("%d\n", i + diff);
                diff++;
            }
        }
    }

}

void find_missing2(struct Array arr, int low, int high)
{
    int *arr2;
    arr2 = (int *)malloc(sizeof(int) * high + sizeof(int));
    

    for (int i = 0; i < arr.length; i ++)
    {
        printf("inserting into position: %d, into new array.\n",arr.A[i]);
        arr2[arr.A[i]] ++;
    }
    printf("\n");

    for (int i = 1; i < high + 1; i ++)
    {
        if (arr2[i] == 0)
            printf("%d\n", i);
    }
}

void find_duplicates(struct Array arr)
{
    int last_dup = 0;
    for (int i = 0; i < arr.length - 1; i ++)
    {
        if (arr.A[i] == arr.A[i + 1] && arr.A[i] != last_dup)
        {
            printf("%d\n", arr.A[i]);
            last_dup = arr.A[i];
        }
    }
}


void find_duplicates2(struct Array arr)
{
   int j;
   for (int i = 0; i < arr.length; i++)
   {
       if (arr.A[i] == arr.A[i + 1])
       {
           j = i + 1;
           while (arr.A[j] == arr.A[i]) j ++;
           printf("%d is appearing %d times\n", arr.A[i], j - i);
           i = j - 1;

       }
   }
}

void find_duplicates_h(struct Array arr)
{
    int max = arr.A[arr.length - 1];
    int *h;
    h = (int *)malloc(sizeof(int) * max);

    for (int i = 0; i < arr.length; i ++)
    {
        h[arr.A[i]] ++;
    }

    for (int i = 0; i < max; i ++)
    {
        if (h[i] > 1)
            printf("%d %d\n", i , h[i]);
    }  
}

void find_duplicates_unsorted(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i ++)
    {
        if (arr.A[i] != -1)
        {
            int count = 1;
            for (int j = i + 1; j < arr.length; j ++)
            {
                if(arr.A[i] == arr.A[j])
                {
                    count ++;
                    arr.A[j] = -1;
                }
            }
            if (count > 1)
                printf("%d %d\n", arr.A[i], count);
        }
    }
}



void display(struct Array arr)
{
    for (int i = 0; i < arr.length; i ++)
    {
       printf("%d\n",arr.A[i]);
    }
    printf("\n");
}

int main()
{
    struct Array arr = {{1,2,3,4,6,7},20,6};
    struct Array arr2 = {{6,7,8,9,11,12,15,16,17,18,19},20,11};
    //find_missing(arr);
    struct Array arr3 = {{3,7,4,9,12,6,1,11,2,10}, 20, 10};
    //find_m_missing(arr2);
    
    struct Array arr4 = {{3,6,8,8,10,12,15,15,15,20}, 20, 10};

    struct Array arr5 = {{8,3,6,4,6,5,6,8,2,7}, 20, 10};

    find_duplicates_unsorted(arr4);


}






