class Solution {
public:
    int bestClosingTime(string customers) {
      int n=customers.size(), min_pan=1e8,sum=0,idx=0;
      vector<int>preN(n+1,0);
      vector<int>postY(n+1,0);
      for(int i=1;i<=n;i++){
        if(customers[i-1]=='N') sum++;
        preN[i]=sum;
      }
      sum=0;
      for(int i=n-1;i>=0;i--){
        if(customers[i]=='Y') sum++;
        postY[i]=sum;
      }
      for(int i=0;i<=n;i++){
        int penality=preN[i]+postY[i];
        if(penality<min_pan){
          min_pan=penality;
          idx=i;
        }
      }
      return idx;
    }
};
