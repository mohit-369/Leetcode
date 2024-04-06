class Solution {
public:
    string minRemoveToMakeValid(string s) {

        stack<int> st;

        string a = s;

        string ans;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '(' && s[i] != ')') {
                // ans.push_back(s[i]);
                continue;
            }

            else if (s[i] == '(') {
                st.push(i);
            }

            else {
                if (st.size()) {
                    int idx = st.top();
                    st.pop();
                    s[idx] = '1';
                    s[i] = '1';
                } else {
                    s[i] = '0';
                }
            }
        }

        while (st.size()) {
            int idx = st.top();
            s[idx] = '0';
            st.pop();
        }

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                ans.push_back(a[i]);
            }
        }

        return ans;
    }
};