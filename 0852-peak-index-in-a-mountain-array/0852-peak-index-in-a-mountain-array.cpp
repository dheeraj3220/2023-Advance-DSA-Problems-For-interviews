class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int maxi=0;
        int index=1;
        for(int i=1;i<arr.size()-1;i++){
            if(maxi<arr[i]){
                index=i;
                maxi=arr[i];
            }
        }
        return index;
    }
};