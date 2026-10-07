class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adjency(numCourses);
        for(const auto& pair:prerequisites){
            int course=pair[0];
            int prereq=pair[1];
            adjency[prereq].push_back(course);
        }
        vector<int>state(numCourses,0);

        for(int i=0;i<numCourses;i++){
            if(state[i]==0){
                if(hascycle(i,adjency,state))
                return false;
            }
        }
    return true;
    }
    bool hascycle(int course, const vector<vector<int>>& adj,vector<int>&state){
        if(state[course]==1)
            return true;
        if(state[course]==2)
            return false;

        state[course]=1;

        for(int nextcourse:adj[course]){
            if(hascycle(nextcourse,adj,state))
                return true;
        }
    state[course]=2;
    return false;
    }
    
};
