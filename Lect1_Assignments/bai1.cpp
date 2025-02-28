#include <iostream>
#include <string>

using namespace std;
int main(){
    string s;
    getline(cin,s);
    for(int i = s.length();i>=0;i--){
        cout << s[i];
    }
}