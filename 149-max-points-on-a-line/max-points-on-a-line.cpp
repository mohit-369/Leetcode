class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {

        // unordered_map<pair<int,int>,int>> mpp;

        if(points.size() == 0 || points.size() == 1) return points.size();

        int ans = 0;

        for(int i = 0; i < points.size(); i++)
        {
            int x1 = points[i][0];

            int y1 = points[i][1];

            for(int j = i + 1; j < points.size(); j++)
            {
                int x2 = points[j][0];
                int y2 = points[j][1];

                int dx = x1 - x2;

                int dy = y1 - y2;

                int gc = __gcd(dx,dy);

                dx = dx/gc;
                dy = dy/gc;

                int cnt = 2;

                for(int k = j + 1; k < points.size(); k++)
                {
                    int ndx = x1 - points[k][0];
                    int ndy = y1 - points[k][1];
                    int ngc = __gcd(ndx,ndy);
                    ndx = ndx/ngc;
                    ndy = ndy/ngc;

                    if(ndx*dy == ndy*dx) cnt++;
                }

                ans = max(ans,cnt);
            }


        }

        // for(auto &it:mpp) ans = max(ans,it.second);

        return ans;
        
    }
};