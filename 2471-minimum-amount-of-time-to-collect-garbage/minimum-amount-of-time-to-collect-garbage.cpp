class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
          int ans = 0, n=garbage.size();
      vector<int>prefix; prefix.push_back(0);
      int t = travel.size();
      for(int i=0;i<t;i++){
          prefix.push_back(travel[i]+prefix[prefix.size()-1]);
      }

      int m=0, g=0, p=0;
      for(int i=0;i<n;i++){
          string s = garbage[i];
          unordered_map<char,int>mp;
          for(char c:s){
              mp[c]++;
          }
          if(mp.count('M')){
              ans += mp['M'] + prefix[i]-prefix[m];
              m = i;
          }
          if(mp.count('P')){
              ans += mp['P'] + prefix[i]-prefix[p];
              p = i;
          }
          if(mp.count('G')){
              ans += mp['G'] + prefix[i]-prefix[g];
              g = i;
          }
      }

      return ans;
    }
};