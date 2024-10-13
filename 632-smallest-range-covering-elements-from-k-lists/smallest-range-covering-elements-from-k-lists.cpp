class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        multiset<pair<int,pair<int,int>>> mt;

        int diff = INT_MAX;

        int a = 0;

        int b = 0;

        while(true)
        {
            if(diff == INT_MAX)
            {
                for(int row = 0; row < nums.size(); row++)
                {
                    int ele = nums[row][0];
                    
                    mt.insert({ele,{0,row}});
                }

                a = mt.begin() -> first;

                b = mt.rbegin() -> first;

                diff = min(diff,b - a);
            }

            else
            {
                auto start = mt.begin();

                auto end = mt.rbegin();

                int ele1 = start -> first;

                int ele2 = end -> first;

                if(ele2 - ele1 < diff)
                {
                    diff = ele2 - ele1;

                    a = ele1;

                    b = ele2;
                }

                int index = start -> second.first;

                int row = start -> second.second;

                if(index + 1 != nums[row].size())
                {
                    mt.erase(start);

                    mt.insert({nums[row][index+1],{index + 1, row}});
                }

                else
                {
                    break;
                }


            }
        }


        return {a,b};
        
    }
};