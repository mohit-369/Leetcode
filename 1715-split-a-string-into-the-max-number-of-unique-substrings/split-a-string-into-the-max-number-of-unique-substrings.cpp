class Solution {
void solve(string s, set<string> &st, int &ans)
{
    if(s.size() == 0)
    {
        int x = st.size();
        ans = max(ans,x);

        return ;
    }

    if(s.size() == 1)
    {
        if(st.count(s) == 0)
        {
            int x = st.size();
            ans = max(ans , 1 + x);
        }

        else
        {
            int x = st.size();
            ans = max(ans, x);
        }

        return;
    }

    for(int i = 0; i < s.size(); i++)
    {
        string temp = s.substr(0, i + 1);

        if(st.count(temp) == 0)
        {
            st.insert(temp);

            solve(s.substr(i + 1), st, ans);

            st.erase(temp);
        }
    }

    return ;
}
public:
    int maxUniqueSplit(string s) {

        int ans = 1;

        set<string> st;

        solve(s,st,ans);

        return ans;
        
    }
};