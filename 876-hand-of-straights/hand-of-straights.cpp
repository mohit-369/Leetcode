class Solution {
class Comparator{
    public:

    bool operator()(pair<int,int> below, pair<int,int> above)
    {
        if(below.first>above.first) return 1;

        return 0;
    }

};
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        unordered_map<int,int> mpp;

        if(hand.size()%groupSize) return 0;

        for(auto &it:hand)
        {
            mpp[it]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,Comparator> pq;

        for(auto &it:mpp)
        {
            pq.push({it.first,it.second});
        }

        while(pq.size())
        {
            vector<pair<int,int>> v;

            int ele = pq.top().first;

            int frq = pq.top().second;

            v.push_back({ele,frq});

            pq.pop();

            for(int i = 1; i<groupSize; i++)
            {
                if(ele != pq.top().first-1)
                {
                    return 0;
                }

                ele = pq.top().first;

                frq = pq.top().second;

                v.push_back({ele,frq});

                pq.pop();


            }

            for(int i = 0; i < groupSize; i++)
            {
                int ele = v[i].first;

                int frq = v[i].second-1;

                if(frq)
                {
                    pq.push({ele,frq});
                }
            }


        }


        return 1;
        
    }
};
/*

*/