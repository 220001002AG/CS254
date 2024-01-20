#include<iostream>
using namespace std;
#include <fstream>
#include <cstdlib>   // for rand() and srand() functions
#include <ctime>     // for time() function

int generateRandomNumber(int a, int b) {
    srand(time(0));
    int randomNumber = a + rand() % (b - a + 1);
    return randomNumber;
}
int myArray[10000000];

int pivot(int myArray[],int i,int j,int n){

    int mid=generateRandomNumber(i,j);
    // cout<<i<<' '<<mid<<' '<<j<<endl;
   
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
    return k;



}

void Quicksort(int myArray[],int i,int j,int n){
    if(i>=j){
        return ;
    }

    int p=pivot(myArray,i,j,n);
    Quicksort(myArray,i,p-1,n);
    Quicksort(myArray,p+1,j,n);

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

   Quicksort(myArray,0,n-1,n-1);




    ofstream outputFile("output.txt");

    // Check if the file is open
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." <<endl;
        return 1; // Exit with an error code
    }

   
    // Write the contents of the array to the output file
    // outputFile<<"The midean element is "<<myArray[midean]<<endl; 
    for (int i = 0; i < arraySize1; ++i) {
        outputFile <<myArray[i]<<' ';
    }
    cout<<endl;

    // Close the output file
    outputFile.close();

    cout << "Data written to output file." << endl;


    return 0;
}
