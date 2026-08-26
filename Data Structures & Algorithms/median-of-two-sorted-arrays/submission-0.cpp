class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();

        if(n1>n2){
            return findMedianSortedArrays(nums2,nums1);
        }
        int l=0;
        int h=n1;
        int totalhalf=(n1+n2+1)/2;
        while(l<=h){
            int i=l+(h-l)/2;
            int j=totalhalf-i;

            int maxl1=(i==0)?INT_MIN:nums1[i-1];
            int minr1=(i==n1)?INT_MAX:nums1[i];
            
            int maxl2=(j==0)?INT_MIN:nums2[j-1];
            int minr2=(j==n2)?INT_MAX:nums2[j];
            
            if(maxl1 <= minr2 && maxl2<=minr1){
                if((n1+n2) %2 ==1)
                    return max(maxl1,maxl2);
                else
                    return (std::max(maxl1,maxl2) + std::min(minr1,minr2))/2.0;
            }
            else if(maxl1>minr2)
            {
                h=i-1;
            }
            else{
                l=i+1;
            }
        }
    return 0.0;
    }
};
