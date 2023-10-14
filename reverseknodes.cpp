#include <iostream>
using namespace std;
class node{
  public:
  int data;
  node* next;
  node(int data){
    this->data=data;
    this->next=NULL;
  }
};
void print(node* head){
  node* temp=head;
  while(temp!=NULL){
    cout<<temp->data<<"";
    temp=temp->next;
  }
}
node* getmiddle(node* &head){
  if(head==NULL){
    cout<<"ll is empty"<<endl;
    return head;
  }
  if(head->next==NULL){
    return head;
  }
  node* slow=head;
  node* fast=head;
  while(slow!=NULL && fast!=NULL){
    fast=fast->next;
    if(fast!=NULL){
      fast=fast->next;
      slow=slow->next;
    }
  }
  return slow;
}
int getlength(node* &head){
  int len=0;
  node* temp=head;
  while(temp!=NULL){
    temp=temp->next;
    len++;
    
  }
  
return len;
}
node* reversenodes(node* &head,int k){
  if(head==NULL){
    cout<<"ll is empty"<<endl;
  }
  int len=getlength(head);
  if(k>len){
    // cout<<"enter valid value for k"<<endl;
    return head;
  }

  node* prev=NULL;
  node* curr=head;
  node* forward=curr->next;
  int count=0;
while(count<k){
  forward=curr->next;
  curr->next=prev;
  prev=curr;
  curr=forward;
  count++;
}
if(forward!=NULL){
  head->next=reversenodes(forward,k);
}

return prev;
} 
int main() {
  node* head=new node(30);
   node* second=new node(76);
  node* third=new node(56);
  node* fourth=new node(47);
  node* fifth=new node(39);
   node* tail=new node(34);
  head->next=second;
  second->next=third;
  third->next=fourth;
  fourth->next=fifth;
  fifth->next=tail;
  // print(head);
    // cout<<endl<<"middle node is:"<<getmiddle(head)->data<<endl;
    getlength(head);
    head=reversenodes(head,6);
    print(head);
  return 0;
}