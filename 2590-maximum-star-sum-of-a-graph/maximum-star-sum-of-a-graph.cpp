class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {

        unordered_map<int,multiset<int>> graph;
        int nodes = vals.size();
        vector<int> sum(nodes,0);

        for(auto &edge:edges)
        {
            int x = edge[0];
            int y = edge[1];

            int a = vals[x];
            int b = vals[y];

            if(b > 0)
            {
                graph[x].insert(b);
                sum[x]+=b;
            }
            if(a > 0)
            {
                graph[y].insert(a);
                sum[y]+=a;
            }
            
            if(graph[x].size() > k)
            {
                auto it = graph[x].begin();
                sum[x]-=*it;
                graph[x].erase(it);
            }
            if(graph[y].size() > k)
            {
                auto it = graph[y].begin();
                sum[y]-=*it;
                graph[y].erase(it);
            }
        }

        int ans = INT_MIN;

        for(int i = 0; i < nodes; i++)
        {
            ans = max(ans,sum[i] + vals[i]);
            ans = max(ans,vals[i]);
        }

        return ans;
        
    }
};