class KthLargest {
private:
    priority_queue<int,vector<int>,greater<int>>minheap;
    int ksize;
public:
    KthLargest(int k, vector<int>& nums) {
        ksize=k;
        for(int num:nums){
            add(num);
        }
    }
    
    int add(int val) {
        minheap.push(val);

        if(minheap.size() >ksize){
            minheap.pop();
        }
    return minheap.top();
    }
};
