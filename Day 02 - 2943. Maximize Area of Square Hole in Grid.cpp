class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        sort(begin(hBars), end(hBars));
        sort(begin(vBars), end(vBars));

        int maxConsecutiveHbars = 1;
        int maxConsecutiveVbars = 1;

        int currConsecutiveHbars = 1;
        for(int i = 1; i < hBars.size(); i++){
            if(hBars[i] - hBars[i-1] == 1) currConsecutiveHbars++;
            else currConsecutiveHbars = 1;

            maxConsecutiveHbars = max(maxConsecutiveHbars, currConsecutiveHbars);
        }

         int currConsecutiveVbars = 1;
        for(int i = 1; i < vBars.size(); i++){
            if(vBars[i] - vBars[i-1] == 1) currConsecutiveVbars++;
            else currConsecutiveVbars = 1;

            maxConsecutiveVbars = max(maxConsecutiveVbars, currConsecutiveVbars);
        }

        int side = min(maxConsecutiveVbars,maxConsecutiveHbars) + 1;
        return side * side;
    }
};