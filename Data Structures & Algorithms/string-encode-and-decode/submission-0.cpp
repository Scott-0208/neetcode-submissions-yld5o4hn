class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for (const string& s : strs) {
            result+=to_string(s.size());
            result+="#";
            result+=s;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while (i < s.size()) {
            // 1. Find the '#' using a second pointer 'j'
            int j = i;
            while (s[j] != '#'){
                j++;
            }
            // 2. Extract the length number
            int word_len = stoi(s.substr(i, j - i)); 
            // start from i, backward how many
            result.push_back(s.substr(j + 1, word_len));
            i = j + word_len + 1;
        }
        return result;
    }
};
