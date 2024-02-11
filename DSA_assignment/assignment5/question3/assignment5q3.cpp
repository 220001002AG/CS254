
#include<iostream>
using namespace std;
#include<vector>
#include <fstream>
#include<queue>



bool isbipartite(vector<vector<int>>&gr,int i,vector<int>&vis){
    vector<int>color(gr.size(),0);
    color[i]=1;
    vis[i]=1;
    queue<int>q;
    q.push(i);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        
        for(int j=0;j<size(gr[curr]);j++){
            if(gr[curr][j]==1 && vis[j]==0 && curr!=j){
                color[j]=color[curr]^1;
                vis[j]=1;
                q.push(j);
            }
            else if(gr[curr][j]==1 && vis[j]==1 && curr!=j){
                if(color[curr]==color[j]){
                    return false;
                }
            }
        }
    }
    return true;
    
    
}

bool isgbipartite(vector<vector<int>>&gr){
    for(int i=0;i<gr.size();i++){
        vector<int>vis(gr.size(),0);
        if(!isbipartite(gr,i,vis)){
            return false;
        }
    }
    return true;
}




int main() {
    // Open the text file for reading
    ifstream inputFile("input.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error opening file." <<endl;
        return 1; // Exit with an error code
    }

    const int maxSize = 10000000; 
    int n,edges;// Set a maximum size for the array
    inputFile>>n>>edges;
    vector<vector<int>>gr(n,vector<int>(n,0));
    for(int i=0;i<edges;i++){
        int a,b;
        inputFile>>a>>b;
        gr[a][b]=1;
        
    }
    // creating complement of the graph
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j!=i && gr[i][j]==1){
                gr[i][j]=0;
            }
            else if(j!=i){
                gr[i][j]=1;
            }
        }
    }




   


    
    


    

    // Close the file
    inputFile.close();

    // Display the contents of the array
    cout << "Data read from file and stored in array:" << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<gr[i][j]<<" ";
        }
        cout<<endl;
    }



    bool ans=isgbipartite(gr);


    


    


    ofstream outputFile("output.txt");

    // Check if the file is open
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." <<endl;
        return 1; // Exit with an error code
    }

   
    // Write the contents of the array to the output file
    for (int i = 0; i < 1; ++i) {
        ans?outputFile<< "YES":outputFile<< "NO";cout<<endl;
    }

    // Close the output file
    outputFile.close();

    cout << "Data written to output file." << endl;


    return 0;
}
    
