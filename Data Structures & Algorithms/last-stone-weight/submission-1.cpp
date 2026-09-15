class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxheap(stones.begin(),stones.end()); //Little more optimize
        /*for(int stone:stones){
            maxheap.push(stone);
        }*/
        while(maxheap.size() >1){
            int element1=maxheap.top();
            maxheap.pop();
            int element2=maxheap.top();
            maxheap.pop();

            if(element1 == element2)
            continue;
            else
            maxheap.push(element1-element2);
        }

    return maxheap.empty()?0:maxheap.top();
    }
};
