class Solution {
public:
    void merge(vector<int> & nums,int start,int mid,int end){
        vector<int> c;
        int i=start,j=mid+1;
        while(i<=mid && j<=end){
            if(nums[i]<nums[j])
                c.push_back(nums[i++]);
            else
                c.push_back(nums[j++]);
        }
        if(i>mid && j<=end)
            while(j<=end) c.push_back(nums[j++]);
        else if(j>end && i<=mid)
            while(i<=mid) c.push_back(nums[i++]);
        int fill=start;
        i=0;
        while(fill<=end){
            nums[fill]=c[i];
            fill++;
            i++;
        }
    }
    void mergeSort(vector<int>& nums,int start,int end){
        if(start>=end) return;
        int mid=(start+end)/2;
        mergeSort(nums,start,mid);
        mergeSort(nums,mid+1,end);
        merge(nums,start,mid,end);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;    
    }
};