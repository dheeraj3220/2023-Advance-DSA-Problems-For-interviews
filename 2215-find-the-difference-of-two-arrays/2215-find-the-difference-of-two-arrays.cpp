class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mapp1,mapp2;
        for(int i=0;i<max(nums1.size(),nums2.size());i++){
            if(i<nums1.size()) mapp1[nums1[i]]++;
            if(i<nums2.size()) mapp2[nums2[i]]++;
        }
        vector<vector<int>> res;
        vector<int> res1,res2;
        for(int i=0;i<max(nums1.size(),nums2.size());i++){
            if(i<nums1.size() && mapp2.count(nums1[i])==0){
                res1.push_back(nums1[i]);
                mapp2[nums1[i]]++;
            }
            if(i<nums2.size() && mapp1.count(nums2[i])==0){
                res2.push_back(nums2[i]);
                mapp1[nums2[i]]++;
            }
        }
        res.push_back(res1);
        res.push_back(res2);
        return res;
    }
};