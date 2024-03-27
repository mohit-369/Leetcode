class Solution {
public:
    int takeCharacters(string s, int k) {

        int ac=0,bc=0,cc=0;

        for(auto it:s)
        {
            if(it=='a') ac++;

            if(it=='b') bc++;

            if(it=='c') cc++;
        }

        ac-=k;
        bc-=k;
        cc-=k;

        if(ac<0 || bc<0 || cc<0) return -1;

        int i=0;
        int j=0;

        int n=s.size();

        int a=0,b=0,c=0;

        int size=0;

        while(j<n)
        {
            if(s[j]=='a') a++;

            if(s[j]=='b') b++;

            if(s[j]=='c') c++;

            while((a>ac || b>bc || c>cc) && i<=j)
            {
                if(s[i]=='a') a--;

                if(s[i]=='b') b--;

                if(s[i]=='c') c--;

                i++;
            }

            size=max(size,j-i+1);
            j++;


        }

        return n-size;
        
    }
};