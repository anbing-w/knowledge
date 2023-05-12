#include <iostream>

using namespace std;

int main()
{
    char str[] = "glad to test something";
    //int str2[] = "Hello, world";
    char *p = str;
    p++;
    int *p1 = reinterpret_cast<int *>(p);
    printf("%s\n", p1);
    p1++;
    printf("%s\n", p1);//还有个空格
    p = reinterpret_cast<char *>(p1);
    printf("result is %s\n", p);
    return 0;
}
