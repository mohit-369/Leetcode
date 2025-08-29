class Solution {
public:
    long long flowerGame(int n, int m) {

        long long int ans = 1;

        ans = ((ans*1ll*((n+1)/2))*(m/2))*1ll;
        ans += (1ll*(n/2))*(((m+1)/2)*1ll);

        return ans;
        
    }
};