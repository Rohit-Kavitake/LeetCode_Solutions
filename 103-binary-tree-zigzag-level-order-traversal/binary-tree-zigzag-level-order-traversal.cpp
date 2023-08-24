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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*> q;
        bool ltr = false;
        q.push(root);

        while(!q.empty()){
            vector<int> level;

            int sizee = q.size();

            while(sizee-- > 0){
                TreeNode* temp = q.front(); q.pop();
                level.push_back(temp->val);
                    if(temp ->left) q.push(temp->left);
                    if(temp ->right) q.push(temp->right);    
            }
            if(ltr) reverse(level.begin(), level.end());
            ltr = !ltr;
            ans.push_back(level);
        }
        return ans;
    }
};