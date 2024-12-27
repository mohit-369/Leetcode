class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {

        int idx = 0;
        int num = values[0];
        int ans = INT_MIN;
        for(int i = 1; i < values.size(); i++)
        {
            if(num - (i - idx) < values[i - 1] - 1)
            {
                num = values[i - 1];
                idx = i - 1;
                ans = max(ans,values[i] + values[i - 1] - 1);
            }

            else
            {
                ans = max(ans,values[i] + num - (i - idx));
            }
        }

        return ans;
        
    }
};