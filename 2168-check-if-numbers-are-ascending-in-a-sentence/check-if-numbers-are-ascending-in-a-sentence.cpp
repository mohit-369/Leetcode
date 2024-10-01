class Solution {
public:
    bool areNumbersAscending(string s) {

        int pre = -1;

        int start = 0;

        while(start < s.size())
        {
            if(s[start] >= '0' && s[start] <= '9')
            {
                int num = 0;
                while(s[start] >= '0' && s[start] <= '9')
                {
                    num = num*10 + s[start] - '0';

                    start++;
                }

                if(pre >= num)
                {
                    return 0;
                }

                pre = num;
            }

            else
            {
                start++;
            }
        }

        return 1;
        
    }
};