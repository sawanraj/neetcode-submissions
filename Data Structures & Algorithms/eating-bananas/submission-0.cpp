class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
     int l=1;
     int high=*std::max_element(piles.begin(),piles.end());
     int ans=high;

     while(l<=high){
        int mid=(l+high)/2;

        long long totalhours=0;
        for(int p:piles){
            totalhours+=(p+mid-1LL)/mid;
        }
        if(totalhours <=h){
            ans=mid;
            high=mid-1;
        }
        else{
            l=mid+1;
        }
     }
    return ans;    
    }
};
