#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *a, int tSize, int uSize)
{
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));
}

void show(struct myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d ", (a->ptr)[i]);
    }
}

void setVal(struct myArray *a)
{
    int n;
    printf("Enter %d elements: ", a->used_size);
    for (int i = 0; i < a->used_size; i++)
    {
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}

void insertAtIndex(struct myArray *a, int index, int value)
{
    if (index < 0 || index > a->used_size)
    {
        printf("Invalid index for insertion.\n");
        return;
    }

    if (a->used_size == a->total_size)
    {
        printf("Array is full. Cannot insert.\n");
        return;
    }

    for (int i = a->used_size - 1; i >= index; i--)
    {
        (a->ptr)[i + 1] = (a->ptr)[i];
    }

    (a->ptr)[index] = value;
    a->used_size++;
}

void deleteAtIndex(struct myArray *a, int index)
{
    if (index < 0 || index >= a->used_size)
    {
        printf("Invalid index for deletion.\n");
        return;
    }

    for (int i = index; i < a->used_size - 1; i++)
    {
        (a->ptr)[i] = (a->ptr)[i + 1];
    }

    a->used_size--;
}

int search(struct myArray *a, int value)
{
    for (int i = 0; i < a->used_size; i++)
    {
        if ((a->ptr)[i] == value)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(struct myArray *a, int value)
{
    int left = 0;
    int right = a->used_size - 1;

    while (left <= right)
    {
        int mid = (left / 2.0) + (right / 2.0);

        if ((a->ptr)[mid] == value)
        {
            return mid;
        }
        else if ((a->ptr)[mid] < value)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

void bubbleSort(struct myArray *a)
{
    for (int i = 0; i < a->used_size - 1; i++)
    {
        for (int j = 0; j < a->used_size - 1 - i; j++)
        {
            if ((a->ptr)[j] > (a->ptr)[j + 1])
            {
                int temp = (a->ptr)[j];
                (a->ptr)[j] = (a->ptr)[j + 1];
                (a->ptr)[j + 1] = temp;
            }
        }
    }
}

struct myArray mergeArrays(struct myArray *arr1, struct myArray *arr2)
{
    struct myArray mergedArray;
    createArray(&mergedArray, arr1->total_size + arr2->total_size, arr1->used_size + arr2->used_size);

    int i, j, k;
    i = j = k = 0;

    while (i < arr1->used_size && j < arr2->used_size)
    {
        if ((arr1->ptr)[i] < (arr2->ptr)[j])
        {
            (mergedArray.ptr)[k++] = (arr1->ptr)[i++];
        }
        else
        {
            (mergedArray.ptr)[k++] = (arr2->ptr)[j++];
        }
    }

    while (i < arr1->used_size)
    {
        (mergedArray.ptr)[k++] = (arr1->ptr)[i++];
    }

    while (j < arr2->used_size)
    {
        (mergedArray.ptr)[k++] = (arr2->ptr)[j++];
    }

    mergedArray.used_size = arr1->used_size + arr2->used_size;
    return mergedArray;
}

void resizeArray(struct myArray *a, int newSize)
{
    int *newPtr = (int *)realloc(a->ptr, newSize * sizeof(int));
    if (newPtr == NULL)
    {
        printf("Memory reallocation failed.\n");
        return;
    }

    a->ptr = newPtr;
    a->total_size = newSize;
}

int main()
{
    struct myArray marks;
    createArray(&marks, 10, 4);
    setVal(&marks);

    printf("\nOriginal Array:\n");
    show(&marks);

    insertAtIndex(&marks, 2, 5);
    printf("\nArray after insertion:\n");
    show(&marks);

    deleteAtIndex(&marks, 1);
    printf("\nArray after deletion:\n");
    show(&marks);

    printf("\nArray before sorting:\n");
    show(&marks);
    bubbleSort(&marks);
    printf("\nArray after sorting:\n");
    show(&marks);

    int searchValue = 5;
    int searchResult = binarySearch(&marks, searchValue);
    if (searchResult != -1)
    {
        printf("\nValue %d found at index %d.\n", searchValue, searchResult);
    }
    else
    {
        printf("\nValue %d not found in the array.\n", searchValue);
    }

    struct myArray array1, array2;
    createArray(&array1, 10, 5);
    createArray(&array2, 10, 3);
    printf("\nArray 1:\n");
    setVal(&array1);
    printf("\nArray 2:\n");
    setVal(&array2);
    bubbleSort(&array1);
    bubbleSort(&array2);

    struct myArray mergedArray = mergeArrays(&array1, &array2);
    printf("\nMerged Array:\n");
    show(&mergedArray);

    int newSize = 15;
    resizeArray(&marks, newSize);
    printf("\nResized Array:\n");
    show(&marks);

    free(marks.ptr);
    free(array1.ptr);
    free(array2.ptr);
    free(mergedArray.ptr);

    return 0;
}
