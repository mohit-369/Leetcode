class Solution {
public:
    int findMin(vector<int>& arr) {

        int low = 0;

        int high = arr.size() - 1;

        if(arr[low]<=arr[high]) return arr[low];

        while(high - low > 1)
        {
            int mid = (high - low)/2 + low;

            if(arr[low] <= arr[mid])
            {
                low = mid;
            } 
            else
            {
                high = mid;
            }
        }

        if(arr[low] <= arr[high]) return arr[low];

        return arr[high];
        
    }
};