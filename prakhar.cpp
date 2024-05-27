#include <bits/stdc++.h>
using namespace std;


class Node{
    public:
    int val;
    Node* next ;

    Node(int val )
    {
        this->next = NULL;
        this->val = val;
    }
};

class LinkedList{
    public:
    Node* head ;
    Node* tail ;
    int size;

    LinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0 ;

    }

    void insertAtHead(int val)
    {
        Node* temp =new Node(val);

        if(size==0) {
        head = temp;
        tail = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
        size++;
    }

    void insertAtTail(int val)
    {
        Node* temp = new Node(val);
        if(size == 0){
        head = temp;
        tail = temp;
        // head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void insertAtIndex(int val, int index)
    {
        if(index < 0 || index > size)
        cout<<"Invalid Index"<<endl;
        else if(index == 0)
        insertAtHead(val);
        else if(index == size-1)
        insertAtTail(val);
        else
        {
        Node* temp = head;
        Node* t = new Node(val);
        for(int i = 1 ; i<=index-1;i++)
        {
            temp = temp->next;
        }
        t->next = temp->next;
        temp->next=t;
        size++;
        }
    }

    void display()
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }



};



int main()
{
    LinkedList ll;
    ll.insertAtHead(12);
    ll.insertAtHead(15);
    ll.insertAtHead(14);
    ll.display();
}