class Solution {
public:
    int m,n;
    int t[101][101][201];
    bool solve(int i,int j,int opencnt,vector<vector<char>>& grid){
        opencnt+=(grid[i][j]=='(')?1:-1;
        if(opencnt<0) return false;
        if(t[i][j][opencnt]!=-1){
            return t[i][j][opencnt];
        }
        if(i==m-1 && j==n-1){
            return t[i][j][opencnt]= (opencnt==0);
        }
        bool res=false;
        if(i+1<m){
            if(solve(i+1,j,opencnt,grid)==true) return t[i][j][opencnt]= true;
        }
        if(j+1<n){
            if(solve(i,j+1,opencnt,grid)==true) return t[i][j][opencnt]= true;
        }
        return t[i][j][opencnt]= false;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        n=grid[0].size();
        m=grid.size();
        if((m+n-1)%2!=0) return false;
        if(grid[0][0]==')') return false;
        memset(t,-1,sizeof(t));
        return solve(0,0,0,grid);
    }
};