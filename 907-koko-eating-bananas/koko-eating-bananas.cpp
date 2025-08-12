class Solution {
bool canEat(int &speed, vector<int> &piles, int &h)
{
    int time = 0;

    for(int i = 0; i < piles.size(); i++)
    {
        time += piles[i] / speed + (piles[i] % speed != 0);
    }

    return time<=h;
}
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;

        int high = *max_element(piles.begin(),piles.end());

        while(high - low > 1)
        {
            int mid = (high-low)/2 + low;

            if(canEat(mid,piles,h))
            {
                high = mid;
            }

            else
            {
                low = mid + 1;
            }
        }

        if(canEat(low,piles,h)) return low;

        else if(canEat(high,piles,h)) return high;

        return -1;



        
        
    }
};