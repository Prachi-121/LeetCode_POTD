class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& cap) {
      int n=apple.size(), m=cap.size(),cnt=0;
      sort(cap.rbegin(),cap.rend());
      int total=0;
      for(int i:apple) total+=i;
      for(int i:cap){
        if(total>0){
            total-=i;
            cnt++;
        }
      }
      return cnt;
    }
};
