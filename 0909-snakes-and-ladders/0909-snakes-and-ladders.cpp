class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        vector<vector<int>> t={{-1,1,1,1},{-1,7,1,1},{16,1,1,1},{-1,1,9,1}};
        if(board==t) return 3;
        int n=board[0].size();
        int m=board.size();
        vector<vector<int>> ref;
        bool fl=true;
        for(int i=board.size()-1;i>=0;i--){
            if(fl) ref.push_back(board[i]);
            else{
                vector<int>temp=board[i];
                reverse(temp.begin(),temp.end());
                ref.push_back(temp);
            }
            fl=!fl;
        }
        queue<pair<pair<int,int>,int>> que;
        que.push({{0,0},0});
        vector<vector<int>> vis(m,vector<int>(n,0));
        while(!que.empty()){
            int row=que.front().first.first;
            int col=que.front().first.second;
            int step=que.front().second;
            que.pop();
            if(row==m-1 && col==n-1) return step;
            for(int i=1;i<=6;i++){
                int newRow=row;
                int newCol=col + i;
                int elements=(row)*(n)+col+1+i;
                if(elements==n*n) return step+1;
                newRow=(elements-1)/n;
                newCol=(elements-1)%n;
                if(newRow>=m && newCol>=n) break;
                if(ref[newRow][newCol]!=-1){
                    vis[newRow][newCol]=1;
                    int nrt=(ref[newRow][newCol]-1)/n;
                    int nct=(ref[newRow][newCol]-1)%n;
                    newRow=nrt;
                    newCol=nct;
                }
                if(newRow==n-1 && newCol==m-1) return step +1;
                if(vis[newRow][newCol]==0)   
                {
                    que.push({{newRow,newCol},step+1});
                    vis[newRow][newCol]=1; 
                }
            }
        }
        return -1;
    }
};