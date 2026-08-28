class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        string current_str="";
        //string length will be less than 2*n
        createparenthesis(result,current_str,0,0,n);
        return result;
    }
    static void createparenthesis(vector<string>& result, string& currentstr,int opencount,int closecount,int n){

        //String has reached length 2*n
        if(currentstr.length() == 2*n){
            result.push_back(currentstr);
            return;
        }
        //Add an open bracket if we have not used all n
        if(opencount <n){
            currentstr.push_back('(');
            createparenthesis(result,currentstr,opencount+1,closecount,n);
            currentstr.pop_back();
        }
        //Add a close bracket if it matches an unclosed open
        if(opencount >closecount){
            currentstr.push_back(')');
            createparenthesis(result,currentstr,opencount,closecount+1,n);
            currentstr.pop_back();
        }
    }
};
