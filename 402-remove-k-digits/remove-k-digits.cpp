class Solution {
public:
    string removeKdigits(string num, int k) {

        stack<char> st;

        st.push(num[0]);

        for (int i = 1; i < num.size(); i++) {

            char ch = num[i];

            while (st.size() && st.top() > ch && k) {
                st.pop();

                k--;
            }

            st.push(ch);

            if (st.size() == 1 && ch == '0') {
                st.pop();
            }
        }

        string ans;

        while (k-- && st.size()) {
            st.pop();
        }

        while (st.size()) {
            ans.push_back(st.top());

            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return (ans.size()==0)?"0":ans;
    }
};