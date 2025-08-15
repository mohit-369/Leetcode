class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {

        vector<int> indegree(numCourses,0);

        unordered_map<int,vector<int>> graph;

        for(auto &it:p)
        {
            indegree[it[1]]++;
            graph[it[0]].push_back(it[1]);
        }

        queue<int> q;

        int cnt = 0;

        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
                cnt++;
            }
        }

        while(q.empty() == false)
        {
            int node = q.front();
            q.pop();

            for(auto &nei:graph[node])
            {
                indegree[nei]--;
                if(indegree[nei] == 0)
                {
                    cnt++;
                    q.push(nei);
                }
            }
        }

        return cnt == numCourses;


        
    }
};