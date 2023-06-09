#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

/**
 * @brief 括号匹配，使用switch语句
 *
 * @param str
 * @return true
 * @return false
 */
bool isValid1(char *str)
{
    if (str == NULL)
    {
        return false;
    }

    int len = strlen(str);
    int top = 0;
    char stack[len];

    for (int i = 0; i < len; i++)
    {
        char ch = str[i];
        switch (ch)
        {
        case '(':
        case '[':
        case '{':
            stack[top++] = ch;
            break;
        case ')':
            if (top == 0 || stack[--top] != '(')
            {
                return false;
            }
            break;
        case ']':
            if (top == 0 || stack[--top] != '[')
            {
                return false;
            }
            break;
        case '}':
            if (top == 0 || stack[--top] != '{')
            {
                return false;
            }
            break;
        default:
            break;
        }
    }
    return true;
}

bool isValid2(const char *str)
{
    int len = strlen(str);
    int top = -1;
    char stack[len];

    for (int i = 0; i < len; i++)
    {
        if ((str[i] == '(') || (str[i] == '[') || (str[i] == '{'))
        {
            stack[++top] = str[i];
        }
        else
        {
            // 如果加的话，左括号出现前，如果有字符就会报错
            //  if (top < 0)
            //  {
            //      return false;
            //  }

            if (str[i] == ')')
            {
                if (stack[top] != '(')
                {
                    return false;
                }
                else
                {
                    top--;
                }
            }

            if (str[i] == ']')
            {
                if (stack[top] != '[')
                {
                    return false;
                }
                else
                {
                    top--;
                }
            }

            if (str[i] == '}')
            {
                if (stack[top] != '{')
                {
                    return false;
                }
                else
                {
                    top--;
                }
            }
        }
    }
    return true;
}

/**
 * @brief 给定两个字符串的非负整数num1和num2，计算他们的和
 * ？？？？？？？？？？？？？不是太理解呀？？？？？？？？？？？？
 * @param num1
 * @param num2
 * @return char*
 */
char *addStrings2(char *num1, char *num2)
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    // 创建结果字符串的数组，并初始化为0
    int maxSize = len1 > len2 ? len1 + 2 : len2 + 2;
    char *result = (char *)malloc(sizeof(char) * maxSize);
    // memset(result, '0', maxSize);
    result[maxSize - 1] = '\0';

    int carry = 0; // 进位标志

    // 从后往前逐位相加
    for (int i = len1 - 1, j = len2 - 1, k = maxSize - 2; i >= 0 || j >= 0; i--, j--, k--)
    {
        int sum = carry;

        if (i >= 0)
        {
            sum += num1[i] - '0';
        }
        if (j >= 0)
        {
            sum += num2[j] - '0';
        }

        result[k] = sum % 10 + '0'; // 当前位的结果
        carry = sum / 10;           // 进位

        // 如果计算完最高位还有进位，则在结果字符串前面添加一个字符
        // if (carry && k == 0)
        // {
        //     memmove(result + 1, result, maxSize);
        //     result[0] = carry + '0';
        // }
    }
    if (carry == 0)
    {
        return result + 1;
    }
    else
    {
        result[0] = carry + '0';
    }
    // printf("result[0] = %c\n", result[0]);
    // printf("result[1] = %c\n", result[1]);
    return result;
}

/**
 * @brief 输入两个二进制字符串，返回他们的和(二进制表示)
 *
 * @param a
 * @param b
 * @return char*
 */
char *addBinary(char *a, char *b)
{
    int carry = 0;                                                        // 进位
    int length = (strlen(a) > strlen(b) ? strlen(a) + 2 : strlen(b) + 2); //
    char *result = (char *)malloc(length * sizeof(char));
    result[length - 1] = '\0'; //
    // 多开辟两个空间，一个存储进位，一个存储结束符
    for (int i = strlen(a) - 1, j = strlen(b) - 1, k = length - 2; (i >= 0) || (j >= 0); i--, j--, k--)
    {
        int sum = carry;
        sum += (i >= 0 ? a[i] - '0' : 0);
        sum += (j >= 0 ? b[j] - '0' : 0);
        carry = sum / 2;
        result[k] = '0' + sum % 2;
    }
    if (carry == 0)
    {
        return result + 1;
    }
    else
    {
        result[0] = '1';
    }
    return result;
}

/**
 * @brief 字符交换
 *
 * @param str
 * @param start
 * @param end
 */
void swapStr(char *str, int start, int end)
{
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
/**
 * @brief 字符串反转
 *
 * @param str
 * @return char*
 */
char *reversalStr(char *str)
{
    int start = 0;
    int end = strlen(str) - 1;
    swapStr(str, start, end);
    return str;
}

/**
 * @brief 反转字符串中的单词,单词以空格进行分割
 *
 * @param str
 * @return char*
 */
char *reverseWords(char *str)
{
    int i = 0;
    int start = 0;
    int end = 0;
    int len = strlen(str);
    while (str[end] != '\0')
    {
        end++;
        if (str[end] == ' ' || str[end] == '\0')
        {
            swapStr(str, start, end - 1);
            start = end + 1;
        }
    }
    return str;
}

/**
 * @brief 字符交换
 *
 * @param str
 * @param start
 * @param end
 * @return int
 */
int sawpVowel(char *str, int start, int end)
{
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
}

/**
 * @brief 判断是否为元音字母
 *
 * @param c
 * @return true
 * @return false
 */
bool isVowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief 交换元音字母
 *
 * @param s
 * @return char*
 */
char *reverseVowels(char *s)
{
    int i = 0;
    int j = strlen(s) - 1;
    while (i < j)
    {
        while (i < j && !isVowel(s[i]))
        {
            i++;
        }
        while (i < j && !isVowel(s[j]))
        {
            j--;
        }
        swapStr(s, i, j);
        i++;
        j--;
    }
    return s;
}

int myIsalnum(int c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'));
}

int myToLower(int c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c + ('a' - 'A');
    }
    return c;
}

/**
 * @brief 判断字符串是否回文
 * isdigit-检查所传字符是否为十进制数字字符(是数字，函数返回非零值)
 * isalpha-检查所传的字符是否是字母
 * isalnum-检查所传的字符是否是字母和数字
 * @param str
 * @return true
 * @return false
 */
bool isPalindrome(char *str)
{
    int len = strlen(str);
    if ((len == 0) || (len == 1))
    {
        return true;
    }
    // 两个指针，一个指向开头，一个指向结尾
    char *p = str;
    char *q = str + len - 1;
    while (p < q)
    {
        while ((!myIsalnum(*p)) && (p < q))
        {
            p++;
        }
        while ((!myIsalnum(*p)) && (p < q))
        {
            q--;
        }
        if (myToLower(*p) != myToLower(*q))
        {
            return false;
        }
        p++;
        q--;
    }
    return true;
}

/********************************************************************************************
 * 给定一个非空字符串，最多删除一个字符，判断是否能成为回文字符串,字符串中只包含a-z的小写字母
 *********************************************************************************************/
bool isPalindrome2(char *start, char *end)
{
    while (start <= end)
    {
        if (*start != *end)
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
bool validPalindrome(char *s)
{
    int flag = 0; // 一次删除机会
    int len = strlen(s);
    if (len <= 2)
    {
        return true; //
    }
    char *start = s;
    char *end = start + len - 1;
    while (*start <= *end)
    {
        if (*start != *end)
        {
            if (isPalindrome2(start + 1, end))
            {
                return true; //
            }
            if (isPalindrome2(start, end - 1))
            {
                return true; //
            }
        }
        start++;
        end--;
    }
    return true; //
}

/**
 * @brief 给定一个字符串，将字符串中字符按照出现的频率降序排列
 * tree -> eetr(eert)
 * @param s
 * @return char*
 */
char *frequencySort(char *s)
{
    int flag[128] = {0};
    int len = strlen(s);
    if (len <= 2)
    {
        return s;
    }
    for (int i = 0; i < len; i++)
    {
        printf("%d ", s[i]);
        flag[s[i]]++;
    }
    // int i,j; //输出结果不对，局部变量不赋初值的话，默认值不确定
    int i = 0, j = 0;
    while (i < len)
    {
        int maxValue = 0;
        int maxIndex = 0;
        for (j = 0; j < 128; j++)
        {
            if (flag[j] > maxValue)
            {
                maxValue = flag[j];
                maxIndex = j;
            }
        }
        if (maxValue != 0)
        {
            flag[maxIndex] = 0;
        }
        for (j = 0; j < maxValue; j++)
        {
            s[i++] = maxIndex;
        }
    }
    return s;
}

/**
 * @brief 统计字符串中单词的个数
 *
 * @param s
 * @return int
 */
int countSegments(char *str)
{
    if (str[0] == '\0')
    {
        return 0;
    }
    int cnt = 0, i = 0;
    int len = strlen(str);
    for (i = 0; i < len; i++)
    {
        if ((i == 0 || str[i - 1] == ' ') && str[i] != ' ')
        {
            cnt++;
        }
    }
    return cnt;
}

#ifdef __TOP_K_HIGH_FREQUENCY_WORDS__

// 定义单词结构体
typedef struct
{
    char *word;
    int count;
} WordCount;

// 比较函数，用于排序
int compare(const void *a, const void *b)
{
    const WordCount *wc1 = (const WordCount *)a;
    const WordCount *wc2 = (const WordCount *)b;

    // 如果两个单词出现次数不同，按照出现次数由高到低排序
    if (wc1->count != wc2->count)
    {
        return wc2->count - wc1->count;
    }
    // 如果出现次数相同，按照字典顺序排序
    else
    {
        return strcmp(wc1->word, wc2->word);
    }
}

char **topKFrequent(char **words, int wordsSize, int k, int *returnSize)
{
    // 创建一个哈希表，用于记录每个单词出现的次数
    int hashSize = wordsSize * 2; // 哈希表的大小
    WordCount *hashTable = (WordCount *)malloc(hashSize * sizeof(WordCount));
    int hashCount = 0; // 哈希表中的单词数量

    for (int i = 0; i < wordsSize; i++)
    {
        // 在哈希表中查找当前单词是否已存在
        int j;
        for (j = 0; j < hashCount; j++)
        {
            if (strcmp(words[i], hashTable[j].word) == 0)
            {
                hashTable[j].count++; // 单词已存在，出现次数加一
                break;
            }
        }

        // 如果哈希表中不存在当前单词，则将其添加到哈希表中
        if (j == hashCount)
        {
            hashTable[hashCount].word = words[i];
            hashTable[hashCount].count = 1;
            hashCount++;
        }
    }

    // 对哈希表中的单词进行排序
    qsort(hashTable, hashCount, sizeof(WordCount), compare);

    // 根据k值，返回前k个出现次数最多的单词
    *returnSize = k;
    char **result = (char **)malloc(k * sizeof(char *));
    for (int i = 0; i < k; i++)
    {
        result[i] = hashTable[i].word;
    }

    free(hashTable); // 释放哈希表内存

    return result;
}

int main()
{
    char *words[] = {"apple", "banana", "apple", "orange", "banana", "pear", "apple"};
    int wordsSize = sizeof(words) / sizeof(words[0]);
    int k = 2; // 返回前2个出现次数最多的单词

    int returnSize;
    char **result = topKFrequent(words, wordsSize, k, &returnSize);

    printf("the word top %d is:\n", k);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%s\n", result[i]);
    }

    // 释放结果内存
    for (int i = 0; i < returnSize; i++)
    {
        free(result[i]);
    }
    free(result);

    return 0;
}
#endif // __TOP_K_HIGH_FRE_WORDS

/**
 * @brief 判断单词的大小写是否正确
 * hello-true;Hello -> true; heLlo->false
 * @param str
 * @return true
 * @return false
 */
bool isValidCapitalWord(const char *str)
{
    if (str == NULL)
    {
        return false;
    }
    int len = strlen(str);
    if (len <= 1)
    {
        return true;
    }
    int count = 0;
    for (int i = 1; i < len; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            count++;
        }
    }
    if (((str[0] >= 'A' && str[0] <= 'Z') && count == len - 1) || (count == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 二级指针
#ifdef __FIND_LONGEST_COMMON_PREFIX__
/**
 * @brief 编写一个函数来查找字符串数组中的最长公共前缀
 *
 * @param strs
 * @param strsSize
 * @return char*
 */
char *longestCommonPrefix(char **strs, int strsSize)
{
    if (strsSize == 0)
    {
        // 字符串数组为空，返回空字符串
        return "";
    }

    // 获取第一个字符串作为初始的最长公共前缀
    char *s0 = strs[0];

    // s0的第col个字符作为基准
    for (int col = 0; s0[col] != '\0'; ++col)
    {
        // 扫描其它字符串，仅当所有字符串的第col个字符都同基准，才会正常结束循环
        for (int row = 1; row < strsSize; ++row)
        {
            // 不会越界！因为即将越界会有 '\0'停止符作为哨兵，此时马上跳出。
            if (s0[col] != strs[row][col])
            {
                s0[col] = '\0'; // 用'\0'表示结束，改短s0
                return s0;
            } // 而且C语言即便越界，只要越的界没有超出整个进程代码段的地址空间，都不会报错。
        }
    }
    return s0; // 其他字符串不存在或都包含s0的前缀
}

int main()
{
    char *strs[] = {"flower", "flow", "flight"};
    int strsSize = sizeof(strs) / sizeof(strs[0]);

    char *prefix = longestCommonPrefix(strs, strsSize);

    printf("最长公共前缀是：%s\n", prefix);

    return 0;
}
#endif // __FIND_LONGEST_COMMONPREFIX

/**
 * @brief 给定一个字符串计算具有相同数量0和1的非空子字符串的数量，并且0和1是组合在一起的
 * 
 * @param s 
 * @return int 
 */
int countBinarySubstrs(char *s)
{
    int n = 0, pre = 0, curr = 1, len = strlen(s) - 1;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == s[i + 1])
        {
            curr++;
        }
        else
        {
            pre = curr;
            curr = 1;
        }
        if (pre >= curr)
        {
            n++;
        }
    }
    return n;
}




int main()
{
    char buf[] = "00110011";
    int count = countBinarySubstrs(buf);
    printf("%d\n", count);
    return 0;
}
