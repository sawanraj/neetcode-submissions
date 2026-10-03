class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        int max_so_far=-1;
        
        for(int i=n-1;i>=0;i--){
            int current_val=arr[i];
            arr[i]=max_so_far;

            if(current_val >max_so_far){
                max_so_far=current_val;
            }
        }
    return arr;
    }
};