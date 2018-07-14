/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<int> _inorder, _postorder;
    TreeNode* createTree(int inL, int inR, int postL, int postR){
        if(inL > inR)
            return NULL;
        int k;
        for(k = inL; k <= inR; k++){
            if(_inorder[k] == _postorder[postR])
                break;
        }
        int leftNum = k - inL;
        TreeNode* root = new TreeNode(_postorder[postR]);
        root->left = createTree(inL, k - 1, postL, postL + leftNum - 1);
        root->right = createTree(k + 1, inR, postL + leftNum, postR - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        _inorder = inorder;
        _postorder = postorder;
        TreeNode* root = createTree(0, inorder.size() - 1, 0, postorder.size() - 1);
        return root;
    }
};
