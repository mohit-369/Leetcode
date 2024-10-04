class Solution {
public:
    long long dividePlayers(vector<int>& skill) {

        long long int ans = 0;

        long long sum = accumulate(skill.begin(),skill.end(),0);


        // if(sum&1) return -1;


        long long requiredSum = (2*sum)/skill.size();


        unordered_map<long long,long long> mpp;

        long long int count = 0;

        for(auto &it:skill)
        {
            if(mpp.find(requiredSum - it) != mpp.end())
            {
                ans = ans + (requiredSum - it )*it;

                mpp[requiredSum - it]--;

                if(mpp[requiredSum - it] == 0)
                {
                    mpp.erase(requiredSum - it);
                }

                count++;
                
            } 

            else
            {
                mpp[it]++;
            }           
        }

        cout<<ans<<endl;

        if(count == (skill.size())/2 ) return ans;

        return -1;




        
    }
};