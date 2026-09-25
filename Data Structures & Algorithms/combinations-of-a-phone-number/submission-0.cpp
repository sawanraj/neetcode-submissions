class Solution {
public:
    const vector<string> keypad={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string>result;
        if(digits.empty())
        return result;

        string current="";
        backtrack(digits,result,current,0);
        return result;
    }
    void backtrack(string &digits,vector<string>&result,string &current, int idx){
        if(idx==digits.length())
        {
            result.push_back(current);
            return;
        }
        int current_digit=digits[idx]-'0';
        if(current_digit < 2 || current_digit >9){
            backtrack(digits,result,current,idx+1);
        }
        for(int i=0;i<keypad[current_digit].size();i++){
            current.push_back(keypad[current_digit][i]);//add letter to current string
            backtrack(digits,result,current,idx+1); //recurse to the next digit
            current.pop_back();
        }
    }
};
