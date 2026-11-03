class Solution {
public:
    string foreignDictionary(vector<string>& words) {
    //build edge of graph by finding all char and make relation of these cha
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        // Step 1: Find all unique characters
        for(string word:words){
            for(char c:word){
                indegree[c]=0;
            }
        }
         // Step 2: Build graph edges
        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];
            int len = min(word1.size(), word2.size());
            bool foundDifference = false;
            for (int j = 0; j < len; j++) {
                if (word1[j] != word2[j]) {
                    char u = word1[j];
                    char v = word2[j];
                    if(!adj[u].count(v)){
                        adj[u].insert(v);
                        indegree[v]++;
                    }
                    foundDifference = true;
                    break;
                }
            }

        if (!foundDifference && word1.size() > word2.size()) {
            return "";
        }
    }
    //now putting inside queue for topology sort
    queue<char>q;
    // Step 3: Put all indegree 0 nodes into queue
    for(auto const &[ch,degree]:indegree ){
        if(degree==0)
            q.push(ch);
    }
    // Step 4: Kahn's BFS
    string result="";
    while(!q.empty()){
        char curr=q.front();
        q.pop();
        result+=curr;
        for(char ne:adj[curr]){
            indegree[ne]--;
            if(indegree[ne]==0){
                q.push(ne);
            }
        }
    }
    // Step 5: Detect cycle
    if(result.size() < indegree.size())
    return "";
    
return result;
}
};
