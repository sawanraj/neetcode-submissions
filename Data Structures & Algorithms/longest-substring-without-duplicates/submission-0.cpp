class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     int n=s.size();
     if(n==0)
     return 0;
     unordered_map<char,int>mp;/*to store charactor and its frequency */
     int l=0;/*Left*/
     int r=0;/*Right*/
     int maxlen=0;

     while(r<n){
        char c=s[r];/*Each char of s*/
        /*if c was seen and its previous index is inside out active window[l,r]*/
        if(mp.find(c) != mp.end() && mp[c] >=l){
            l=mp[c]+1;/* increasing l */
        }
            mp[c]=r;/*Update the latest index of c*/
            maxlen=max(maxlen,r-l+1); //Update the lenght
            r++;
    }
    return maxlen;   
    }
};
