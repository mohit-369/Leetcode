class Solution {
class Dsu{
    public:
    vector<int> size;
    vector<int> parent;
    int node;
    Dsu(int node)
    {
        this->node = node;
        size.resize(node,1);
        for(int i = 0; i < node; i++)
        {
            parent.push_back(i);
        }
    }

    int findparent(int child)
    {
        if(parent[child] == child) return child;
        return parent[child] = findparent(parent[child]);
    }

    void unionbysize(int x, int y)
    {
        x = findparent(x);
        y = findparent(y);
        if(x != y)
        {
            if(size[x] < size[y]) swap(x,y);
            size[x]+=size[y];
            parent[y] = parent[x];
        }
        return ;
    }

    long long ans()
    {
        long long ans = 0;

        long long groupsize = 0;

        for(int i = 0; i < node; i++)
        {
            if(parent[i] == i)
            {
                ans+=groupsize*size[i]*1ll;
                groupsize+=size[i]*1ll;
                

            }
        }

        return ans;
    }
};
public:
    long long countPairs(int n, vector<vector<int>>& edges) {

        Dsu D(n);
        for(auto &it:edges)
        {
            int x = it[0];
            int y = it[1];
            D.unionbysize(x,y);
        }

        return D.ans();
        
    }
};