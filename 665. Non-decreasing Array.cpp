//https://leetcode.com/problems/non-decreasing-array/

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool fl = 0;
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] < nums[i - 1]){
                if (fl)
                    return 0;
                else {
                    fl = (i == 1 || nums[i] >= nums[i - 2] || i == nums.size() - 1 || nums[i + 1] >= nums[i - 1]);
                    if (!fl)
                        return false;
                }
            }
        return true;
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
        vector<int> nums = stringToIntegerVector(line);
        
        bool ret = Solution().checkPossibility(nums);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
