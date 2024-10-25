class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        
        unordered_map<string,int> mpp;

        sort(folder.begin(),folder.end());

        vector<string> ans;

        for(auto it:folder)
        {
            int flag = 1;

            string temp;

            for(int i = 0; i < it.size(); i++)
            {
                if( it[i] == '/')
                {
                    if(mpp.find(temp) != mpp.end())
                    {
                        flag = 0;
                        break;
                    }

                    
                }

                temp.push_back(it[i]);

               
            }

            if(mpp.find(temp) != mpp.end()) flag = 0;

            if(flag)
            {
                mpp[temp] = 1;
            }
        }

        for(auto it:mpp)
        {
            ans.push_back(it.first);
        }

        return ans;




        
    }
};