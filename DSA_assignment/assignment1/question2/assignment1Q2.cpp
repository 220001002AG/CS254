#include<iostream>
using namespace std;
#include<cmath>
#include <fstream>
int arr[10000000];
int values[10000000];
// int dp[100][10000];

int knap(int arr[],int **dp,int i,int w,int weight,int price[],int n){
    if(weight>w){
        return INT_MIN;
    }
    if(i>n-1){
        return 0;
    }
    if(dp[weight][i]!=-1){
        return dp[weight][i];
    }
    
    return dp[weight][i]=max(price[i]+knap(arr,dp,i+1,w,weight+arr[i],price,n),knap(arr,dp,i+1,w,weight,price,n));

}
int main() {
    
    // Open the text file for reading
    ifstream inputFile("input.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error opening file." <<endl;
        return 1; // Exit with an error code
    }

    int n,w;
    inputFile>>n>>w;
    int rows=w+1;
    int columns=n+1;
    int** dp = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        dp[i] = new int[columns];
    }

    // Initialize the values of the dynamic 2D array
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            // Set your desired values or use any initialization logic
            dp[i][j] =-1;
        }
    }
    int maxSize=n;
    
    int arraySize=0;
    int valuessize=0;
    int val;
    

    // Read data from the file into the array
    while (arraySize < maxSize && inputFile >> val) {
        arr[arraySize]=val;
        arraySize++;
    }
    while (valuessize < maxSize && inputFile >> val) {
        values[valuessize]=val;
        valuessize++;
    }

    // Close the file
    inputFile.close();

    // Display the contents of the array
    cout << "Data read from file and stored in array (weights):" << endl;
    for (int i = 0; i < arraySize; ++i) {
        cout <<arr[i] << " ";
    }
    cout <<endl;

    cout << "Data read from file and stored in array (price):" << endl;
    for (int i = 0; i < valuessize; ++i) {
        cout <<values[i] << " ";
    }
    cout <<endl;

    int ans=knap(arr,dp,0,w,0,values,n);
    cout<<ans<<endl;

    for (int i = 0; i < rows; ++i) {
        delete[] dp[i];
    }
    delete[] dp;






    ofstream outputFile("output.txt");

    // Check if the file is open
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." <<endl;
        return 1; // Exit with an error code
    }

   
    // Write the contents of the array to the output file
    for (int i = 0; i < 1; ++i) {
        outputFile <<"The maximum value we can get provided the given constraints is  "<<ans;
    }

    // Close the output file
    outputFile.close();

    cout << "Data written to output file." << endl;


    return 0;
}
