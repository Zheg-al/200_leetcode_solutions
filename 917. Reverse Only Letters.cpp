//https://leetcode.com/problems/reverse-only-letters/

class Solution {
public:
    string reverseOnlyLetters(string S) {
        int l = 0, r = S.length() - 1;
        while (l < r){
            while (l < r && !((S[l] >= 'a' && S[l] <= 'z') || (S[l] >= 'A' && S[l] <= 'Z')))
                l++;
            while (l < r && !((S[r] >= 'a' && S[r] <= 'z') || (S[r] >= 'A' && S[r] <= 'Z')))
                r--;
            swap (S[l++],S[r--]);
        }
        return S;
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

int main() {
    string line;
    while (getline(cin, line)) {
        string S = stringToString(line);
        
        string ret = Solution().reverseOnlyLetters(S);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
