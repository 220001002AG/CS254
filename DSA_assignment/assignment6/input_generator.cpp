// #include<iostream>
// using namespace std;
// #include <fstream>


// long int main(){

// ofstream input;
//     input.open("input2.txt",ios::in);
//     long int testcase;
//     testcase = rand()%long int(1e6);
//     input << testcase << endl;
//     while(testcase--){
//         long int num = rand()%10;
//         input << num << endl;
//         input << rand()%10 << endl;//W
//         for(long int i=0;i<num;i++){
//             input << rand()%10 << " ";//v[i]
//         }
//         input << endl;
//         for(long int i=0;i<num;i++){
//             input << rand()%10 << " ";//w[i]
//         }
//         input << endl;
//     }
//     #ifndef ONLINE_JUDGE
// 	    freopen("input2.txt","r",stdin);
// 	    freopen("output2.txt","w",stdout);
//     #endif




// }




#include<iostream>
using namespace std;
#include <fstream>


int main(){

ofstream input;
    input.open("input.txt",ios::in);
    long int testcase;
    testcase = 1;
    // input << testcase << endl;
    
        long int num = 100;
        input << num <<' ';
        input << num << endl;
        input << num << " ";
        input << num << endl;
        // input << rand()%10 << endl;//W
        for(int j=0;j<num;j++){
        for(long int i=0;i<num;i++){
            input << i << " ";//v[i]
        }
            input << endl;}
            input << endl;input << endl;


        for(int j=0;j<num;j++){
        for(long int i=0;i<num;i++){
            if(i==j){
            input << 1 << " ";}
            else{input << 0 << " ";
            }
            }input << endl;}
    
    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
    #endif





}