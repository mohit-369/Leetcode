class Solution {
public:
    string largestOddNumber(string num) {

        int end = -1;

        int start = 0;

        while(start < num.size())
        {
            int nu = num[start] - '0';

            if(nu&1)
            {
                end = start;
            }

            start++;
        }

        return num.substr(0,end+1);
        
        
    }
};