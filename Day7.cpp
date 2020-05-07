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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == NULL)    return false;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int qSize = q.size();
            bool xExist = false;
            bool yExist = false;
            while(qSize-->0)
            {
                TreeNode* curr = q.front();     q.pop();
                if(curr->val == x)
                    xExist = true;
                if(curr->val == y)
                    yExist = true;
                
                if(curr->left!=NULL and curr->right!= NULL and curr->left->val == x and curr->right->val == y)
                    return false;
                if(curr->left!=NULL and curr->right!= NULL and curr->right->val == x and curr->left->val == y)
                    return false;
                
                if(curr->left !=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
                
            }
            if(xExist and yExist)
                return true;
            if(xExist || yExist)
                return false;
        }
        return false;
    }
};
