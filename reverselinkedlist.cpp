#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
void LinkedListtraversal(struct Node *ptr)
{
    while(ptr != NULL)
    {
        printf("%i ", ptr->data);
        ptr=ptr->next;
    }
}
void addatindex(struct Node **head,int pos, int val)
{
    struct Node *p=(struct Node*)malloc(sizeof(struct Node*));
    p=*head;
    if(pos==0)
    {
       struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
       temp->data=val;
       temp->next=*head;
       *head=temp;
       return;
    }
    else if (pos!=0){
        struct Node *q;
        
        struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
        temp->data=val;
        int i=0;
        while(i!=pos-1)
        {
            p=p->next;
            i++;
        }
        if(p->next!=NULL)
        {
            q=p->next;
            temp->next=q;
            p->next=temp;
        }
        if(p->next==NULL)
        {
            p->next=temp;
            temp->next=NULL;
        }
    }
}
void reverseLinkedlist(struct Node **head)
{
    struct Node *curr=*head;
    struct Node *prev=NULL;
    struct Node *next=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
}
struct Node* reverseaLinkedingrps(struct Node *head, int n)
{
    stack<Node*> S;
    struct Node *p=head;
    struct Node *q=NULL;
    while(p!=NULL)
    {
        int count=0;
        while(p!=NULL && count<n)
        {
            S.push(p);
            p=p->next;
            count++;
        }
        while(S.size()>0)
        {
            if(q==NULL)
            {
                q=S.top();
                head=q;
                S.pop();
            }
            else 
            {
                q->next=S.top();
                q=q->next;
                S.pop();
            }

        }
    }
    q->next=NULL;
    return head; 
}
int main()
{
    struct Node *ptr;
    struct Node* head= (struct Node *)malloc(sizeof(struct Node*));
    head->data=0;
    head->next=NULL;
    ptr=head;
    
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        
        int x;
        cin>>x;
        addatindex(&head,i,x);
    }
    
    ptr=reverseaLinkedingrps(head,2);
    LinkedListtraversal(ptr);

}
