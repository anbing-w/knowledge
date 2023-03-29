#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>

#ifdef __PLINDROMESTRING__
// ABCCBA,回文字符串
int isPlindromeString1(const char *string)
{
    const char *start = string;
    int len = strlen(string);
    const char *end = string + len - 1;
    int count = 0;
    while ((len % 2) || (len == 0))
    {
        return 0;
    }

    for (size_t i = 0; i < (len / 2); i++)
    {
        while (*start++ != *end--)
        {
            return 0;
        }
        count++;
    }
    if (count == (len / 2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isPlindromeString2(const char *string)
{
    const char *start = string;
    int len = strlen(string);
    const char *end = string + len - 1;
    while (start < end)
    {
        if (*start != *end)
        {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

int main(int argc, char **argv)
{
    char str1[] = "ABCCBA";
    char str2[] = "Hello";
    char str3[] = "";
    char str4[] = "AA";
    char str5[] = "ABCBA";

    printf("%s is %s\n", str1, isPlindromeString2(str1) ? "a palindrome" : "not a palindrome");
    printf("%s is %s\n", str2, isPlindromeString2(str2) ? "a palindrome" : "not a palindrome");
    printf("%s is %s\n", str3, isPlindromeString2(str3) ? "a palindrome" : "not a palindrome");
    printf("%s is %s\n", str4, isPlindromeString2(str4) ? "a palindrome" : "not a palindrome");
    printf("%s is %s\n", str5, isPlindromeString2(str5) ? "a palindrome" : "not a palindrome");

    return 0;
}

#endif

#ifdef __REVERSESTRING__

// 反转字符串，ABCD-DCBA
char *reverseString1(char *dest, const char *src)
{
    assert(src != NULL);
    int len = strlen(src);
    const char *end = src + len - 1;
    char *start = dest;
    for (size_t i = 0; i < len; i++)
    {
        *start++ = *end--;
    }
    *start = '\0';
    return start;
}

char *reverseString2(char *src)
{
    assert(src != NULL);
    int len = strlen(src);
    char *start = src;
    char *end = src + len - 1;
    while (start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

char *reverseString3(char *src)
{
    assert(src != NULL);
    int len = strlen(src);
    char *start = src;
    char *end = src + len - 1;
    while (start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main(int argc, char **argv)
{
    char str[100] = "1122334455aabbccddAABBCCDD";
    char dest[100];
    memset(dest, 0, sizeof(dest));
    reverseString3(str);
    printf("%s\n", str);
    return 0;
}

#endif // DEBUG

#ifdef __CHARTOINT__
// 将数字字符串转换为对应的数字，00st2427ytgj980
int charToInt(char *src)
{
    short sign = 1;
    int len = strlen(src);
    int num = 0;

    if (src[0] == '-')
    {
        sign = -1;
    }
    for (int i = 0; i < len; i++)
    {
        char ch = src[i];
        if (ch >= '0' && ch <= '9')
        {
            num = num * 10 + (ch - '0');
        }
    }
    return sign * num;
}

// 这样写不对，if，else if是并列关系，字符串中无论哪里出现-都会变成负数，如果要首位为-才为负的话就不能这样写
int extractNumber(const char *str)
{
    int len = strlen(str);
    int num = 0;
    int sign = 1; // 正负号标志，默认为正数

    for (int i = 0; i < len; i++)
    {
        char ch = str[i];
        if (ch == '-')
        {
            sign = -1; // 出现负号，将标志设置为负数
        }
        else if (ch >= '0' && ch <= '9')
        {
            num = num * 10 + (ch - '0'); // 累加数字
        }
    }

    return num * sign; // 返回最终结果
}

char *extract_lowercase_letters(char *dest, const char *src)
{
    int i = 0;
    int j = 0;
    int len = strlen(src);

    while (src[i])
    {
        if (src[i] >= 'a' && src[i] <= 'z')
        {
            dest[j++] = src[i];
        }
        i++; //
    }
}

int main()
{
    char str1[] = "a-bc12-34def";
    char str2[] = "12-a34b5-6c";
    char str3[] = "-123AADFDFDdsfsdfgs-4";
    char str4[] = "-12-342-224";
    char dest[100];
    int num = 0;
    num = atoi(str4); // atoi,遇到非数字字符就停止转换

    printf("%d\n", charToInt(str1)); // 输出 1234
    memset(dest, 0, sizeof(dest));
    extract_lowercase_letters(dest, str2);
    printf("%s\n", dest); // 输出 123456
    memset(dest, 0, sizeof(dest));
    extract_lowercase_letters(dest, str3);
    printf("%s\n", dest); // 输出 -1234
    printf("%d\n", num);  // 输出 -1234
    return 0;
}

#endif

#ifdef __HEXADECIMAL_TO_DECIMAL__

/**
 * @brief Hexdecimal to decimal conversion
 *
 * @param src
 * @return int
 */
int hexToInt1(const char *src)
{
    assert(src != NULL);
    int i = 0, n = 0, sum = 0;
    int len = strlen(src);
    for (i = 2; i < len; i++)
    {
        char ch = src[i];
        if (ch >= '0' && ch <= '9')
            n = ch - '0';
        else if (ch >= 'A' && ch <= 'F')
            n = ch - 'A' + 10;
        else if (ch >= 'a' && ch <= 'f')
            n = ch - 'a' + 10;
        sum = sum * 16 + n;
    }
    return sum;
}

int hexToInt2()
{
    char hex[100];
    printf("please input hex string or q to quit\n");
    while ((scanf("%s", hex)) != EOF && hex[0] != 'q')
    {
        int len = strlen(hex), num = 0, n;

        for (int i = 2; i < len; i++)
        {
            char ch = hex[i];
            if (ch >= '0' && ch <= '9')
            {
                n = ch - '0';
            }
            else if (ch >= 'A' && ch <= 'Z')
            {
                n = ch - 'A' + 10;
            }
            else if (ch >= 'a' && ch <= 'z')
            {
                n = ch - 'a' + 10;
            }
            num = num * 16 + n;
            // return num;

            // return 0;
        }
        printf("hex to decimal is %d \n", num);
    }
    printf("Goodbye!");
    return 0;
}

void hexToDec()
{
    char hex[100];
    printf("Enter hexadecimal numbers (one per line, press 'q' to quit):\n");
    while (scanf("%s", hex) != EOF && hex[0] != 'q')
    {
        int len = strlen(hex);
        int base = 1;
        int dec = 0;
        for (int i = len - 1; i >= 0; i--)
        {
            if (hex[i] >= '0' && hex[i] <= '9')
            {
                dec += (hex[i] - '0') * base;
            }
            else if (hex[i] >= 'A' && hex[i] <= 'F')
            {
                dec += (hex[i] - 'A' + 10) * base;
            }
            else if (hex[i] >= 'a' && hex[i] <= 'f')
            {
                dec += (hex[i] - 'a' + 10) * base;
            }
            base *= 16;
        }
        printf("Decimal equivalent of %s is: %d\n", hex, dec);
    }
    printf("Goodbye!\n");
}

int main()
{
    char a[1000];
    int result_hti;
    // scanf("%s", a);
    // result_hti = hexToInt(a);

    // printf("%d", result_hti);
    hexToInt2();
    return 0;
}

#endif

#if __COUNT_SUBSTR__
char *findSubString(char *str, char *substr)
{
    // assert(str != NULL);
    // assert(substr != NULL);
    if (str == NULL || substr == NULL)
    {
        return 0;
    }
    // int count = 0;
    char *p1 = str;
    char *p2 = substr;
    char *pc = str;
    while (*pc)
    {
        p1 = pc;
        p2 = substr;
        while (*p1 && *p2 && (*p1 == *p2))
        {
            p1++;
            p2++;
            // pc++;
        }
        if (*p2 == '\0')
        {
            // pc++;
            return pc;
        }
        else
        {
            pc++;
        }
    }
}

// subfunction count

int findSubStrNum2(char *str, char *substr)
{
    assert(str != NULL);
    assert(substr != NULL);
    int count = 0;
    char *p1 = NULL;
    char *p2 = NULL;
    char *pc = str;
    while (*pc)
    {
        p1 = pc;
        p2 = substr;
        while (*p1 && *p2 && (*p1++ == *p2++))
            ;
        if (*p2 == '\0')
        {
            count++;
        }
        pc++;
    }
    return count;
}

int countSubstring(char *str, char *subStr)
{
    int count = 0;
    int len = strlen(subStr);
    while ((str = strstr(str, subStr)))
    {
        count++;
        str += len;
    }
    return count;
}

int countSubStr(char *str, char *substr)
{
    int count = 0;
    int len = strlen(substr);
    while (str = strstr(str, substr))
    {
        count++;
        str = str + len;
    }
    return count;
}

int main(int argc, char **argv)
{
    char mon[] = "aaaaaa";
    char son[] = "a";
    // char *res = strstr(mon, "a1a"); // strstr(mon, son),找到第一个与son相等的子字符串返回
    int num;
    // printf("%s\n", res);
    num = findSubStrNum2(mon, son);
    printf("%d", num);
    return 0;
}

#endif

#ifdef __FIND_PUBLIC_STRING__
// return public string

int findCommonStr(char *str1, char *str2)
{
    int count = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i, j, k;

    for (i = 0; i < len1; i++)
    {
        for (j = 0; j < len2; j++)
        {
            if (str1[i] == str2[j])
            {
                k = 1;
                while (i + k < len1 && j + k < len2 && tolower(str1[i + k]) == tolower(str2[j + k]))
                {
                    k++;
                }
                if (k > 1)
                {
                    printf("Common string: ");
                    for (int m = 0; m < k; m++)
                    {
                        printf("%c", str1[i + m]);
                    }
                    printf("\n");
                    count++;
                }
            }
        }
    }
    return count;
}

int FindCommonStrNum(char *str1, char *str2)
{
    if (str1 == NULL || str2 == NULL)
    {
        return 0;
    }
    int count = 0;

    for (int i = strlen(str1); i > 0; i--)
    {
        for (int j = 0; j <= strlen(str1) - i; j++)
        {
            char *temp_str = (char *)malloc(256);
            memcpy(temp_str, &str1[j], i);
            temp_str[i] = '\0';
            if (strstr(str2, temp_str) != NULL)
            {
                count++;
                printf("%s\t", temp_str);
            }
            memset(temp_str, 0, i * 4);
        }
    }
    return count;
}

int main()
{
    char str1[] = "Hello, world!";
    char str2[] = "hello, world!";
    int count = FindCommonStrNum(str1, str2);
    printf("Found %d common strings\n", count);
    return 0;
}
#endif

#if 1

void max_common_string(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int max_len = 0, max_end = 0;
    int i, j;
    int dp[len1][len2];

    memset(dp, 0, sizeof(dp));

    for (i = 0; i < len1; i++) {
        for (j = 0; j < len2; j++) {
            if (str1[i] == str2[j]) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
            }
            if (dp[i][j] > max_len) {
                max_len = dp[i][j];
                max_end = i;
            }
        }
    }

    printf("最大公共字符串为：");
    for (i = max_end - max_len + 1; i <= max_end; i++) {
        printf("%c", str1[i]);
    }
}

int main() {
    char str1[100], str2[100];

    printf("请输入第一个字符串：");
    scanf("%s", str1);

    printf("请输入第二个字符串：");
    scanf("%s", str2);



    max_common_string(str1, str2);

    return 0;
}
#endif
