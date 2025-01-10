class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {

        int ans = 0;

        int size = pref.size();

        for(auto &it:words)
        {
            string a = it;

            if(a.size() >= size)
            {
                if(a.substr(0,size) == pref) ans++;
            }
        }

        return ans;
        
    }
};