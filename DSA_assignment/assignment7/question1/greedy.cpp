// T(O(nlogn))
#include<iostream>
using namespace std;
#include <fstream>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
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
vector<vector<int>>vec;
for(int i=0;i<n;i++){
    vec.push_back({(value[i]/weights[i]),i});
}
sort(vec.begin(),vec.end());
int w_=0;
int cost=0;
for(int i=0;i<n;i++){
    if(w_+weights[vec[i][0]]<=w){
        cost=cost+value[vec[i][1]]; 
        w_=w_+weights[vec[i][1]];
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
