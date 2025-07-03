class Solution {
public:
    char kthCharacter(int k) {

        int n = 1;

        string temp = "a";

        while(n < k)
        {
            for(int index = 0; index < n; index++)
            {
                char next = 'a' + (temp[index] - 'a' + 1) % 26;

                temp.push_back(next);
            }

            n = temp.size();
        }

        // cout<<temp<<endl;

        return temp[k-1];
        
    }
};