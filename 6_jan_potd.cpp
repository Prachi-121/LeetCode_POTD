class Solution {
public:
    int maxLevelSum(TreeNode* root) {
       queue<TreeNode*>q;
       q.push(root);

       int max_sum = INT_MIN;
       int lev = 1, max_level=1;

       while(!q.empty()){
        int sz=q.size();
        int sum=0;

        while(sz--){
          TreeNode* n=q.front();
          sum+=n->val;
          q.pop();
          if(n->left) q.push(n->left);
          if(n->right) q.push(n->right);
        }
        if(sum>max_sum){
          max_sum=sum;
          max_level=lev;
        }
        lev++;
       }
      return max_level;
    }
};
