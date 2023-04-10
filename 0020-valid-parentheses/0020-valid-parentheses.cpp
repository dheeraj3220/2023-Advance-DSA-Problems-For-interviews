class Solution {
public:
    bool isValid(string s) 
    {
         stack<char> par;
        int i=0;
        while(s[i]!='\0')
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                par.push(s[i]);
            }
            else
            {   if(par.size()==0)
                {
                    return false;
                }
                if(s[i]==')')
                {
                    if(par.top()=='(')
                    {
                        par.pop();
                    }
                    else
                    return false;
                }
                else if(s[i]==']')
                {
                    if(par.top()=='[')
                    {
                        par.pop();
                    }
                    else
                    return false;
                }
                else if(s[i]=='}')
                {
                    if(par.top()=='{')
                    {
                        par.pop();
                    }
                    else
                    return false;
                }
            }
            i++;
        }
        if(par.size()!=0)
        {
            return false;
        }
        return true;
        
    }
};