class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mat) {
      long long cnt=0,zero=0;
      long long sum=0;
      long long mini=1e9;
      for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++){
          sum+=abs(mat[i][j]);
          mini=min(mini,abs((long long)mat[i][j]));
          if(mat[i][j]<0){
             cnt++;
          }
        }
      }
      if(cnt%2==1) sum-=2*mini;
      return sum;
    }
};
