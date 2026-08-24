class Solution {
public:
    int find_days(vector<int>& weights,int cap){

        int Days = 1, load =0;

        for(int i = 0; i<weights.size() ; i++){

            if(weights[i] + load > cap){

                Days+=1;
                load = weights[i];
            }
            else{

                load+=weights[i];
            }
        }

        return Days;
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int st = *max_element(weights.begin(),weights.end());

        int end = accumulate(weights.begin(),weights.end(), 0);

        while(st <= end){

            int mid = st +(end-st)/2;

            int Day = find_days(weights,mid);

            if(Day <= days){

                end = mid-1;
            }
            else{

                st = mid+1;
            }

        }

        return st;

        
    }
};