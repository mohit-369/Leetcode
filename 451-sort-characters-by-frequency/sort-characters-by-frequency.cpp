class Solution {
public:
    string frequencySort(string s) {

        priority_queue<pair<int,char>> pq;

        unordered_map<char,int> mpp;

        for(int i = 0; i < s.size(); i++)
        {
            mpp[s[i]]++;
        }

        for(auto it:mpp)
        {
            pq.push({it.second,it.first});
        }

        string ans;

        while(pq.empty()==false)
        {
            ans+=string(pq.top().first,pq.top().second);

            pq.pop();
        }

        return ans;

        
    }
};