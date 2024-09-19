class Solution {
vector<int> solve(string s, unordered_map<string,vector<int>> &mpp)
{
    // Check if the result for this expression is already computed (Memoization)
    if(mpp.find(s) != mpp.end()) {
        return mpp[s];
    }

    vector<int> result;

    // Base case: if the string is a number, return the number as the result
    bool isNumber = true;
    for(char c : s) {
        if(!isdigit(c)) {
            isNumber = false;
            break;
        }
    }

    if(isNumber) {
        result.push_back(stoi(s));
        mpp[s] = result;
        return result;
    }

    for(int cur = 0; cur < s.size(); cur++)
    {
        char op = s[cur];

        if(op == '+' || op == '-' || op == '*' || op == '/')
        {
            vector<int> leftPart = solve(s.substr(0,cur), mpp);
            vector<int> rightPart = solve(s.substr(cur+1), mpp);

            for(auto &leftVal : leftPart)
            {
                for(auto &rightVal : rightPart)
                {
                    if(op == '+') {
                        result.push_back(leftVal + rightVal);
                    }
                    else if(op == '-') {
                        result.push_back(leftVal - rightVal);
                    }
                    else if(op == '*') {
                        result.push_back(leftVal * rightVal);
                    }
                    // If division is required, uncomment below block
                    /*
                    else if(op == '/') {
                        if(rightVal != 0) { // Handle division by zero
                            result.push_back(leftVal / rightVal);
                        }
                    }
                    */
                }
            }
        }
    }

    // Store the computed result in the map for memoization
    mpp[s] = result;
    return result;
}
    
public:
    vector<int> diffWaysToCompute(string expression) {
        unordered_map<string,vector<int>> mpp;
        return solve(expression, mpp);
    }
};
