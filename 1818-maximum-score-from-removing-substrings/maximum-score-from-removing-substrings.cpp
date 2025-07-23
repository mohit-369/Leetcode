class Solution {
int solve(string s, char first, char second, int x, int y)
{
    stack<char> st;

    int ans = 0;

    int i = 0;

    while(i < s.size())
    {
        if(st.size() == 0)
        {
            st.push(s[i]);
        }

        else
        {
            if(st.top() == first && s[i] == second)
            {
                ans+=x;
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }

        i++;

    }

    string temp;

    while(st.size())
    {
        temp.push_back(st.top());
        st.pop();
    }

    reverse(temp.begin(),temp.end());

    stack<char> mt;

    i = 0;

    while(i < temp.size())
    {
        if(mt.size() == 0)
        {
            mt.push(temp[i]);
        }
        else
        {
            if(mt.top() == second && temp[i] == first)
            {
                ans+=y;
                mt.pop();
            }
            else
            {
                mt.push(temp[i]);
            }
        }

        i++;
    }

    return ans;


}
public:
    int maximumGain(string s, int x, int y) {

        if(x > y)
        {
            return solve(s, 'a', 'b', x, y);
        }

        return solve(s, 'b', 'a', y, x);
    }
};