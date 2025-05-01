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
class BSTIterator {
private:
stack<TreeNode*> st;
void initialiseBst(TreeNode* root){
    if(!root) return;
    st.push(root);
    initialiseBst(root->left);
}
public:
    BSTIterator(TreeNode* root) {
        initialiseBst(root);
    }
    
    int next() {
        TreeNode* ele = st.top();
        st.pop();
        initialiseBst(ele->right);
        return ele->val;
    }
    
    bool hasNext() {
        if(st.empty())return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */