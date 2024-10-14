class Solution {
public:
    int halveArray(vector<int>& nums) {

        priority_queue<double,vector<double>> pq;

        double sum = 0;

        for(auto &it:nums) 
        {
            
            
            int num = it;

            double x = num*1.00;

            pq.push(x);

            sum += x;


        }

        double temp = sum;

        int ans = 0;

        while(temp > (sum / 2))
        {
            double num = pq.top();

            pq.pop();

            temp -= num;

            num = num / 2;

            temp +=  num;

            pq.push(num);

            ans++;
        }

        return ans;



        
        
    }
};