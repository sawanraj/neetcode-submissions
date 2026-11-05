class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(groupSize >n || n%groupSize!=0)
            return false;
        unordered_map<int,int>mp;
        sort(hand.begin(),hand.end());
        for(int h:hand){
            mp[h]++;
        }
        for(int h:hand){
            if(mp[h]==0)
                continue;
            for(int j=0;j<groupSize;j++){
                int needed=h+j;
                if(mp[needed]==0){
                    return false;
                }
                mp[needed]--;
            }
        }   
    return true;
    }
};
