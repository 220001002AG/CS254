
#include<iostream>
using namespace std;
#include<vector>
#include <fstream>



int bfs(int i,int j,vector<vector<int>>&vec,vector<vector<int>>&vis){

    if(i<0 || j<0 || i>=vec.size() || j>=vec[0].size() || vis[i][j]==1 || vec[i][j]==0){
        return 0;
    }
    vis[i][j]=1;
    return bfs(i+1,j,vec,vis)+bfs(i-1,j,vec,vis)+bfs(i,j+1,vec,vis)+bfs(i,j-1,vec,vis)+bfs(i+1,j+1,vec,vis)+bfs(i-1,j-1,vec,vis)+bfs(i-1,j+1,vec,vis)+bfs(i+1,j-1,vec,vis)+1;
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
    int n,m;// Set a maximum size for the array
    inputFile>>n>>m;
    vector<vector<int>>vec;
    for(int i=0;i<n;i++){
        vector<int>h;
        for(int j=0;j<m;j++){
            int val;inputFile>>val;
            h.push_back(val);


        }
    
        vec.push_back(h);
    }
    


    

    // Close the file
    inputFile.close();

    // Display the contents of the array
    cout << "Data read from file and stored in array:" << endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<vec[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }



    int ans=0;
    vector<vector<int>>vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0){
                
                int number=bfs(i,j,vec,vis);
                if(number>ans){
                    ans=number;

                }


            }
        }
    }

  
    


    


    ofstream outputFile("output.txt");

    // Check if the file is open
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." <<endl;
        return 1; // Exit with an error code
    }

   
    // Write the contents of the array to the output file
    for (int i = 0; i < 1; ++i) {
        outputFile<<"the largest connected pool of 1's are "<<ans<<endl;
    }

    // Close the output file
    outputFile.close();

    cout << "Data written to output file." << endl;


    return 0;
}
    
