#include <bits/stdc++.h>
using namespace std;

struct Job
{
    char id;
    int dead;
    int profit;
};

struct jobProfit
{
    bool operator()(Job const &a, Job const &b)
    {
        return (a.dead < b.dead);
    }
};
int solve(Job arr[],vector<vector<int>>&dp,int i,int time,int maxn,int n,set<char>&amt){
    
    if(i>=n){
        return 0;
    }
    if(time>maxn){return INT_MIN;}
    if(dp[i][time]!=-1){return dp[i][time];}
    int a=solve(arr,dp,i+1,time,maxn,n,amt);
    
    int b=0;
    if(time<=arr[i].dead){
        b=arr[i].profit+solve(arr,dp,i+1,time+1,maxn,n,amt);
    }
    if(a>b){
        dp[i][time]=a;
        if(amt.find(arr[i].id)!=amt.end()){
        amt.erase(amt.find(arr[i].id));}
    

    }
    else{
        dp[i][time]=b;
        amt.insert(arr[i].id);
    }
    return dp[i][time];


}
void JobScheduling(Job arr[], int n)
{
    vector<Job> result;
    sort(arr, arr + n,
         [](Job a, Job b)
         { return a.dead < b.dead; });
    for(int i=0;i<n;i++){
        cout<<arr[i].id<<" "<<arr[i].profit<<" "<<arr[i].dead<<endl;

    }
    cout<<endl;
    cout<<endl;
    int maxi=0;
    for(int i=0;i<n;i++){
        maxi=max(maxi,arr[i].dead);
    }     
    cout<<maxi<<endl;
    vector<vector<int>>dp(n,vector<int>(maxi+1,-1));
    set<char>amt;
    int pr=solve(arr,dp,0,1,arr[n-1].dead,n,amt);
    cout<<pr<<endl;
    // for(auto I:amt){
    //     cout<<I<<" ";
    // }
    // cout<<endl;




    

    
}

int main()
{
    ifstream inputFile("input.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error opening file." <<endl;
        return 1; // Exit with an error code
    }
    int n;
    inputFile>>n;

    Job arr[n];
    for(int i=0;i<n;i++){
        Job v;
        inputFile>>v.id>>v.dead>>v.profit;
        arr[i]=v;
        // cout<<v.id<<endl;

        
    }
    inputFile.close();
    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." <<endl;
        return 1; // Exit with an error code
    }
    JobScheduling(arr, n);
    return 0;
}