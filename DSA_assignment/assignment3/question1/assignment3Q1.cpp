#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
#include <fstream>
int myArray[10000000];





// sum function for summing two matrices
vector<vector<int>> sum(vector<vector<int>>m1,vector<vector<int>>m2,int op){
    vector<vector<int>>sums;
    if(op==1){
    for(int i=0;i<size(m1);i++){
        vector<int>k;
        for(int j=0;j<size(m1);j++){
            k.push_back(m1[i][j]+m2[i][j]);
        
        }
        sums.push_back(k);
    }}
    else{
        for(int i=0;i<size(m1);i++){
        vector<int>k;
        for(int j=0;j<size(m1);j++){
            k.push_back(m1[i][j]-m2[i][j]);
        
        }
        sums.push_back(k);
    }
        
    }

    return sums;
}
// multiplication function using devide and conquer (strassen method)
vector<vector<int>> multiply(vector<vector<int>>m1,vector<vector<int>>m2){
    vector<vector<int>>ans;
    int n=size(m1);
    int mid=n/2;
    if(n==1){
        ans={{ m1[0][0]*m2[0][0]}};
        return ans;
    }
    vector<vector<int>>A11,A12,A21,A22,B11,B12,B21,B22,P,Q,R,S,T,U,V,C11,C12,C21,C22;
    // A11
    for(int i=0;i<mid;i++){
        vector<int>f;
        for(int j=0;j<mid;j++){
            f.push_back(m1[i][j]);

        }
        A11.push_back(f);
    }
    // A12
    for(int i=0;i<mid;i++){
        vector<int>f;
        for(int j=mid;j<n;j++){
            f.push_back(m1[i][j]);

        }
        A21.push_back(f);
    }
    
    // A21
    for(int i=mid;i<n;i++){
        vector<int>f;
        for(int j=0;j<mid;j++){
            f.push_back(m1[i][j]);

        }
        A12.push_back(f);
    }
    
    // A22
    for(int i=mid;i<n;i++){
        vector<int>f;
        for(int j=mid;j<n;j++){
            f.push_back(m1[i][j]);

        }
        A22.push_back(f);
    }
    // B11
    for(int i=0;i<mid;i++){
        vector<int>f;
        for(int j=0;j<mid;j++){
            f.push_back(m2[i][j]);

        }
        B11.push_back(f);
    }
    // B12
     for(int i=0;i<mid;i++){
        vector<int>f;
        for(int j=mid;j<n;j++){
            f.push_back(m2[i][j]);

        }
        B21.push_back(f);
    }
    
    // B21
    for(int i=mid;i<n;i++){
        vector<int>f;
        for(int j=0;j<mid;j++){
            f.push_back(m2[i][j]);

        }
        B12.push_back(f);
    }
   
    // B22
    for(int i=mid;i<n;i++){
        vector<int>f;
        for(int j=mid;j<n;j++){
            f.push_back(m2[i][j]);

        }
        B22.push_back(f);
    }

    P=multiply(sum(A11,A22,1),sum(B11,B22,1));
    Q=multiply(sum(A21,A22,1),B11);
    R=multiply(A11,sum(B12,B22,0));
    S=multiply(A22,sum(B21,B11,0));
    T=multiply(sum(A11,A12,1),B22);
    U=multiply(sum(A21,A11,0),sum(B11,B12,1));
    V=multiply(sum(A12,A22,0),sum(B21,B22,1));
    C11=sum(sum(P,S,1),sum(T,V,0),0);
    C21=sum(R,T,1);
    C12=sum(Q,S,1);
    C22=sum(sum(P,R,1),sum(Q,U,0),0);

    for(int i=0;i<mid;i++){
        vector<int>l;
        for(int j=0;j<n;j++){
            if(j<mid){
                l.push_back(C11[i][j]);
            }
            else{
                l.push_back(C12[i][j-mid]);
            }
        }
        ans.push_back(l);
    }


    for(int i=mid;i<n;i++){
        vector<int>l;
        for(int j=0;j<n;j++){
            if(j<mid){
                l.push_back(C21[i-mid][j]);
            }
            else{
                l.push_back(C22[i-mid][j-mid]);
            }
        }
        ans.push_back(l);
    }

    return ans;


}

int main() {
    // Open the text file for reading
    ifstream inputFile("input.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error opening file." <<endl;
        return 1; // Exit with an error code
    }

    const int maxSize = 10000000; // Set a maximum size for the array
    // int myArray[maxSize];
    int A,B,C,D;
    inputFile>>A>>B;

    
    


    inputFile>>C>>D;
   



    

    if(B!=C){
        cout<<"ERROR matrices cannot be multiplied"<<endl;
        return 0;
    }


    int padA=pow(2,floor(log2(A))+1);
    int padB=pow(2,floor(log2(B))+1);
    int padC=pow(2,floor(log2(C))+1);
    int padD=pow(2,floor(log2(D))+1);


    int maxpadding=max(max(padA,padB),max(padC,padD));
    vector<vector<int>>m1;
    for(int i=0;i<maxpadding;i++){
        vector<int>af(maxpadding,0);
        m1.push_back(af);

        

    }

    vector<vector<int>>m2;
    for(int i=0;i<maxpadding;i++){
        vector<int>af(maxpadding,0);
        m2.push_back(af);

        

    }

    // Read data from the file into the array
    for(int i=0;i<maxpadding;i++){
        for(int j=0;j<maxpadding;j++){
            if(i<A && j<B){
            inputFile>>m1[i][j];}
            else{
                m1[i][j]=0;
            }
        }
    }
    for(int i=0;i<maxpadding;i++){
        for(int j=0;j<maxpadding;j++){
            if(i<C && j<D){
            inputFile>>m2[i][j];}
            else{
                m2[i][j]=0;
            }
        }
    }

    




    // Close the file
    inputFile.close();

    vector<vector<int>>ans;

    ans=multiply(m2,m1);



    ofstream outputFile("output.txt");

    // Check if the file is open
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." <<endl;
        return 1; // Exit with an error code
    }

   
    // Write the contents of the array to the output file
    for(int i=0;i<A;i++){
        for(int j=0;j<D;j++){
            outputFile<<ans[i][j]<<' ';
        }
        outputFile<<endl;
    }
    

    // Close the output file
    outputFile.close();

    cout << "Data written to output file." << endl;


    return 0;
}
