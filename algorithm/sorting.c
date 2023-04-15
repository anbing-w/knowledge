#include <string.h>
#include <stdio.h>
#include <stdlib.h>
// #define NDEBUG
#include <assert.h>

/******************************************冒泡排序********************************************

                Bubble它重复地走访过要排序的数列，一次比较两个元素，如果他们的顺序错误就把他们交换过来。

**********************************************************************************************/

void bubbleSort(int *arr, int len)
{
    int i, j, temp;
    int flag = 0;
    for (i = 0; i < len - 1; i++)
    {
        flag = 0;
        for (j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

/******************************************选择排序********************************************
            O(n²) 的时间复杂度
            首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置。
            再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。
            重复第二步，直到所有元素均排序完毕。
**********************************************************************************************/
void swap(int *a, int *b) // 交換兩個變數
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selection_sort(int arr[], int len)
{
    int i, j;

    for (i = 0; i < len - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < len; j++) // 走訪未排序的元素
            if (arr[j] < arr[min])    // 找到目前最小值
                min = j;              // 紀錄最小值
        if (min != i)
        {
            swap(&arr[min], &arr[i]); // 做交換
        }
    }
}

/******************************************插入排序********************************************
        将第一待排序序列第一个元素看做一个有序序列，把第二个元素到最后一个元素当成是未排序序列。
        从头到尾依次扫描未排序序列，将扫描到的每个元素插入有序序列的适当位置。
        （如果待插入的元素与有序序列中的某个元素相等，则将待插入元素插入到相等元素的后面。
**********************************************************************************************/
void insertion_sort(int arr[], int len)
{
    int i, j, key;
    for (i = 1; i < len; i++)
    {
        key = arr[i];
        j = i - 1;
        while ((j >= 0) && (arr[j] > key))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


int main()
{
    int arr[] = {5, 2, 8, 3, 1, 9, 4, 6, 7};
    int len = sizeof(arr) / sizeof(int);
    int i;

    printf("Array before sorting: ");
    for (i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    selection_sort(arr, len);

    printf("Array after sorting: ");
    for (i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

