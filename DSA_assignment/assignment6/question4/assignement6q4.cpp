#include<iostream>
using namespace std;
#include <fstream>
#include<map>
#include<vector>
#include<queue>
// int myArray[10000000];
#define ll int


ll dfs(vector<ll>&recurse,vector<ll>&visited,ll node,map<ll,vector<ll>>&m){
    visited[node]=1;
    recurse[node]=1;
    for(auto n:m[node]){
        if(recurse[n]==1){
                return 0;
            }
        if(visited[n]==0){
            
            
            ll val= dfs(recurse,visited,n,m);
            if(val==0){
                return 0;
            }
            else{
                recurse[n]=0;
            }
        }
       
    }
    return 1;

}
int main() {
    // Open the text file for reading
    ifstream inputFile("input.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error opening file." <<endl;
        return 1; // Exit with an error code
    }

    int v,e;
    inputFile>>v>>e;
    map<int,vector<int>>m;
    vector<int>in_degree(v+1,0);
    vector<int>topological_sort;
    queue<int>q;
    for(int i=0;i<e;i++){
        ll u,v;
        inputFile>>u>>v;
        in_degree[v]++;
        m[u].push_back(v);

    }
    



    cout << "Data read from file and stored in array:" << endl;
    for(auto i:in_degree){
        cout<<i<<' ';
    }
    cout<<endl;


    inputFile.close();
    int ans=1;

    vector<int>recurse(v+1,0),visited(v+1,0);
    for(int i=1;i<=v;i++){
        if(visited[i]==0){
            ans=(ans&dfs(recurse,visited,i,m));
        }
    }
    
    




    ofstream outputFile("output.txt");

    // Check if the file is open
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." <<endl;
        return 1; // Exit with an error code
    }

   
    // Write the contents of the array to the output file
    if(ans==0){
   outputFile <<"The graph has a cycle: "<<endl;}
   else{
       outputFile <<"The graph does not have a cycle: "<<endl;

   }
    
    

    // Close the output file
    outputFile.close();

    cout << "Data written to output file." << endl;


    return 0;
}
