class Solution {
public:
    string makeGood(string s) {
        string ans="";
        ans +=s[0];
        for(int i=1;i<s.size();i++)
        {
            char c;
            if(ans.size()!=0){
            int l=ans.size()-1;
            char c=ans[l];
            if((c>='a' and c<='z') and (s[i]>='A' and s[i]<='Z'))
            {
                c=c-'a'+'A';
                if(c==s[i])
                {
                    ans.pop_back();
                }
                else{
                    ans.push_back(s[i]);
                }
            }
            else if((c>='A' and c<='Z') and (s[i]>='a' and s[i]<='z'))
            {
                c=c-'A'+'a';
                if(c==s[i])
                {
                    ans.pop_back();
                }
                else{
                    ans.push_back(s[i]);
                }
            }
            else{
                ans.push_back(s[i]);
            }
            }
             else{
                ans.push_back(s[i]);
            }
        }
        return ans;
        
    }
};