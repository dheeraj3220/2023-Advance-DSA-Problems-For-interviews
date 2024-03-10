class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        vector<set<string>> substringMap;
        for(auto str: arr){
            set<string> substringsSet;
            for(int i=0;i<str.size();i++){
                string currentSubstr="";
                for(int j=i;j<str.size();j++){
                    currentSubstr+=str[j];
                    substringsSet.insert(currentSubstr);
                }
            }
            substringMap.push_back(substringsSet);
        }
        vector<string> result(arr.size(),"");
        for(int i=0;i<substringMap.size();i++){
            for(auto it=substringMap[i].begin();it!=substringMap[i].end();it++){
                bool found=true;
                string currentSubstr=*it;
                for(int j=0;j<substringMap.size();j++){
                    if(j!=i){
                        if(substringMap[j].count(currentSubstr)==1){
                            found=false;
                            break;
                        }
                    }
                }
                if(found==true){
                    if(result[i]!="" && (result[i].size()<=currentSubstr.size() && result[i]<currentSubstr)){
                    }
                    else {
                        result[i]=currentSubstr;
                    }
                    
                }
            }
        }
         return result;
    }
};