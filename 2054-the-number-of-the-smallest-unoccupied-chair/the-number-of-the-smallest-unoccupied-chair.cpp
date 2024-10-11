class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {

        int t = times[targetFriend][0];

        sort(times.begin(),times.end());

        

        multiset<pair<int,int>> mt;

        set<int> st;

        int seat = 0;

        for(auto &it:times)
        {
            int at = it[0];

            int lt = it[1];

            int rq;

            while(mt.size())
            {
                auto pt = mt.begin();

                int x = pt -> first;

                int y = pt -> second;

                cout<<x<<" "<<y<<endl;

                if(x <= at)
                {
                    st.insert(y);

                    mt.erase(mt.begin());
                }

                else
                {
                    break;
                }
            }

            if(st.size())
            {
                rq = *st.begin();

                st.erase(st.begin());
            }

            else
            {
                rq = seat;

                seat++;
            }

            mt.insert({lt,rq});


            if(at == t) return rq;




        }


        return 0;
        
    }
};