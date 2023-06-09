#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// #define __PARENTHESE_MATCH_

#ifdef __ARRAY_STACK__

#define STACK_INIT_SIZE 100 // 数值可以根据实际情况确定
#define STACK_INCREMENT 10  // 数值可以根据实际情况确定
/*
typedef struct
{
    void *base; //栈底指针
    void *top; //栈顶指针
    int stackSize; //栈当前可以使用的最大容量
} */
// 结点设计
typedef struct stack
{
    int data[STACK_INIT_SIZE];
    int top;
} stack;

// 创建
stack *init()
{
    stack *s = (stack *)malloc(sizeof(stack));
    if (NULL == s)
    {
        printf("分配内存空间失败");
        exit(0);
    }
    memset(s->data, 0, sizeof(s->data));
    s->top = 0; // 栈的top和bottom均为0(表示为空)
    return s;
}

/**
 * @brief 入栈
 *
 * @param s
 * @param data
 */
void push(stack *s, int data)
{
    s->data[s->top] = data;
    s->top++;
}

/**
 * @brief 出栈
 *
 * @param s
 */
void pop(stack *s)
{
    if (s->top != 0)
    {
        s->data[s->top] = 0; // 让其回归0，模拟表示未初始化即可
        s->top--;
    }
}

/**
 * @brief 模拟打印栈中元素
 *
 * @param s
 */
void print_stack(stack *s)
{
    for (int n = s->top - 1; n >= 0; n--)
    {
        printf("%d\t", s->data[n]);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    stack *s = init();
    int input[] = {11, 22, 33, 44, 55}; // 模拟五个输入元素
    for (int i = 0; i < 5; i++)
    {
        push(s, input[i]);
    }
    print_stack(s);
    ////////////////////////////////////////////////////////////////////////
    pop(s);
    print_stack(s);
    pop(s);
    print_stack(s);
    return 0;
}

#endif // DEBUG

#ifdef __LIST__STACK__

typedef struct node
{
    int data;          //
    struct node *next; //
} Node;

typedef struct stack
{
    Node *top; // 永远指向帧头
    int count; // 计数器
} Link_stack;

Link_stack *createStack()
{
    Link_stack *p;
    p = (Link_stack *)malloc(sizeof(Link_stack));
    if (p == NULL)
    {
        printf("malloc failure");
        exit(0);
    }
    else
    {
        printf("createStack successful");
        p->count = 0;
        p->top = NULL;
        return p;
    }
}

/**
 * @brief 入栈
 *
 * @param p 需要操作的函数
 * @param elem 入栈的元素
 * @return Link_stack*
 */
Link_stack *push_stack(Link_stack *p, int elem)
{
    if (p == NULL)
    {
        return NULL;
    }
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));

    // temp = new Node
    temp->data = elem;
    temp->next = p->top;
    p->top = temp;
    p->count++;
    return p;
}

/**
 * @brief
 *
 * @param p
 * @return Link_stack*
 */
Link_stack *pop_stack(Link_stack *p)
{
    Node *temp;
    temp = p->top;
    if (p->top == NULL)
    {
        printf("错误:栈为空\n");
        return p;
    }
    else
    {
        printf("pop succeeded\n");
        p->top = p->top->next;
        free(temp);
        p->count--;
        return p;
    }
}

/**
 * @brief 输出栈中所有元素
 *
 * @param p
 * @return int
 */
int show_stack(Link_stack *p)
{
    Node *temp;
    temp = p->top;
    if (p->top == NULL)
    {
        printf("");
        printf("错误:栈为空");
        return 0;
    }
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}

int main(int argc, char **argv)
{
    int i;
    Link_stack *p;
    p = createStack();
    int input[] = {10, 20, 30, 40, 50, 60};
    int len = sizeof(input) / sizeof(input[0]);
    /*                       以依次入栈的方式创建整个栈                   */
    for (i = 0; i < len; i++)
    {
        push_stack(p, input[i]);
    }
    show_stack(p);

    /*                             出栈                                 */
    pop_stack(p);
    show_stack(p);
    return 0;
}

#endif // __LIST__STACK__

#ifdef __PARENTHESE_MATCH_

bool isMatched(char *str)
{
    int len = strlen(str);
    char stack[len]; // 定义栈，存储左括号
    int top = 0;     // 栈顶指针，指向最后一个入栈的元素
    for (int i = 0; i < len; i++)
    {
        char ch = str[i];
        switch (ch)
        {
            case '(':
            case '[':
            case '{':
                stack[top++] = ch; // 左括号入栈
                break;
            case ')':
                if (top == 0 || stack[--top] != '(') // 栈空或栈顶元素不是对应的左括号，匹配失败
                    return false;
                break;
            case ']':
                if (top == 0 || stack[--top] != '[')
                    return false;
                break;
            case '}':
                if (top == 0 || stack[--top] != '{')
                    return false;
                break;
            default:
                break;
        }
    }
    return true; // 栈空，匹配成功
}

int main()
{
    // int a == 0;
    char str[] = "(1(1[a5]))";
    if (isMatched(str))
        printf("match success!\n");
    else
        printf("match error!\n");
    return 0;
}

#endif // __PARENTHESE_MATCH_

int isMatch(char *str)
{
    int top = 0;
    int len = strlen(str);
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
                return 0;
            }
            break;
        case ']':
            if (top == 0 || stack[--top] != '[')
            {
                return 0;
            }
            break;
        case '}':
            if (top == 0 || stack[--top] != '{')
            {
                return 0;
            }
            break;
        default:
            break;
        }
    }
    return top == 0;
}

int main()
{
    char buf[] = "({{[]}})";
    if (isMatch(buf))
    {
        printf("matching successful!\n");
    }
    else
    {
        printf("matching failed!\n");
    }
    return 0;
}
