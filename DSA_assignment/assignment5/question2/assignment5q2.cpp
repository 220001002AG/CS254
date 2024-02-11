
#include<iostream>
using namespace std;
#include<vector>
#include <fstream>
#include<map>
#include<queue>




int dijectra(int node,map<int,vector<vector<int>>>&gr,int final,int n){
    if(node==final){
        return 0;
    }
    vector<int>dis(n+1,INT_MAX);
    dis[node]=0;
    priority_queue<vector<int>>q;
    vector<int>vis(n+1,0);
    q.push({0,node});
    while(!q.empty()){
        vector<int> curr=q.top();
        q.pop();
        vis[curr[1]]=1;
        for(int j=0;j<size(gr[curr[1]]);j++){
            if(dis[gr[curr[1]][j][0]]>curr[0]+gr[curr[1]][j][1]){
                dis[gr[curr[1]][j][0]]=curr[0]+gr[curr[1]][j][1];

            
                q.push({dis[gr[curr[1]][j][0]],gr[curr[1]][j][0]});
            }
        }
    }

    return dis[final];

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
    int n,m,k;// Set a maximum size for the array
    inputFile>>n>>m>>k;
    vector<vector<int>>vec;
    for(int i=0;i<k;i++){

        int type,ini,fin;
        inputFile>>type>>ini>>fin;
        vec.push_back({type,ini,fin});

    
      
    }

    map<int,vector<vector<int>>>gr;
    for(int i=1;i<=n*m;i++){
        for(int j=i+1;j<=i+6;j++){
            if(j<=n*m){
                gr[i].push_back({j,1});

            }
            
        }
    }

    for(int i=0;i<k;i++){
        if(vec[i][0]==1){
            gr[vec[i][2]].erase(gr[vec[i][2]].begin(),gr[vec[i][2]].end());
            gr[vec[i][2]].push_back({vec[i][1],0});
        }
        else{
            gr[vec[i][1]].erase(gr[vec[i][1]].begin(),gr[vec[i][1]].end());           
            gr[vec[i][1]].push_back({vec[i][2],0});

        }
    }

    

    


    
    


    

    // Close the file
    inputFile.close();

    // Display the contents of the array
    cout << "Data read from file and stored in array:" << endl;
    int ans=dijectra(1,gr,n*m,n*m);
  
    


    


    ofstream outputFile("output.txt");

    // Check if the file is open
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." <<endl;
        return 1; // Exit with an error code
    }

   
    // Write the contents of the array to the output file
    for (int i = 0; i < 1; ++i) {
        outputFile<<"the minimum number of moves required is  "<<ans<<endl;
    }

    // Close the output file
    outputFile.close();

    cout << "Data written to output file." << endl;


    return 0;
}
    
