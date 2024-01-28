#include<iostream>
using namespace std;
#include <fstream>
int myArray[10000000];


int main() {
    // Open the text file for reading
    ifstream inputFile("input.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error opening file." <<endl;
        return 1; // Exit with an error code
    }
    int sa1,sa2;
    inputFile>>sa1;
    const int maxSize1{sa1} ; // Set a maximum size for the array
    // int myArray[maxSize];
    int arraySize1 = 0;
    

    // Read data from the file into the array
    while (arraySize1 < maxSize1 && inputFile >> myArray[arraySize1]) {
        arraySize1++;
    }
 
    // Close the file
    inputFile.close();

    // Display the contents of the array
    cout << "Data read from file and stored in array:" << endl;
    // for (int i = 0; i < arraySize1; ++i) {
    //     cout << myArray[i] << " ";
    // }
    // cout <<endl;

// function to get the maximum sum of a continuous array in myArray
   int sumtillnow=INT_MIN;
   int sum=0;
   int j=0;
   for(int i=0;i<arraySize1;i++){
    sum=sum+myArray[i];
    if(sum<0){
        if(sum>sumtillnow){
        sumtillnow=sum;
        }
        j=i;
        sum=myArray[i];
    }
    if(sum>sumtillnow){
        sumtillnow=sum;
    }



   }


   


    ofstream outputFile("output.txt");

    // Check if the file is open
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." <<endl;
        return 1; // Exit with an error code
    }

   
    // Write the contents of the array to the output file
  
    outputFile <<"The maximum sum of contigous segment of the array is "<<sumtillnow<<endl;
    
    

    // Close the output file
    outputFile.close();

    cout << "Data written to output file." << endl;


    return 0;
}
