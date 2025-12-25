class Solution {
public:
    long long maximumHappinessSum(vector<int>& hap, int k) {
       int n=hap.size();
       long long ans=0;
       sort(hap.rbegin(),hap.rend()); 
       for(int i=0;i<k;i++){
        if(hap[i]-i>0){
          ans += (hap[i]-i);
        }
        else break;
       }
       return ans;
    }
};
