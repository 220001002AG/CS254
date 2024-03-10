#include <iostream>
using namespace std;
#include <fstream>
#include <map>
#include <vector>
#include <queue>
// int myArray[10000000];
#define ll int
void dfs(vector<ll> &visited, map<ll, vector<ll>> &m, ll node, vector<ll> &articulation,
 vector<ll> &time, vector<ll> &low, ll &count, vector<ll> &parent)
{
    time[node] = low[node] = count;
    count++;
    visited[node] = 1;
    ll child=0;

    for (auto n : m[node])
    {
        if (n == parent[node])
            continue;
        if (visited[n] == 0)
        {
            parent[n] = node;
            dfs(visited, m, n, articulation, time, low, count, parent);
            low[node] = min(low[node], low[n]);
            if (time[node] <= low[n] && parent[node]!=-1)
            {
                articulation[node]=1;
            }
            child++;
        }
        else
        {
            low[node] = min(low[node], time[n]);
        }
    }
    if(child>1 && parent[node]==-1){
        articulation[node]=1;
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

    vector<int> parent(v + 1, -1), low(v + 1, 0), time(v + 1, 0), visited(v + 1, 0);

    queue<int> q;
    vector<vector<int>>vec(v+1,vector<int>(v+1,0));
    for (int i = 0; i < e; i++)
    {
        ll u, v;
        inputFile >> u >> v;
        if(vec[u][v]==0){
            m[u].push_back(v);
        m[v].push_back(u);
        vec[u][v]++;
        vec[v][u]++;

        }

        
    }
    vector<int>articulation(v+1,0);
    ll count = 0;
    dfs(visited, m, 1, articulation, time, low, count, parent);

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
    for (int i = 1; i <size(articulation) ; i++)
    {
        if(articulation[i]==1){
        outputFile << i<<' '<< endl;}
    }
    outputFile << endl;

    // Close the output file
    outputFile.close();

    cout << "Data written to output file." << endl;

    return 0;
}
