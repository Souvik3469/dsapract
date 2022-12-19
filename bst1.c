#include <stdio.h>
#include <stdlib.h>
#define max 100
#define MAX_Q_SIZE 500
typedef struct bt
{
    int data;
    struct bt *left;
    struct bt *right;
} bt;

bt *ins(bt *root, int val)
{
    bt *ptr = root;
    bt *par = NULL;
    bt *t = (bt *)malloc(sizeof(bt));
    t->data = val;
    t->left = NULL;
    t->right = NULL;

    while (ptr != NULL)
    {
        par = ptr;
        if (val < ptr->data)
            ptr = ptr->left;
        else if (val > ptr->data)
            ptr = ptr->right;
        else
            printf("Duplicate");
    }

    if (par == NULL)
        root = t;
    else if (val < par->data)
        par->left = t;
    else
        par->right = t;
    return root;
}
void in(bt *root)
{
    int top = -1;
    bt *ptr = root;
    bt *stack[max];

    if (ptr == NULL)
    {
        printf("Empty tree");
        return;
    }

    while (1)
    {
        while (ptr->left != NULL)
        {
            stack[++top] = ptr;
            ptr = ptr->left;
        }
        while (ptr->right == NULL)
        {
            printf("%d ", ptr->data);
            if (top == -1)
                return;
            ptr = stack[top--];
        }
        printf("%d ", ptr->data);
        ptr = ptr->right;
    }
    printf("\n");
}
void po(bt *root)
{
    int top = -1;
    bt *ptr = root;
    bt *q;
    bt *stack[max];

    if (ptr == NULL)
    {
        printf("Empty tree");
        return;
    }
    q = root;
    while (1)
    {
        while (ptr->left != NULL)
        {
            stack[++top] = ptr;
            ptr = ptr->left;
        }
        while (ptr->right == NULL || ptr->right == q)
        {
            printf("%d ", ptr->data);
            if (top == -1)
                return;
            q = ptr;
            ptr = stack[top--];
        }
        stack[++top] = ptr;
        ptr = ptr->right;
    }
    printf("\n");
}
bt *minv(bt *root)
{
    bt *cur = root;
    while (cur && cur->left)
        cur = cur->left;
    return cur;
}

bt *del(bt *root, int val)
{
    if (root == NULL)
        return root;
    else if (val < root->data)
        root->left = del(root->left, val);
    else if (val > root->data)
        root->right = del(root->right, val);
    else
    {

        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            bt *t = root->right;
            free(root);
            return t;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            bt *t = root->left;
            free(root);
            return t;
        }
        else
        {
            bt *t = minv(root->right);
            root->data = t->data;
            root->right = del(root->right, t->data);
        }
    }
    return root;
}

bt **createQueue(int *front, int *rear)
{
    bt **queue = (bt **)malloc(
        sizeof(bt *) * MAX_Q_SIZE);

    *front = *rear = 0;
    return queue;
}

void enQueue(bt **queue, int *rear,
             bt *new_node)
{
    queue[*rear] = new_node;
    (*rear)++;
}

bt *deQueue(bt **queue, int *front)
{
    (*front)++;
    return queue[*front - 1];
}

void printLevelOrder(bt *root)
{
    int rear, front;
    bt **queue = createQueue(&front, &rear);
    bt *temp_node = root;

    while (temp_node)
    {
        printf("%d ", temp_node->data);

        /*Enqueue left child */
        if (temp_node->left)
            enQueue(queue, &rear, temp_node->left);

        /*Enqueue right child */
        if (temp_node->right)
            enQueue(queue, &rear, temp_node->right);

        /*Dequeue node and make it temp_node*/
        temp_node = deQueue(queue, &front);
    }
}

int main()
{
    bt *l = NULL;
    int d;
    int a;
    printf("Enter 1 to insert,2 to inorder,3 to postorder,4 to exit:\n");
    while (1)
    {
        int c;
        printf("Enter choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:

            printf("Enter data: ");
            scanf("%d", &d);
            l = ins(l, d);
            break;
        case 2:
            printf("inorder is:\n");
            in(l);
            break;
        case 3:
            printf("postorder is:\n");
            po(l);
            break;
        case 4:
            printf("Enter data to be deleted: ");
            scanf("%d", &a);
            printf("Deleted %d:\n", a);
            l = del(l, a);
            break;
        case 5:
            printf("level order:\n");
            printLevelOrder(l);
            break;
        case 6:
            exit(1);
            break;
        }
    }
    return 0;
}