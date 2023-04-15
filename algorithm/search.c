#include <string.h>
#include <stdio.h>
#include <stdlib.h>
// #define NDEBUG
#include <assert.h>

/********************************************普通查找********************************************
                顺序查找适合于存储结构为顺序存储或链接存储的线性表，时间复杂度为O(n)
************************************************************************************************/
int find_normal(const int *num, int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (num[i] == target)
        {
            return i;
        }
    }
    return -1;
}

/********************************************二分查找********************************************
                    元素必须是有序的，如果是无序的则要先进行排序操作,查找数量只能为一个
                    关键词比较次数为log2(n+1)，且期望时间复杂度为O(log2n)；
************************************************************************************************/
/**
 * @brief 左闭右闭区间[left,right]
 *
 * @param num 数组
 * @param size 数组大小
 * @param target 需要查找的值
 * @return int
 */
int binarySearch1(int num[], int size, int target)
{
    int left = 0;
    int right = size - 1; // 定义了target在左闭右闭的区间内，[left, right]
    while (left <= right) // 必须写=否则可能会漏查找
    {
        int mid = left + ((right - left) / 2); // 等同于 (left + right) / 2，防止溢出.()优先级高，先算其中的有溢出的风险

        if (num[mid] > target)
        {
            right = mid - 1; // target在左区间，所以[left, mid - 1]
        }
        else if (num[mid] < target)
        {
            left = mid + 1; // target在右区间，所以[mid + 1, right]
        }
        else
        {
            return mid; // 既不在左边，也不在右边，那就是找到答案了
        }
    }
    return -1;
}

/**
 * @brief 左闭右开区间[left,right)
 *
 * @param num 数组
 * @param size 数组大小
 * @param target 查找目标
 * @return int 返回值
 */
int binarySearch2(int num[], int size, int target)
{
    int left = 0;
    int right = size - 2; //??这样不可以吗

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (num[mid] > target)
        {
            right = mid - 1;
        }
        else if (num[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

/**
 * @brief 左闭右开区间[left,right)
 *
 * @param num 数组
 * @param size 数组大小
 * @param target 查找目标
 * @return int 返回值
 */
int binarySearch3(int num[], int size, int target)
{
    int left = 0;
    int right = size; // 定义target在左闭右开的区间里，即[left, right)

    while (left < right) // 因为left = right的时候，在[left, right)区间上无意义
    {
        int mid = left + (right - left) / 2;
        if (num[mid] > target)
        {
            right = mid; // target 在左区间，在[left, middle)中
        }
        else if (num[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

/********************************************插值查找********************************************
                    元素必须是有序的，如果是无序的则要先进行排序操作,查找数量只能为一个
                    基于二分查找算法，将查找点的选择改进为自适应选择，可以提高查找效率。
                    查找成功或者失败的时间复杂度均为O(log2(log2n))。
    只需要修改一行代码mid = left + (target - num[left])/(num[right]-num[left])*(right-left);
************************************************************************************************/
int insertSearch(int num[], int size, int target)
{
    int left = 0, right = size - 1;
    while ((left <= right) && (num[left] <= target) && (num[right] >= target))
    {
        int mid = left + (target - num[left]) / (num[right] - num[left]) * (right - left);
        if (target < num[mid])
        {
            right = mid - 1;
        }
        else if (target > num[mid])
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

/******************************************斐波那契查找******************************************
                    元素必须是有序的，如果是无序的则要先进行排序操作,查找数量只能为一个
                    基于二分查找算法，将查找点的选择改进为自适应选择，可以提高查找效率。
                    时间复杂度为O(log2n)，且其期望复杂度也为O(log2n)。
            斐波那契数列：1, 1, 2, 3, 5, 8…….（从第三个数开始，后边每一个数都是前两个数的和）。
                        随着斐波那契数列的递增，前后两个数的比值会越来越接近0.618
************************************************************************************************/

//这个算法存在问题
int fibonacciSearch(int arr[], int size, int target) {
    // 定义斐波那契数列
    int fib1 = 0;
    int fib2 = 1;
    int fib = fib1 + fib2;

    // 找到大于等于数组长度的最小斐波那契数
    while (fib < size) {
        fib1 = fib2;
        fib2 = fib;
        fib = fib1 + fib2;
    }

    // 特判：目标值等于数组的第一个数值
    if (arr[0] == target) {
        return 0;
    }

    // 定义左右边界
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + fib1 - 1;
        if (mid > right) {
            mid = right;
        }
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
            fib = fib2;
            fib2 = fib1;
            fib1 = fib - fib2;
        } else {
            right = mid - 1;
            fib = fib1 - fib2;
            fib2 = fib1;
            fib1 = fib - fib2;
        }
    }
    return -1;
}


#define MAXN 20

void Fibonacci(int *f)
{
    int i;
    f[0] = 1;
    f[1] = 1;
    for (i = 2; i < MAXN; ++i)
        f[i] = f[i - 2] + f[i - 1];
}

/*
* 查找
* */
int Fibonacci_Search(int *a, int key, int n)
{
    int i, low = 0, high = n - 1;
    int mid = 0;
    int k = 0;
    int F[MAXN];
    Fibonacci(F);
    while (n > F[k] - 1)          //计算出n在斐波那契中的数列  
        ++k;
    for (i = n; i < F[k] - 1; ++i) //把数组补全  
        a[i] = a[high];
    while (low <= high)
    {
        mid = low + F[k - 1] - 1;  //根据斐波那契数列进行黄金分割  
        if (a[mid] > key)
        {
            high = mid - 1;
            k = k - 1;
        }
        else if (a[mid] < key)
        {
            low = mid + 1;
            k = k - 2;
        }
        else
        {
            if (mid <= high) //如果为真则找到相应的位置  
                return mid;
            else
                return -1;
        }
    }
    return 0;
}


/******************************************二叉树查找********************************************
                1）若任意节点的左子树不空，则左子树上所有结点的值均小于它的根结点的值；
                2）若任意节点的右子树不空，则右子树上所有结点的值均大于它的根结点的值；
                3）任意节点的左、右子树也分别为二叉查找树。
                插入和查找的时间复杂度均为O(logn)，但是在最坏的情况下仍然会有O(n)的时间复杂度。
************************************************************************************************/
int main()
{
    int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int result = fibonacciSearch(arr, size, target);

    if (result == -1)
    {
        printf("dest %d\n", target);
    }
    else
    {
        printf("dest %d in arry %d\n", target, result);
    }
    return 0;
}

