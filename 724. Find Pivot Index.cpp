//https://leetcode.com/problems/find-pivot-index/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector <int> sum(nums.size() + 1);
        sum [0] = 0;
        for (int i = 0; i < nums.size(); i++){
            sum [i + 1] = sum [i] + nums [i];
        }
        sum.push_back (0);
        int n = sum.size() - 1;
        for (int i = 1; i < sum.size() - 1; i++)
            if (sum [i - 1] == sum [n - 1] - sum [i])
                return i - 1;
        return -1;
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().pivotIndex(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
