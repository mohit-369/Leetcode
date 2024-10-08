class Solution {
public:
    int minSwaps(string s) {

        int cnt = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '[') cnt++;

            else if(s[i] == ']' && cnt) cnt--;
        }

        return (cnt + 1) / 2;
        
    }
};