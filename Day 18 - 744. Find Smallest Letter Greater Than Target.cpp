class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i=upper_bound(letters.begin(), letters.end(), target)-letters.begin();
        return (i==letters.size())?letters[0]:letters[i];
    }
};

// 2nd Solution
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(int i = 0; i<letters.size(); i++){
            if(letters[i]>target) return letters[i];
        }
        return letters[0];
    }
};

//3nd Solution
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res = letters[0];
        bool flag = false;

        for (char ch : letters) {
            if (!flag) {
                if (ch > target) {
                    res = ch;
                    flag = !flag;
                }
            } else {
                if (ch > target && ch < res) res = ch;
            }
        }

        return res;
    }
};

