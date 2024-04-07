#include<iostream>
using namespace std;
#include <fstream>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<set>
// int myArray[10000000];
#define ll int
int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}
ll find(map<ll,ll>&mk,ll a){
    while(mk[a]!=a){
        a=mk[a];
    }
    return a;
}
ll unions(map<ll,ll>&mk,ll a,ll b){
    if(find(mk,a)!=find(mk,b)){
        mk[find(mk,a)]=find(mk,b);
        return 1;
    }
    return 0;

}
int main() {
    // Open the text file for reading
    ifstream inputFile("input.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error opening file." <<endl;
        return 1; // Exit with an error code
    }
    ll nodes;inputFile>>nodes;
    int n;
    inputFile>>n;
    map<ll,vector<ll>>m;
    vector<vector<ll>>edges;
    for(ll i=0;i<n;i++){
        
        ll u,v,w;
        inputFile>>w>>u>>v;
        edges.push_back({w,u,v});

    
    }
    sort(edges.begin(),edges.end(),greater<vector<ll>>());
    map<ll,ll>mk;
    for(ll i=1;i<=nodes;i++){
        mk[i]=i;

    }
    ll ed=0;
    vector<vector<ll>>ans;
    for(ll i=0;i<edges.size();i++){
        if(ed==n-1){
            break;
        }
        ll a=unions(mk,edges[i][1],edges[i][2]);
        ed=ed+a;
        if(a==1){
        ans.push_back(edges[i]);}
        
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
    
    for(ll i=0;i<ans.size();i++){
        outputFile<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<" "<<endl;
    }
    outputFile<<endl;
    

    
    

    // Close the output file
    outputFile.close();

    cout << "Data written to output file." << endl;


    return 0;
}
