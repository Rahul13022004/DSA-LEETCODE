class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = 1e9 + 7;
        int n = arr.size();
        vector<int> ple(n), nle(n); // previous less, next less
        stack<int> s;

        // Find PLE (Previous Less Element)
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            ple[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        // Clear stack for reuse
        while (!s.empty()) s.pop();

        // Find NLE (Next Less Element)
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            nle[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        // Compute the result
        long res = 0;
        for (int i = 0; i < n; ++i) {
            long left = i - ple[i];
            long right = nle[i] - i;
            res = (res + arr[i] * left % MOD * right % MOD) % MOD;
        }

        return (int)res;
    }
};
