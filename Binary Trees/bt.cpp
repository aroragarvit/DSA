#include<bits/stdc++.h>
using namespace std;
 
/* A binary tree Node has data, pointer to left child
   and a pointer to right child */

class node
{
  public:
  int data ;
  node  * left ;
  node * right  ;


  node (int d){
    this -> data = d;
    this -> left = NULL;
    this -> right = NULL ;
  }
  
};


node* buildTree(node* root )
{
cout<<"Enter the data";
int data ;
cin>> data ;
root = new node(data);

if (data == -1)

return  NULL ;

cout << "Enter data for  insertion  in left of" << data << endl ;

root->left = buildTree(root->left);  // calling function on left node as  root and samely creating a  node dynamically and giving data to it and assigning that node to root-> left

cout << "Enter the data for insertion in right  of " << data << endl ; 

root ->right =  buildTree(root->right);

return  root ;
 // so as to return root at the end so that we  can get final root of three  at the  end in between steps this return is of not much use 
} 


void levelOrderTraversal(node  * root)
{
  queue <node *> q;
  q.push(root);
  q.push(NULL);



  while(!q.empty())
  {
    node * temp = q.front();
    cout<< temp->data << ""  ;
    q.pop();


    if (temp == NULL){   // It means that previous level is complete so  we are giving line space 
   cout << endl ; 

   if(!q.empty()) // q still has some child nodes
   {
    q.push(NULL);
   }
    }

    if (temp->left){
      q.push(temp->left);                                                   
    }

    if (temp->right){
      q.push(temp->right);
    }


  }
 }
Recursive codes
 
/* Iterative function for inorder tree
   traversal */
void inOrderNonRecursive(struct Node *root)
{
    stack<Node *> s;
    

    Node * curr = root;


 
    while (s.empty() == false || curr!=NULL  ){                                   
       

       while(curr!=NULL){
          
          s.push(curr);
          curr = curr->left;
       }                       // left ma khatam ho gaya ha to root print karo  stack sa nikalo aur right pa call kar do  

        

    curr = s.top();
    s.pop();
    cout<< curr-> data  ;
    curr = curr ->right ;     // agar right bhi null ho jaya to matlab pichli wali node ka left complete ho gaya ha ab us node ka root print karo aur uska right pa call kar do 
    
     

    
 }

    
}

void preOrderNonRecursive(Node* root) // root left right    // dia na help ki 
{
      stack<Node*> s;
      Node* temp = root ;
      cout<<temp->data ;
      if(temp->right) s.push(temp->right);
      temp=temp->left;
      cout<<temp->data;

      while(!s.empty() && temp!=NULL){
        
        if(temp->right){
            s.push(temp->right);
        }
        
        if(temp->left){
              temp = temp->left;
              cout<< temp->data;
        }

        else if(temp->left==NULL){
         if(s.top()){
              temp = s.top();
              cout<< temp->data;
              s.pop();
            }
        }
          
        else{
              break;
          }
        }
}
int main()
{
 
    /* Constructed binary tree is
              1
            /   \
          2      3
        /  \
      4     5
    */
    struct Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
 
    preOrderNonRecursive(root);
    return 0;
}
