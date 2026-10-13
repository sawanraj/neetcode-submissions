class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>wordset(wordList.begin(),wordList.end());

        //if the target word is not even 
        if(wordset.find(endWord) ==wordset.end())
            return 0;

        queue<pair<string,int>>q;
        q.push({beginWord,1});

        while(!q.empty()){
            auto [currentword,steps]=q.front();
            q.pop();
            if(currentword == endWord)
                return steps;

            for(int i=0;i<currentword.length();i++){
                char orgchar=currentword[i];

                for(char c='a';c<='z';c++){
                    if(c == orgchar)//skip the replacing with same char
                        continue;
                    
                    currentword[i]=c;

                    if(wordset.find(currentword)!=wordset.end()){
                        q.push({currentword,steps+1});
                        wordset.erase(currentword);
                    }
                }
                currentword[i]=orgchar;//Restore the character for the next postion
            }
        }
        return 0;
    }
};
