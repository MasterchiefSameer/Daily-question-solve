class Solution {
    public:
    int minimumDeletions(string s) {
        int res = 0;
        int b_count = 0;
        
        // Iterate by reference to avoid unnecessary copying
        for (const char& c : s) {
            if (c == 'b') {
                b_count++;
            } else { 
                // Encountered 'a'
                // If there are preceding 'b's, we have a conflict ("ba")
                if (b_count > 0) {
                    res++;      // Delete one character to resolve conflict
                    b_count--;  // Decrease count of unmatched 'b's
                }
            }
        }
        
        return res;
    }
};