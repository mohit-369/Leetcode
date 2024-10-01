class Solution {
bool check(vector<int> &bloomDay, int m, int k, int day)
{
    int count = 0;

    int start = 0;

    int end = 0;

    while(start < bloomDay.size())
    {
        if(bloomDay[start] <= day)
        {
            int size = start - end + 1;

            start++;

            if(size == k)
            {
                count++;
                end = start;
            }
        }

        else
        {
            start++;
            end = start;
        }
    }

    return count >= m;


}
public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        int low = *min_element(bloomDay.begin(),bloomDay.end());

        int high = *max_element(bloomDay.begin(),bloomDay.end());

        while(high - low > 1)
        {
            int mid = (high - low)/2 + low;

            if(check(bloomDay,m,k,mid))
            {
                high = mid;
            }

            else
            {
                low = mid;
            }
        }

        if(check(bloomDay,m,k,low)) return low;

        if(check(bloomDay,m,k,high)) return high;

        return -1;
        
    }
};