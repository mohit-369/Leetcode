class Solution {
public:
    int countHomogenous(string s) {

        int m=1e9+7;

        int ans=0;

        int i=0;

        int j=0;

        unordered_map<char,int> mpp;

        int n=s.size();

        while(j<n)
        {
            
            mpp[s[j]]++;
            while(i<=j && mpp.size()>1)
            {
                mpp[s[i]]--;

                if(mpp[s[i]]==0)
                {
                    mpp.erase(s[i]);
                }

                i++;
            }

            ans=(ans%m+(j-i+1)%m)%m;

            j++;
        }
        
        return ans;
    }
};