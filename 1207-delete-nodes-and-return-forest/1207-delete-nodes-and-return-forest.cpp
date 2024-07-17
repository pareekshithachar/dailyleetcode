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
    void solve(TreeNode* root, unordered_map<int,bool>&mp, vector<TreeNode*>&ans,TreeNode* parent, int isleft){
        if(!root) return;
        if(mp[root->val]){
            if(parent->val != -1){
                isleft ? parent->left = NULL : parent->right = NULL;
            }
            if(root->left){
                if(!mp[root->left->val])ans.push_back(root->left);
                solve(root->left,mp,ans,new TreeNode(-1),1);
            }
            if(root->right){
                if(!mp[root->right->val])ans.push_back(root->right);
                solve(root->right,mp,ans,new TreeNode(-1),0);
            }
        }else{
            solve(root->left,mp,ans,root,1);
            solve(root->right,mp,ans,root,0);
        }
        return;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_map<int,bool>mp;
        for(int i =0;i<to_delete.size();i++){
            mp[to_delete[i]] = true;
        }
        if(root == NULL) return {};
        if(!mp[root->val]){
            ans.push_back(root);
        }
        solve(root,mp,ans,new TreeNode(-1),-1);
        return ans;
    } 
};