#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    float coeff;
    int expo;
    struct node *link;
}poly;
poly *insertion(poly *head,float co,int ex)
{
    poly *temp;
    poly *newp=malloc(sizeof(poly));
    newp->coeff=co;
    newp->expo=ex;
    newp->link=NULL;
    if(head==NULL || ex > head->expo)
    {
        newp->link=head;
        head=newp;
    }
    else
    {
        temp=head;
        while(temp->link!=NULL && temp->link->expo >= ex)
              temp=temp->link;
        newp->link=temp->link;
        temp->link=newp;
    }
  return head;  
}
poly *create(poly *head)
{
    int n,i,expo;
    float coeff;
    printf("Enter no of terms : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter coefficient of term %d : ",i+1);
        scanf("%f",&coeff);
        printf("Enter exponent of term %d : ",i+1);
        scanf("%d",&expo);
        head=insertion(head,coeff,expo);
    }
  return head;  
}
void print(poly *head)
{
    if(head==NULL)
       printf("Not any polynomial");
    else
    {
        poly *temp=head;
        while(temp!=NULL)
        {
            printf("%.1fX^%d", temp->coeff, temp->expo);
            temp=temp->link;
            if(temp!=NULL)
               printf(" + ");
            else
               printf("\n");   
        }
    }   
}
void addition(poly *head1,poly *head2)
{
      poly *ptr1=head1;
      poly *ptr2=head2;
      poly *head3=NULL;
      while(ptr1!=NULL && ptr2!=NULL)
      {
        if(ptr1->expo==ptr2->expo)
        {
            head3=insertion(head3,ptr1->coeff+ptr2->coeff,ptr1->expo);
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }
        else if(ptr1->expo > ptr2->expo)
        {
            head3=insertion(head3,ptr1->coeff,ptr1->expo);
            ptr1=ptr1->link;
        }
        else if(ptr1->expo < ptr2->expo)
        {
            head3=insertion(head3,ptr2->coeff,ptr2->expo);
            ptr2=ptr2->link;
        }
      }
      while(ptr1!=NULL)
      {
        head3=insertion(head3,ptr1->coeff,ptr1->expo);
        ptr1=ptr1->link;
      }
      while(ptr2!=NULL)
      {
        head3=insertion(head3,ptr2->coeff,ptr2->expo);
        ptr2=ptr2->link;
      }
      printf("polynomial addition is: ");
    print(head3);
}
poly *sepration(poly *head3)
{
    poly *cur,*ptr;
    float co;
    poly *temp=malloc(sizeof(poly));
    cur=head3;
    while(cur->link!=NULL)
    {
       if(cur->expo == cur->link->expo)
       {
        co=cur->coeff +cur->link->coeff;
        cur->coeff=co;
        temp=cur->link;
        cur->link=cur->link->link;
        free(temp);
       }
       else
       {
       cur=cur->link;
       }
    }
   return head3; 
}
void multiplication(poly *head1, poly *head2)
{
    int coef1,expo1;
    poly *ptr1=head1;
    poly *ptr2=head2;
    poly *head3=NULL;
    while(ptr1!=NULL)
    {
        ptr2=head2;
        while(ptr2!=NULL)
        {
            coef1=ptr1->coeff * ptr2->coeff;
            expo1=ptr1->expo + ptr2->expo;
            head3=insertion(head3,coef1,expo1);
            ptr2=ptr2->link;
        }
        ptr1=ptr1->link;
    }
    head3=sepration(head3);
    printf("polynomial multiplication is : ");
    print(head3);
}
int main()
{
    poly *head1=NULL;
    poly *head2=NULL;
    printf("Enter 1st polynomial ");
    head1=create(head1);
    printf("\n1st polynomial : ");
    print(head1);
    printf("\n");
    printf("Enter 2nd polynomial ");
    head2=create(head2);
    printf("\n2nd polynomial : ");
    print(head2);
    printf("\n");
    addition(head1,head2);
    printf("\n");
    multiplication(head1,head2);
    return 0;
}