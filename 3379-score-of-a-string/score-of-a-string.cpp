class Solution {
public:
    int scoreOfString(string s) {

        int ans=0;

        for(int i=0;i<s.size()-1;i++)
        {
            int x=s[i]-'a';

            int y=s[i+1]-'a';

            ans+=abs(x-y);
        }

        return ans;
        
    }
};