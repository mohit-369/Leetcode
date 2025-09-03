class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {

        auto cmp = [](auto a, auto b)
        {
            if(a[0] == b[0]) return a[1] > b[1];

            return a[0] < b[0];
        };

        sort(points.begin(),points.end(),cmp);

        int ans = 0;

        int maxi =  INT_MIN;

        for(int i = 0; i < points.size(); i++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            int maxi =  INT_MIN;

            for(int j = i + 1; j < points.size(); j++)
            {
                int x2 = points[j][0];
                int y2 = points[j][1];

                if(y1>=y2)
                {
                    if(y2 > maxi)
                    {
                        maxi = y2;
                        ans++;

                        if(maxi == y1) break;

                    }
                }
            }
        }

        return ans;


        
    }
};