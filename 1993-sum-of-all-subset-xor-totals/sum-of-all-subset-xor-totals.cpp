class Solution {
void solve(int index,vector<int> &nums,int &ans,int count,int currans)
{
    if(nums.size()==index)
    {
        if(count) ans+=currans;

        return ;
    }

    solve(index+1,nums,ans,count,currans);

    if(count==0)
    {
        currans=nums[index];
    }

    else
    {
        currans=currans^nums[index];
    }

    solve(index+1,nums,ans,count+1,currans);

    return;
}
public:
    int subsetXORSum(vector<int>& nums) {

        int ans=0,count=0,currans=0;

        solve(0,nums,ans,count,currans);

        return ans;
        
    }
};