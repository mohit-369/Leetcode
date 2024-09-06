class Solution {
public:
    string removeKdigits(string num, int k) {

        stack<char> st;

        st.push(num[0]);

        for(int i = 1; i < num.size(); i++)
        {
            while(k && st.empty()==false && st.top() > num[i])
            {
                st.pop();

                k--;
            }

            st.push(num[i]);
        }

        while(k-- && !st.empty())
        {
            st.pop();
        }

        string ans;

        while(st.empty()==false)
        {
            ans.push_back(st.top());
            st.pop();
        }

        for(int i = ans.size()-1; i>=0; i--)
        {
            if(ans[i]!='0') break;
            ans.pop_back();
        }



        reverse(ans.begin(),ans.end());

        

        return ans.size()==0?"0":ans;


        
    }
};