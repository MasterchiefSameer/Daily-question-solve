class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int maxi = INT_MAX;
        int i=0; 
        int j=i+1;
        while(j < arr.size()){
            if(arr[j]-arr[i] < maxi) maxi = min(maxi, arr[j] - arr[i]);
            i++;
            j++;
        }
        vector<vector<int> > result;
        for(int i = 0; i < arr.size() - 1; i++){
            if(arr[i + 1] - arr[i] == maxi){
                result.push_back({arr[i], arr[i + 1]});
            }
        }
        return result;
    }
};

//2nd Solution

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int min_diff = arr[1] - arr[0];
        for(int i = 0; i < n - 1; i ++){
            min_diff = min(min_diff, arr[i + 1] - arr[i]);
        }   
        vector<vector<int> > sol;
        for(int i = 0; i < n - 1; i++){
            if(arr[i + 1] - arr[i] == min_diff){
                sol.push_back({arr[i], arr[i + 1]});
            }
        }
        return sol;
    }
};