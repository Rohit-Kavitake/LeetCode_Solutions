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

    TreeNode* solve(vector<int> postorder, vector<int> inorder,int& index,int start,int end,int n){

        if(index < 0 || start > end){
            return NULL;
        }

        int ele = postorder[index--];
        TreeNode* root = new TreeNode(ele);
        int pos = findPos(inorder,ele,n);

        root -> right = solve(postorder,inorder,index,pos+1,end,n);
        root -> left = solve(postorder,inorder,index,start,pos-1,n);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = inorder.size()-1;
        TreeNode* root = solve(postorder,inorder,index,0,inorder.size()-1,inorder.size());
        return root;
    }
};