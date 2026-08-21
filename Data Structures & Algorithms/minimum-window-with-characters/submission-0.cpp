class Solution {
public:
    string minWindow(string s, string t) {
        int ns=s.size();
        int nt=t.size();
        if(ns==0|| nt==0|| ns<nt)
            return"";
        /*Target frequency for string t*/
        vector<int>target_freq(128,0);
        /*count unique char*/
        int unique_count=0;
        /*Store frequency for each char and unique count*/
        for(char c:t){
            if(target_freq[c]==0){
                unique_count++;
            }
            target_freq[c]++;   
        }
        /*Window frequecy for string s big one*/
        vector<int>window_freq(128,0);
        int formed=0;
        int l=0;
        int minlen=INT_MAX;
        int start_index=0;

        /*Start the window matching from right*/
        for(int r=0;r<ns;r++){
            char c=s[r];
            window_freq[c]++;
            /*if current char count matched the target frequency, increase formed*/
            if(target_freq[c]>0 && window_freq[c] == target_freq[c]){
                formed++;
            }
            /*Try to shrink window from the left while it is valid*/
            while(l<=r && formed == unique_count){
                /*Track the smallest window*/
                if(r-l+1 <minlen){
                    minlen=r-l+1;
                    start_index=l;
                }
                //Remove s[l] from the current window
                char left_char=s[l];
                window_freq[left_char]--;

                if(target_freq[left_char] >0 && window_freq[left_char] <target_freq[left_char]){
                    formed--;
                }
                l++;//shrink window
            }
        }
        return minlen==INT_MAX?"":s.substr(start_index,minlen);
    }
};
