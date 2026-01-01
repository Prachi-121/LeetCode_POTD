class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int n=digits.size(), cnt=0;
      for(int i:digits){
        if(i==9) cnt++;
      }

      if(digits[n-1]!=9){
        digits[n-1]++;
        return digits;
      }

      if(cnt==n){
        vector<int>ans(n+1,0);
        ans[0]=1;
        return ans; 
      }
      
      int idx=-1;
      if(digits[n-1]==9){
        for(int i=n-1;i>=0;i--){
          if(digits[i]!=9){
            idx=i;
            break;
          }
          else digits[i]=0;
        }
      }
      digits[idx]++;
      return digits;
    }
};
