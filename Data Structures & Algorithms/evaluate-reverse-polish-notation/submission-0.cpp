class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long>st;

        for(const string& token:tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/" ){
                long long op2=st.top();
                st.pop();
                long long op1=st.top();
                st.pop();

                if(token == "+"){
                    st.push(op1+op2);
                }
                if(token == "-"){
                    st.push(op1-op2);
                }
                if(token == "*"){
                    st.push(op1*op2);
                }if(token == "/"){
                    st.push(op1/op2);
                }
            }
            else{
                    st.push(stoll(token));
                }
        }
    return st.top();
    }
};
