
#include<iostream>
using namespace std;
#include<vector>
#include <fstream>


void maxheapify(vector<int>&vec,int i){

    int l=2*i+1;
    int r=2*i+2;
    int largest=i;
    if(l<vec.size() && vec[l]>vec[largest]){
        largest=l;
    }
    if(r<vec.size() && vec[r]>vec[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(vec[i],vec[largest]);
        maxheapify(vec,largest);
    }

}

void buildmaxheap(vector<int>&vec){

    for(int i=vec.size()/2-1;i>=0;i--){
        maxheapify(vec,i);
    }
}

int kthlargest(vector<int>&vec,int k){

    buildmaxheap(vec);
    int n=vec.size();
    for(int i=vec.size()-1;i>=n-k+1;i--){
        swap(vec[0],vec[i]);
        vec.pop_back();
        maxheapify(vec,0);
    }
    return vec[0];
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
    int n,k;// Set a maximum size for the array
    inputFile>>n>>k;
    vector<int>vec;
    for(int i=0;i<n;i++){
        int val;
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

    int a=kthlargest(vec,k);


    


    


    ofstream outputFile("output.txt");

    // Check if the file is open
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." <<endl;
        return 1; // Exit with an error code
    }

   
    // Write the contents of the array to the output file
    for (int i = 0; i < 1; ++i) {
        outputFile<<"the kth largest element is "<<a<<endl;
    }

    // Close the output file
    outputFile.close();

    cout << "Data written to output file." << endl;


    return 0;
}
    
