#include <iostream>

using namespace std;

int main(){
    int a,b;
    cin >> a;
    cin >> b;
    cout << "a:" << a << "  b:" << b << endl;
    int c = a >> b;
    cout << "ret:" << c << endl;
    return 0;
}