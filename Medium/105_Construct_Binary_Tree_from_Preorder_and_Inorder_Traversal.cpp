/*
 * Problem #105: Construct Binary Tree from Preorder and Inorder Traversal
 * Difficulty: Medium
 *
 * ----- Description -----
 *
 * Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
 * 
 *  
 * Example 1:
 * 
 * Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * Output: [3,9,20,null,null,15,7]
 * 
 * 
 * Example 2:
 * 
 * Input: preorder = [-1], inorder = [-1]
 * Output: [-1]
 * 
 * 
 *  
 * Constraints:
 * 
 * 
 * 	1 <= preorder.length <= 3000
 * 	inorder.length == preorder.length
 * 	-3000 <= preorder[i], inorder[i] <= 3000
 * 	preorder and inorder consist of unique values.
 * 	Each value of inorder also appears in preorder.
 * 	preorder is guaranteed to be the preorder traversal of the tree.
 * 	inorder is guaranteed to be the inorder traversal of the tree.
 *
 * ----- Solution -----
 */

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

    // Find the root value in the inorder traversal
    int search(vector<int>& inorder, int left, int right, int val){
        for(int i = left; i<= right; i++){
            if(inorder[i] == val){
                return i;
            }
        }
        return -1;
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int &preIdx, int left, int right){

         // No elements left in this subtree
        if(left > right){
            return NULL;
        }

        // First element in preorder is the current root
        TreeNode* root = new TreeNode(preorder[preIdx]);

        // Find root position in inorder
        int inIdx = search(inorder, left, right, preorder[preIdx]);
        preIdx++;

        root->left = helper(preorder, inorder, preIdx, left, inIdx-1);
        root->right = helper(preorder, inorder, preIdx, inIdx+1, right);

        return root;

    } 

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return helper(preorder, inorder, preIdx, 0, inorder.size()-1);
    }
};