#include<iostream>
using namespace std;
#include <fstream>
int myArray[10000000];
int myArray2[10000000];
int myArray3[10000000];

int main() {
    // Open the text file for reading
    ifstream inputFile("input.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error opening file." <<endl;
        return 1; // Exit with an error code
    }
    int sa1,sa2;
    inputFile>>sa1>>sa2;
    const int maxSize1{sa1},maxSize2{sa2} ; // Set a maximum size for the array
    // int myArray[maxSize];
    int arraySize1 = 0;
    // int arraySize2 = 0;

    // Read data from the file into the array
    while (arraySize1 < maxSize1 && inputFile >> myArray[arraySize1]) {
        arraySize1++;
    }
    int arraySize2 = 0;

    // Read data from the file into the array
    while (arraySize2 < maxSize2 && inputFile >> myArray2[arraySize2]) {
        arraySize2++;
    }

    // Close the file
    inputFile.close();

    // Display the contents of the array
    cout << "Data read from file and stored in array:" << endl;
    // for (int i = 0; i < arraySize1; ++i) {
    //     cout << myArray[i] << " ";
    // }
    // cout <<endl;

    cout << "Data read from file and stored in array:" << endl;
    // for (int i = 0; i < arraySize2; ++i) {
    //     cout << myArray2[i] << " ";
    // }
    // cout <<endl;
    int j=0;
    int i=0;
    int k=0;
    while(true){
        if( (i<arraySize1 && j<arraySize2) && myArray[i]<myArray2[j]){
            if(k>0){
                if(myArray[i]==myArray3[k-1]){
                    i++;
                   
                    continue;
                }
            }
            myArray3[k]=myArray[i];
            i++;
        }
        else if( (i<arraySize1 && j<arraySize2) && myArray[i]>=myArray2[j]){
            if(k>0){
                if(myArray2[j]==myArray3[k-1]){
                    j++;
                    
                    continue;
                }
            }
            myArray3[k]=myArray2[j];
            j++;
        }
        else if(i<arraySize1){
            if(k>0){
                if(myArray[i]==myArray3[k-1]){
                    i++;
                   
                    continue;
                }
            }
            myArray3[k]=myArray[i];
            i++;

        }
        else if(j<arraySize2){
            if(k>0){
                if(myArray2[j]==myArray3[k-1]){
                    j++;
                 
                    continue;
                }
            }
            myArray3[k]=myArray2[j];
            j++;

        }
        else{
            break;
        }
        
        k++;

    }






   


    ofstream outputFile("output.txt");

    // Check if the file is open
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." <<endl;
        return 1; // Exit with an error code
    }

   
    // Write the contents of the array to the output file
    // arraySize1--;
    for (int i = 0; i < k; ++i) {
        outputFile <<myArray3[i]<<' ';
    }
    cout<<endl;

    // Close the output file
    outputFile.close();

    cout << "Data written to output file." << endl;


    return 0;
}
