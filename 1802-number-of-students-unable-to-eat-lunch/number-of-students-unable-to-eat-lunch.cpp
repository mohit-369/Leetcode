class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int c0=0,c1=0;

        for(auto &it:students)
        {
            if(it) c1++;
            else
            {
                c0++;
            }
        }

        for(int i=0;i<sandwiches.size();i++)
        {
            if(sandwiches[i]==1 && c1) c1--;
            else if(sandwiches[i]==0 && c0) c0--;
            else
            {
                return c1+c0;
            }
        }

        return 0;
    }
};