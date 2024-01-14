#include<iostream>
using namespace std;
#include<cmath>
#include<vector>
#include <fstream>
#include<map>

// ll dp[100][10000];

#define ll unsigned long long int
ll solve(ll i,ll **dp, ll **w,ll travelled,ll ini,vector<ll>&ans,ll n,map<ll,ll>&m){
    
    if(dp[i][travelled]!=-1){
        return dp[i][travelled];
    }
    ll min=ULLONG_MAX;
    ll node=ini;
    
    for(ll j=0;j<n;j++){
        ll val;
        if(w[i][j]!=-1 && (travelled>>j)%2==0){
            val=w[i][j]+solve(j,dp,w,(travelled | (1<<j)),ini,ans,n,m);
            if(val<min){
                min=val;
                node=j;
            }
            
        }
        

    }
    // cout<<min<<' '<<i<<' '<<node<<endl;
    if(m[node]==0){
        ans.push_back(node);
        m[node]++;
    }
    

    if(node==ini){
        return dp[ini][travelled]=w[i][ini];

    }
    return dp[i][travelled]=min;
}
int main() {
    
    // Open the text file for reading
    ifstream inputFile("input.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error opening file." <<endl;
        return 1; // Exit with an error code
    }

    ll n,ini;
    inputFile>>n>>ini;
    ll rows=n;
    // ll columns=n+1;
    // ll** dp = new ll*[rows];

    ll **w=new ll *[n];
    for (ll i = 0; i < rows; ++i) {
        w[i] = new ll[n];
    }
    for(ll i=0;i<n;i++){

        for(ll j=0;j<n;j++){
            w[i][j]=-1;
        }
    }



    ll maxSize=n*n;
    
    ll arraySize=0;
   
    ll val,val2,val3;
    
cout << "Data read from file and stored in array (weights):" << endl;
    // Read data from the file llo the array
    while (arraySize < maxSize && inputFile >> val) {
        if(val>100000000000){
            break;
        }
        
            inputFile>>val2>>val3;
            
            w[val][val2]=val3;
            w[val2][val]=val3;
            cout<<val<<' '<<val2<<' '<<val3<<' ';
        
        arraySize=arraySize+1;
        
    }
    cout<<endl;
   
  
    

    // Close the file
    inputFile.close();

    // Display the contents of the array
    
    


    ll **dp=new ll *[n];
    for(ll j=0;j<n;j++){
        dp[j]=new ll[1<<(n+1)];
    }

    for(ll i=0;i<n;i++){
        for(ll j=0;j<(1<<(n+1));j++){
            dp[i][j]=-1;
        }
    }

    vector<ll>vec;
    ll mask=(1<<n);
    mask=(mask | 1>>ini);
    map<ll,ll>l;
    ll as=solve(ini,dp,w,mask,ini,vec,n,l);
    
  
    // cout<<"ANs "<<as<<endl;


   

    for (ll i = 0; i < n; ++i) {
        delete[] w[i];
    }
    delete[] w;








    ofstream outputFile("output.txt");

    // Check if the file is open
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." <<endl;
        return 1; // Exit with an error code
    }

   
    // Write the contents of the array to the output file
    for (ll i = 0; i < 1; ++i) {
        outputFile <<"The maximum value we can get provided the given graph is "<<as<<" and the path is ";
    }
    for(ll i=0;i<size(vec);i++){
        outputFile<<vec[i]<<' ';


    }

    for (ll i = 0; i < 1; ++i) {
        cout <<"The maximum value we can get provided the given graph is "<<as<<" and the path is ";
    }
    for(ll i=0;i<size(vec);i++){
        cout<<vec[i]<<' ';


    }
    cout<<ini<<endl;
    
    // Close the output file
    outputFile.close();

    cout << "Data written to output file." << endl;


    return 0;
}
