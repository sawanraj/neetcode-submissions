class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int right=digits.size()-1;right>=0;right--){
            if(digits[right] <9){
               digits[right]++;
               return digits;
            }
            digits[right]=0;
        }
        digits.insert(digits.begin(),1);
    return digits;
    }
};
