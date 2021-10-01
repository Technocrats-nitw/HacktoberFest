// Code snippets for intersection of 2 linkedlists
int intersectPoint(Node* head1, Node* head2)
{
    Node* a=head1,*b=head2;
    while(a!=b)
    {
        if(a->next==NULL)
        a=head2;
        else
        a=a->next;
        if(b->next==NULL)
        b=head1;
        else
        b=b->next;
    }
    return a->data;
    // Your Code Here
}
// Two Pointer Method
// Time Complexity : O(M+N)
// Space Complexity : O(1)

Node* Floyd(Node* head)
    {
        Node* sp=head,*fp=head;
        sp=sp->next;
        fp=fp->next->next;
        while(sp!=fp)
        {
            sp=sp->next;
            fp=fp->next->next;
        }
        sp=head;
        while(sp!=fp)
        {
            sp=sp->next;
            fp=fp->next;
        }
        return sp;
    }
int intersectPoint(Node* head1, Node* head2)
{
    Node *a=head1;
    while(a->next)
    a=a->next;
    a->next=head1;
    return Floyd(head2)->data;
    // Your Code Here
}

// Floyd cycle method
// Time Complexity : O(M+N)
// Space Complexity : O(1)

struct Node* reverseList(struct Node *head)
    {
        if(head==NULL)
        return head;
        Node* curr=head->next,*prev=NULL;
        while(curr)
        {
            head->next=prev;
            prev=head;
            head=curr;
            curr=curr->next;
        }
        head->next=prev;
        return head;
    }
int intersectPoint(Node* head1, Node* head2)
{
    Node *a=head1;
    int s1=0,s2=0;
    while(a)
    a=a->next,s1++;
    a=head2;
    while(a)
    a=a->next,s2++;
    head1=reverseList(head1);
    a=head2;
    int t=0;
    while(a)
    a=a->next,t++;
    t=(s1+s2-t)/2;
    a=head1;
    while(t)
    a=a->next,t--;
    return a->data;
    // Your Code Here
}

// Reverse LL method
// Time Complexity : O(M+N)
// Space Complexity : O(1)

int intersectPoint(Node* head1, Node* head2)
{
    stack<Node*>a,b;
    while(head1)
    a.push(head1),head1=head1->next;
    while(head2)
    b.push(head2),head2=head2->next;
    Node* k=a.top();
    a.pop();b.pop();
    while(!a.empty() && !b.empty())
    {
        if(a.top()!=b.top())
        return k->data;
        else
        {
            k=a.top();
            a.pop();
            b.pop();
        }
    }
    return k->data;
    // Your Code Here
}

// Stack Method
// Time Complexity : O(M+N)
// Space Complexity : O(M+N)

int intersectPoint(Node* head1, Node* head2)
{
    unordered_set <Node*> s;
    Node* a=head1;
    while(a)
    s.insert(a),a=a->next;
    a=head2;
    while(a)
    {
        if(s.find(a)!=s.end())
        return a->data;
        a=a->next;
    }
    // Your Code Here
}

// Hashing method
// Time Complexity : O(M+N)
// Space Complexity : O(M+N)
