class Solution {
public:
  int helper(int num){
    int sum=0,cnt=0;
    for(int i=1;i*i<=num;i++){
      if(num%i==0){
        int tmp=num/i;
        sum+=i;
        cnt++;
        if(tmp!=i){
          cnt++;
          sum+=tmp;
        }
      }
    }
    return (cnt==4)? sum:0;
  }
    int sumFourDivisors(vector<int>& nums) {
      int ans=0;
      for(int i:nums){
        int val=helper(i);
        ans+=val;
      }  
      return ans;
    }
};
