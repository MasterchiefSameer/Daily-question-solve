class Solution {

    int getDigitRange(int num){
        int min_digit = 9;
        int max_digit = 0;

        while(num > 0){
            int digit = num % 10;
            min_digit = min(min_digit, digit);
            max_digit = max(max_digit, digit);
            num /= 10;
        }
        return max_digit - min_digit;
    }
public:
    int maxDigitRange(vector<int>& nums) {
        int n = nums.size();
        int max_range = -1;

        for(int num : nums){
            max_range = max(max_range, getDigitRange(num));
        }
        int total_sum =0;

        for(int num:nums){
            if(getDigitRange(num) == max_range){
                total_sum += num;
            }
        }
        return total_sum;
    }
};