#include<iostream>
using namespace std;
#include <fstream>
#include<map>
#include<vector>
#include<queue>
// int myArray[10000000];
#define ll int

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
    vector<int>parent(v+1,0);
    vector<int>topological_sort;
    queue<int>q;
    for(int i=0;i<e;i++){
        ll u,v;
        inputFile>>u>>v;
        in_degree[v]++;
        m[u].push_back(v);

    }
    





    
  
    // Close the file

     // Display the contents of the array
    cout << "Data read from file and stored in array:" << endl;
    for(auto i:in_degree){
        cout<<i<<' ';
    }
    cout<<endl;


    inputFile.close();
    for(int j=1;j<size(in_degree);j++){
        if(in_degree[j]==0){
            q.push(j);
            parent[j]=j;
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:m[u]){
            if(in_degree[v]>0){
                in_degree[v]--;
                
            }
            if(in_degree[v]==0){
                q.push(v);
                parent[v]=u;
            }
            
        }
        // cout<<u<<endl;
        topological_sort.push_back(u);
    }
    vector<int>longestpath;
    int st=topological_sort[topological_sort.size()-1];
    while(parent[st]!=st){
        longestpath.push_back(st);
        st=parent[st];

        
    }
    longestpath.push_back(st);




    ofstream outputFile("output.txt");

    // Check if the file is open
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." <<endl;
        return 1; // Exit with an error code
    }

   
    // Write the contents of the array to the output file
    for(int i=size(longestpath)-1;i>=0;i--){
        outputFile<<longestpath[i]<<' ';
    }
    outputFile<<endl;
    
    

    // Close the output file
    outputFile.close();

    cout << "Data written to output file." << endl;


    return 0;
}
