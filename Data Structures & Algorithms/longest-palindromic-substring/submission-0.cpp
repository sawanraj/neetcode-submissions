class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(s.empty())
            return "";
        int start=0;
        int maxlen=0;

        for(int i=0;i<n;i++){
            int len1=helper(s,i,i);
            int len2=helper(s,i,i+1);

            int len=max(len1,len2);

            if(len>maxlen)
            {
                maxlen=len;
                start=i-(len-1)/2;
            }
        }
    return s.substr(start,maxlen);
    }
    int helper(string &s, int left, int right){
        while(left>=0 && right<s.length() && s[left]==s[right]){
            left--;
            right++;
        }
    return right-left-1;
    }
};
