// Using binary search
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
       int cnt=0;
       int n=grid.size();
       int m=grid[0].size();
       for(int i=0;i<n;i++){
        int idx=upper_bound(grid[i].begin(),grid[i].end(),0, greater<int>())
        - grid[i].begin();
        cnt+=(m-idx);
       } 
       return cnt;
    }
};

// StairCase method
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
      int cnt=0,n=grid.size(),m=grid[0].size();
      int j=0,i=n-1;
      while(i>=0 && j<m){
        if(grid[i][j]<0){
          cnt+=(m-j);
          i--;
        }
        else j++;
      }
      return cnt;
    }
};
