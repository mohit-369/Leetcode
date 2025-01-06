class Solution {
public:
    vector<int> minOperations(string boxes) {

        int cnt = 0;

        int sum = 0;

        vector<int> ans(boxes.size(),0);

        for(int i = 0; i < boxes.size(); i++)
        {
            ans[i] += sum;

            if(boxes[i] == '1')
            {
                cnt++;
                sum += cnt;
            }
            else
            {
                sum += cnt;
            }
        }

        cnt = 0;
        sum = 0;

        for(int i = boxes.size() - 1; i >= 0; i--)
        {
            ans[i] += sum;

            if(boxes[i] == '1')
            {
                cnt++;
                sum += cnt;
            }

            else
            {
                sum += cnt;
            }
        }

        return ans;


        
    }
};