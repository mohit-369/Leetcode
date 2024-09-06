class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        int mod = 1e9+7;

        int n = arr.size();

        vector<int> l(n,-1);

        vector<int> r(n,n);

        stack<int> st;

        st.push(0);

        for(int i = 0; i < n; i++)
        {
            while(st.empty() == false && arr[st.top()] > arr[i] )
            {
                int index = st.top();

                st.pop();

                if(st.empty() == 1)
                {
                    r[index] = i;

                    l[index] = -1;
                }

                else
                {
                    r[index] = i;

                    l[index] = st.top();
                }
            }

            st.push(i);
        }

        while(st.empty()==false)
        {
            int index = st.top();

            st.pop();

            if(st.empty()==true)
            {
                r[index]=n;
                l[index]=-1;
            }

            else
            {
                r[index]=n;
                l[index]=st.top();
            }
        }

        // for(int i = 0; i<n;i++)
        // {
        //     cout<<l[i]<<" "<<r[i]<<endl;
        // }



        long long int ans = 0;

        for(int i = 0; i < n; i++)
        {
            long long  number = ((r[i]-i)%mod*(i-l[i])%mod)%mod;

            // number = number -1;

            // cout<<number<<endl;

            ans = (ans%mod + (number*arr[i])%mod)%mod;
        }

        return int(ans);
    }
};