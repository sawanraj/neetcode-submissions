class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        if(n1 ==0 || n2==0 || n1 >n2)
        return false;
        
        vector<int>freq1(26,0);//Frequency of each char in s1
        vector<int>freq2(26,0);//Frequency of each char in s2
        //Getting Frequency of each char of both string till size of s1(which should be lower)
        for(int i=0;i<n1;i++){
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }
        //If frequecny of both is same.
        if(freq1 == freq2)
          return true;
        //
        for(int i=n1;i<n2;i++){
             freq2[s2[i]-'a']++;
             freq2[s2[i-n1]-'a']--;
             if(freq1 == freq2)
                return true;
        }
    return false;

    }
};
