class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int leftmax=0;
        int rightmax=0;
        int trappedwater=0;

        while(l<r){
            if(height[l]<height[r]){
                if(height[l]>=leftmax)
                    leftmax=height[l];
                else
                    trappedwater+=leftmax-height[l];
                l++;
            }
            else{
                if(height[r]>=rightmax)
                    rightmax=height[r];
                else
                    trappedwater+=rightmax-height[r];
                r--;

            }
        }
    return trappedwater;
    }
};
