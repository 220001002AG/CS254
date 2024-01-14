#include<iostream>
using namespace std;
#include <fstream>

int main() {
    // Open the text file for reading
    ifstream inputFile("input.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error opening file." <<endl;
        return 1; // Exit with an error code
    }

    const int maxSize = 100; // Set a maximum size for the array
    int myArray[maxSize];
    int arraySize = 0;

    // Read data from the file into the array
    while (arraySize < maxSize && inputFile >> myArray[arraySize]) {
        arraySize++;
    }

    // Close the file
    inputFile.close();

    // Display the contents of the array
    cout << "Data read from file and stored in array:" << endl;
    for (int i = 0; i < arraySize; ++i) {
        cout << myArray[i] << " ";
    }
    cout <<endl;


    int fmax=INT_MIN;
    int smax=INT_MIN;
    for(int i=0;i<arraySize;i++){
        if(fmax<=myArray[i]){
            smax=fmax;
            fmax=myArray[i];

        }
        else if(smax<=myArray[i]){
            smax=myArray[i];
        }

    }
    cout<<"The largest sum of two numbers are "<<smax+fmax<<endl;


    ofstream outputFile("output.txt");

    // Check if the file is open
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." <<endl;
        return 1; // Exit with an error code
    }

   
    // Write the contents of the array to the output file
    for (int i = 0; i < 1; ++i) {
        outputFile <<"The largest sum of two numbers are "<<smax+fmax;
    }

    // Close the output file
    outputFile.close();

    cout << "Data written to output file." << endl;


    return 0;
}
