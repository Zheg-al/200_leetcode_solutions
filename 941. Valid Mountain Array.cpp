//https://leetcode.com/problems/valid-mountain-array/

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3 || A[0] >= A[1] || A[A.size() - 2] <= A[A.size() - 1])
            return false;
        int i = 1;
        while (i < (int) A.size() && A[i - 1] < A[i])
            i++;
        while (i < (int)A.size() && A[i - 1] > A[i])
            i++;
        return (i == (int)A.size());
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> A = stringToIntegerVector(line);
        
        bool ret = Solution().validMountainArray(A);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
