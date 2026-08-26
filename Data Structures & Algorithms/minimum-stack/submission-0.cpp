class MinStack {
    stack<int>mainst;
    stack<int>minst;
public:
    MinStack() {    
    }
    void push(int val) {
       mainst.push(val);
       if(minst.empty() || val<=minst.top()){
        minst.push(val);
       } 
    }   
    void pop() {
        if(mainst.empty()){
            return;
        }
        if(mainst.top()==minst.top()){
            minst.pop();
        }
        mainst.pop();
    }
    int top() {
        if(mainst.empty()){
            throw out_of_range("stack is empty");
        }
        return mainst.top();
    }
    int getMin() {
        if(minst.empty()){
            throw out_of_range("stack is empty");
        }
        return minst.top();
    }
};
