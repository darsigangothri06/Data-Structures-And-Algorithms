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
    INORDER_TRAVERSE(ROOT);
}