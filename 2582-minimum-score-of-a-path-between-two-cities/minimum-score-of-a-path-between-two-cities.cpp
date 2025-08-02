class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        unordered_map<int,vector<pair<int,int>>> graph;

        for(auto &road:roads)
        {
            int city1 = road[0];
            int city2= road[1];
            int dis = road[2];

            graph[city1].push_back({city2,dis});
            graph[city2].push_back({city1,dis});
        }

        int ans = INT_MAX;

        vector<int> vis(n+1,0);

        queue<int> q;

        q.push(1);

        while(q.empty() == false)
        {
            int city = q.front();
            q.pop();

            vis[city] = 1;

            for(auto &it:graph[city])
            {
                int x = it.first;
                int dis = it.second;

                if(!vis[x])
                {
                    ans = min(ans,dis);
                    q.push(x);
                }
            }
        }

        return ans;
        
    }
};