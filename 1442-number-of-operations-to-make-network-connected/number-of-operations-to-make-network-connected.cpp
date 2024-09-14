class Solution {
class Dsu{
    vector<int> parent;

    vector<int> size;

    public:

    Dsu(int n)
    {
        parent.resize(n,-1);

        size.resize(n,1);

        for(int i = 0;  i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int x)
    {
        if(x == parent[x]) return parent[x];

        return parent[x] = findParent(parent[x]);
    }


    void Union(int x , int y)
    {
        x = findParent(x);
        y = findParent(y);

        if(x!=y)
        {
            if(size[x] > size[y])
        {
            swap(x,y);
        }

        parent[x] = y;

        size[y]+= size[x];
        }

        

        return ;
    }
};
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        
        Dsu d(n);

        int node = 1;

        int count = 0;

        for(auto &it:connections)
        {
            int x = it[0];

            int y = it[1];

            if(d.findParent(x) != d.findParent(y))
            {   node++;
                d.Union(x,y);
            }

            else
            {
                count++;
            }
        }

        // cout<<node<<endl;

        cout<<count<<endl;

        return (n-node > count) ? -1 : n - node;

        
        
    }
};