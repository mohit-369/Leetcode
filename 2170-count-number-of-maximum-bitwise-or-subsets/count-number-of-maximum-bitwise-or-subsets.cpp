class Solution {
void solve(int index, vector<int> &nums, int maxi, int &temp, int &ans)
{
    if(index == nums.size())
    {
        if(maxi > temp)
        {
            temp = maxi;

            ans = 1;

        }

        else if(maxi == temp)
        {
            ans++;
        }

        return ;
    }

    solve(index + 1, nums, maxi | nums[index], temp, ans);
    solve(index + 1, nums, maxi,temp, ans);

    return ;
}
public:
    int countMaxOrSubsets(vector<int>& nums) {

        int ans = 0;

        int temp = INT_MIN;

        solve(0,nums,0,temp,ans);

        return ans;
        
    }
};