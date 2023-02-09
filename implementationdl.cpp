#include<iostream>
using namespace std;

class NODE
{
    int data;
    NODE* next;
    NODE* prev;
    public:
    NODE(int data)
    {
      this->data=data;
      this->next=NULL;
      this->prev=NULL;
    }
    void insertF(NODE* &head,int x);
    void insertL(NODE* &head,int x);
    void insertR(NODE* &head,int x,int pos);
    void display(NODE* &head);
    int deleteF(NODE* &head);
    int deleteL(NODE* &head);
    int deleteR(NODE* &head,int pos);
    int size(NODE* &head);
};

void NODE::insertF(NODE* &head,int x)
{
    NODE* temp=new NODE(x);
    if(head==NULL)
    {
        head=temp;
    }
    else 
    {
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}
void NODE::insertL(NODE* &head,int x)
{
    NODE* temp=new NODE(x);
    NODE*p;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
      for(p=head;p->next!=NULL;p=p->next);
      p->next=temp;
      temp->prev=p;
    }
}
void NODE::insertR(NODE* &head,int x,int pos)
{
    NODE* temp=new NODE(x);
    NODE*p,*t;
    int i;
    int l=size(head);
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
      if(pos==1)
      insertF(head,x);
      else if(pos==l+1)
      insertL(head,x);
      else if(pos<0&&pos>l+1)
      cout<<"invalid position";
      else
      {
        for(p=head,i=1;i<(pos-1);i++,p=p->next);
        temp->next=p->next;
        p->next->prev=temp;
        p->next=temp;
        temp->prev=p;
      }
    }
}
int NODE::size(NODE* &head)
{
    NODE*p;
    int i;
    if(head==NULL)
    {
        cout<<"empty list:"<<endl;
    }
    else
    {for(p=head,i=0;p!=NULL;i++,p=p->next);
    return i;
    }
}
void NODE::display(NODE* &head)
{
    NODE*p;
    if(head==NULL)
    {
        cout<<"empty list"<<endl;
    }
    else
    {for(p=head;p!=NULL;p=p->next)
    cout<<p->data<<" ";
    }
}
int NODE::deleteF(NODE* &head)
{
    NODE* p;
    int x;
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
    }
    p=head;
    head=p->next;
    head->prev=NULL;
    x=p->data;
    delete p;
    return x;

}
int NODE::deleteL(NODE* &head)
{
    NODE*p,*t;
    int x;
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
    }
    else
    {
        for(p=head;p->next!=NULL;t=p,p=p->next);
        t->next=NULL;
        x=p->data;
        delete p;
        return x;


    }
}
int NODE::deleteR(NODE* &head,int pos)
{
    NODE*p,*t;
    int x,l,i;
    l=size(head);
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
    }
    else
    {
       if(pos==1)
          {
            deleteF(head);
          }
       else if(pos==l)
          {
            deleteL(head);
          }
       else if(pos<0 &&pos>l)
         {
            cout<<"invalid position:";
         }
       else
       {
          for(p=head,i=1;i<(pos-1);i++,p=p->next);
          t=p->next;
          p->next=t->next;
          t->next->prev=p;
          x=t->data;
          delete t;
       }
       return x;
    }
}
int main()
{
    NODE* node=new NODE(10);
    NODE* head=NULL;
    int ch,x,k,pos;
    cout<<"\n1.insert first\n2.insert last\n3.insert random\n4.display\n5.delete first\n6.delete last\n7.delete random\n8.size\n9.exit"<<endl;
    do
    {
        cout<<"enter your choice:";
        cin>>ch;
        switch(ch)
        {
           case 1:
             cout<<"enter the value have to insert:";
             cin>>x;
             node->insertF(head,x);
             break;
           case 2:
           cout<<"enter the value you have to insert:";
           cin>>x;
           node->insertL(head,x);
           break;
           case 3:
             cout<<"enter the value you have to insert:";
             cin>>x;
             cout<<"enter the position at which you have to insert:";
             cin>>pos;
             node->insertR(head,x,pos);
             break;
           case 4:
            node->display(head);
            break;
           case 5:
             k=node->deleteF(head);
             cout<<"deleted element is:"<<k<<endl;
             break;
           case 6:
            k=node->deleteL(head);
            cout<<"deleted value is:"<<k<<endl;
            break;
           case 7:
           cout<<"enter the position you want to delete the node:";
           cin>>pos;
           k=node->deleteR(head,pos);
           cout<<"the deleted value is:"<<k<<endl;
           break;   
           case 8:
             k=node->size(head);
             cout<<"size of list is:"<<k<<endl;
             break;
           case 9:
            cout<<"exit"<<endl;       

        }
    }while(ch!=9);
    return 0;
}