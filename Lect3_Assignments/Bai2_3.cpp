#include<iostream>

using namespace std;
double bitleft(int n){
    double result;
    if(n>=0){
        result = 1 << n; //Khi n không âm dịch bit trái của 1 n lần tương đương với 2^n
    }
    else{
        result = 1 << -(n);// Khi n âm dịch bit trái của 1 |n| lần tính được 2^|n|
        result = 1/result;// Tính nghịch đảo của 2^|n| để tính 2^n
    }
    return result;
}
int main(){
    int n;
    cin>> n;
    cout << bitleft(n);
    return 0;
}    
