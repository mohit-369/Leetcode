class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int required = 0;

        int station = -1;

        int currPetrol = 0;

        for(int sta = 0; sta < gas.size(); sta++)
        {
            currPetrol = gas[sta] + currPetrol;

            if(station == -1 &&  currPetrol >= cost[sta])
            {
                station = sta;
                currPetrol -= cost[sta];
            }

            else if(currPetrol < cost[sta])
            {
                required = required + (currPetrol - cost[sta]);

                currPetrol = 0;

                station = -1;
            } 

            else
            {
                currPetrol-=cost[sta];
            }
        }

        if(currPetrol + required >= 0) return station;

        return -1;
        
    }
};

// [ 2, 1, 2, 3]
//[1, 1, 4,1]