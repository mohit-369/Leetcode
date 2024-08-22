class Solution {
public:
    string reverseWords(string s) {

        stack<string> st;

        string temp;

        for(int i =0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                if(temp.size())
                {
                    st.push(temp);
                    temp="";
                }
            }

            else
            {
                temp.push_back(s[i]);
            }
        }

        string ans;

        if(temp.size())
        {
            ans=temp;
        }

        while(!st.empty())
        {
            if(ans.size())
            {
                ans=ans+" "+st.top();
            }
            else
            {
                ans=st.top();
            }

            st.pop();
        }

        return ans;
        
    }
};