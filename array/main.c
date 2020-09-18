#include <stdio.h>
#include <stdlib.h>


struct Array {

    int A[20];
    int size;
    int length;
};

void display(struct Array arr)
{
    for (int i = 0; i < arr.length; i ++)
    {
        printf("%d ",arr.A[i]);
    }
    printf("\n");

}

void stats(struct Array arr)
{
    printf("size: %d\n",arr.size);
    printf("length: %d \n", arr.length);
}

void append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length] = x;
    }
    arr->length ++;
}

void insert(struct Array *arr, int index, int x)
{
    if (index >= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i --)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length ++;
    }

    else
    {
        printf("index invalid, could not insert");
    }
}


int delete(struct Array *arr, int index)
{

    int x = -100;
    if (index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for (int i = index; i < arr->length - 1; i ++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length --;
    }


    return x;
}

int linearSearch(struct Array *arr, int key)
{
    int found = -1;

    for (int i = 0; i < arr->length; i ++)
    {
        if (arr->A[i] == key)
        {
            found = i;
            break;
        }
    }

    return found;
}

int binarySearch(struct Array *arr, int key)
{

    int left = 0;
    int right = arr->length - 1;
    int mid;

    while (left <= right)
    {
        mid = (left + right) / 2;

        if (arr->A[mid] == key)
        {
            return mid;
        }

        else if (arr->A[mid] > key)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return -1;
}

int rBinarySearch(int arr[], int left, int right, int key)
{
    int mid;

    if (left < right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if(arr[mid] > key)
        {
            return rBinarySearch(arr, left, mid - 1, key);
        }
        else
        {
            return rBinarySearch(arr, left + 1, mid, key);
        }
    }

    return - 1;
}

int get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
    {
        return arr.A[index];
    }

    return - 1;
}

void set(struct Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = x;
    }


}

int max(struct Array arr)
{
    int max = arr.A[0];

    for (int i = 1; i < arr.length; i ++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }

    return max;
}

int min(struct Array arr)
{
    int min = arr.A[0];

    for (int i = 1; i < arr.length; i ++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }

    return min;

}
void swap (int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}



void reverse(struct Array *arr)
{
    int *b;
    int i, j;

    b = (int *)malloc(arr->length * sizeof(int));

    for (i = arr->length -1,j = 0; i >= 0; i--, j++)
    {
        b[j] = arr->A[i];
    }

    for (i = 0; i < arr->length; i ++)
    {
        arr->A[i] = b[i];
    }


}

void reverse2(struct Array *arr)
{
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        swap(&arr->A[i],&arr->A[j]);
    }
}

// not sure if these work right
void leftShift(struct Array *arr)
{
    for (int i = 0; i < arr->length - 1; i ++)
    {
        arr->A[i] = arr->A[i + 1];
    }
    arr->A[arr->length - 1] = 0;
    arr->length --;
}

void rightShift(struct Array *arr)
{
    for (int i = arr->length - 1; i > 0; i --)
    {
        arr->A[i] = arr->A[i - 1];
    }

    arr->A[0] = 0;
    arr->length --;

}

struct Array * merge(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3;
    arr3  = (struct Array *)malloc(sizeof(struct Array));

    int i, j, k;
    i = j = k = 0;

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else
        {
            arr3->A[k++] = arr2->A[j++];
        }
    }

    for(; i < arr1->length; i ++)
        arr3->A[k++] = arr1->A[i];
    for(; j < arr2->length; j ++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;
    arr3->size = arr1->size + arr2->size;

    return arr3;
}

int main()
{

    struct Array arr = {{2,3,4,5,6},20,5};
    struct Array arr2 = {{2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20},20,19};


    display(arr);
    stats(arr);
    append(&arr, 10);

    display(arr);
    stats(arr);

    insert(&arr,1,25);
    display(arr);
    stats(arr);

    int x = delete(&arr,1);
    printf("%d\n",x);
    display(arr);
    stats(arr);

    int y = linearSearch(&arr,10);
    printf("%d\n",y);

    int h = linearSearch(&arr,11);
    printf("%d\n", h);

    printf("binsearch");
    int q = binarySearch(&arr, 10);
    printf("%d\n",q);

    int w = binarySearch(&arr, 11);
    printf("%d\n",w);

    int r = rBinarySearch(arr.A, 0, arr.length - 1, 4);
    printf("%d\n",r);

    printf("\n");

    //get set max

    printf("%d\n",get(arr,2));
    set(&arr,2,30);
    display(arr);

    printf("%d\n",max(arr));
    printf("%d\n",min(arr));


    return 0;
}
