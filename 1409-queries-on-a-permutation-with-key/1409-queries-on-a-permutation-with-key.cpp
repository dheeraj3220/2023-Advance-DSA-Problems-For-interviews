class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int i, j;
        vector<int> p;
        vector<int> ans;
        for(i=0 ; i<m ; i++)
        {
            p.push_back(i+1);
        }
        for(i=0 ; i<queries.size() ; i++)
        {
            for(j=0 ; j<p.size() ; j++)
            {
                if(queries[i]==p[j])
                {
                    ans.push_back(j);
                    p.erase(p.begin()+j);
                    p.insert(p.begin()+0, queries[i]);
                    break;
                }
            }
        }
        return ans;
    }
};