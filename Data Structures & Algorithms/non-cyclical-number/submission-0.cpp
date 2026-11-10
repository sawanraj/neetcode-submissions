class Solution {
public:
    bool isHappy(int n) {
       int slow=n;
       int fast=n;
       do{
        slow=digitsqrsum(slow);
        fast=digitsqrsum(digitsqrsum(fast));
       } while(slow!=fast);
       return slow==1;
    }
    int digitsqrsum(int n){
        int sum=0;
        while(n>0){
            int d=n%10;
            sum+=d*d;
            n/=10;
        }
        return sum;
    }
};
