class Solution {
public:
    int edgeScore(vector<int>& edges) {

        int nodes = edges.size();

        vector<long long int> indegreeSum(nodes,0);

        for(int node = 0; node < nodes; node++)
        {
            indegreeSum[edges[node]] += node*1ll;
        }

        long long  nodesum = 0;

        int ans = 0;

        for(int node = 0; node < nodes; node++)
        {
            if(nodesum < indegreeSum[node])
            {
                nodesum = indegreeSum[node];
                ans = node;
            }
        }

        return ans;
        
    }
};