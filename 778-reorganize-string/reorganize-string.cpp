class Solution {
public:
    string reorganizeString(string s) {

        priority_queue<pair<int,char>,vector<pair<int,char>>> pq;

        vector<int> freq(26,0);

        string ans;

        for(int i = 0; i < s.size(); i++)
        {
            freq[s[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++)
        {
            if(freq[i] != 0)
            {
                pq.push({freq[i],i + 'a'});
            }
        }

        while(pq.size() > 1)
        {
            auto first = pq.top();
            pq.pop();
            auto second = pq.top();
            pq.pop();

            int x = first.first;
            int y = second.first;
            char a = first.second;
            char b = second.second;

            x--;
            y--;

            ans.push_back(a);
            ans.push_back(b);

            if(x)
            {
                pq.push({x,a});
            }
            if(y)
            {
                pq.push({y,b});
            }


        }

        // cout<<ans<<endl;

        if(pq.empty() == false)
        {
            cout<<ans<<"inside"<<endl;
            int x = pq.top().first;
            if(x == 1)
            {
                ans.push_back(pq.top().second);

                return ans;
            }

            return "";
        }

        return ans;
    }
};