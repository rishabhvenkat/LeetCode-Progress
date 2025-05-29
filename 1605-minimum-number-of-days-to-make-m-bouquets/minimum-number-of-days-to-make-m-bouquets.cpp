class Solution {
public:
    bool possible(vector<int> &arr, int day, int b, int r) {
        int cnt = 0;
        int noOfB = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] <= day) cnt++;
            else {
                noOfB += (cnt / r);
                cnt = 0;
            }
        }
        noOfB += (cnt / r);
        return noOfB >= b;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1LL * k * 1LL;
        if(val > bloomDay.size()) return -1;
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i = 0; i < bloomDay.size(); i++) {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }
        int low = mini, high = maxi;
        while(low <= high) {
            int mid = (high + low) / 2;
            if(possible(bloomDay, mid, m, k)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};