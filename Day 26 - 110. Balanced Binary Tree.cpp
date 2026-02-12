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
    pair<bool, int> isBalancedgood(TreeNode* root){
        if(root == NULL){
            pair<bool,int> p = make_pair(true, 0);
            return p;
        }

        pair<int,int>left = isBalancedgood(root->left);
        pair<int,int>right = isBalancedgood(root->right);

        bool Lans = left.first;
        bool Rans = right.first;
        bool difference = abs(left.second - right.second)<=1;

        pair<bool, int> ans;

        ans.second = max(left.second, right.second) + 1;

        if(Lans && Rans && difference){
            ans.first = true;
        } else{
            ans.first = false;
        }
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        return isBalancedgood(root).first;
    }
};