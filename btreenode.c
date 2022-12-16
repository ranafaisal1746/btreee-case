# include <stdio.h>
# include <stdlib.h>

struct btreenode 
{
  int data;
  struct btreenode *leftchild;
  struct btreenode *rightchild;
};
struct btreenode *insert(struct btreenode *sr, int num)
{
    struct btreenode *r;
    if(sr == NULL)
    {
        r = (struct btreenode *)malloc(sizeof(struct btreenode));
        r -> data = num;
        r-> leftchild = NULL;
        r->rightchild = NULL;
        
        return r;
    }
    else if(num < sr->data)
    {
        sr-> leftchild = insert(sr->leftchild, num);
    }
    else
    {
        sr -> rightchild = insert(sr->rightchild, num);
    }
    
    return sr;
}

void inorder(struct btreenode *sr)
{
    
    if(sr != NULL)
    {
        inorder(sr->leftchild);
        printf("\t%u", sr);
        inorder(sr->rightchild);
    }
}


int main()
{
    struct btreenode *bt;
    int req, num, i=1;
    bt = NULL;
    printf("Enter number of items to be inserted.");
    scanf("%d", &req);
    while(i <= req)
    {
        printf("\nEnter Data");
        scanf("%d", &num);
        bt = insert(bt, num);
        i++;
    }
    printf("\nInorder traversal \n");
    inorder_data(bt);
    printf("\n");
    inorder(bt);
    
    return 0;
}
