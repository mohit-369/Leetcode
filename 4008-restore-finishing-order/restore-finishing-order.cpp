class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> ans;
        for(int i = 0; i < order.size(); i++)
        {
            int ele = order[i];

            for(int j = 0; j < friends.size(); j++)
            {
                if(ele == friends[j]) ans.push_back(ele);
            }
        }

        return ans;
        
    }
};