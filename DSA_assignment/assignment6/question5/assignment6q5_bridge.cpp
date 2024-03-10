#include <iostream>
using namespace std;
#include <fstream>
#include <map>
#include <vector>
#include <queue>
// int myArray[10000000];
#define ll int
void dfs(vector<ll> &visited, map<ll, vector<ll>> &m, ll node, vector<vector<ll>> &bridge,
 vector<ll> &time, vector<ll> &low, ll &count, vector<ll> &parent)
{
    time[node] = low[node] = count;
    count++;
    visited[node] = 1;

    for (auto n : m[node])
    {
        if (n == parent[node])
            continue;
        if (visited[n] == 0)
        {
            parent[n] = node;
            dfs(visited, m, n, bridge, time, low, count, parent);
            low[node] = min(low[node], low[n]);
            if (time[node] < low[n])
            {
                bridge.push_back({node, n});
            }
        }
        else
        {
            low[node] = min(low[node], low[n]);
        }
    }
}

int main()
{
    // Open the text file for reading
    ifstream inputFile("input.txt");

    // Check if the file is open
    if (!inputFile.is_open())
    {
        cerr << "Error opening file." << endl;
        return 1; // Exit with an error code
    }

    int v, e;
    inputFile >> v >> e;
    map<int, vector<int>> m;

    vector<int> parent(v + 1, 0), low(v + 1, 0), time(v + 1, 0), visited(v + 1, 0);

    queue<int> q;
    for (int i = 0; i < e; i++)
    {
        ll u, v;
        inputFile >> u >> v;

        m[u].push_back(v);
        m[v].push_back(u);
    }
    vector<vector<int>> bridge;
    ll count = 0;
    dfs(visited, m, 1, bridge, time, low, count, parent);

    // Close the file

    // Display the contents of the array
    cout << "Data read from file and stored in array:" << endl;

    inputFile.close();

    ofstream outputFile("output.txt");

    // Check if the file is open
    if (!outputFile.is_open())
    {
        cerr << "Error opening output file." << endl;
        return 1; // Exit with an error code
    }

    // Write the contents of the array to the output file
    for (int i = size(bridge) - 1; i >= 0; i--)
    {
        outputFile << bridge[i][0] << ' ' << bridge[i][1] << endl;
    }
    outputFile << endl;

    // Close the output file
    outputFile.close();

    cout << "Data written to output file." << endl;

    return 0;
}
