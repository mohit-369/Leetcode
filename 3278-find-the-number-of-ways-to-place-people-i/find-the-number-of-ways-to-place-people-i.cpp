class Solution {
public:
    int numberOfPairs(vector<vector<int>>& arr) {

        auto cmp = [](auto a, auto b)
        {
            if(a[0] == b[0]) return a[1] > b[1];

            return a[0] < b[0];
        };

        sort(arr.begin(),arr.end(),cmp);
        set<pair<int,int>> st;

        int ans = 0;

        for(int i = 0; i < arr.size(); i++)
        {

            for(int j = 0; j < arr.size(); j++)
            {
                if(i == j) continue;
                int a = min(i,j);
                int b = max(i,j);

                int x1 = arr[a][0];
                int y1 = arr[a][1];
                int x2 = arr[b][0];
                int y2 = arr[b][1];

                if(x1 <= x2 && y1 >= y2)
                {
                    int flag = true;

                    for(int k = 0; k < arr.size(); k++)
                    {
                        if(k != i && k != j)
                        {
                            int x3 = arr[k][0];
                            int y3 = arr[k][1];

                            if(x3>=x1 && x3 <= x2 && y3>=y2 && y3<= y1)
                            {
                                flag = false;
                                break;
                            }
                        }
                    }

                    if(flag && st.find({a,b}) == st.end())
                    {
                        st.insert({a,b});
                        ans++;
                    }
                }


            }
        }

        return ans;
        
    }
};