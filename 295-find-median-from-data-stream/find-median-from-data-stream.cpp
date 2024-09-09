class MedianFinder {
priority_queue<int,vector<int>> leftPart;
priority_queue<int,vector<int>,greater<int>> rightPart;
int size1,size2;

public:
    MedianFinder() {

        size1=0;
        size2=0;
        
    }
    
    void addNum(int num) {

        if(size1 && leftPart.top()>num)
        {
            leftPart.push(num);

            size1++;
        }

        else if(size2 && rightPart.top()<num)
        {
            rightPart.push(num);

            size2++;
        }

        else
        {
            leftPart.push(num);

            size1++;
        }

        if((size1-size2) > 1)
        {
            rightPart.push(leftPart.top());

            leftPart.pop();

            size1--;
            size2++;
        }

        else if((size2-size1)>=1)
        {
            leftPart.push(rightPart.top());

            rightPart.pop();

            size2--;
            size1++;
        }
        
        
    }
    
    double findMedian() {

        if((size1>size2))
        {
            
            return leftPart.top();
            


        }

        
        double median = double(leftPart.top() + rightPart.top());

            

        return median/2;
        


        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */