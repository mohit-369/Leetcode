class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {

        vector<pair<int,int>> track;

        for(int i = 0; i < nums.size(); i++)
        {
            track.push_back({nums[i],i});
        }

        sort(track.begin(),track.end());

        int mini = track[0].second;

        int ans = 0;

        for(int i = 1; i < track.size(); i++)
        {
            ans = max(ans, track[i].second - mini);

            mini = min(mini,track[i].second);
        }

        return ans;
        
    }
};