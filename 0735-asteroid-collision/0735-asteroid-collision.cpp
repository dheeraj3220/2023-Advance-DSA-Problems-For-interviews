class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
         vector<int> res;
        int i=0;
        while(i<ast.size()){
            if(res.size()==0 || res.back()<0 ) res.push_back(ast[i++]);
            else{
                if(ast[i]/abs(ast[i])!=abs(res.back())/res.back()){
                 if(abs(res.back())>abs(ast[i]))   i++;
                 else if(abs(res.back())<abs(ast[i])) res.pop_back();
                 else {
                     cout<<"imp";
                    res.pop_back();
                    i++;
                }
            }
            else{
                    res.push_back(ast[i++]);
                }
                
            }
            
        }
        return res;
    }
};