class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& evt) {
       int n=evt.size(),ans=0;
       sort(evt.begin(),evt.end());
       vector<int>suf(n,0);
       suf[n-1]=evt[n-1][2];
       for(int i=n-2;i>=0;i--){
        suf[i]=max(suf[i+1],evt[i][2]);
       }
       for(int i=0;i<n;i++){
        auto it=lower_bound(evt.begin(),evt.end(),vector<int>{evt[i][1]+1, INT_MIN, INT_MIN});    
        if(it!=evt.end()){
            int idx=it-evt.begin();
            ans=max(ans, suf[idx]+evt[i][2]);
        }
        else{
            ans=max(ans,evt[i][2]);
        }
       }
       return ans;
    }
};
