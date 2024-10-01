class Solution {
public:
    string intToRoman(int num) {

        map<int,string> mpp;

        mpp[1000] = "M";

        mpp[900] = "CM";

        mpp[500] = "D";

        mpp[400] = "CD";

        mpp[100] ="C";

        mpp[90] ="XC";

        mpp[50] ="L";

        mpp[40] ="XL";

        mpp[10] = "X";


        mpp[9] = "IX";

        mpp[5] = "V";

        mpp[4] = "IV";

        mpp[1] = "I";

        string ans;

        for(auto it = mpp.rbegin(); it != mpp.rend(); it++)
        {
            int x = it -> first;

            if(num >= x)
            {
                int mul = num/x;

                num = num % x;

                while(mul--)
                {
                    ans = ans + mpp[x];
                }
            }

            if(num==0) break;
        }

        return ans;


        
    }
};