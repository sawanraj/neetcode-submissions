class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();//Size of vector
        vector<int>result(n);
        vector<int>left(n); //sufix
        vector<int>right(n); //prefix
        
        /*Step1 build sufix*/
        left[0]=1;
        for(int i=1;i<n;i++){
            left[i]=left[i-1]*nums[i-1];
        }
         /*Step2 build Prefix*/
        right[n-1]=1;
        for(int i=n-2;i>=0;i--){
            right[i]=right[i+1]*nums[i+1];
        }
        /*Step3 Build complete Sufix*Prefix */
        for(int i=0;i<n;i++){
            result[i]=left[i]*right[i];
        }
    return result;
    }
};
