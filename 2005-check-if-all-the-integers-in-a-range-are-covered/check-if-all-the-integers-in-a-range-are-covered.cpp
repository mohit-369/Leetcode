class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {

        vector<int> temp(52,0);

        for(auto &it:ranges)
        {
            temp[it[0]]++;

            temp[it[1] + 1]--;
        }

        int count = 0;

        int ans = 0;

        for(int i = 0; i < 52; i++)
        {
            count += temp[i];

            if(count > 0 && i >= left && i <= right)
            {
                ans++;
            }
        }
        

        cout << ans << endl;

        return (ans == right - left + 1);
        
    }
};