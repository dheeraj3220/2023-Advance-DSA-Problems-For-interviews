class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
       int n=time.size();
        long long cc=0,c30=0;
        for(int i=0;i<n;i++){
            if(time[i]%60==0) cc++;
            if(time[i]%60==30) c30++;
            time[i]=time[i]%60;
            cout<<time[i]<<" ";
        }
        unordered_map<int,int> mapp;
        for(auto t :time) mapp[t]++;
        int count=0;
        for(auto i=mapp.begin();i!=mapp.end();i++){
            if(i->first!=30 && mapp.count(60-(i->first))==1){
                count+=i->second*mapp[60-(i->first)];
                // if(count==1) cout<<"1 hogya : "<<i->first;
            }
            i->second=0;
        }
        if(cc) cc=(cc*(cc-1))/2;
        if(c30) c30=(c30*(c30-1))/2;
        cout<<endl;
        cout<<"count "<<count <<" cc"<<cc <<" c30"<<c30<<" "; 
        
        
        return count+cc+c30;
    }
};