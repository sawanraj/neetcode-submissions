class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n=arr.size();
        int sum=0;
        int count=0;
        int targetsum=threshold*k;
        for(int i=0;i<k;i++){
            sum+=arr[i];
        } 
        
        if(sum >=targetsum){
            count++;
        }
        for(int j=k;j<n;j++){
            sum+=arr[j]-arr[j-k];
            if(sum >=targetsum){
                count++;
            }
        }
    return count;
    }
};