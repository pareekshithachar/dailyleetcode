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
    TreeNode* solve(int root,unordered_map<int,vector<int>>&mp){
        if(root == 0) return NULL;
        TreeNode* head = new TreeNode(root);
        head->left =  mp.find(root)!=mp.end()?solve(mp[root][0],mp) : NULL;
        head->right = mp.find(root)!=mp.end()?solve(mp[root][1],mp) : NULL;
        return head;

    }
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        set<int>st;
        for(int i= 0;i<d.size();i++){
            st.insert(d[i][0]);
        }
        
        for(int i= 0;i<d.size();i++){
            st.erase(d[i][1]);
        }
        set<int, greater<int> >::iterator itr = st.begin();

        int root = *itr;
        unordered_map<int,vector<int>>mp;
        for(int i =0;i<d.size();i++){
            vector<int>vec(2,0);

            if(mp.find(d[i][0]) != mp.end()){
               vec = mp[d[i][0]];
            }
            if(d[i][2] == 0){
                    vec[1]= d[i][1];
            }else{
                vec[0] = d[i][1];
            }
            mp[d[i][0]] = vec;
        }
        
        return solve(root,mp);
        
    }
};