class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())
        return false;

        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return dfs(0,0,s1,s2,s3,dp);
    }
    bool dfs(int i,int j,string &s1,string &s2, string &s3,vector<vector<int>> &dp){
        if(i==s1.size() && j==s2.size())
            return true;
        int k=i+j;
        if(dp[i][j]!=-1)
            return dp[i][j];

        bool froms1=false;
        bool froms2=false;

        if(i<s1.size() && s1[i]==s3[k]){
            froms1=dfs(i+1,j,s1,s2,s3,dp);
        }
         if(j<s2.size() && s2[j]==s3[k]){
            froms2=dfs(i,j+1,s1,s2,s3,dp);
        }
        dp[i][j]=froms1||froms2;

        return dp[i][j];
    }
};
