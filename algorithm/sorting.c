#include <string.h>
#include <stdio.h>
#include <stdlib.h>
// #define NDEBUG
#include <assert.h>

void swap(int *a, int *b) // 交換兩個變數
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap1(int *a, int *b) // 交換兩個變數
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void swap2(int *a, int *b) // 交換兩個變數
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

/******************************************冒泡排序********************************************

                Bubble它重复地走访过要排序的数列，一次比较两个元素，如果他们的顺序错误就把他们交换过来。

**********************************************************************************************/

// 冒泡排序
void bubbleSort(int *arr, int len)
{
    int i, j;
    int flag = 0;                 // 标记当前是否有交换操作
    for (i = 0; i < len - 1; i++) // 外层循环控制排序轮数
    {
        flag = 0;                         // 每轮开始时将交换标记重置为 0
        for (j = 0; j < len - i - 1; j++) // 内层循环控制每轮排序的次数
        {
            if (arr[j] > arr[j + 1]) // 如果前一个元素大于后一个元素
            {
                /*
                                temp = arr[j]; // 交换两个元素的位置
                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                 */
                swap2(&arr[j], &arr[j + 1]);
                flag = 1; // 标记当前有交换操作
            }
        }
        if (flag == 0) // 如果当前轮次没有交换操作，说明已经排序完成，直接跳出循环
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

void selection_sort(int arr[], int len)
{
    int i, j;

    for (i = 0; i < len - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < len; j++) // 走訪未排序的元素
        {
            if (arr[j] < arr[min]) // 找到目前最小值
            {
                min = j; // 紀錄最小值
            }
        }
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
// 插入排序
void insertion_sort(int arr[], int len)
{
    int i, j, key;
    for (i = 1; i < len; i++) // 外层循环从第二个元素开始遍历，因为第一个元素默认为已排序
    {
        key = arr[i];                      // 记录当前要插入的元素
        j = i - 1;                         // 将 j 指向当前元素的前一个元素
        while ((j >= 0) && (arr[j] > key)) // 内层循环从当前元素的前一个元素开始遍历，向前查找合适的插入位置
        {
            arr[j + 1] = arr[j]; // 如果当前元素比要插入的元素大，将当前元素后移
            j--;                 // 继续向前查找
        }
        arr[j + 1] = key; // 找到插入位置，将要插入的元素插入到该位置
    }
}

/******************************************快速排序********************************************
        从数列中挑出一个元素，称为 "基准"（pivot）;
        重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。
        在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作；
        递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序；
**********************************************************************************************/

/**

递归实现快速排序
@param arr 待排序数组
@param start 起始下标
@param end 结束下标
*/
void quick_sort_recursive(int arr[], int start, int end)
{
    // 递归终止条件，如果起始下标大于等于结束下标，直接返回
    if (start >= end)
        return;
    // 选取最后一个元素作为中间值
    int mid = arr[end];
    // 定义左右两个指针
    int left = start, right = end - 1;
    // 当左指针小于右指针时进行循环
    while (left < right)
    {
        // 左指针向右移动，找到第一个大于中间值的元素
        while (arr[left] < mid && left < right)
            left++;
        // 右指针向左移动，找到第一个小于中间值的元素
        while (arr[right] >= mid && left < right)
            right--;
        // 交换左右指针所指向的元素
        swap(&arr[left], &arr[right]);
    }
    // 将中间值与左指针所指向的元素交换
    if (arr[left] >= arr[end])
        swap(&arr[left], &arr[end]);
    else
        left++;
    // 递归调用左右两部分进行排序
    if (left)
        quick_sort_recursive(arr, start, left - 1);
    quick_sort_recursive(arr, left + 1, end);
}

void quick_sort(int arr[], int len)
{
    quick_sort_recursive(arr, 0, len - 1);
}

void swapNum(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort2(int *num, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < len - i - 1; j++)
        {
            if (num[j] > num[j + 1])
            {
                swap(&num[j], &num[j + 1]);
                flag = 1;
            }

            if (flag == 0)
            {
                break;
            }
        }
    }
}

void selectionSort(int *num, int len)
{
    int min = 0;
    for (int i = 0; i < len - 1; i++)
    {
        min = i;
        for (int j = i; j < len; j++)
        {
            if (num[min] > num[j])
            {
                min = j;
            }
        }
        swag(&num[min], &num[i]);
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

    bubbleSort2(arr, len);

    printf("Array after sorting: ");
    for (i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}


