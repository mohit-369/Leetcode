class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        
        int ans=0;
        
        for(int i=0;i<words.size()-1;i++)
        {
            string a=words[i];
            for(int j=i+1;j<words.size();j++)
            {
                string b=words[j];
                
                if(a.size()<=b.size())
                {
                    int flag=1;
                    
                    int flag1=1;
                    
                    for(int k=0;k<a.size();k++)
                    {
                        if(a[k]!=b[k])
                        {
                            flag=0;
                            break;
                        }
                    }
                    
                    int x=0;
                    
                    for(int k=a.size()-1;k>=0;k--)
                    {
                        if(a[k]!=b[b.size()-1-x])
                        {
                            flag1=0;
                            break;
                        }
                        x++;
                    }
                    if(flag and flag1)
                    {
                        ans++;
                    }
                    
                    
                }
                
            }
            
            
        }
        
        return ans;
        
    }
};