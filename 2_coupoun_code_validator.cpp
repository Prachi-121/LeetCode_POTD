class Solution {
public:
  bool check(string &s){
    if(s=="") return false;
    for(auto i:s){
        if(isalnum(i) || i=='_') continue;
        else return false;
    }
    return true;
  }
    vector<string> validateCoupons(vector<string>& code, vector<string>& bl, vector<bool>& isActive) {

      vector<pair<int,string>>ans;
      unordered_map<string,int>priority={
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
      };

     for(int i=0;i<code.size();i++){
        if(check(code[i]) && isActive[i] &&
         ((bl[i]=="electronics") || (bl[i]=="grocery") ||
          (bl[i]=="pharmacy") || (bl[i]=="restaurant")))
         ans.push_back({priority[bl[i]],code[i]});
     }
        sort(ans.begin(),ans.end());
        vector<string>v;
        for(auto i:ans){
            v.push_back(i.second);
        }
        return v;
    }
};
