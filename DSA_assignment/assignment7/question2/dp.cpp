// T(O(n^2))
#include <bits/stdc++.h>
using namespace std;
struct Job {
    char id;
    int deadline, profit;
};

bool comparison(Job a, Job b) {
    return (a.deadline < b.deadline);
}

int solve(vector<Job>& jobs, int n) {
    sort(jobs.begin(), jobs.end(), comparison);
    int maxDeadline = jobs[n-1].deadline;
    vector<int> dp(maxDeadline+1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (dp[j] < dp[j-1] + jobs[i].profit) {
                dp[j] = dp[j-1] + jobs[i].profit;
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<Job> j = {{'a', 4, 20}, {'b', 1, 10}, {'c', 1, 40}, {'d', 1, 30}};
    int n = j.size();
    cout << "Maximum profit is " << solve(j, n) << endl;
    return 0;
}

// T.C. - O(n^2)