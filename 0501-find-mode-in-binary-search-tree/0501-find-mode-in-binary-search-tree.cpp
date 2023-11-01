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
    int maxi;
public:
    void solve(TreeNode* root, unordered_map<int,int>&mp){

        if(!root) return;
        solve(root->left,mp);

        mp[root->val]++;
        maxi = max(maxi, mp[root->val]);

        solve(root->right,mp);

    }
    vector<int> findMode(TreeNode* root) {
        
        maxi = INT_MIN;
        unordered_map<int,int>mp;

        solve(root,mp);
        vector<int>ans;
        for(auto x : mp){
            if(x.second == maxi) ans.push_back(x.first);
        }
        return ans;
    }
};