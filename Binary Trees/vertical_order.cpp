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

};

 node* newNode(int data)
{
     node* Node = new  node;
    Node->data = data;
    Node->left = Node->right = NULL;
    return (Node);
}
// If  we dont want to use pair then we can also use recursion for horizantal distance management 
void verticalOrderIterative(node * root){
     map<int, vector<int> > m;  // map will contain horizantal distance and vector
    int hd = 0;
    queue<pair<node*, int> > que;  // queue will have elements and horizantal distance because we need horizantal distance 
    que.push(make_pair(root, hd));
    
    while(!que.empty()){
         pair<node*, int> temp = que.front();
         node * temp_node = temp.first;
         int hd = temp.second;
         m[hd].push_back(temp_node->data);
         que.pop();
         
         if(temp_node->left){
             que.push(make_pair(temp_node->left,hd-1));
             
         }
         
         if(temp_node->right){
             que.push(make_pair(temp_node->right,hd+1));
         }
    }
    
    map<int, vector<int> > :: iterator it;
    for(it = m.begin(); it!=m.end(); it++){
        for(int i=0; i<it->second.size(); i++){
            cout<<it->second[i]<<" ";
        }
        cout<<endl;
    }

}

 

int main()
{
    // create tree
   node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    root->right->right->left = newNode(10);
    root->right->right->left->right = newNode(11);
    root->right->right->left->right->right = newNode(12);
    cout << "Vertical order traversal is \n";
    verticalOrderIterative(root);
    return 0;

 

    return 0;
}
