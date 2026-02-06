class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        int length = 1;
        int maxNum = nums[0];
        int minNum = nums[0];
        int i = 0;
        int j = 0;

        while(j<n){
            minNum = nums[i];
            maxNum = nums[j];

            while(i < j && maxNum > (long long)k*minNum){
                i++;
                minNum = nums[i];
            }
            length = max(length, j-i+1);
            j++;
        }
        return n-length; //delete
    }
};


//2nd solution
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        int maxLen = 0;
        
        for (int j = 0; j < n; j++) {
            // Cast to long long to prevent overflow
            while ((long long)nums[j] > (long long)nums[i] * k) {
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
        }
        
        return n - maxLen;
    }
};