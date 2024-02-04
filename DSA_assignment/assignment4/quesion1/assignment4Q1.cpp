#include<iostream>
using namespace std;
#include<vector>
#include <fstream>
#define ll long long int
int myArray[10000000];
ll max(ll a, ll b){
    if(a>b){
        return a;
        
    }
    return b;
}
vector<ll> merger(vector<ll>&v1,vector<ll>&v2,ll &count){
    ll c=0;
    vector<ll>vec;
    ll i{0},j{0};
    while(i<size(v1)|j<size(v2)){
        if(i<size(v1) && j<size(v2)){
            if(v1[i]<=v2[j]){
                vec.push_back(v1[i]);
                i++;
                c=c+max(0,j);



            }
            else if(v1[i]>v2[j]){
                vec.push_back(v2[j]);
                j++;
               
            }
        }
        else if(i<size(v1)){
            vec.push_back(v1[i]);
            i++;
            c=c+max(j,0);
        }
        else if(j<size(v2)){
            vec.push_back(v2[j]);
            j++;
            
        }
    }
    count=c+count;
    return vec;
}
vector<ll> mergesort(vector<ll>&v,ll &count){
    if(size(v)==1){
        return v;
    }
    vector<ll>v1;
    vector<ll>v2;
    for(ll i=0;i<size(v);i++){
        if(i<size(v)/2){
            v1.push_back(v[i]);
        }
        else{
            v2.push_back(v[i]);
        }
    }
    v1=mergesort(v1,count);
    v2=mergesort(v2,count);
    v=merger(v1,v2,count);
    return v;
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
    ll n;// Set a maximum size for the array
    inputFile>>n;
    vector<ll>vec;
    for(ll i=0;i<n;i++){
        ll val;
        inputFile>>val;
        vec.push_back(val);
    }
    

    // Close the file
    inputFile.close();

    // Display the contents of the array
    cout << "Data read from file and stored in array:" << endl;
    // for (int i = 0; i < n; ++i) {
    //     cout << vec[i] << " ";
    // }
    // cout <<endl;

    ll c=0;
    mergesort(vec,c);
    


    


    ofstream outputFile("output.txt");

    // Check if the file is open
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." <<endl;
        return 1; // Exit with an error code
    }

   
    // Write the contents of the array to the output file
    for (int i = 0; i < 1; ++i) {
        outputFile<<"The number of inversions are "<<c<<endl;
    }

    // Close the output file
    outputFile.close();

    cout << "Data written to output file." << endl;


    return 0;
}
