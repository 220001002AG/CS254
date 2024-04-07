#include <bits/stdc++.h>
using namespace std;
int graph[18][18][2];

long long dp[1 << 18][18][2];
 

long long minCost(int n, int m, int mask, int prev, int col)
{
    // Base case
    if (mask == ((1 << n) - 1)) {
        return 0;
    }
    // If already calculated
    if (dp[mask][prev][col == 1] != 0) {
        return dp[mask][prev][col == 1];
    }
 
    long long ans = 1e9;
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            
            if (graph[prev][i][j] && !(mask & (1 << i)) 
                && (j != col)) {
                long long z = graph[prev][i][j] + 
                              minCost(n,m,mask|(1<<i),i,j);
                ans = min(z, ans);
            }
        }
    }
 
    return dp[mask][prev][col == 1] = ans;
}
 

void makeGraph(vector<pair<pair<int,int>,
                      pair<int,char>>>& vp,int m){
 
  for (int i = 0; i < m; i++) {
    int a = vp[i].first.first - 1;
    int b = vp[i].first.second - 1;
    int cost = vp[i].second.first;
    char color = vp[i].second.second;
    graph[a][b][color == 'W'] = cost;
    graph[b][a][color == 'W'] = cost;
  }
}
 

int getCost(int n,int m){

    long long ans = 1e9;
 
    for (int i = 0; i < n; i++) {
        ans = min(ans, minCost(n, m, 1 << i, i, 2));
    }
 
    if (ans != 1e9) {
        return ans;
    }
    else {
        return -1;
    }
}
 

int main()
{
    ifstream inputFile("input.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error opening file." <<endl;
        return 1; // Exit with an error code
    }
    int nodes;inputFile>>nodes;
    int m;inputFile>>m;
    // int n = 3, m = 4;
    vector<pair<pair<int, int>, pair<int, char> > > vp ;
    for(int i=0;i<m;i++){
        int a,b,w;inputFile>>a>>b>>w;
        char c;inputFile>>c;
        vp.push_back({{a,b},{w,c}});
    }
 
    makeGraph(vp,m);

    inputFile.close();
  
    



    ofstream outputFile("output.txt");

    // Check if the file is open
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." <<endl;
        return 1; // Exit with an error code
    }
    outputFile << getCost(nodes,m) << '\n';
     
    return 0;
}