class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();

        int totalcount=0;

        for(int i=0;i<n;i++){
            totalcount+=explorefrommiddle(s,i,i);
            totalcount+=explorefrommiddle(s,i,i+1);
        }
    return totalcount;
    }
    int explorefrommiddle(string &s, int left, int right){
        int count=0;
        while(left>=0 && right<s.length() && s[left]==s[right]){
            left--;
            count++;
            right++;
        }
    return count;
    }
};
