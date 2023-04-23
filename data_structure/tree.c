#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 树的结点
typedef struct node
{
    int data;           //
    struct node *left;  // 左孩子结点
    struct node *right; // 右孩子结点
} Node;

// 树根
typedef struct
{
    Node *root; //
} Tree;

/**
 * @brief 创建树--插入数据
 *
 * @param tree
 * @param value
 */
void insert(Tree *tree, int value)
{
    // 创建一个节点，左右指针均指向空，数据为value
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    // 判断树是不是空树，如果是，直接让树根指向这一结点
    if (tree->root == NULL)
    {
        tree->root = node;
    }
    else
    {                            // 不是空树
        Node *temp = tree->root; // 从树根开始
        while (temp != NULL)
        {
            if (value < temp->data)
            { // 小于就进左儿子
                if (temp->left == NULL)
                {
                    temp->left = node; //
                    return;
                }
                else
                { // 继续向下搜寻
                    temp = temp->left;
                }
            }
            else
            { // 否则进右儿子
                if (temp->right == NULL)
                {
                    temp->right = node; //
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
    return;
}

/**
 * @brief 树的先序遍历 Preorder traversal,根左右
 *
 * @param node
 */
void preorder(Node *node)
{
    if (node != NULL)
    {
        printf("%d\n", node->data);
        inorder(node->left);
        inorder(node->right);
    }
}

/**
 * @brief 树的中序遍历,In-order traversal,左根右
 *
 * @param node
 */
void inorder(Node *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        printf("%d\n", node->data);
        inorder(node->right);
    }
}

/**
 * @brief 树的后序遍历，左右根
 * 
 * @param node 
 */
void postorder(Node *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        inorder(node->right);
        printf("%d\n", node->data);
    }
}




