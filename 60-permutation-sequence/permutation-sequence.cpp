class Solution {
string solve(string ans)
{
    int golaindex = -1;

    for( int i = ans.size() - 2; i >= 0 ; i--)
    {
        if(ans[i] < ans[i + 1])
        {
            golaindex = i;

            break;
        }
    }

    for(int i = ans.size() - 1; i >= golaindex; i--)
    {
        if(ans[i] > ans[golaindex])
        {
            swap(ans[i],ans[golaindex]);

            break;
        }
    }

    int start = golaindex + 1;

    int end = ans.size() -1;

    while(start < end)
    {
        swap(ans[start++],ans[end--]);
    }

    return ans;
}
public:
    string getPermutation(int n, int k) {

        string ans;

        for(int i = 1; i <= n; i++)
        {
            char ch = i + '0';
            ans.push_back(ch);
        }

        int step = 1;

        while(step != k)
        {
            ans = solve(ans);

            step++;
        }

        return ans;
        
    }
};