class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        unordered_map<char,int>mp;// to store the last index of each char
        for(int i=0;i<s.size();i++){
            mp[s[i]]=i;
        }
        int end=0;
        int start=0;
        for(int i=0;i<s.size();i++){
            end=max(end,mp[s[i]]);
            if(i==end){
                ans.push_back(i-start+1);
                start=i+1;
            }
        }
    return ans;
    }
};
