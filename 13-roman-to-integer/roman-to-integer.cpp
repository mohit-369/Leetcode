class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char,int> mpp;

        mpp['I']=1;
        mpp['V']=5;
        mpp['X']=10;
        mpp['L']=50;
        mpp['C']=100;
        mpp['D']=500;
        mpp['M']=1000;

        int ans = 0;

        for(int i = 0;i<s.size();i++)
        {
            if(s[i]=='I')
            {
                if((i+1)<s.size())
                {
                    if(s[i+1]=='V')
                    {
                        ans+=4;
                        i++;
                    }

                   else if(s[i+1]=='X')
                    {
                        ans+=9;
                        i++;
                    }
                    else
                    {
                        ans++;
                    }
                }
                else
                {
                    ans++;

                }
            }

            else if(s[i]=='X')
            {
                if((i+1)<s.size())
                {
                    if(s[i+1]=='L')
                    {
                        ans+=40;
                        i++;

                    }

                    else if(s[i+1]=='C')
                    {
                        ans+=90;
                        i++;
                    }
                    else
                    {
                        ans+=10;
                    }
                }
                else
                {
                    ans+=10;
                }
            }

            else if(s[i]=='C')
            {
                if((i+1)<s.size())
                {
                    if(s[i+1]=='D')
                    {
                        ans+=400;
                        i++;
                    }

                    else if(s[i+1]=='M')
                    {
                        ans+=900;
                        i++;
                    }
                    else
                    {
                        ans+=100;
                    }
                }
                else
                {
                    ans+=100;
                }
            }

            else
            {
                ans+=mpp[s[i]];
            }
        }

        return ans;
        
    }
};