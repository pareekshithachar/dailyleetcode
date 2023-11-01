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

    int val = INT_MIN, maxfreq = -1, freq =0;
    void solve(TreeNode* root, vector<int>&ans){
        if(!root) return;
        solve(root->left,ans);
        if(val == root->val){
            freq++;
        }else{
            val = root->val;
            freq = 1;
        }
        if(freq > maxfreq){
            maxfreq = freq;
            ans = {root->val};
        }else if(freq == maxfreq){
            ans.push_back(root->val);
        }

        solve(root->right,ans);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>ans;
        solve(root, ans);
        return ans;
    }
};