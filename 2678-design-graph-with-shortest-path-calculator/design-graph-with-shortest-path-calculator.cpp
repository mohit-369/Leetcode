class Graph {
int node;
unordered_map<int,vector<pair<int,int>>> graph;
public:
    Graph(int n, vector<vector<int>>& edges) {

        node = n;
        for(auto &e:edges)
        {
            int x = e[0];
            int y = e[1];
            int p = e[2];
            graph[x].push_back({y,p});
        }
        
    }
    
    void addEdge(vector<int> edge) {

        int x = edge[0];
        int y = edge[1];
        int p = edge[2];
        graph[x].push_back({y,p});
        
    }
    
    int shortestPath(int node1, int node2) {

        set<pair<int,int>> st;

        st.insert({0,node1});

        vector<int> dis(node,INT_MAX);
        dis[node1] = 0;

        while(st.size() != 0)
        {
            auto it = st.begin();
            int curr = (*it).first;
            int no = (*it).second;
            st.erase(it);

            for(auto &n:graph[no])
            {
                int y = n.first;
                int w = n.second;

                if(dis[y] > w + curr )
                {
                    dis[y] = w + curr;
                    st.insert({w+curr,y});
                }
            }
        }

        if(dis[node2] == INT_MAX) return -1;

        return dis[node2];
        
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */