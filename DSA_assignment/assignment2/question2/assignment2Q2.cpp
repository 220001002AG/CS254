#include<iostream>
using namespace std;
#include <fstream>
int myArray[10000000];

void merger(int myArray[],int m,int n,int i){
     
    if(m<=i){
        return ;
    }
    if(m>n-1){
        return;
    }


    int c=0;
    int k=m;
    for(int j=i;j<m;j++){
   

        if(myArray[j]<=myArray[k] && myArray[j]<=myArray[k+c]){
            continue;}
        else if(myArray[k]>myArray[k+c] ){
            int ko=myArray[j];
            myArray[j]=myArray[k+c];
            myArray[k+c]=ko;
            c++;}
        else if(myArray[k]<=myArray[k+c] && c==0 ){
            int ko=myArray[j];
            myArray[j]=myArray[k];
            myArray[k]=ko;c++;}
            
             
        else if(myArray[k]<=myArray[k+c]  ){
            int ko=myArray[j];
            myArray[j]=myArray[k];
            for(int point=k;point<k+c-1;point++){
                myArray[point]=myArray[point+1];
            }
            myArray[k+c-1]=ko;
            }}

       

    merger(myArray,k+c,n,m);

    
}
int main() {
    for(int i=0;i<10000000;i++){
        myArray[i]=INT_MAX;

    }
    // Open the text file for reading
    ifstream inputFile("input.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error opening file." <<endl;
        return 1; // Exit with an error code
    }
    int n,m;
    inputFile>>n>>m;
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

    merger(myArray,m,n,0);




    ofstream outputFile("output.txt");

    // Check if the file is open
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." <<endl;
        return 1; // Exit with an error code
    }

   
    // Write the contents of the array to the output file
    for (int i = 0; i < arraySize1; ++i) {
        outputFile <<myArray[i]<<' ';
    }
    cout<<endl;

    // Close the output file
    outputFile.close();

    cout << "Data written to output file." << endl;


    return 0;
}
