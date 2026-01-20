class Solution {
public:
//Brute Force Approach 
//T.c = O(n*max(nums[i]))
// S.C = O(1)
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            bool found = false;
            for(int x=0; x<nums[i]; x++){
                if((x | (x+1)) == nums[i]){
               result.push_back(x);
               found = true;
               break;
                }
            }
            if(found == false) result.push_back(-1);
        }
        return result;
    }
};


