#include <stdio.h>
#include <stdlib.h>


struct Array {

    int A[20];
    int size;
    int length;
};

// display append insert delete linear/binary search
// swap two ints function
// get set max reverse reverse2 right shift left shift rotate left rotate right
// check if array is sroted
// merge

void display(struct Array arr) {

    for (int i = 0; i < arr.length; i++) {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}


void append(struct Array *arr, int x) {

    if (arr->length < arr->size) {

        arr->A[arr->length] = x;
    }

    arr->length++;
}


void insert(struct Array *arr, int index, int x) {

    if (index > 0 && index <= arr->length) {
        for (int i = arr->length; i > index; i --) {
            arr->A[i] = arr->A[i - 1];
        }

        arr->A[index] = x;
        arr->length++;
    }
}

int delete(struct Array *arr, int index) {
    int deletedItem = -1;

    if (index > 0 && index <= arr->length) {
        for (int i = index; i < arr->length - 1; i ++) {
            arr->A[i] = arr->A[i + 1];
        }
    }
    arr->length--;

    return deletedItem;
}

int main() {
    // tests for
    //display append insert delete linear/binary search
    struct Array arr = {{2,3,4,5,6},20,5};
    // struct Array arr2 = {{2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20},20,19};
    // struct Array arr3 = {{1,7,8,9}},20,4};

    display(arr);
    append(&arr, 7);
    display(arr);

    insert(&arr, 2, 88);
    display(arr);

    delete(&arr, 2);
    display(arr);


    return 0;

}
