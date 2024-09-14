class Solution {
void solve(vector<int> &left, vector<int> &right, vector<int> dp)
{
    left.resize(dp.size(),-1);

    right.resize(dp.size(),dp.size());

    stack<int> st;

    st.push(0);

    for(int i = 1; i < dp.size(); i++)
    {
        while( st.empty() == false && dp[st.top()] > dp[i])
        {
            int index = st.top();

            st.pop();

            right[index] = i;

            if(st.empty() == false)
            {
                left[index] = st.top();
            }
        }

        st.push(i);
    }

    while(st.empty() == false)
    {
        int index = st.top();
        
        st.pop();

        if(st.empty() == false)
        {
            left[index] = st.top();
        }
        else
        {
            left[index] = -1;
        }
    }

    return ;
}
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        int rows = matrix.size();

        int cols = matrix[0].size();

        vector<int> dp(cols,0);

        vector<int> left(cols,-1);

        vector<int> right(cols,cols);

        int ans = 0;

       

        for(int row = 0; row < rows; row++)
        {
            for(int col = 0; col < cols ; col++)
            {
                if(matrix[row][col] == '1')
                {
                    dp[col]+=1;
                }

                else
                {
                    dp[col] = 0;
                }
            }

            // for(int col = 0; col < cols; col++)
            // {
            //     cout<<dp[col]<<" "<<endl;
            // }

            // cout<< "firs row"<<row<<endl;

            solve(left,right,dp);

            

            for(int i = 0; i < cols; i++)
            {
                cout<<left[i]<<" "<<right[i]<<" "<<dp[i]<<endl;

                ans = max(ans,(right[i]-left[i]-1)*dp[i]);
            }

            cout<<"for row "<<row<<endl;




        }

        return ans;




        
    }
};