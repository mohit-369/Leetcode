class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int s = 0;

        int e = nums.size() - 1;

        // if(nums.size() == 1) return nums[0];

        while(e - s > 1)
        {
            int mid = (e-s)/2 + s;

            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
            {
                cout<<e<<" "<<s<<endl;
                return nums[mid];
            }

            if(mid&1)
            {
                if(nums[mid-1] == nums[mid])
                {
                    s = mid + 1;
                }

                else
                {
                    e = mid -1;
                }
            }

            else
            {
                if(nums[mid] == nums[mid+1])
                {
                    s = mid + 1;
                }

                else
                {
                    e = mid -1;
                }
            }
        }

        cout<<s<<" "<<e<<endl;
        if(s == e) return nums[s];
        else if(s==0 && nums[s] != nums[e])
        {
            return nums[s];
        }

        else if(e == nums.size()-1 && nums[e] != nums[s])
        {
            return nums[e];
        }

        else if(nums[s] != nums[s-1]) return nums[s];

        return nums[e];


        
    }
};