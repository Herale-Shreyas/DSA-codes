
// Iterative Solution

Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   Node *temp = root;
   if(!root)
        return root;
   while(temp)
   {
       // if both the key values are at one side of the root(temp, in this case), then traverse in that direction
       // else it means that the key values have spilt direction indicating that the split position is the lowest ancestor
        if(n1< temp->data && n2<temp->data)
            temp = temp->left;
        else if(n1>temp->data && n2>temp->data)
            temp = temp->right;
        else
            return temp;
   }
   return root;   
}


// Recursive Solution

Node* LCA(Node *root, int n1, int n2)
{
    if(n1 < root->data && n2 < root->data)
        LCA(root->left, n1, n2);
    else if(n1 > root->data && n2 > root->data)
        LCA(root->right, n1, n2);
    else return root;
}

