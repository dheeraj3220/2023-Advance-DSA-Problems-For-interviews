class Solution {
public:
    void merge(vector<pair<int,int>>&arr,int st, int mid, int end, vector<int>&res){
        int i=st;
        int j=mid+1;
        vector<pair<int,int>> temp;
        int cnt=0;
        while(i<=mid && j<=end){
            if(arr[i].first>arr[j].first){
                temp.push_back(arr[j]);
                cnt++;
                j++;
            }
            else{
                res[arr[i].second]+=cnt;
                temp.push_back(arr[i]);
                i++;
            }
        }
        // if(i<=mid) res[arr[i].second]+=(j-mid+1);
        while(i<=mid){
            res[arr[i].second]+=cnt;
            temp.push_back(arr[i++]);
        }
        while(j<=end) temp.push_back(arr[j++]);
        i=st,j=mid+1;
        int k=0;
        while(i<=mid) arr[i++]=temp[k++];
        while(j<=end) arr[j++]=temp[k++];
    }
    void helper(vector<pair<int,int>>&arr,int st, int end, vector<int>&res){
        if(st>=end) return ;
        int mid=(st+end)/2;
        helper(arr,st,mid,res);
        helper(arr,mid+1,end,res);
        merge(arr,st,mid,end,res);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>> arr;
        for(int i=0;i<nums.size();i++){
            arr.push_back({nums[i],i});
        }
        vector<int> res(nums.size(),0);
        helper(arr,0,nums.size()-1,res);
        for(int i=0;i<nums.size();i++) cout<<arr[i].first<<" ";
        return res;
    }
};