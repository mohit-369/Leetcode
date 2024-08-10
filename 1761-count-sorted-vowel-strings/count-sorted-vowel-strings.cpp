class Solution {
int solve(int index, int charindex, int size)
{
    if(index == size)
    {
        return 1;
    }

    int ans=0;

    if(charindex==-1)
    {
        for(int i = 0;i<5;i++)
        {
            ans+=solve(index+1,i,size);
        }
    }

    else
    {
        for(int i = charindex;i<5;i++)
        {
            ans+=solve(index+1,i,size);
        }
    }

    return ans;
}
public:
    int countVowelStrings(int n) {

        return solve(0,-1,n);
        
    }
};