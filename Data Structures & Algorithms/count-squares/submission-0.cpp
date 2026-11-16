class CountSquares {
    private:
        unordered_map<int,unordered_map<int,int>>pointCount;
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        int x=point[0];
        int y=point[1];
        pointCount[x][y]++;
    }
    
    int count(vector<int> point) {
        int x1=point[0];
        int y1=point[1];

        if(!pointCount.count(x1)){
            return 0;
        }
        int totalSquares=0;
        for(auto& [x2,ycountmap]:pointCount){
            if(x2!=x1){
                int distance=x2-x1;
                auto& x1points=pointCount[x1];
                totalSquares+=ycountmap[y1]*x1points[y1+distance]*ycountmap[y1+distance];
                totalSquares+=ycountmap[y1]*x1points[y1-distance]*ycountmap[y1-distance];
            }
        }
    return totalSquares;
    }
};
