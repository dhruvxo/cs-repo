#include <stdio.h>

struct node
{
    int data;
    struct tnode *right;
    struct tnode *left;
};

struct node *Create(struct node *, int);
void Inorder(struct node *);
void Preorder(struct node *);
void Postorder(struct node *);

int main()
{
    struct node *root = NULL;
    int choice, item, n, i;
    do
    {
        printf("\n Binary Search Tree \n");
        printf("\n1. Creation of BST");
        printf("\n2. Inorder Traversal");
        printf("\n3. Preorder Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Exit\n");

        printf("\nEnter Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            root = NULL;
            printf("\n Number of Nodes to be inserted ? ");
            scanf("%d",&n);
            for(i = 1; i <= n; i++)
            {
                printf("\nEnter data for node %d : ", i);
                scanf("%d",&item);
                root = Create(root,item);
            }
            printf("\nBST with %d nodes is inserted\n", n);
            break;

        case 2:
            printf("\n INORDER Traversal \n");
            Inorder(root);
            break;

        case 3:
            printf("\n PREORDER Traversal \n");
            Preorder(root);
            break;

        case 4:
            printf("\n POSTORDER Traversal \n");
            Postorder(root);
            break;

        case 5:
            printf("\n Exit \n");
            break;

        default:
            printf("\n Invalid Option \n");
            break;
        }
    } while(choice != 5);
    return 0;
}


struct node *Create(struct node *root, int item)
{
    if(root == NULL)
    {
        root = (struct node *)malloc(sizeof(struct node));
        root->left = root->right = NULL;
        root->data = item;
        return root;
    }
    else
    {
        if(item < root->data )
            root->left = Create(root->left,item);
        else if(item > root->data )
            root->right = Create(root->right,item);
       return(root);
    }
}

void Inorder(struct node *root)
{
    if( root != NULL)
    {
        Inorder(root->left);
        printf(" %d ",root->data);
        Inorder(root->right);
    }
}

void Preorder(struct node *root)
{
    if( root != NULL)
    {
        printf(" %d ",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(struct node *root)
{
    if( root != NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        printf(" %d ",root->data);
    }
}