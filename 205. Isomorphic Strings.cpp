//https://leetcode.com/problems/isomorphic-strings/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return 0;
        map <char, char> StoT, TtoS;
        for (int i = 0; i < s.length(); i++){
            if (StoT.count (s[i])){
                if (StoT[s[i]] != t[i])
                    return 0;
            }
            else
                StoT[s[i]] = t[i];
            if (TtoS.count (t[i])){
                if (TtoS[t[i]] != s[i])
                    return 0;
            }
            else
                TtoS[t[i]] = s[i];
        }
        set <char> checkS, checkT;
        for (auto i : StoT)
            checkS.insert(i.second);
        if (checkS.size() != StoT.size())
            return 0;
        for (auto i : TtoS)
            checkT.insert(i.second);
        if (checkT.size() != TtoS.size())
            return 0;
        return 1;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string t = stringToString(line);
        
        bool ret = Solution().isIsomorphic(s, t);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
