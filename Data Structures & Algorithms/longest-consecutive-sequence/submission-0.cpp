class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(!n)
        return 0;

        int maxlen=0;
        /*Step1 remove duplicate by using set*/
        unordered_set<int>myset(nums.begin(),nums.end());
        /*step2 Check each number presence*/
        for(int num:myset){
            /*Step3 find the number first ouccerence */
            if(myset.find(num-1) == myset.end()){
                int curnum=num;
                int curlen=1;
             /*Step4 count consecutive number */
            while(myset.find(curnum+1)!= myset.end()){
                curnum++;
                curlen++;
            }
            /*Step5 maxlen of consecutive sequence  */
            maxlen=max(maxlen,curlen);
            }
        }
        return maxlen;
    }
};
