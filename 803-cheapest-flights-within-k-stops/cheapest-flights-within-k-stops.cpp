class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        // priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        queue<pair<int,pair<int,int>>> pq;

        vector<pair<int,int>> adj[n];

        for(auto &it:flights)
        {
            int x = it[0];

            int y = it[1];

            int price = it[2];

            adj[x].push_back({y,price});
        }

        vector<int> prices(n,INT_MAX);

        pq.push({0,{0,src}});

        prices[src] = 0;

        while(pq.size())
        {
            int price = pq.front().first;

            int stops = pq.front().second.first;

            int dest = pq.front().second.second;

            pq.pop();

            // if(dest == dst) return price;

            if(stops > k ) continue;
            

            for(auto &it:adj[dest])
            {
                int y = it.first;

                int cost = it.second;

                if(price + cost < prices[y]  )
                {
                    prices[y] = price + cost;

                    pq.push({price + cost, {stops+1,y}});
                }
            }


        }

        if(prices[dst]!=INT_MAX) return prices[dst];

        return -1;




        
    }
};