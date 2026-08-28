class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int>stk;
        vector<int>result(n,0);

        for(int i=0;i<n;i++){
            //While stack is not empty and temp of current is waremer than last
            while(!stk.empty() && temperatures[i]>temperatures[stk.top()]){
                int previndx=stk.top();
                stk.pop();
                result[previndx]=i-previndx;//calculate day difference by using index differences current - prev
            }
            //Push current day index of array in stack
        stk.push(i);
        }
    return result;
    }
};
