class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0,j=0;
        map<int,int> mapp;
        vector<int> res;
        while(j<nums.size()){
            if(j-i+1<=k){
                mapp[nums[j]]++;
            }
            else{
                res.push_back(mapp.rbegin()->first);
                mapp[nums[i]]--;
                if(mapp[nums[i]]==0) mapp.erase(nums[i]);
                i++;
                mapp[nums[j]]++;
                cout<<j-i+1<<endl;
            }
            j++;
        }
        res.push_back(mapp.rbegin()->first);
        return res;
    }
};