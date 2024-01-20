#include<iostream>
using namespace std;
#include <fstream>
int myArray[10000000];
int corrector(int n,int i){
    if(i>n-1){
        return INT_MAX;
    }
    return myArray[i];
    
}
void merger(int myArray[],int m,int n,int i){
    if(m<=i){
        return ;
    }
    if(m>n-1){
        return;
    }

    // if(n-1==m && i==m-1){
    //     if(myArray[i]>myArray[m]){
    //         int y=myArray[i];
    //         myArray[i]=myArray[m];
    //         myArray[m]=y;


    //          for(int o=i;o<n;o++){
    //         cout<<myArray[o]<<' ';
    //     }
    //     cout<<endl;   


    //         return;

    //     }
    //     return;
        
    // }
    int c=0;
    int k=m;
    for(int j=i;j<m;j++){
        

        if(myArray[j]<=myArray[k] && myArray[j]<=corrector(n,k+c)){
            continue;}
        else if(myArray[k]>corrector(n,k+c) ){
            int ko=myArray[j];
            myArray[j]=myArray[k+c];
            myArray[k+c]=ko;
            c++;}
        else if(myArray[k]<=corrector(n,k+c) && c==0 ){
            int ko=myArray[j];
            myArray[j]=myArray[k];
            myArray[k]=ko;c++;}
            
             
        else if(myArray[k]<=corrector(n,k+c) ){
            int ko=myArray[j];
            myArray[j]=myArray[k];
            for(int point=k;point<k+c-1;point++){
                myArray[point]=myArray[point+1];
            }
            myArray[k+c-1]=ko;
            }}

//    cout<<"after"<<endl;
//              for(int o=i;o<n;o++){
//             cout<<myArray[o]<<' ';
//         }
//         cout<<endl;       
    merger(myArray,k+c,n,m);

    
}
void mergesort(int myArray[], int start, int end){
    int mid=start+(end-start)/2;
    if(start==end){
        return;
    }
    mergesort(myArray,start,mid);
    mergesort(myArray,mid+1,end);
    merger(myArray,mid+1,end+1,start);
    
}
int main() {
    // Open the text file for reading
      for(int i=0;i<10000000;i++){
        myArray[i]=INT_MAX;

    }
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

    mergesort(myArray,0,n-1);




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
