#include <bits/stdc++.h>
using namespace std;
#include <fstream>
struct Job
{
    char id;
    int dead;
    int profit;
};

struct jobProfit
{
    bool operator()(Job const &a, Job const &b)
    {
        return (a.profit < b.profit);
    }
};

void JobScheduling(Job arr[], int n)
{
    vector<Job> result;
    sort(arr, arr + n,
         [](Job a, Job b)
         { return a.dead < b.dead; });

    priority_queue<Job, vector<Job>, jobProfit> pq;

    for (int i = n - 1; i >= 0; i--)
    {
        int slot_available;

        if (i == 0)
        {
            slot_available = arr[i].dead;
        }
        else
        {
            slot_available = arr[i].dead - arr[i - 1].dead;
        }

        pq.push(arr[i]);

        while (slot_available > 0 && pq.size() > 0)
        {

            Job job = pq.top();
            pq.pop();
            slot_available--;

            result.push_back(job);
        }
    }

    sort(result.begin(), result.end(),
         [&](Job a, Job b)
         { return a.dead < b.dead; });

    for (int i = 0; i < result.size(); i++)
        cout << result[i].id << ' ';
    cout << endl;
}

int main()
{
    ifstream inputFile("input.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error opening file." <<endl;
        return 1; // Exit with an error code
    }
    int n;
    inputFile>>n;

    Job arr[n];
    for(int i=0;i<n;i++){
        Job v;
        inputFile>>v.id>>v.dead>>v.profit;
        arr[i]=v;
        // cout<<v.id<<endl;

        
    }
    inputFile.close();
    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." <<endl;
        return 1; // Exit with an error code
    }
    JobScheduling(arr, n);
    // int n = sizeof(arr) / sizeof(arr[0]);
    
    return 0;
}