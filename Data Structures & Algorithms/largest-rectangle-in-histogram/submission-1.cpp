class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>stk;
        int maxarea=0;

        for(int i=0;i<=n;i++){
            //Last bar in height 
            int height=(i==n)?0:heights[i];
            //While stack is not empty and height of current is lesser greater than top of height
            while(!stk.empty() && height<heights[stk.top()]){
                int h=heights[stk.top()];
                stk.pop();
                int w=stk.empty()?i:(i-stk.top()-1);
                maxarea=max(maxarea,h*w);
            }
            //Push current day index of array in stack
        stk.push(i);
        }
    return maxarea;
    }
};
