class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);

        for(auto task:tasks){
            freq[task-'A']++;
        }
        sort(freq.begin(),freq.end());
        int max_freq=freq[25];
        int idleslot=(max_freq-1)*n;
        for(int i=24;i>=0 && freq[i]>0;i--){
            idleslot-=min(max_freq-1,freq[i]);
        }
        idleslot=max(0,idleslot);

        int result=tasks.size()+idleslot;

        return result;
    }
};
