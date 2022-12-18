// Write a program which create binary search tree and implement 
// tree traversing methods in order, preorder and post-order 
// traversal.
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *left, *right;
};
struct node *root = NULL;
void CreateBST(struct node *,int);
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
int main()
{
    int n, val,i=0,ch;
    printf("\n1)Create a Binary Search Tree(-1 to end)");
    printf("\n2)Traverse in Inorder.");
    printf("\n3)Traverse in Preorder.");
    printf("\n4)Traverse in Postorder.");
    printf("\n5)Exit");
    while(i>=0)
    {
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                while(1)
                {
                    printf("\nEnter Node : ");
                    scanf("%d",&val);
                    if(val==-1)
                    break;
                    CreateBST(root, val);
                }
                break;
            case 2:
                printf("Inorder traversal: ");
                inorder(root);
                break;
            case 3:
                printf("Preorder traversal: ");
                preorder(root);
                break;
            case 4:
                printf("Postorder traversal: ");
                postorder(root);
                break;
            case 5:
                return 0;
            default:
                printf("\nInvalid Input!!");    
        }
    }  
}
void CreateBST(struct node* node, int val)
{
    if (root == NULL)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = val;
        newnode->left = newnode->right = NULL;
        root=newnode;
        printf("%d is Root Node",val);
    }
    else if (val < node->data)
    {
        if(node->left==NULL)
        {
            struct node *newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = val;
            newnode->left = newnode->right = NULL;
            node->left=newnode;
            printf("%d is Left Child of %d",val,node->data);
        }
        else
        {
            CreateBST(node->left,val);
        }
    }
    else if (val >= node->data)
    {
        if(node->right==NULL)
        {
            struct node *newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = val;
            newnode->left = newnode->right = NULL;
            node->right=newnode;
            printf("%d is Right Child of %d",val,node->data);
        }
        else
        {
            CreateBST(node->right,val);
        }
    }
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

/*
OUTPUT:
1)Create a Binary Search Tree(-1 to end)
2)Traverse in Inorder.
3)Traverse in Preorder.
4)Traverse in Postorder.
5)Exit
Enter your choice:1

Enter Node : 25
25 is Root Node
Enter Node : 19
19 is Left Child of 25
Enter Node : 35
35 is Right Child of 25
Enter Node : 9
9 is Left Child of 19
Enter Node : 15
15 is Right Child of 9
Enter Node : 3
3 is Left Child of 9
Enter Node : 7
7 is Right Child of 3
Enter Node : 11
11 is Left Child of 15
Enter Node : 13
13 is Right Child of 11
Enter Node : 50
50 is Right Child of 35
Enter Node : 43
43 is Left Child of 50
Enter Node : 62
62 is Right Child of 50
Enter Node : 55
55 is Left Child of 62
Enter Node : 47
47 is Right Child of 43
Enter Node : 39
39 is Left Child of 43
Enter Node : -1

Enter your choice:2
Inorder traversal: 3    7       9       11      13      15      19      25      35      39      43      47      50      55      62
Enter your choice:3
Preorder traversal: 25  19      9       3       7       15      11      13      35      50      43      39      47      62      55
Enter your choice:4
Postorder traversal: 7  3       13      11      15      9       19      39      47      43      55      62      50      35      25
Enter your choice:5
*/