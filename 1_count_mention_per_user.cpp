class Solution {
public:
// Storing id from string
  vector<int>helper(string &s){
    vector<int>ans;
    string str="";
    for(char c:s){
        if(c=='i' || c=='d') continue;
        else if(c==' '){
            int x=stoi(str);
            ans.push_back(x);
            str = "";
        }
        else{
            str+=c;
        }
    }
    ans.push_back(stoi(str));
    return ans;
  }
    vector<int> countMentions(int nou, vector<vector<string>>& events) {

       sort(events.begin(),events.end(),[&](vector<string>a, vector<string>b){
        if(a[1]==b[1]) return a[0]>b[0];
        return stoi(a[1])<stoi(b[1]);
       });

       vector<int>offline(nou,1);
       vector<int>ans(nou,0);
       vector<int>ts(nou,-1);

      for(auto i:events){
        string task=i[0];
        int time=stoi(i[1]);
        for(int i=0;i<nou;i++){
         if(!offline[i] && time-ts[i]>=60){
            offline[i]=1;
         }
        }
        if(task=="MESSAGE"){
            if(i[2]=="ALL"){
                for(int i=0;i<nou;i++){
                    ans[i]++;
                }
            }
            else if(i[2]=="HERE"){
                for(int i=0;i<nou;i++){
                    if(offline[i]) ans[i]++;
                }
            }
            else{
                vector<int>v=helper(i[2]);
                for(int i=0;i<v.size();i++){
                    ans[v[i]]++;
                }
            }
        }
        else{
            int id=stoi(i[2]);
            offline[id]=0;
            ts[id]=time;
        }
      }
    return ans;
    }
};
