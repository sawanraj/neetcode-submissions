class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string="";
        for(string& str:strs){
            /*encoded by strlen anddemiliter #*/
            encoded_string=encoded_string+to_string(str.size())+'#'+str;
        }

        return encoded_string;
    }

    vector<string> decode(string s) {
       vector<string> decoded_result;
        size_t i=0;
        while(i<s.size()){
            /*Finding delimiter position*/
            size_t delimiter_pos=s.find('#',i);
            /*finding the length of substirng string from i to delimiter position minus 1*/
            int len=stoi(s.substr(i,delimiter_pos-i));
            /*find the substring as per start(delimiter_pos+1 and end(lenght of substring))*/
            string str=s.substr(delimiter_pos+1,len);
            /*storing in vector of string*/
            decoded_result.push_back(str);
            /*Increasing i by sting len+delimiter position*/
            i=delimiter_pos+1+len;
        }
        return decoded_result;
    }
};
