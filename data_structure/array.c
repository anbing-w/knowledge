#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// #define __FIND_COMMON_CHAR__

/**********************************************************************************************
 * 给定一个整数数组nums，找到一个具有最大和的连续子数组(最少包含一个元素)，返回其最大和
 ***********************************************************************************************/
int maxSubArray1(int *nums, int numSize)
{
    int i;
    int j;
    int Max = nums[0];
    int Tmp;
    for (i = 0; i < numSize; i++)
    {
        Tmp = 0;
        for (j = i; j < numSize; j++)
        {
            Tmp += nums[j];
            if (Tmp > Max)
            {
                Max = Tmp;
            }
        }
    }
    return Max;
}

#define MAX1(a, b, c) (((a) > (b) ? (a) : (b)) > (c) ? ((a) > (b) ? (a) : (b)) : (c))
#define MAX2(a, b, c) (((a) > ((b) > (c) ? (b) : (c))) ? (a) : ((b) > (c) ? (b) : (c)))

/**
 * @brief 分治法求解
 *
 * @param nums
 * @param numSize
 * @return int
 */
int maxSubArray2(int *nums, int numSize)
{
    int i = 0;
    int iTmp = 0;
    int MAX_Left = 0;
    int MAX_Right = 0;
    int MAX_l = 0;
    int MAX_r = 0;
    if ((0 == numSize) || (1 == numSize))
    {
        return nums[0];
    }
    else
    {
        MAX_Left = maxSubArray2(&nums[0], (numSize - 1) / 2);
        MAX_Right = maxSubArray2(&nums[(numSize + 1) / 2], numSize / 2);
    }
}

/**
 * @brief 移除满足条件的元素
 *
 * @param num
 * @param numSize
 * @param val
 * @return int
 */
int removeElement(int *num, int *numSize, int val)
{
    int count = 0;
    int *p = num;
    int size = *numSize;
    for (int i = 0; i < size; i++)
    {
        if (p[i] != val)
        {
            *num = p[i];
            num++;
            count++;
        }
    }
    *numSize = count; // 移除指定元素后数组的新长度
    return count;
}

// 移除数组中的指定元素
void removeElement2(int arr[], int *size, int element)
{
    int i, j;
    int newSize = *size;

    for (i = 0; i < newSize; i++)
    {
        if (arr[i] == element)
        {
            // 将后面的元素向前移动一个位置
            for (j = i; j < newSize - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            newSize--; // 数组长度减一
            i--;       // 重新检查当前位置的元素
        }
    }

    *size = newSize; // 更新数组的大小
}

#ifdef __FIND_COMMON_CHAR__
/**
 * @brief给你一个字符串数组 words ，请你找出所有在 words 的每个字符串中都出现的共用字符
 * （ 包括重复字符），并以数组形式返回。你可以按 任意顺序 返回答案。
 * @param A
 * @param Asize
 * @param returnsize
 * @return char**
 */
char **commonChars(char **A, int Asize, int *returnsize)
{
    if ((A == NULL) || (Asize == 0))
    {
        (*returnsize) = 0;
        return NULL;
    }

    // 创建二维数组 res，用于记录每个字符出现的次数
    int res[100][26] = {0}; // 每个单词占一行

    // 创建结果数组 rslt
    char **rslt = (char **)malloc(sizeof(char *) * 100);

    int i, j;
    for (i = 0; i < 100; i++)
    {
        // 为结果数组中的每个元素分配内存
        rslt[i] = (char *)malloc(sizeof(char) * 26);
    }

    // 遍历字符串数组 A，统计每个字符出现的次数
    for (i = 0; i < Asize; i++)
    {
        for (j = 0; j < strlen(A[i]); j++)
        {
            res[i][A[i][j] - 'a']++;
        }
    }

    int idx = 0;
    // 依次比较每个单词中字符出现的次数，找到共用字符
    for (i = 0; i < 26; i++)
    {
        int min = res[0][i];
        for (j = 1; j < Asize; j++)
        {
            if (res[j][i] < min)
            {
                min = res[j][i];
            }
        }
        // 将共用字符重复添加到结果数组中
        while (min > 0)
        {
            rslt[idx][0] = i + 'a';
            rslt[idx][1] = '\0';
            idx++;
            min--;
        }
    }

    // 更新返回结果的大小
    *returnsize = idx;

    // 返回共用字符的数组
    return rslt;
}

void printResult(char **result, int size)
{
    if (result == NULL || size == 0)
    {
        printf("No common characters.\n");
        return;
    }

    printf("Common characters: ");
    for (int i = 0; i < size; i++)
    {
        printf("%s ", result[i]);
    }
    printf("\n");
}

void freeResult(char **result, int size)
{
    if (result == NULL || size == 0)
    {
        return;
    }

    for (int i = 0; i < size; i++)
    {
        free(result[i]);
    }
    free(result);
}

int main()
{
    char *words1[] = {"bella", "label", "roller"};
    int size1 = sizeof(words1) / sizeof(words1[0]);
    int returnSize1 = 0;
    char **result1 = commonChars(words1, size1, &returnSize1);
    printf("Test Case 1:\n");
    printResult(result1, returnSize1);
    freeResult(result1, returnSize1);
    printf("\n");

    char *words2[] = {"cool", "lock", "cook"};
    int size2 = sizeof(words2) / sizeof(words2[0]);
    int returnSize2 = 0;
    char **result2 = commonChars(words2, size2, &returnSize2);
    printf("Test Case 2:\n");
    printResult(result2, returnSize2);
    freeResult(result2, returnSize2);
    printf("\n");

    // 添加更多测试用例...

    return 0;
}

#endif // __FIND_COMMON_CHAR__

/**
 * @brief 找到数组中缺失的元素
 * 求和相减获得缺失的元素
 * @param num
 * @param numSize
 * @return int
 */
int findMissingNumber1(int *num, int numSize)
{
    /*
        int max = 0, sum1 = 0, sum2 = 0;
        for (int i = 0; i < numSize; i++)
        {
            if (num[i] > max)
            {
                max = num[i];
            }
            sum1 += num[i];
        }
        for (int j = 0; j <= max; j++)
        {
            sum2 += j;
        }
        int nmissingNum = sum2 - sum1;
        return nmissingNum;
    */
    int sum = 0;
    for (int i = 0; i < numSize; i++)
    {
        sum += num[i];
    }
    return numSize * (numSize + 1) / 2 - sum;
}

int findMissingNumber2(int *num, int numSize)
{
    int res = numSize;
    for (int i = 0; i < numSize; i++)
    {
        res ^= num[i];
        res ^= i;
    }
    return res;
}

/**
 * @brief 使用Hash表进行查找遗漏的元素
 *
 * @param num
 * @param numSize
 * @return int
 */
int findMissingNumber3(int *num, int numSize)
{
    int hash[500000] = {0};
    for (int i = 0; i < numSize; i++)
    {
        hash[num[i]]++;
    }
    int sum;
    for (int i = 0; i < 50000; i++)
    {
        if (hash[i] == 0)
        {
            // printf("%d\t", i);
            return i;
        }
    }
    return -1;
}

#ifdef __PARITY_SORT__

/**
 * @brief 按照奇偶排序数组
 *
 * @param A
 * @param Asize
 * @return int*
 */
int *sortArrayByParity(int *A, int Asize)
{
    // *returnSize = Asize;
    if (Asize < 2)
    {
        return A;
    }
    int *arr = (int *)malloc(sizeof(int) * Asize);
    int head = 0, tail = Asize - 1;
    for (int i = 0; i < Asize; i++)
    {
        if (A[i] % 2 == 0)
        {
            arr[head++] = A[i];
        }
        else
        {
            arr[tail--] = A[i];
        }
    }
    return arr;
}
int main()
{
    // 测试用例1
    int A1[] = {1, 2, 3, 4, 5, 6};
    int Asize1 = sizeof(A1) / sizeof(A1[0]);
    int *result1 = sortArrayByParity(A1, Asize1);
    printf("Test Case 1:\nOriginal Array: ");
    for (int i = 0; i < Asize1; i++)
    {
        printf("%d ", A1[i]);
    }
    printf("\nSorted Array: ");
    for (int i = 0; i < Asize1; i++)
    {
        printf("%d ", result1[i]);
    }
    printf("\n\n");
    free(result1);

    return 0;
}
#endif // __PARITY_SORT__

#ifdef __DUPLICATE__ELEMENT__INDEX

typedef struct node_t
{
    int value;
    int index;
} node;

int cmp(void *a, void *b)
{
    if ((((node *)a)->value) < (((node *)b)->value))
    {
        return -1;
    }
    else if ((((node *)a)->value) == (((node *)b)->value))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/**
 * @brief 给定一个整数数组和一个整数k，判断数组中是否存在两个不同的索引i和j，使得nums[i] = nums[j]
 * 并且|i - j| <= k
 * @param nums
 * @param numSize
 * @param k
 * @return true
 * @return false
 */
bool containsNearbyDuplicates(int *nums, int numSize, int k)
{
    node array[100000];
    int i, j;
    for (i = 0; i < numSize; i++)
    {
        array[i].value = nums[i];
        array[i].index = i;
    }
    qsort(array, numSize, sizeof(node), cmp);
    for (i = 0; i < numSize - 1; i++)
    {
        for (j = i + 1; i < numSize; i++)
        {
            if (array[i].value == array[j].value)
            {
                if (array[j].index - array[i].index <= k)
                {
                    return true;
                }
            }
            else
            {
                break; // 已经从小到大排序过了，相邻的元素不相等的话，就直接比较下个元素就行
            }
        }
    }
    return false;
}

#endif // __DUPLIELEMINDEX

/**
 * @brief 找到数组中唯一超过25%的元素
 *HASH TABLE
 * @param arr
 * @param arrSize
 * @return int
 */
int findSpecialInteger1(int *arr, int arrSize)
{
    if (arrSize < 4)
    {
        return -1;
    }
    int flag[100000] = {0};
    for (int i = 0; i < arrSize; i++)
    {
        flag[arr[i]]++;
    }
    int cnt = arrSize * 0.25;
    for (int i = 0; i < 100000; i++)
    {
        if (cnt < flag[i])
        {
            return i;
        }
    }
    return -1;
}

/**
 * @brief 找到数组中唯一超过25%的元素
 * 元素+1/4还是等于本身
 * @param arr
 * @param arSize
 * @return int
 */
int findSpecialInteger2(int *arr, int arrSize)
{
    if (arrSize < 4)
    {
        return -1;
    }
    int threshold = arrSize / 4;
    for (int i = 0; i < arrSize - threshold; i++)
    {
        if (arr[i] == arr[i + threshold])
        {
            return arr[i];
        }
    }
    return -1;
}

int maxMountain(int *A, int Asize)
{
    int i = 0, index = 0, max = A[0];
    for (i = 0; i < Asize; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
            index = i;
        }
    }
    return index;
}

bool isValidMountain1(int *A, int Asize)
{
    if (Asize < 3)
    {
        return false;
    }
    int i = 0, re = 0;
    bool ans = true;
    re = maxMountain(A, Asize);
    if (re == 0 || re == Asize - 1)
    {
        return 0;
    }
    for (i = 0; i < re; i++)
    {
        if (A[i] >= A[i + 1])
        {
            ans = false;
            break;
        }
    }
    for (i = re; i < Asize - 1; i++)
    {
        if (A[i] <= A[i + 1])
        {
            ans = false;
            break;
        }
    }
    return ans;
}

/**
 * @brief 上山步数和下山步数相加等于总长度-1
 *
 * @param A
 * @param ASize
 * @return true
 * @return false
 */
bool isValidMountain2(int *A, int ASize)
{
    if (ASize < 3)
    {
        return false;
    }
    int inc = 0;
    int dec = 0;
    for (int i = 0; i < ASize - 1; i++)
    {
        if (A[i] < A[i + 1] && dec == 0)
        {
            inc++;
        }
        else if (A[i] > A[i + 1] && inc > 0)
        {
            dec++;
        }
    }
    if ((inc + dec == ASize - 1) && (inc > 0 && inc < ASize - 1) && (dec > 0 && dec < ASize - 1))
    {
        return true;
    }
    return false;
}

/**
 * @brief 一个未排序的数组，找到最长且连续的递增序列，并返回该序列的长度
 *
 * @param num
 * @param numSize
 * @return int
 */
int findLengthOfLCIS1(int *num, int numSize)
{
    if (numSize == 0)
    {
        return 0;
    }
    if (numSize == 1)
    {
        return 1;
    }
    int length = 1;
    int max = 1;
    for (int i = 0; i < numSize - 1; i++)
    {
        if (num[i] < num[i + 1])
        {
            length++;
        }
        else
        {
            length = 1;
        }
        if (length > max)
        {
            max = length;
        }
    }
    return max;
}

#define MAX(a, b) ((a) > (b) ? (a) : (b))
/**
 * @brief 使用滑动窗口法，找到最长且连续的递增序列，并返回该序列的长度
 *
 * @param num
 * @param numSize
 * @return int
 */
int findLengthOfLCIS2(int *num, int numSize)
{
    int start = 0, end = 1;
    int max_len = 1;
    if (num == NULL || numSize == 0)
    {
        return 0;
    }
    while (end < numSize)
    {
        if (num[end - 1] >= num[end])
        {
            start = end;
        }
        max_len = MAX(max_len, end - start + 1);
        end++;
    }
    return max_len;
}

int main()
{
    int num[] = {1, 2, 3, 2};
    int arrSize = sizeof(num) / sizeof(int);
    int len1 = findLengthOfLCIS1(num, arrSize);
    int len2 = findLengthOfLCIS2(num, arrSize);
    printf("len1 = %d, len2 = %d\n", len1, len2);

    return 0;
}


