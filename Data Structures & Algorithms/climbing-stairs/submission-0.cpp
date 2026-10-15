class Solution {
public:
    int climbStairs(int n) {
        //Base case
        if(n<=2){
            return n;
        }
        int prev2=1;//Way to reach step 1
        int prev1=2; //Way to reach step 2
        int current=0;
        //Iteratively calculate ways for subsequent step
        for(int i=3;i<=n;i++){
            current=prev1+prev2;
            prev2=prev1; //Move prev2 one step forward
            prev1=current; //Move prev1 one step forward
        }
    return current;
    }
};
