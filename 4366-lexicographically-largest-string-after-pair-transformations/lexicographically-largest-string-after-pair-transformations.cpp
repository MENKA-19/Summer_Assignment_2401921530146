class Solution {
public:
    vector<string> largestString(vector<int>& nums) {

        vector<string>Ans;

        for(int x : nums){

            string s;
            for(int i = 25 ; i>= 0; i--){

                long long p = 1LL << i;
                while(x >= p){

                    s += char('a'+i);
                    x -= p;
                }
            }

            Ans.push_back(s);
        }

        return Ans;
        
    }
};