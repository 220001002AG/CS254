#include<iostream>
using namespace std;
#include <fstream>
#include<map>
#include<vector>
#include<queue>
#include<stack>
// int myArray[10000000];
#define ll int
ofstream outputFile("output.txt");
void dfs(map<int,vector<int>>&m,vector<int>&visited,int node,stack<int>&s){
    visited[node]=1;
    

    for(auto n:m[node]){
        if(visited[n]==0){
            dfs(m,visited,n,s);
            
        }
    }
    s.push(node);
}

void dfs2(map<int,vector<int>>&m,vector<int>&visited,int node){
    visited[node]=1;
   
    cout<<node<<" ";
    outputFile<<node<<" ";

    for(auto n:m[node]){
        if(visited[n]==0){
            dfs2(m,visited,n);
            
        }
    }
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
    map<int,vector<int>>m,m_rev;
    
    

    for(int i=0;i<e;i++){
        ll u,v;
        inputFile>>u>>v;
     
        m[u].push_back(v);
        m_rev[v].push_back(u);
        cout<<u<<" "<<v<<endl;

    }
    



    cout << "Data read from file and stored in array:" << endl;
   


    inputFile.close();
    

    // kosaraju

    vector<int>visited(v+1,0);
    stack<int>s;
    for(int i=1;i<=v;i++){
        if(visited[i]==0){
            dfs(m,visited,i,s);
        }
    }
    vector<int>visited2(v+1,0);
    // ofstream outputFile("output.txt");
    while(!s.empty()){
        int node=s.top();
        if(visited2[node]==0){
            dfs2(m_rev,visited2,node);
            cout<<endl;
            
            outputFile<<endl;

        }
        s.pop();
        
    }



    

    
    
    




    

    // Check if the file is open
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." <<endl;
        return 1; // Exit with an error code
    }

   
    // Write the contents of the array to the output file
    
    
    

    // Close the output file
    outputFile.close();

    cout << "Data written to output file." << endl;


    return 0;
}
