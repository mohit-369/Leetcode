class Solution {
public:
    int maxDepth(string s) {

        // stack<char> st;

        int count=0;

        int ans=INT_MIN;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                count++;
                ans=max(ans,count);
                
            }
            else if(s[i]==')')
            {
                count--;

                // ans=max(ans,count);
            }
        }

        return (ans==INT_MIN)?0:ans;
        
    }
};