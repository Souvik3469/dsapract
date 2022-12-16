#include <stdio.h>
#include <stdlib.h>
#define MAX 50

struct node
{
    struct node *lchild;
    int info;
    struct node *rchild;
};

struct node *insert_nrec(struct node *root, int ikey);
void nrec_pre(struct node *root);
void nrec_in(struct node *root);
void nrec_post(struct node *root);
int height(struct node *root);

// void push_stack(struct node *item);
// struct node *pop_stack();
// int stack_empty();

int main()
{
    struct node *root = NULL, *ptr;
    int choice, k;
    printf("1.Insert\n2.Preorder Traversal\n3.Inorder Traversal\n4.Postorder Traversal\n5.Quit");
    while (1)
    {

        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            printf("\nEnter the key to be inserted : ");
            scanf("%d", &k);
            root = insert_nrec(root, k);
            break;

        case 2:
            printf("Preorder Traversal : ");
            nrec_pre(root);

            break;

        case 3:
            printf("Ineorder Traversal : ");
            nrec_in(root);

            break;

        case 4:
            printf("Postorder Traversal : ");
            nrec_post(root);

            break;

        case 5:
            exit(1);

        default:
            printf("\nWrong choice\n");
        }

    } /*End of while */

    return 0;
}

struct node *insert_nrec(struct node *root, int ikey)
{
    struct node *tmp, *par, *ptr;

    ptr = root;
    par = NULL;

    while (ptr != NULL)
    {

        par = ptr;
        if (ikey < ptr->info)
            ptr = ptr->lchild;
        else if (ikey > ptr->info)
            ptr = ptr->rchild;
        else
        {
            printf("\nDuplicate key");
            return root;
        }
    }

    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = ikey;
    tmp->lchild = NULL;
    tmp->rchild = NULL;

    if (par == NULL)
        root = tmp;
    else if (ikey < par->info)
        par->lchild = tmp;
    else
        par->rchild = tmp;

    return root;
}

void nrec_pre(struct node *root)
{
    int top = -1;
    struct node *stack[MAX];
    struct node *ptr = root;
    if (ptr == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    stack[++top] = ptr;
    while (top == -1)
    {
        ptr = stack[top--];
        printf("%d  ", ptr->info);
        if (ptr->rchild != NULL)
            stack[++top] = ptr->rchild;
        if (ptr->lchild != NULL)
            stack[++top] = ptr->lchild;
    }
}

void nrec_in(struct node *root)
{
    int top = -1;
    struct node *stack[MAX];
    struct node *ptr = root;

    if (ptr == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    while (1)
    {
        while (ptr->lchild != NULL)
        {
            stack[++top] = ptr;
            ptr = ptr->lchild;
        }

        while (ptr->rchild == NULL)
        {
            printf("%d  ", ptr->info);
            if (top == -1)
                return;
            ptr = stack[top--];
        }
        printf("%d  ", ptr->info);
        ptr = ptr->rchild;
    }
    printf("\n");
}

void nrec_post(struct node *root)
{
    int top = -1;
    struct node *stack[MAX];
    struct node *ptr = root;
    struct node *q;

    if (ptr == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    q = root;
    while (1)
    {
        while (ptr->lchild != NULL)
        {
            stack[++top] = ptr;
            ptr = ptr->lchild;
        }

        while (ptr->rchild == NULL || ptr->rchild == q)
        {
            printf("%d  ", ptr->info);
            q = ptr;
            if (top == -1)
                return;
            ptr = stack[top--];
        }
        stack[++top] = ptr;
        ptr = ptr->rchild;
    }
    printf("\n");
}

// #include <stdio.h>
// #include <stdlib.h>
// #define MAX 50

// struct node
// {
//     struct node *lchild;
//     int info;
//     struct node *rchild;
// };

// struct node *insert_nrec(struct node *root, int ikey);
// void nrec_pre(struct node *root);
// void nrec_in(struct node *root);
// void nrec_post(struct node *root);
// int height(struct node *root);
// struct node *stack[MAX];
// int top = -1;
// void push_stack(struct node *item);
// struct node *pop_stack();
// int stack_empty();

// int main()
// {
//     struct node *root = NULL, *ptr;
//     int choice, k;
//     printf("1.Insert\n2.Preorder Traversal\n3.Inorder Traversal\n4.Postorder Traversal\n5.Quit");
//     while (1)
//     {

//         printf("\nEnter your choice : ");
//         scanf("%d", &choice);

//         switch (choice)
//         {

//         case 1:
//             printf("\nEnter the key to be inserted : ");
//             scanf("%d", &k);
//             root = insert_nrec(root, k);
//             break;

//         case 2:
//             printf("Preorder Traversal : ");
//             nrec_pre(root);

//             break;

//         case 3:
//             printf("Ineorder Traversal : ");
//             nrec_in(root);

//             break;

//         case 4:
//             printf("Postorder Traversal : ");
//             nrec_post(root);

//             break;

//         case 5:
//             exit(1);

//         default:
//             printf("\nWrong choice\n");
//         } /*End of switch*/
//     }     /*End of while */

//     return 0;

// } /*End of main( )*/
// struct node *insert_nrec(struct node *root, int ikey)
// {
//     struct node *tmp, *par, *ptr;

//     ptr = root;
//     par = NULL;

//     while (ptr != NULL)
//     {
//         par = ptr;
//         if (ikey < ptr->info)
//             ptr = ptr->lchild;
//         else if (ikey > ptr->info)
//             ptr = ptr->rchild;
//         else
//         {
//             printf("\nDuplicate key");
//             return root;
//         }
//     }

//     tmp = (struct node *)malloc(sizeof(struct node));
//     tmp->info = ikey;
//     tmp->lchild = NULL;
//     tmp->rchild = NULL;

//     if (par == NULL)
//         root = tmp;
//     else if (ikey < par->info)
//         par->lchild = tmp;
//     else
//         par->rchild = tmp;

//     return root;
// } /*End of insert_nrec( )*/

// void nrec_pre(struct node *root)
// {
//     struct node *ptr = root;
//     if (ptr == NULL)
//     {
//         printf("Tree is empty\n");
//         return;
//     }
//     push_stack(ptr);
//     while (!stack_empty())
//     {
//         ptr = pop_stack();
//         printf("%d  ", ptr->info);
//         if (ptr->rchild != NULL)
//             push_stack(ptr->rchild);
//         if (ptr->lchild != NULL)
//             push_stack(ptr->lchild);
//     }

// } /*End of nrec_pre*/

// void nrec_in(struct node *root)
// {
//     struct node *ptr = root;

//     if (ptr == NULL)
//     {
//         printf("Tree is empty\n");
//         return;
//     }
//     while (1)
//     {
//         while (ptr->lchild != NULL)
//         {
//             push_stack(ptr);
//             ptr = ptr->lchild;
//         }

//         while (ptr->rchild == NULL)
//         {
//             printf("%d  ", ptr->info);
//             if (stack_empty())
//                 return;
//             ptr = pop_stack();
//         }
//         printf("%d  ", ptr->info);
//         ptr = ptr->rchild;
//     }
//     printf("\n");
// } /*End of nrec_in( )*/

// void nrec_post(struct node *root)
// {
//     struct node *ptr = root;
//     struct node *q;

//     if (ptr == NULL)
//     {
//         printf("Tree is empty\n");
//         return;
//     }
//     q = root;
//     while (1)
//     {
//         while (ptr->lchild != NULL)
//         {
//             push_stack(ptr);
//             ptr = ptr->lchild;
//         }

//         while (ptr->rchild == NULL || ptr->rchild == q)
//         {
//             printf("%d  ", ptr->info);
//             q = ptr;
//             if (stack_empty())
//                 return;
//             ptr = pop_stack();
//         }
//         push_stack(ptr);
//         ptr = ptr->rchild;
//     }
//     printf("\n");
// } /*End of nrec_post( )*/

// /*Functions for implementation of stack*/
// void push_stack(struct node *item)
// {
//     if (top == (MAX - 1))
//     {
//         printf("Stack Overflow\n");
//         return;
//     }
//     top = top + 1;
//     stack[top] = item;
// } /*End of push_stack()*/

// struct node *pop_stack()
// {
//     struct node *item;
//     if (top == -1)
//     {
//         printf("Stack Underflow....\n");
//         exit(1);
//     }
//     item = stack[top];
//     top = top - 1;
//     return item;
// } /*End of pop_stack()*/

// int stack_empty()
// {
//     if (top == -1)
//         return 1;
//     else
//         return 0;
// } /*End of stack_empty*/
