#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _CIRCULAR_LINKED_LIST__

#ifdef _SINGLE_LINKED_LIST__
// 定义结点类型
typedef struct Node
{
    int data;          // 数据类型，可以把int型修改为任意数据类型，包括结构体struct等复合类型,数据域
    struct Node *next; // 单链表的指针域
} Node, *LinkedList;

/**
 * @brief 链表初始化
 *
 * @return LinkedList
 */
LinkedList listInit()
{
    Node *L;
    L = (Node *)malloc(sizeof(Node)); // 开辟空间
    // 判断是否成功开辟空间
    if (NULL == L)
    {
        printf("申请空间失败！");
        // exit(0); //直接结束程序
    }
    L->next = NULL;
}
// 头插入法建立单链表
LinkedList linkListCreateH()
{
    Node *L;
    L = (Node *)malloc(sizeof(Node)); // 申请头结点空间
    L->next = NULL;                   // 初始化一个空表

    int x; // 链表数据域中的数据
    while (scanf("%d", &x) != EOF)
    {
        Node *p;
        p = (Node *)malloc(sizeof(Node)); // 申请新结点
        p->data = x;                      // 结点数域赋值
        p->next = L->next;                // 将结点插到表头 L-->|2|-->|1|-->NULL
        L->next = p;
    }
    return L; //
}

// 尾插入法建立单链表
LinkedList linkListCreateT()
{
    Node *L;
    L = (Node *)malloc(sizeof(Node)); // 申请头结点空间
    L->next = NULL;                   // 初始化空链表
    Node *r;                          // r始终指向终端结点，
    r = L;                            // r始终指向终端结点，开始时指向头结点
    int x;                            // x为链表数据域中的数据
    while (scanf("%d", &x) != EOF)
    {
        Node *p;
        p = (Node *)malloc(sizeof(Node)); // 申请新的结点
        p->data = x;                      // 结点数据域赋值
        r->next = p;                      // 将结点插入到表头 L-->|1|-->|2|-->NULL
        r = p;
    }
    r->next = NULL;
    return L;
}

// 遍历输出单链表
void printList(LinkedList L)
{
    Node *p = L->next;
    int i = 0;
    while (p)
    {
        printf("the value of %d element:%d\n", ++i, p->data);
        p = p->next;
    }
}
// 链表内容修改，在链表中修改值为x的元素变为k
LinkedList linkedListReplace(LinkedList L, int x, int k)
{
    Node *p = L->next;
    int i = 0;
    while (p)
    {
        if (p->data == x)
        {
            p->data = k;
        }
        p = p->next;
    }
    return L;
}
// 单链表的插入，在链表的第i个位置插入x的元素
LinkedList linkedListInsert(LinkedList L, int i, int x)
{
    Node *pre; // pre为前驱结点
    pre = L;
    int tempi = 0;
    for (tempi = 1; tempi < i; tempi++)
    {
        pre = pre->next; // 查找第i个位置的前驱结点
    }
    Node *p; // 插入结点为p
    p = (Node *)malloc(sizeof(Node));
    p->data = x;
    p->next = pre->next;
    pre->next = p;
    return L;
}
// 单链表的删除，在链表中删除值为x的元素
LinkedList linkedListDelete(LinkedList L, int x)
{
    Node *p, *pre; // pre为前驱结点，p为查找的结点

    p = L->next;
    while (p->data != x)
    {
        pre = p;
        p = p->next;
    }
    pre->next = p->next; // 删除操作，将其前驱next指向后继
    free(p);
    return NULL;
}

#endif

#ifdef _DOUBLE_LINKED_LIST__
typedef struct line
{
    int data;
    struct line *pre;  // pre node,前驱
    struct line *next; // next node，后继
} line, *a;

// 创建新链表
line *initLine()
{
    int number, pos = 1, input_data; // 三个变量分别表示结点数量，当前位置，输入数据
    printf("请输入创建结点的大小\n");
    scanf("%d", &number); //
    if (number < 1)
    { // 输入非法直接结束
        return NULL;
    }
    // 头结点创建
    line *head = (line *)malloc(sizeof(line));
    head->pre = NULL;
    head->next = NULL;
    printf("请输入第%d个数据\n", pos++);
    scanf("%d", &input_data); //
    head->data;
    line *list = head;
    while (pos <= number)
    {
        line *body = (line *)malloc(sizeof(line));
        body->pre = NULL;
        body->next = NULL;
        printf("请输入第%d个数据\n", pos++);
        scanf("%d", &input_data);
        body->data = input_data;
        list->next = body;
        body->pre = list;
        list = list->next;
    }
    return head;
}

/**
 * @brief 插入数据
 *
 * @param head 进行操作的双链表
 * @param data 需要插入的数据
 * @param add 插入的位置
 * @return line*
 */
line *insertLine(line *head, int data, int add)
{
    line *temp = (line *)malloc(sizeof(line));
    temp->data = data;
    temp->next = NULL;
    temp->pre = NULL;
    // 插入到链表头，要特殊考虑
    if (add == 1)
    {
        temp->next = head;
        head->pre = temp;
        head = temp;
    }
    else
    {
        line *body = head;
        for (int i = 0; i < add - 1; i++)
        {
            body = body->next;
        }
        // 判断条件为真，说明插入位置为链表尾
        if (body->next == NULL)
        {
            body->next = temp;
            temp->pre = body;
        }
        else
        {
            body->next->pre = temp;
            temp->next = body->next;
            temp->pre = body;
            body->next = temp;
        }
    }
    return head;
}

/**
 * @brief 删除元素
 *
 * @param head 需要操作的链表
 * @param data 需要删除的数据
 * @return line*
 */
line *deleteLine(line *head, int data)
{
    line *list = head;
    // 遍历链表

    while (list)
    {
        if (list->data == data)
        {
            list->pre->next = list->next;
            list->next->pre = list->pre;
            free(list);
            printf("delete successful!\n");
            return head;
        }
        list = list->next;
    }
    printf("ERROR:can`t find the element!!!\n");
    return head;
}

// 遍历双链表，同时打印元素数据
void printLine(line *head)
{
    line *list = head;
    int pos = 1;
    while (list)
    {
        printf("第%d个数据是:%d\n ", pos++, list->data);
        list = list->next;
    }
}

#endif

#ifdef _CIRCULAR_LINKED_LIST__
typedef struct list
{
    int data;          // 数据域
    struct list *next; // 指针域
} list;

// 初始化结点
list *initList()
{
    list *head = (list *)malloc(sizeof(list));
    if (head == NULL)
    {
        printf("创建失败,退出程序");
        exit(0);
    }
    else
    {
        head->next = NULL;
        return head;
    }
}
/*
    //主函数重调用
    list *head = initList();
    head->next = head;
*/
// 创建-插入数据
int insert_list(list *head)
{
    int data; // 插入的数据类型
    printf("请输入要插入的元素: ");
    scanf("%d", &data); //
    list *node = initList();
    node->data = data; // 初始化一个新链表，准备进行链接

    if (head != NULL)
    {
        list *p = head;
        // 找到最后一个数据
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = node;
        node->next = head;
        return 1;
    }
    else
    {
        printf("头结点已无元素\n");
        return 0;
    }
}

/**
 * @brief 插入元素
 *
 * @param head 需要操作的链表
 * @param pos 需要插入的位置
 * @param data 插入的数值
 * @return list*
 */
list *insert_list(list *head, int pos, int data)
{
    list *node = initList(); // 新建结点
    list *p = head;          // p表示新的链表
    list *t;
    t = p; //
    node->data = data;
    if (head != NULL)
    {
        for (int i = 1; i < pos; i++)
        {
            t = t->next; // 走到需要插入的位置处
        }
        node->next = t->next;
        t->next = node;
        return p;
    }
    return p;
}

/**
 * @brief 删除元素
 *
 * @param head 操作的链表
 * @return int 返回值
 */
int deleteList(list *head)
{
    if (NULL == head)
    {
        printf("链表为空!\n");
        return 0;
    }
    list *temp = head;
    list *ptr = head->next;

    int del;
    printf("请输入你要删除的元素:");
    scanf("%d", &del);
    while (ptr != head)
    {
        if (ptr->data == del)
        {
            if (ptr->next == head)
            {
                temp->next = head;
                free(ptr);
                return 1;
            }
            temp->next = ptr->next; // 核心删除操作代码
            free(ptr);
            // printf("元素删除成功！\n");
            return 1;
        }
        temp = temp->next;
        ptr = ptr->next;
    }
    printf("没有找到需要删除的元素");
    return 0;
}

/**
 * @brief 遍历输出链表
 *
 * @param head
 * @return int
 */
int display(list *head)
{
    if (head != NULL)
    {
        list *p = head;
        // 遍历头结点到最后一个数据
        while (p->next != head)
        {
            printf("%d ", p->next->data);
            p = p->next;
        }
        printf("\n");
        return 1;
    }
    else
    {
        printf("头结点为空!\n");
        return 0;
    }
}

#endif
