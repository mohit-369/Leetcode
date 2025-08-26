class Solution {

public:
    void solve(int index, set<string> &st, string &s, int &ans)
    {
        if(index == s.size())
        {
            int size = st.size();
            ans = max(ans,size);
            // for(auto &it:st)
            // {
            //     cout<<it<<" "<<endl;
            // }
            // cout<<st.size()<<endl;

            return;
        }

        string temp;

        for(int i = index; i < s.size(); i++)
        {
            temp.push_back(s[i]);
            if(st.find(temp) == st.end())
            {
                st.insert(temp);
            solve(i+1,st,s,ans);
            st.erase(temp);
            }
            
        }

        return ;
    }
    int maxUniqueSplit(string s) {

        set<string> st;

        int ans = 1;

        solve(0,st,s,ans);

        return ans;
        
    }
};