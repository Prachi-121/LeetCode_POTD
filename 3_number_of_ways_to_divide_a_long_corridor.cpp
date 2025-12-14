class Solution {
public:
    int numberOfWays(string c) {
      int mod=1e9+7,n=c.size();
      long long ans=1;
      vector<int>pos;
      for(int i=0;i<n;i++){
        if(c[i]=='S'){
            pos.push_back(i);
        }
      } 
      if(pos.size()==0)  return 0;
      if(pos.size()%2!=0) return 0;
      for(int i=2;i<pos.size();i+=2){
        int x=pos[i]-pos[i-1];
        ans =(ans*x)%mod;
      }
      return ans;
    }
};
