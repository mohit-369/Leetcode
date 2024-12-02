class Solution {
public:
    bool checkIfExist(vector<int>& arr) {

        int cnt = 0;

        unordered_map<int,int> mpp;

        for(int i = 0; i < arr.size(); i++)
        {
            mpp[arr[i]] = i;

            if(arr[i] == 0) cnt++;
        }

        if(cnt > 1) return 1;

        for(auto it:mpp)
        {
            int x = it.first;

            if(x == 0) continue;

            int y = 2*x;

            if(mpp.find(y) != mpp.end()) return 1;
        }

        return 0;
        
    }
};