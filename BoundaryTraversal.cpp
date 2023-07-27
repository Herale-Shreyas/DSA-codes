class Solution {
private:
    void leftTraversal(Node *root, vector<int> &ans) {
        if(root == NULL) return;

        //Leaf node is neglected, this is taken care of in the leaf section
        if(root -> left == NULL and root -> right == NULL) return;

        //Push the value first and then traverse
        ans.push_back(root -> data);
        
        if(root -> left) leftTraversal(root -> left, ans);
        else leftTraversal(root -> right, ans);
    }
    
    void leafTraversal(Node *root, vector<int> &ans) {
        if(root == NULL) return;
        if(!root -> left and !root -> right) ans.push_back(root -> data);
        
        leafTraversal(root -> left, ans);
        leafTraversal(root -> right, ans);
    }
    
    void rightTraversal(Node *root, vector<int> &ans){
        if(!root) return;
        if(!root->left and !root -> right) return;
        
        if(root -> right) rightTraversal(root -> right, ans);
        else rightTraversal(root -> left, ans);
        ans.push_back(root -> data);
    }
public:
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        ans.push_back(root -> data);
        //Left Boundary Traversal
        leftTraversal(root -> left, ans);
        
        //Leaf Traversal
        
        // Left leaf traversal
        leafTraversal(root -> left, ans);
        
        //right leaf traversal
        leafTraversal(root -> right, ans);
        
        //Right boundary traversal
        rightTraversal(root->right, ans);
        
        return ans;
    }
};
