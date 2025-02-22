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
    TreeNode* solve(string &traversal,int level, int& i){
        if(i >= traversal.size()) return NULL;
        string num = "";
        while(i < traversal.size() && traversal[i] != '-'){
            num+=traversal[i];
            i++;
        }
        int val = stoi(num);
        int count = 0;
        TreeNode* head = new TreeNode(val);
        int initialval = i;
        while(i < traversal.size() && traversal[i] == '-'){
            count++;
            i++;
        }
        if(count == level+1){
            head->left = solve(traversal,level+1,i);
        }else{
            i = initialval;
        }
        count = 0;
        initialval = i;
        while(i < traversal.size() && traversal[i] == '-'){
            count++;
            i++;
        }
        if(count == level+1){
            head->right = solve(traversal,level+1,i);
        }else{
            i = initialval;
        }
        return head;

    }
    TreeNode* recoverFromPreorder(string traversal) {
        int i =0;
        return solve(traversal,0,i);
    }
};