/*
@author:ASISH PAL
@Software Engineer
@Orbitax LLC.
********Link List Basic**********
   1. Insert
   2. Delete
   3. Traverse
   4. Reverse
   5. Copy Link List
   6. CompareLinked List
   7. Search Data
   8. InsertFront
   9. Modify Data
*/
#include<iostream>
#include<stdio.h>
using namespace std;

struct Node{
  int data;
  Node *next;
  Node *previous;
};

 Node *head;
 Node *tail;

void Initialize(){
   head = new Node;
   head->previous = NULL;
   tail = head;
}

void Insert(int num){
   tail->data = num;
   tail->next = new Node;
   tail->next->previous = tail;
   tail = tail->next;
}
void TraverseDisplay(){
    Node *list = head;
    while(list!=tail){
        cout<<list->data<<" ";
        list = list->next;
    }
    cout<<endl;
}

void ReverseDisplay(){
    Node *list = tail;
    list = list->previous;
    while(list!=NULL){
       cout<<list->data<<" ";
       list = list->previous;
    }
  cout<<endl;
}

bool Search(int data){
   Node * list = head;
   while(list != tail){
     if(list->data == data) return true;
     list = list->next;
   }
   return false;
}

int Delete(int data){
  Node *cur = head;
  if(cur->data == data){
     head = cur->next;
     head->previous = NULL;
     delete cur;
     return true;
  }
  while(cur!=tail){
    if(cur->data == data){
       cur->previous->next = cur->next;
       cur->next->previous = cur->previous;
       delete cur;
       return true;
    }
    cur = cur->next;
  }
  return false;
}

void InsertFront(int data){
    Node * tmp = new Node;
    tmp->data = data;
    tmp->previous = NULL;
    tmp->next = head;
    head->previous = tmp;
    head = tmp;
}

bool ModifyData(int findData, int replaceData){
    Node *cur = head;
    while(cur!=tail){
    if(cur->data == findData){
       cur->data = replaceData;
       return true;
    }
    cur = cur->next;
  }
  return false;
}
int main(){
   Initialize();
   for(int i = 1; i<12; i++)
     Insert(i);
   cout<<"TraverseList: ";TraverseDisplay();
   cout<<"ReverseList: ";ReverseDisplay();
   cout<<"Search Data: "<<Search(7)<<endl;
   cout<<"Delete Data: "; Delete(1);cout<<"Success"<<endl;
   cout<<"TraverseList: ";TraverseDisplay();
   Insert(1);
   cout<<"TraverseList: ";TraverseDisplay();
   InsertFront(20);
   cout<<"TraverseList: ";TraverseDisplay();
   cout<<"ReverseList: ";ReverseDisplay();
   InsertFront(21);
   cout<<"TraverseList: ";TraverseDisplay();
   cout<<"ReverseList: ";ReverseDisplay();
   cout<<"ModifyData: "<<ModifyData(21, 11)<<endl;
   cout<<"TraverseList: ";TraverseDisplay();
   return 0;
}
