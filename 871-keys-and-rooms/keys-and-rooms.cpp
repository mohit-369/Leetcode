class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int cnt = rooms.size();

        vector<int> open(cnt,0);

        queue<int> q;

        q.push(0);

        while(q.empty() == false)
        {
            int key = q.front();
            q.pop();
            if(open[key]) continue;
            open[key] = 1;
            cnt--;
            if(cnt == 0) return 1;

            for(auto &it:rooms[key])
            {
                q.push(it);
            }
        }

        if(cnt == 0) return 1;
        return 0;
        
    }
};