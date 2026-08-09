class Solution {
public:
    double minPrice(vector<int>& v1, vector<int>& v2) {
        
            sort(v1.begin(), v1.end(), greater<int>());
            sort(v2.begin(), v2.end(), greater<int>());
            double sum = 0.0;

          int s = min(v1.size(),v2.size());
        for(int i = 0;i < s;i++){
            
            sum += double((v1[i] * (100-v2[i])) / 100.0);

        }
    
            for(int i = v2.size(); i < v1.size();i++){
                sum += double(v1[i]);
            }
        
        return sum;
    }
};