class Solution {
long long fuel = 0;
int solve(int child, int parent, unordered_map<int,vector<int>> &tree, int seats)
{
    int person = 1;

    for(auto &c:tree[child])
    {
        if(c != parent)
        {
            person+=solve(c,child,tree,seats);
        }
    }
    if(child != 0)
    fuel+=1ll*((person+seats-1)/seats);
    return person;
}
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        unordered_map<int,vector<int>> tree;
        for(auto &it:roads)
        {
            int x = it[0];
            int y = it[1];
            tree[x].push_back(y);
            tree[y].push_back(x);
        }
        solve(0,-1,tree,seats);
        return fuel;
        
    }
};