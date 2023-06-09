#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define _SINGLE_LINKED_LIST__

#ifdef _SINGLE_LINKED_LIST__
// 定义结点类型
typedef struct ListNode
{
    int data;              // 数据类型，可以把int型修改为任意数据类型，包括结构体struct等复合类型,数据域
    struct ListNode *next; // 单链表的指针域
} ListNode;

/**
 * @brief 链表初始化
 *
 * @return LinkedList
 */
ListNode *listInit()
{
    ListNode *L;
    L = (ListNode *)malloc(sizeof(ListNode)); // 开辟空间
    // 判断是否成功开辟空间
    if (NULL == L)
    {
        printf("申请空间失败！");
        // exit(0); //直接结束程序
    }
    L->next = NULL;
    L->data = 0;
    return L;
}

#if 1
// 头插入法建立单链表
ListNode *linkListCreateH()
{
    // ListNode *L;
    // L = (ListNode *)malloc(sizeof(ListNode)); // 申请头结点空间
    // L->next = NULL;                           // 初始化一个空表

    ListNode *head = NULL;         //
    int x;                         // 链表数据域中的数据
    while (scanf("%d", &x) != EOF) // CTRL+Z表示文件结束符
    {
        // 申请新结点                           // scanf的返回值-所输入的数据与格式字符串中匹配次数
        ListNode *p = (ListNode *)malloc(sizeof(ListNode));
        p->data = x;    // 结点数域赋值
        p->next = head; // 将结点插到表头 L-->|2|-->|1|-->NULL
        head = p;
    }
    return head; //
}
#endif

#if 0
// 头插入法建立单链表
ListNode *linkListCreateH()
{

    // ListNode *L;
    // L = (ListNode *)malloc(sizeof(ListNode)); // 申请头结点空间
    // L->next = NULL;                           // 初始化一个空表

    ListNode *head = NULL; //

    for (int i = 5; i > 0; i--)
    {
        ListNode *p = (ListNode *)malloc(sizeof(ListNode));
        p->data = i;                              // 结点数域赋值
        p->next = head;                        // 将结点插到表头 L-->|2|-->|1|-->NULL
        head = p;
    }
    return head; //
}
#endif

// 尾插入法建立单链表
ListNode *linkListCreateT()
{
    ListNode *head;
    head = (ListNode *)malloc(sizeof(ListNode)); //
    ListNode *r;                                 // r始终指向终端结点，
    r = head;                                    // r始终指向终端结点，开始时指向头结点
    int x;                                       // x为链表数据域中的数据
    while (scanf("%d", &x) != EOF)
    {
        ListNode *p = (ListNode *)malloc(sizeof(ListNode));
        p->data = x; // 结点数据域赋值
        r->next = p; // 将结点插入到表头 head-->|1|-->|2|-->NULL
        r = p;
    }
    r->next = NULL;
    return head;
}

// 遍历输出单链表
void printList(ListNode *head)
{
    ListNode *p = head;
    while (p)
    {
        // printf("the value of %d element:%d\n", ++i, p->data);
        printf("%d->", p->data);
        p = p->next;
    }
}
// 链表内容修改，在链表中修改值为x的元素变为k
ListNode *linkedListReplace(ListNode *L, int x, int k)
{
    ListNode *p = L->next;
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
ListNode *linkedListInsert(ListNode *L, int i, int x)
{
    ListNode *pre; // pre为前驱结点
    pre = L;
    int tempi = 0;
    for (tempi = 1; tempi < i; tempi++)
    {
        pre = pre->next; // 查找第i个位置的前驱结点
    }
    ListNode *p; // 插入结点为p
    p = (ListNode *)malloc(sizeof(ListNode));
    p->data = x;
    p->next = pre->next;
    pre->next = p;
    return L;
}
// 单链表的删除，在链表中删除值为x的元素
ListNode *linkedListDelete(ListNode *L, int x)
{
    if (L == NULL)
    {
        return NULL;
    }
    ListNode *p = L, *pre = L; // pre为前驱结点，p为查找的结点
    p = L->next;
    while (p->data != x)
    {
        pre = p;
        p = p->next;
    }
    pre->next = p->next; // 删除操作，将其前驱next指向后继
    free(p);
    return L;
}

/**
 * @brief 链表反转
 *
 * @param head
 * @return ListNode*
 */
ListNode *linkedListReversal(ListNode *head)
{
    // assert(head != NULL);
    if ((head == NULL) || head->next == NULL)
        return head; //

    ListNode *former = NULL;
    ListNode *mid = head;
    ListNode *latter = mid;
    while (mid != NULL)
    {
        latter = mid->next;
        mid->next = former;
        former = mid;
        mid = latter;
    }
    return former;
}

/**
 * @brief 使用递归方式实现链表反转
 *
 * @param head
 * @return ListNode*
 */
ListNode *linkedListReversal2(ListNode *head)
{
    if ((head == NULL) || head->next == NULL)
        return head;              //
    ListNode *mid = head;         // 保存头节点
    ListNode *latter = mid->next; // 保存下一个结点

    head = linkedListReversal2(latter); // 递归到最后一个结点，返回转置后链表的地址
    latter->next = mid;                 // 让后面的结点指向前一个结点

    mid->next = NULL;
    return head;
}

/**
 * @brief 计算链表的长度
 *
 * @param head
 * @return ListNode*
 */
int linkedListLen(ListNode *head)
{
    ListNode *p = head;
    int list_len = 0;
    while (p != NULL)
    {
        list_len++;
        p = p->next;
    }
    return list_len;
}

/**
 * @brief remove the same node
 *
 * @param head
 * @return ListNode*
 */
ListNode *removeSameNode(ListNode *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    ListNode *cur = head;
    while (cur != NULL)
    {
        ListNode *prev = cur->next;
        while (prev != NULL)
        {
            if (cur == prev)
            {
                cur = prev->next;
            }
            prev = prev->next;
        }
        cur = prev;
    }
    return head;
}

/**
 * @brief 使用标记数组进行重复节点的去除
 *
 * @param head
 * @return ListNode*
 */
ListNode *removeSameNode2(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    int index[1001] = {0};
    index[head->data] = 1;
    ListNode *cur = head, *prev = head->next;
    while (prev)
    {
        if (index[prev->data] == 0)
        {
            index[prev->data] = 1;
            cur = prev;
            prev = prev->next;
        }
        else
        {
            cur->next = prev->next;
            prev = prev->next;
        }
    }
    return head;
}

/**
 * @brief 使用快慢指针找到链表倒数第k个结点并返回
 *
 * @param head
 * @return ListNode*
 */
ListNode *findKthfromend(ListNode *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    ListNode *faster = head;
    ListNode *latter = head;
    for (int i = 0; i < k; i++)
    {
        faster = faster->next;
    }
    while (faster)
    {
        faster = faster->next;
        latter = latter->next;
    }
    return latter;
}

/**
 * @brief 找到链表的中间节点,偶数个结点的话，返回左结点和右节点条件不同
 *
 * @param head
 * @return ListNode*
 */
ListNode *findListMidNode(ListNode *head)
{
    ListNode *faster = head;
    ListNode *latter = head;
#ifdef __LIST_LEFT_NODE_
    while ((faster != NULL) && (faster->next != NULL))
    {
#else
    while (faster->next != NULL && faster->next->next != NULL)
    {
#endif

        faster = faster->next->next;
        latter = latter->next;
    }
    return latter;
}

/**
 * @brief 寻找环形链表的入口结点
 * S1 = Y + X, S2 = Y + X + NR = 2S1 -> Y = NR - X -> 一定在入口结点相遇
 *
 * @param head
 * @return ListNode*
 */
ListNode *detectEntryNode(ListNode *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    ListNode *slow = head;
    ListNode *fast = head;

    while ((fast != NULL) && (fast->next != NULL))
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            fast = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

/**
 * @brief Get the Intersection Node object
 * 找到链表相交的结点
 * @param headA
 * @param headB
 * @return ListNode*
 */
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == NULL || headB == NULL)
    {
        return NULL;
    }

    ListNode *p = headA;
    ListNode *q = headB;
    while (p != q)
    {
        if (p != NULL)
        {
            p = p->next;
        }
        else
        {
            p = headB;
        }
        if (q != NULL)
        {
            q = q->next;
        }
        else
        {
            q = headA;
        }
    }
    return p;
}

/**
 * @brief 判断链表是否回文
 * 1->2->2->1    1->2->3->2->1
 * @param head
 * @return true
 * @return false
 */
bool isPalindrome(ListNode *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast->next != NULL && fast != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode *former = NULL;
    ListNode *mid = slow;
    ListNode *latter = NULL;
    while (slow != NULL)
    {
        latter = mid->next;
        mid->next = former;
        former = mid;
        mid = latter;
    }
    ListNode *pre = head;
    while (former != NULL)
    {
        if (pre->data == former->data)
        {
            pre = pre->next;
            former = former->next;
        }
        else
        {
            return false;
        }
    }
    return true;
}

/**
 * @brief 遍历删除重复节点
 *
 * @param head
 * @return ListNode*
 */
ListNode *removeDuplicateNodes1(ListNode *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    ListNode *cur = head;
    ListNode *pre = head;
    while (cur != NULL)
    {
        pre = cur;
        while (pre->next != NULL)
        {
            if (pre->next->data == cur->data)
            {
                pre->next = pre->next->next;
            }
            else
            {
                pre = pre->next;
            }
        }
        cur = cur->next;
    }
    return head;
}


/**
 * @brief 使用标记数组删除重复结点
 * 
 * @param head 
 * @return ListNode* 
 */
ListNode *removeDuplicateNodes2(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }    
    int index[1001] = {0};
    index[head->data] = 1;

    ListNode *cur = head,*pre = head->next;
    while (pre)
    {
        if (index[pre->data] == 0)
        {
            index[pre->data] = 1;
            cur = pre;
            pre = pre->next;
        }
        else
        {
            cur->next = pre->next;
            pre = pre->next;
        }
        
    }
    
#if 0
    while (pre->next != NULL)
    {
        if (index[pre->next->data] == 0)
        {
            index[pre->next->data] = 1;
            pre = pre->next;
        }
        else
        {
            pre->next = pre->next->next;
        }
    }
#endif
    return head;
}


/**
 * @brief 使用非递归方式合并链表，并返回
 * 
 * @param l1 
 * @param l2 
 * @return ListNode* 
 */
ListNode *mergeTwoLists1(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL)
    {
        return l2;
    }
    if (l2 == NULL)
    {
        return l1;
    }
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    ListNode *pre = head;
    
    //先连接小的元素
    while (l1 && l2 )
    {
        if (l1->data <= l2->data)
        {
            pre->next = l1;
            l1 = l1->next;
        }
        else
        {
            pre->next = l2;
            l2 = l2->next;
        }
        pre = pre->next;
    }
    //将剩下的元素直接连接在最后面
    pre->next = ((NULL == l1)?l2:l1);
    return head->next;
}


ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL)
    {
        return l2;
    }
    if (l2 == NULL)
    {
        return l1;
    }
    if (l1->data < l2->data)
    {
        l1->next = mergeTwoLists2(l1->next,l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoLists2(l1,l2->next);
        return l2;
    }
}

#if 0
int main()
{
    ListNode *L = NULL;

    printf("Enter integers to create a linked list (EOF to stop):\n");
    L = linkListCreateH();
    printf("Linked list created using head insertion:\n");
    printList(L);

    printf("\nTesting linkListCreateT:\n");
    L = linkedListReversal(L);
    printf("Linked list reversal:\n");
    printList(L);

    return 0;
}
#endif

#if 1
int main()
{
    ListNode *L = NULL;
    printf("Testing listInit:\n");
    L = listInit();
    if (L != NULL)
        printf("listInit passed\n");
    else
        printf("listInit failed\n");

    printf("\nTesting linkListCreateH:\n");
    printf("Enter integers to create a linked list (EOF to stop):\n");
    L = linkListCreateH();
    printf("Linked list created using head insertion:\n");
    printList(L);

    printf("\nTesting linkListCreateT:\n");
    L = linkedListReversal(L);
    printf("Linked list reversal:\n");
    printList(L);

    printf("\nTesting linkListCreateT:\n");
    printf("Enter integers to create a linked list (EOF to stop):\n");
    L = linkListCreateT();
    printf("Linked list created using tail insertion:\n");
    printList(L);

    printf("\nTesting linkListCreateT:\n");
    L = linkedListReversal(L);
    printf("Linked list reversal:\n");
    printList(L);

    printf("\nTesting linkedListReplace:\n");
    printf("Enter the value to be replaced: ");
    int replaceVal;
    scanf("%d", &replaceVal);
    printf("Enter the new value: ");
    int newVal;
    scanf("%d", &newVal);
    L = linkedListReplace(L, replaceVal, newVal);
    printf("Linked list after replacement:\n");
    printList(L);

    printf("\nTesting linkedListInsert:\n");
    printf("Enter the position for insertion: ");
    int position;
    scanf("%d", &position);
    printf("Enter the value to be inserted: ");
    int insertVal;
    scanf("%d", &insertVal);
    L = linkedListInsert(L, position, insertVal);
    printf("Linked list after insertion:\n");
    printList(L);

    printf("\nTesting linkedListDelete:\n");
    printf("Enter the value to be deleted: ");
    int deleteVal;
    scanf("%d", &deleteVal);
    L = linkedListDelete(L, deleteVal);
    printf("Linked list after deletion:\n");
    printList(L);
    return 0;
}
#endif

#endif

#ifdef __LIST_RESERVAL_SINGLE_LIST_
// 填空题3，反转链表
typedef struct node
{
    int data;
    struct node *next;
} node;

void print_list(struct node *head)
{
    printf("List: ");
    struct node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void free_list(struct node *head)
{
    struct node *current = head;
    while (current != NULL)
    {
        struct node *next = current->next;
        free(current);
        current = next;
    }
}

node *reverse_list(node *head)
{
    /*     struct node *p, *q;
        if (head == NULL)
        {
            return;
        }
        p = *head;
        if (p == NULL)
        {
            return;
        }
        q = p->next;
        if (q == NULL)
        {
            return;
        }
        p->next = NULL; // 1. 将当前节点p的next指针设为NULL，表示它将成为反转后的链表的尾节点
        while (q != NULL)
        {
            struct node *r = q->next; // 2. 用r指针来保存q节点的下一个节点
            q->next = p;              // 将q的next指针指向p
            p = q;                    // 将p和q指针向前移动
            q = r;
        }
        *head = p; // 最后将头指针指向反转后的链表头节点p */

    node *former = NULL;
    node *mid = head;
    node *latter = mid;
    while (mid != NULL)
    {
        latter = mid->next;
        mid->next = former;
        former = mid;
        mid = latter;
    }
    return former;
}

void reverse_list2(node **head)
{
    node *former = NULL;
    node *mid = *head;
    node *latter = mid;
    while (mid != NULL)
    {
        latter = mid->next;
        mid->next = former;
        former = mid;
        mid = latter;
    }
    *head = former;
    //  return former;
}

/**
 * @brief Get the List Length object
 *
 * @param head
 * @return int
 */
int getListLength(node *head)
{
    int length = 0; // 局部变量，不初始化为0的话，初始值随机
    node *cur = head;
    while (cur != NULL)
    {
        length++;
        cur = cur->next;
    }
    return length;
}

node *listCreate()
{
    struct node *head = NULL;
    // 创建一个长度为5的链表
    for (int i = 5; i > 0; i--)
    {
        struct node *new_node = malloc(sizeof(struct node));
        new_node->data = i;
        new_node->next = head;
        head = new_node;
    }
    return head;
}

int main()
{
    node *head = listCreate();
    print_list(head);
    int len = getListLength(head);
    printf("%d\n", len);

    reverse_list2(&head);
    print_list(head);

    // 反转链表
    node *p = reverse_list(head);
    print_list(p);

    // 释放链表内存
    free_list(p);

    return 0;
}

#endif // DEBUG

#ifdef _SINGLE_LINKED_LIST_OPERATE

typedef struct ListNode
{
    int data;              // 数据域
    struct ListNode *next; // 指针域
} ListNode;

ListNode *initListNode()
{
    ListNode *p = malloc(sizeof(struct ListNode));
    if (p == NULL)
    {
        exit(0);
    }
    p->next = NULL;
    return p;
}

// 头插入法建立单链表
ListNode *linkListCreate(int num)
{
    ListNode *head = initListNode();
    head->data = 1;
    // ListNode *newNode = initListNode();

    for (int i = 1; i < num; i++)
    {
        ListNode *node = initListNode();
        node->data = i;
        head->next = node;
    }
    return head;
}

/**
 * @brief 打印链表中的内容
 *
 * @param head
 * @return int
 */
void displayList(ListNode *head)
{
    if (head == NULL)
    {
        return; //
    }
    ListNode *temp = head;

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    // return 0;
}

int getListLen(ListNode *head)
{
    int len = 0;
    ListNode *temp = head;
    while (temp)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

int main()
{
    int num = 5;
    ListNode *head = linkListCreate(num);
    displayList(head);
    getListLen(head);
    return 0;
}

#endif //

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

int main(int argc, char **argv[])
{
    line *head = initLine();

    return 0;
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

#ifdef __REVERSED_SINGLE_LIST_

// 定义单链表结构体
typedef struct ListNode
{
    int val;               // 节点值
    struct ListNode *next; // 指向下一个节点的指针
} ListNode;

// 反转单链表
ListNode *reverseList(ListNode *head)
{
    // 定义前驱节点和当前节点，初始时前驱节点为 NULL，当前节点为头节点
    ListNode *prev = NULL, *curr = head;
    // 当前节点不为空时循环
    while (curr)
    {
        // 保存下一个节点
        ListNode *next = curr->next;
        // 反转指针，将当前节点指向前驱节点
        curr->next = prev;
        // 更新前驱节点和当前节点
        prev = curr;
        curr = next;
    }
    // 返回新的头节点，即原单链表的尾节点
    return prev;
}

// 创建新节点
ListNode *createNode(int val)
{
    // 分配节点内存空间
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    // 初始化节点值和指针
    node->val = val;
    node->next = NULL;
    // 返回新节点
    return node;
}

// 创建单链表
ListNode *createList(int *nums, int size)
{
    if (size == 0)
    { // 如果数组为空，返回 NULL
        return NULL;
    }
    // 创建头节点，并将其值设置为数组的第一个元素
    ListNode *head = createNode(nums[0]);
    ListNode *curr = head;
    // 遍历数组，创建新节点并将其插入到单链表的尾部
    for (int i = 1; i < size; i++)
    {
        curr->next = createNode(nums[i]);
        curr = curr->next;
    }
    // 返回单链表的头节点
    return head;
}

// 打印单链表
void printList(ListNode *head)
{
    ListNode *curr = head;
    while (curr)
    {
        printf("%d -> ", curr->val);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main()
{
    // 测试代码
    int nums[] = {1, 2, 3, 4, 5};
    int size = sizeof(nums) / sizeof(nums[0]);
    // 创建单链表，并打印原始的单链表
    ListNode *head = createList(nums, size);
    printf("Original list: ");
    printList(head);
    // 反转单链表，并打印反转后的单链表
    head = reverseList(head);
    printf("Reversed list: ");
    printList(head);
    // 释放单链表的内存空间
    ListNode *tmp = NULL;
    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    return 0;
}

#endif // __REVERSED_SINGLE_LIST_
