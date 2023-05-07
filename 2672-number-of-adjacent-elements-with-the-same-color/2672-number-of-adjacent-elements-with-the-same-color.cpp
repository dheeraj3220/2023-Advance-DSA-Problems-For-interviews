class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& que) {
        vector<int> res(n,0);
        int count=0;
        vector<int> ans;
        for(int i=0;i<que.size();i++){
            int index=que[i][0];
            int col=que[i][1];
            if(res[index]!=0 && index!=0 && res[index]==res[index-1]) count--;
            if(res[index]!=0 && index<n-1 && res[index]==res[index+1]) count--;
            res[index]=col;
            if(res[index]!=0 && index!=0 && res[index]==res[index-1]) count++;
            if(res[index]!=0 && index<n-1 && res[index]==res[index+1]) count++;
            ans.push_back(count);
        }
        return ans;
    }
};