class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {

        long long int ans = 0;

        multiset<int> mt;

        for(auto &it:nums) mt.insert(it);

        while(k--)
        {

            auto it = prev(mt.end());
            int num = *it;

            mt.erase(it);

            mt.insert((num + 2) / 3);

            ans += num*1ll;
        }

        return ans;
        
    }
};