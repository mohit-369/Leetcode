class Solution {
void calculateParent(int child, int parent, unordered_map<int,vector<int>> &tree, vector<int> &parentarray)
{
    parentarray[child] = parent;

    for(auto &c:tree[child])
    {
        if(parent == c) continue;
        calculateParent(c,child,tree,parentarray);
    }

    return;
}
void solve(int child, int parent, unordered_map<int,vector<int>> &tree, vector<int> &distime,int currans, int &ans, int time, vector<int> &amount)
{
    if(distime[child] == -1 || distime[child] > time) currans+=amount[child];

    else if(distime[child] == time) currans+=amount[child]/2;

    int leafnode = 1;

    for(auto &c:tree[child])
    {
        if(c != parent)
        {
            leafnode = 0;
            solve(c,child,tree,distime,currans,ans,time+1,amount);
        }
        
    }

    if(leafnode)
    {
        ans = max(ans,currans);
    }

    return ;
}
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {

        int node = edges.size() + 1;

        vector<int> parentarray(node);

        unordered_map<int,vector<int>> tree;

        for(auto &e:edges)
        {
            int x = e[0];
            int y = e[1];
            tree[x].push_back(y);
            tree[y].push_back(x);
        }

        calculateParent(0,-1,tree,parentarray);

        vector<int> distime(node,-1);

        int time = 0;

        int child = bob;

        while(child != -1)
        {
            distime[child] = time;
            child = parentarray[child];
            time++;
        }

        int ans = INT_MIN;

        int currans = 0;

        solve(0,-1,tree,distime,currans,ans,0,amount);

        return ans;
        
    }
};