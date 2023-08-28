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
private:
    int findPos(vector<int>& inorder, int ele, int n){
        for(int i=0;i< n;i++){
            if(inorder[i] == ele)
                return i;
        }
        return -1;
    }

    TreeNode* solve(vector<int> preorder, vector<int> inorder,int& index,int start,int end,int n){

        if(index >= n || start > end){
            return NULL;
        }

        int ele = preorder[index++];
        TreeNode* root = new TreeNode(ele);
        int pos = findPos(inorder,ele,n);

        root -> left = solve(preorder,inorder,index,start,pos-1,n);
        root -> right = solve(preorder,inorder,index,pos+1,end,n);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        TreeNode * root = solve(preorder,inorder,index,0,preorder.size()-1,preorder.size());
        return root;
    }
};