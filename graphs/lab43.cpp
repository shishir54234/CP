#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
    /*
    The Time Complexity O(N)
    */
private:
    int dfs(TreeNode* root, int& maxsum) {
        if(!root) return 0;
        int l=0,r=0;
        if(root->left && dfs(root->left,maxsum)>0)//Check if sum of the root->left subtree maximum is positive if yes then we update l
        {
            l=dfs(root->left,maxsum); 
        }
        if(root->right && dfs(root->right,maxsum)>0)//Check if sum of the root->right subtree maximum is positive if yes then we update r
        {
            r=dfs(root->right,maxsum);
        }
        maxsum = max(l+r+root->val, maxsum); //keep updating the maxsum
        return root->val + max(l,r);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        dfs(root,maxsum);
        return maxsum;
    }
};