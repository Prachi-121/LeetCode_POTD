class Solution {
public:
    long long getDescentPeriods(vector<int>& p) {
       int n=p.size(),cnt=1;
       if(n==1) return n;
       long long ans=0;
       for(int i=0;i<n-1;i++){
        if((p[i]-p[i+1])==1){
            cnt++;
        }
        else{
            long long tmp=1LL*cnt*(cnt+1)/2;
            ans+=tmp;
            cnt=1;
        }
       } 
       ans+=1LL*cnt*(cnt+1)/2;
       return ans;
    }
};
