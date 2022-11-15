#include <stdio.h>   
#include <malloc.h>  
struct node  
{  
    struct node *left;  
    int data;  
    struct node *right;  
};  
   
void main()  
{  
    void insert(struct node **,int);  
    void inorder(struct node *);  
    void postorder(struct node *);  
    void preorder(struct node *);  
   
    struct node *ptr = NULL;  
    int no,i,num;      
    int data,choice;   
        do      
        {  
            printf("\nSelect one of the operations:");  
            printf("\n1. To insert a new node in the Binary Tree");  
            printf("\n2. To display the nodes of the Binary Tree Preorder Traversal");  
            printf("\n3. To display the nodes of the Binary Tree Inorder Traversal");  
            printf("\n4. To display the nodes of the Binary Tree Postorder Traversal");
            printf("\n5. Exit\n");    
            scanf("%d",&choice);              
            switch (choice)  
            {  
            case 1 :   
                printf("Enter the value to be inserted\n");  
                scanf("%d",&data);  
                insert(&ptr,data);                    
                break;                            
            case 2 :   
                printf("Preorder Traversal of the Binary Tree:\n");  
                preorder(ptr);  
                break;  
            case 3 :   
                printf("Inorder Traversal of the Binary Tree:\n");  
                inorder(ptr);  
                break;  
            case 4 :   
                printf("Postorder Traversal of the Binary Tree:\n");  
                postorder(ptr);  
                break; 
            case 5:
            printf("Program Exit Sucessfully!\n");
            break;       
            default :   
                printf("Invalid Choice\n");  
                break;     
            }                           
        } while (choice!=5);  
}  
   
void insert(struct node **p,int num)  
{  
    if((*p)==NULL)  
    {  
        printf("Leaf node created.");  
        (*p)=malloc(sizeof(struct node));  
        (*p)->left = NULL;  
        (*p)->right = NULL;  
        (*p)->data = num;  
        return;  
    }  
    else  
    {  
        if(num==(*p)->data)  
        {  
            printf("REPEATED ENTRY ERROR VALUE REJECTED\n");  
            return;  
        }  
        if(num<(*p)->data)  
        {  
            printf("Directed to left link.\n");  
            insert(&((*p)->left),num);  
        }  
        else  
        {  
            printf("Directed to right link.\n");  
            insert(&((*p)->right),num);  
        }  
    }  
    return;  
}  
   
void inorder(struct node *p)  
{  
    if(p!=NULL)  
    {  
        inorder(p->left);  
        printf("%d ",p->data);  
        inorder(p->right);  
    }  
    else  
    return;  
}  
   
void preorder(struct node *p)  
{  
    if(p!=NULL)  
    {  
        printf("%d ",p->data);  
        preorder(p->left);  
        preorder(p->right);  
    }  
    else  
    return;  
}  
   
void postorder(struct node *p)  
{  
    if(p!=NULL)  
    {  
        postorder(p->left);  
        postorder(p->right);  
        printf("%d ",p->data);  
    }  
    else  
    return;  
}  
