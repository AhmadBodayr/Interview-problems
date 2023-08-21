leetcode
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
    map<string, int> freq;
    vector<TreeNode*> out;
    string s;

    void preorder(TreeNode* root) {
        if(!root) {
            s += "*" + to_string(201) + "*";
            return;
        }
        s += "*" + to_string(root->val) + "*";
        
        preorder(root->left);
        preorder(root->right);
        
    }

    void dfs(TreeNode* root) {
        if(!root) return;
        s = "";
        preorder(root);
        freq[s]++;
        if(freq[s] == 2) out.push_back(root);
        dfs(root->left);
        dfs(root->right);
    }
    
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        freq.clear();
        out.clear();
        dfs(root);
        return out;   
    }
};