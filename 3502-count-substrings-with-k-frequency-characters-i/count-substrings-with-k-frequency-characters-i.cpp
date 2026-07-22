class Solution {
public:
    int numberOfSubstrings(string s, int k) {
      unordered_map<char,int> mpp;
      int st = 0,end = 0;
      int m = 0;
      int n = s.size();
      while(end < s.size()){
         mpp[s[end]] += 1;
        while(mpp[s[end]] >= k){
            m += n-end;
            mpp[s[st]] -= 1;
            st++;
        }
        
        
        end++;
      }
      return m;

        
        
    }
};