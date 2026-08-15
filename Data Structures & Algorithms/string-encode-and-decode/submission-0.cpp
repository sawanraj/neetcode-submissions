class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string="";
        for(string& str:strs){
            encoded_string=encoded_string+to_string(str.size())+'#'+str;
        }

        return encoded_string;
    }

    vector<string> decode(string s) {
       vector<string> decoded_result;
        size_t i=0;
        while(i<s.size()){
            size_t delimiter_pos=s.find('#',i);
            int len=stoi(s.substr(i,delimiter_pos-i));
            string str=s.substr(delimiter_pos+1,len);
            decoded_result.push_back(str);
            i=delimiter_pos+1+len;
        }
        return decoded_result;
    }
};
