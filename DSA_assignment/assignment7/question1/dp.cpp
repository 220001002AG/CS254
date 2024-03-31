// T(O(nw))
#include<iostream>
using namespace std;
#include <fstream>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
// int myArray[10000000];
#define ll int
int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}
int solve(vector<int>&weights,vector<int>&value,vector<vector<int>>&dp,int n,int w){
    // cout<<"g"<<endl;
    if(n<0){
        // cout<<"g1"<<endl;
        return 0;
    }
    if(w<0){
        // cout<<"g2"<<endl;
        return INT_MIN;
    }
    
    if(dp[n][w]!=-1){
        // cout<<n<<w<<" "<<dp[n][w]<<"g3"<<endl;
        return dp[n][w];}


    
    return dp[n][w]=max(solve(weights,value,dp,n-1,w-weights[n])+value[n],solve(weights,value,dp,n-1,w));


}
int main() {
    // Open the text file for reading
    ifstream inputFile("input.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error opening file." <<endl;
        return 1; // Exit with an error code
    }

    int n;
    inputFile>>n;
    vector<int>weights,value;
    int w;
    inputFile>>w;
    for(int i=0;i<n;i++){
        int val;
        inputFile>>val;
        weights.push_back(val);
        
    }
    for(int i=0;i<n;i++){
        int val;
        inputFile>>val;
        // weights.push_back(val);
        value.push_back(val);
    }
    vector<vector<int>>dp(n,vector<int>(w+1,-1));
    cout<<"iji"<<n<<" "<<w<<endl;
    int cost=solve(weights,value,dp,n-1,w);
    for(int i=0;i<n;i++){
        for(int j=0;j<=w;j++){
            cout<<dp[i][j]<<" ";
        }
    }
    
    



    
    





    
  
    // Close the file

     // Display the contents of the array
    


    inputFile.close();
  
    



    ofstream outputFile("output.txt");

    // Check if the file is open
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." <<endl;
        return 1; // Exit with an error code
    }

   
    // Write the contents of the array to the output file
    
    outputFile <<cost<<endl;
    
    

    // Close the output file
    outputFile.close();

    cout << "Data written to output file." << endl;


    return 0;
}
