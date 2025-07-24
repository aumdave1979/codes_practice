# include<iostream>
using namespace std;
class Node {
public:
    char a;
    Node *next;
    Node *prev;
};
class DLL{
    public:
        Node *Head;
        Node *Curr ;
};

int main(){
    Node A;
    A.a='a';

    DLL First_Link;
    First_Link.Head=&A;

    Node B;
    B.a='b';
    A.next=&B;
    B.prev=&A;

    Node c;
    B.next=&c;
    c.a='q';
    c.next=NULL;
    c.prev=&B;
    
    A.prev=NULL;

    First_Link.Curr=&c;

    // while (First_Link.Curr!=NULL)
    // {
    //     cout<<First_Link.Curr->a<<endl;
    //     First_Link.Curr=First_Link.Curr->next;
    // }
    while (First_Link.Curr!=NULL)
    {
        cout<<First_Link.Curr->a<<"\n";
        First_Link.Curr=First_Link.Curr->prev;
    }
    
    return 0;
    
}