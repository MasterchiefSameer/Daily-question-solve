class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                result[i] = 0;
            } else {
                int k = (i + nums[i]) % n;
                if (k < 0)
                   k = (k + n) % n  ;
                result[i] = nums[k];
            }
        }
        return result;
    }
};
