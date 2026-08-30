class Solution {
public:

    int gcd(int a , int b){
        return std::gcd(a , b);
    }

    int getscore(vector<int> & a){

        int n = a.size();
        if(n < 2){
            return 0;
        }

        vector<int> pre(n) , suf(n);
        pre[0] = a[0];
        for(int i = 1; i < n ;i++){

            pre[i] = gcd(pre[i - 1], a[i]);

        }
        suf[n - 1] = a[n - 1];
        for(int i = n -2; i >= 0; i--){

                suf[i] = gcd(a[i],suf[i+1]);
        }
        int ans = 0;
        for(int i = 0;i < n-1; i++){

            if(pre[i] == suf[i+1]){

                ans++;
            }

                    
        }

        return ans;

                
    }
    int maxValidSplits(vector<int>& nums) {

        int ans = getscore(nums);

        for( int remove = 0; remove < nums.size(); remove++){
            vector<int> a;
            for(int i =0; i < nums.size(); i++){
    
                if(i != remove){
                    a.push_back(nums[i]);
                }
            }
            ans = max(ans , getscore(a));
        
        
        }

        return ans;
        
    }
};