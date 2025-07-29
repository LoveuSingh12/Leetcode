/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inOrder(TreeNode* root, TreeNode* &first, TreeNode* &second, TreeNode* &prev){
        if(root==NULL) return;
        inOrder(root->left,first,second,prev);
        if(prev && prev->val>root->val){
            if(!first) first=prev;
            second=root;
        }
        prev=root;
        inOrder(root->right,first,second,prev);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* first=NULL;
        TreeNode* second=NULL;
        TreeNode* prev=NULL;
        inOrder(root,first,second,prev);
        if(first && second){
            swap(first->val,second->val);
        }
    }
};