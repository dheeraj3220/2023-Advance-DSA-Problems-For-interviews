class Solution {
public:
    int searchInsert(vector<int>&arr, int target){
    int l=0, h=arr.size()-1;
    int indx=-1;
    
    while(l<=h){
        int mid=l+(h-l)/2;
        if(arr[mid]==target) return mid;
        else if(arr[mid]>target) h=mid-1;
        else l=mid+1;
    }
    return l; 
}
};