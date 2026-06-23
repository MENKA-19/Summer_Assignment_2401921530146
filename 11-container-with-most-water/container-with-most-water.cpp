class Solution {
public:
    int maxArea(vector<int>& height) {
    int n=height.size();
    int l=0,r=n-1,maxwater=0;
    while(l<r){
        int w=r-l;
        int ht=min(height[l],height[r]);
        int currwater=w*ht;
        maxwater=max(maxwater,currwater);
        if(height[l]<height[r]){
            l++;

        }
        else
        r--;


    }
    return maxwater;
        
    }
};