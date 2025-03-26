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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {{}};
        map<int,map<int,vector<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        
        while(!q.empty()){
            auto front = q.front();
            int level = front.second.first;
            int height = front.second.second;
            q.pop();
            mp[level][height].push_back(front.first->val);
            
            if(front.first->left){
                q.push({front.first->left,{level-1,height+1}});
            }
            if(front.first->right){
                q.push({front.first->right,{level+1,height+1}});
            }
        }
        
        vector<vector<int>>ans;
        for(auto x : mp){
            vector<int>res;
            for(auto y : x.second){
                sort(y.second.begin(), y.second.end());
                for(auto z : y.second){
                    res.push_back(z);
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};