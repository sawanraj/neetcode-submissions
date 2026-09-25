class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        vector<string>current;
        backtrack(s,0,current,result);

        return result;
    }
    void backtrack(string &s,int idx, vector<string>&current,vector<vector<string>>&result){
         if(idx == s.length()){
            result.push_back(current);
            return;
         }
         for(int i=idx;i<s.length();i++){
            string sub=s.substr(idx,i-idx+1);
            if(ispalindrome(sub)){
                current.push_back(sub);
                backtrack(s,i+1,current,result);
                current.pop_back();
            }      
         }
    }
    bool ispalindrome(string &s){
        int start=0;
        int end=s.length()-1;
        while(start<end){
            if(s[start]!=s[end])
            return false;
            start++;
            end--;
        }
    return true;
    }
};
