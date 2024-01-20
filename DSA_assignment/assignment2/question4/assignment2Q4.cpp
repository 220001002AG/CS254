#include<iostream>
using namespace std;
#include <fstream>
int myArray[10000000];

int pivot(int myArray[],int i,int j,int n){
    int mid=i+(j-i)/2;
   
    int k=i+1,p=0;
    int bu=myArray[mid];
    myArray[mid]=myArray[i];
    myArray[i]=bu;
    for( p=i+1;p<=j+1;p++){
        if(p==j+1){
            k--;
            bu=myArray[i];
            myArray[i]=myArray[k];
            myArray[k]=bu;
           break;




        }

        if(myArray[p]<myArray[i]){
            // cout<<myArray[p]<<endl;
            // cout<<myArray[i]<<endl;

            bu=myArray[k];
            myArray[k]=myArray[p];
            myArray[p]=bu;
            if(p==k){
                k++;

            }
            else{
            k++;
            p--;}




        }
        // for(int y=0;y<=n;y++){
        //     cout<<myArray[y]<<' ';

        // }
        // cout<<endl;
        
    }

    if(k==n/2){
        return k;
    }
    else if(k<n/2){
        return pivot(myArray,k+1,j,n);
    }
    else{
        return pivot(myArray,i,k-1,n);

    }
    return -1;

}
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
    const int maxSize1{10000000}; // Set a maximum size for the array
    // int myArray[maxSize];
    int arraySize1 = 0;
   

    // Read data from the file into the array
    while (arraySize1 < maxSize1 && inputFile >> myArray[arraySize1]) {
        arraySize1++;
    }
    int arraySize2 = 0;

    // Close the file
    inputFile.close();

    // Display the contents of the array
    cout << "Data read from file and stored in array:" << endl;
    // for (int i = 0; i < arraySize1; ++i) {
    //     cout << myArray[i] << " ";
    // }
    // cout <<endl;

    int midean=pivot(myArray,0,n-1,n-1);




    ofstream outputFile("output.txt");

    // Check if the file is open
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." <<endl;
        return 1; // Exit with an error code
    }

   
    // Write the contents of the array to the output file
    outputFile<<"The midean element is "<<myArray[midean]<<endl; 
    // for (int i = 0; i < arraySize1; ++i) {
    //     outputFile <<myArray[i]<<' ';
    // }
    // cout<<endl;

    // Close the output file
    outputFile.close();

    cout << "Data written to output file." << endl;


    return 0;
}
