class Solution {
int solve(vector<int> &prices,int index,int &ans)
{
    if(index == 0) return prices[0];

    int mi = solve(prices,index-1,ans);

    ans = max(ans,prices[index]-mi);

    return min(prices[index],mi);




}
public:
    int maxProfit(vector<int>& prices) {

        int ans =INT_MIN;

        solve(prices,prices.size()-1,ans);

        return ans<0?0:ans;

        
        
    }
};