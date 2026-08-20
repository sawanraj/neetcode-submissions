class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        unordered_map<char,int>freq;
        int l=0; int r=0;
        int maxlen=0;
        int maxfreq=0;

        while(r<n){
            freq[s[r]-'A']++;//Count frequency of each char
            /* calculate maxium frequency*/  
            maxfreq=max(maxfreq,freq[s[r]-'A']);
            /*Current window size - maxfreq is greater than k, shrink window */
            while((r-l+1) - maxfreq > k){
                freq[s[l]-'A']--; 
                l++;
            }
            maxlen=max(maxlen,(r-l+1));
            r++;
        }
    return maxlen;
    }
};
