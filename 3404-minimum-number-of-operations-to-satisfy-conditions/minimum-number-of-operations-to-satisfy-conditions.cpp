class Solution {
int solve(int row,int col,int colno,int parent,vector<vector<int>> &freq,vector<vector<int>> &dp)
{
    if(colno<0) return 0;


    if(dp[parent][colno]!=-1) return dp[parent][colno];

    int ans=INT_MAX;
    cerr<<"HccccELLO"<<endl;
    for(int i=9;i>=0;i--)
    {
        
        if(i!=parent)
        {
            int temp=row-freq[i][colno]+solve(row,col,colno-1,i,freq,dp);

            ans=min(ans,temp);
        }
    }

    return dp[parent][colno]=ans;
}
public:
    int minimumOperations(vector<vector<int>>& grid) {

        int row=grid.size();

        int col=grid[0].size();

        vector<vector<int>> freq(10,vector<int>(col,0));
        cerr<<"HELLllO"<<endl;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                freq[grid[i][j]][j]++;
            }
        }
        cerr<<"HELLO"<<endl;
        vector<vector<int>> dp(11,vector<int> (col,-1));

        return solve(row,col,col-1,10,freq,dp);


        
    }
};