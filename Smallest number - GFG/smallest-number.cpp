//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        // code here 
        if(S> D*9) return "-1";
        string res="1";
        for(int i=1;i<D;i++) res+="0";
        if(S==1) return res;
        int sum=1;
        int i=res.size()-1;
        while(i>=0){
            if(i==0){
                for(int j=2;j<=9;j++){
                sum++;
                if(sum==S){
                  res[i]=(j+'0');
                  return res;
                } 
            }
            }
            for(int j=1;j<=9;j++){
                sum++;
                if(sum==S){
                  res[i]=(j+'0');
                  return res;
                } 
            }
            res[i]=9+'0';
            i--;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends