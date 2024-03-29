//https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string s) {
        if (s.length() == 0)
            return s;
        string result;
        int pos = 0;
        int i = 0;
        /*while (i < s.length() && s[i] == ' '){
            i++;
            //pos++;
        }*/
        for (i; i < s.length(); i++){
            if (s[i] == ' '){
                if (i > pos )
                    result = s.substr(pos,i-pos) +  " " + result ;
                pos = i + 1;
            }
            else{
                //pos++;
                if (i == s.length() - 1)
                    result = s.substr(pos, s.length()-pos) + " " + result;
                
                
            }
        }
        if (result.length() != 0)
            result.erase(result.length() - 1);
        return result;
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
        string s = stringToString(line);
        
        string ret = Solution().reverseWords(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
