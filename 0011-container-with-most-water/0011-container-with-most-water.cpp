class Solution {
public:
    int maxArea(vector<int>& height) {
       int i=0;
    int j=height.size()-1;
    int maxWater=0;
    int curWater=0;
    while(i<j){
        curWater=min(height[i],height[j])*(j-i);
        maxWater=max(curWater,maxWater);
        height[i]>height[j]?j--:i++;
    }
    return maxWater;
    }
};