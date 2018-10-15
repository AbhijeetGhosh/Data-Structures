#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
};
class Stack
{
    Node *top=NULL,*p;

public:
    void push(int a)
    {
    //The only difference here is that instead of inserting node at end of linked list
    //as we usually do, we insert node at the beginning of linked list.

    //Which just means that instead of top moving left with every new element top will now move right with
    //every new element that is inserted. New elements will inserted to the right of linked list now.

    //this helps as we can only traverse left in a singly linked list as so it is difficult to
    //delete an element and assign the right element as top so we do it this way.
    p = new Node;
    p->data = a;
    p->next = NULL;

        if(top==NULL)
        top=p;
        else
        {
        p->next=top;
        top=p;
        }
    }

    void pop(){
    if(top==NULL){
        cout<<"Stack is empty!!";
    }
    else{
        cout<<"Deleted element is "<<top->data;
        p=top;
        top=top->next;
        delete(p);
    }
    }

    void showstack()
    {
    Node *q;
    q=top;

    if(top==NULL){
        cout<<"Stack is empty!!";
    }
    else{
        while(q!=NULL)
        {
            cout<<q->data<<" ";
            q=q->next;
        }
    }
    }
};
int main()
{
    Stack ob;
    int ch,x;
    Node *nptr;

    while(1)
    {
        cout<<"\n\n1.Push\n2.Pop\n3.Display\n4.Exit";
        cout<<"\nEnter your choice(1-4):";
        cin>>ch;

        switch(ch){
            case 1: cout<<"\nEnter data:";
                    cin>>x;
                    ob.push(x);
                    break;

            case 2: ob.pop();
                    break;

            case 3: ob.showstack();
                    break;

            case 4: exit(0);

            default: cout<<"\nWrong choice!!";

        }
    }

    return 0;
}
