class Solution {
public:
    bool parseBoolExpr(string expression) {

        stack<char> st;

        string s = expression;

        for(int i = s.size() -1 ; i >=0; i--)
        {
            if(s[i] == ',') continue;

            else if(s[i] != '!' && s[i] != '&' && s[i] != '|')
            {
                st.push(s[i]);
            }
            else
            {
                if(s[i] == '!')
                {
                    int flag = 0;

                    st.pop();

                    if(st.top() == 'f') 
                    {
                        flag = 1;

                    }

                    if(st.size()) st.pop();

                    if(st.size()) st.pop();

                    if(flag) st.push('t');

                    else st.push('f');
                }

                else if(s[i] == '&')
                {
                    int flag = 1;

                    st.pop();

                    while(st.top() != ')')
                    {
                        if(st.top() == 'f') 
                        {
                            flag = 0;
                        }

                        st.pop();
                    }

                    st.pop();

                    if(flag) st.push('t');

                    else st.push('f');
                }

                else
                {
                    int flag = 0;

                    st.pop();

                    while(st.top() != ')')
                    {
                        if(st.top() == 't') 
                        {
                            flag = 1;
                        }

                        st.pop();
                    }

                    st.pop();

                    if(flag) st.push('t');

                    else st.push('f');
                }
            }
        }

        if(st.top() == 'f')
        {
            return 0;
        }

        return 1;
        
    }
};