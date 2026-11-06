class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int>result(3,0);

        for(auto &t:triplets){
            if(t[0]>target[0] || t[1]>target[1] || t[2]>target[2])
               {continue;} 

            //find the max from each triplate
            result[0]=max(result[0],t[0]);
            result[1]=max(result[1],t[1]);
            result[2]=max(result[2],t[2]);
        }
    return result==target;
    }
};
