// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>>result;
        if(pairs.empty())
        return result;

        for(int i=0;i<pairs.size();i++){
            Pair key=pairs[i];
            int j=i-1;
            while(j>=0 && pairs[j].key >key.key){
                    pairs[j+1]=pairs[j];
                    j--;
            }
            pairs[j+1]=key;
            result.push_back(pairs);
        }
    return result;
    }
};
