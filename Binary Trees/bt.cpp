#include<bits/stdc++.h>
#include <iostream>
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
//Recursive codes for pre post and in order 

void inorderTraversal ( node * root)   // left root right
 
{
if (root==NULL)

return ;

inorderTraversal(root -> left);
cout << root->data  ;                    

inorderTraversal(root->right );

}

void preOrderTraversal(node * root )  // root left right

{
 if (root==NULL)

return ;


cout << root->data ;
preOrderTraversal(root->left);
preOrderTraversal(root->right);
}

void postOrderTraversal(node * root)     // left right  root

// First solve left then right and we get results from there and at end print your root 

{ 
  if(root== NULL){
    return

  postOrderTraversal(root-> left);

  postOrderTraversal(root->right);

  cout << root->data ; 



  }

}

 
/* Iterative function for inorder tree
   traversal */
void inOrderNonRecursive( node *root)
{
    stack<node *> s;
    

    node * curr = root;


 
    while (s.empty() == false || curr!=NULL  ){                                   
       

       while(curr!=NULL){
          
          s.push(curr);
          curr = curr->left;
       }                       // left ma khatam ho gaya ha to root print karo  stack sa nikalo aur right pa call kar do  

        

    curr = s.top();
    s.pop();
     cout << curr-> data  ;
    curr = curr ->right ;     // agar right bhi null ho jaya to matlab pichli wali node ka left complete ho gaya ha ab us node ka root print karo aur uska right pa call kar do 
    
     

    
 }

    
}

void preOrderNonRecursive(node* root) // root left right    // dia na help ki 
{
      stack<node*> s;
      node* temp = root ;
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

void postorderNonRecursal ( node  * root)
{
  stack<node * > s1;
  stack<node * > s2;

  s1.push(root);

  while(!s1.empty()){
   node *  temp = s1.top();
   s1.pop();
   s2.push(temp);

   if (temp->left){
    s1.push(temp->left);
   }

   if (temp->right){
    s1.push(temp->right);}
}

while(!s2.empty()){
  node * temp  = s2.top();
s2.pop();
  cout<< temp->data << "";

}



}
void  buildTreeFromLevelOrder(node * * root)
{
  queue <node *> q;
  int data ;
  cout<< "Enter the root data " ;

  cin>> data ;

  *root = new node(data);

  q.push(*root);

  while(!q.empty())
  {
    node * temp = q.front();
    q.pop();

    cout << "Enter the left child of " << temp->data << endl ;
    int leftData ;
    cin>> leftData ;

    if (leftData != -1)
    {
      temp->left = new node(leftData);
      q.push(temp->left);
    }

    cout << "Enter the right child of " << temp->data << endl ;
    int rightData ;
    cin>> rightData ;

    if (rightData != -1)
    {
      temp->right = new node(rightData);
      q.push(temp->right);
    }                     // Must check this code once 
  }
}

  int heightOfTree (node * root)
  {
  if (root==NULL)
  return 0;

  int left = heightOfTree(root->left);
  int right = heightOfTree(root->right);

  int ans = (max(left,right)+1);

  return ans ; 
  }

int diammeterOfTree(node * root){
  if (root == NULL)

  return 0;

  int diameterleft = diammeterOfTree(root->left);
  int diameterRight = diammeterOfTree(root->right);
  int diameterRoot = heightOfTree(root->left) + heightOfTree(root->right) + 1;

  return max(diameterRoot,max(diameterleft,diameterRight));

}


pair<int,int> diameterOptimised(node * root){   // instead of making functio call for heights return height instead 

if(root == NULL)
{
  pair<int , int > p = make_pair(0,0);
  return p ;

};

pair<int , int > left = diameterOptimised(root->left);  // diameter of left

pair<int ,int> right = diameterOptimised(root->left);   // diameter of right

int diameterLeft = left.first;

int diameterRight = right.first;

int diameterRoot = left.second  + right.second  + 1 ;

pair<int ,int >  ans ;

ans.first = max(diameterLeft , max(diameterRight , diameterRoot));
ans.second= (max(left.second , right.second)+1);

return ans ; 



}

bool isBalanced (node * root )
{

if (root == NULL)
return 1;

bool left = isBalanced(root->left);       //  IN this way we are checking each node because all nodes are needed to be checked 
bool right = isBalanced(root -> right);

bool RootBalanced  = abs(heightOfTree(root->left)- heightOfTree(root->right)) <= 1 ; 

if(left & right  &  RootBalanced){
  return 1  ;
}

else
return 0 ;
}

pair<bool,int> isBalancedOptimised (node * root)
{
  if (root==NULL)
  {
pair<bool , int > p = make_pair(true,0)  ;  
return p ;
  }

 pair<bool,int> left = isBalancedOptimised(root->left);
 pair<bool,int>right  = isBalancedOptimised(root->right);
 

}  /// complete later 


// I guess its only for leaf to leaf because in maxii we are always storing a u 

int maxPathSumLeafToLeaf(node * root)  // Its almost same as diameter problem 
{
  if (root == NULL)
  return 0;

  int maxii = 0 ;

  // max sum including that node  means we have to take max of either  left or right of its child so that path to node is not blocked forming a u 

  int left = maxPathSumLeafToLeaf(root -> left);
  int right = maxPathSumLeafToLeaf(root-right);

  maxii = max(maxii , left + right + root->data); 

  return ( max(left,right) + root->data);
} 

 // At the end we have to return maxi 
// for each node we have to check a u forming  only which will be node value + max (left path)+ max (right path) which we are checking for each node using maxi variable 
//  instead if all possible paths then check u 
// and in return we can return max (left + a-> val , right + a-> val )   for solving leaf to leaf solution 


int Solution::maxPathSum()

int findMaxPath(node * A){

}

vector<int> zigZagTraversal(node * root) // in this we have to process  a level at a same time so that we can pass values in vector in proper zig zag pattern so use loop to process all elements current present in queue and put them in vector accordingly 
{
  vector<int> ans;
if (root==NULL)
return ans;

queue<node * > q;

bool leftToRight = true ;


q.push(root);

while(!q.empty()){
  vector<int> vec ;
for(int i = 0 ; i)
  node * temp = q.front();

  q.pop();

  if(temp->left){
    q.push(temp->left);
  }

if(temp->right)
{
  q.push(temp->right);

}








}

}
int main()
{
 
 
    return 0;
}
