class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {

        vector<int> vis(n,0);

        unordered_map<int,vector<int>> graph;

        for(auto &edge:edges)
        {
            int x = edge[0];
            int y = edge[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        for(auto &res:restricted)
        {
            vis[res] = 1;
        }

        int ans = 0;

        queue<int> q;

        q.push(0);

        while(q.empty() == false)
        {
            int node = q.front();

            q.pop();

            vis[node] = 1;

            ans++;

            for(auto &nei:graph[node])
            {
                if(vis[nei] == 0)
                {
                    q.push(nei);

                }
            }
        }

        return ans;
        
    }
};