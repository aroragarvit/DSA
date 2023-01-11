

#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(int value , Node **head){
Node *newone  = new Node(value);
Node *temp =  *head ;
while(temp->next != NULL){
    temp=temp->next;
}

temp ->next = newone ;
newone -> next = NULL ;

 
}
 
void insertAtHead(int value , Node * *head){     //The reason why there is no change in the output is that it is created a copy pointer for the function. So, the change in the address of the pointer does not reflect out of the function. References or double-pointer can be used for this.
    Node *newone = new Node(value);
    newone->next = *head;
    *head = newone;
}


void recursiveDisplay(Node *head){
    if (head==NULL){
        return;
    }
    cout<<head->data<<" ";
    recursiveDisplay(head->next);                                  
    

}

void insertInMiddle(int value, int pos, Node * * head){

Node *newone = new Node(value);
Node * p = * head ;
for (int i = 0 ; i< pos-1 ; i++)
{
  p = p -> next;
}

newone ->next = p ->next ;
p->next = newone ;

}

void reverseLinkedListNonRecursive (Node * head) // only printing no permanent change in  linked list 
{
    Node* curr = head;
    Node* prev = NULL ; 
    Node* nextPointer = NULL ;
                                         
    while(curr != NULL){    
     
       nextPointer  = curr-> next ;
       curr -> next = prev ;
       prev = curr ;
       curr = nextPointer;

 }
    head = prev ;
   

    recursiveDisplay(head);                                   

}

Node * reverseLinkedListRecursive(Node * head)
  
 {
  if(head == NULL || head-> next == NULL )
  {
    return head;
  }
else{
    
    Node * rest = reverseLinkedListRecursive(head->next);  // 1->2->3->4 function(1) call function(2) after next function 2 call ends and returns for previous function call in function stack head is 1 and head->next is 2 
    head->next->next = head ;
    head->next = NULL;
    return rest ;
    
}

}


int main(){
    Node * node1 = new Node(10);     // pointer and memory allocated for that pointer that can be accessed by that pointer

    Node * head = node1;             // simply pointer for that class 

    
    insertAtTail(20,&head);
    insertAtTail(30,&head);
    insertAtTail(40,&head);
    insertAtTail(50,&head);
    insertAtTail(60,&head);
    insertAtHead(0,&head);
    recursiveDisplay(head);
    cout<< "__________________________";
    insertInMiddle(7,4,&head);

    recursiveDisplay(head);

     cout<< "__________________________";

     Node *temp = reverseLinkedListRecursive(head);
     recursiveDisplay(temp);

}
