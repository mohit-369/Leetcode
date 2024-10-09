class MyCalendarTwo {
map<int,int> mpp;
public:
    MyCalendarTwo() {

        
    }
    
    bool book(int start, int end) {

        mpp[start] += 1;

        mpp[end] -= 1;

        int count = 0;

        int flag = 0;

        for(auto &it:mpp)
        {
            count += it.second;

            if(count > 2)
            {
                mpp[start] -= 1;
                mpp[end] += 1;
                return 0;
            }
        }

        return 1;


        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */