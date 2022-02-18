#include <stdio.h>
#include <stdlib.h>

struct TAG
{
    int DATA;
    struct TAG *LCHILD;
    struct TAG *RCHILD;
};

typedef struct TAG BST;

BST* CREATE(int X)
{
    BST *TEMP;
    TEMP = (BST*)malloc(sizeof(BST));
    TEMP -> RCHILD = NULL;
    TEMP -> LCHILD = NULL;
    TEMP -> DATA = X;
    return TEMP;
}

void INORDER_TRAVERSE(BST *Root)
{
    if(Root != NULL)
    {
        INORDER_TRAVERSE(Root -> LCHILD);
        printf("%d - ", Root -> DATA);
        INORDER_TRAVERSE(Root -> RCHILD);   
    }
}

void PREORDER_TRAVERSE(BST *Root)
{
    if(Root != NULL)
    {
        printf("%d - ", Root -> DATA);
        PREORDER_TRAVERSE(Root -> LCHILD);
        PREORDER_TRAVERSE(Root -> RCHILD);   
    }
}

void POSTORDER_TRAVERSE(BST *Root)
{
    if(Root != NULL)
    {
        POSTORDER_TRAVERSE(Root -> LCHILD);
        POSTORDER_TRAVERSE(Root -> RCHILD);  
        printf("%d - ", Root -> DATA); 
    }
}

BST *INSERT(BST* Root, int X)
{
    if(Root == NULL)
        return CREATE(X);
    else if(X < Root -> DATA)
        Root -> LCHILD = INSERT(Root -> LCHILD, X);
    else
        Root -> RCHILD = INSERT(Root -> RCHILD, X);
    return Root;
}

void main()
{
    BST *ROOT = NULL;
    ROOT = INSERT(ROOT, 21);
    ROOT = INSERT(ROOT, 10);
    ROOT = INSERT(ROOT, 31);
    ROOT = INSERT(ROOT, 11);
    ROOT = INSERT(ROOT, 91);
    printf("Inorder: ");
    INORDER_TRAVERSE(ROOT);
    printf("\nPreorder: ");
    PREORDER_TRAVERSE(ROOT);
    printf("\nPostorder: ");
    POSTORDER_TRAVERSE(ROOT);
}