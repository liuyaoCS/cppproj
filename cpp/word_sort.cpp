#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool test(string& str){
    return str.size() >=3;
}

class GT_cls{
public:
    GT_cls(int val):bound(val){}
    bool operator()(string& s){return s.size() >= bound;}
private:
    int bound;
};

int main(){
    string wd;
    vector<string> words;
    while(cin>>wd){
        words.push_back(wd);
    }
    sort(words.begin(),words.end());
    vector<string>::iterator it=unique(words.begin(),words.end());
    words.erase(it,words.end());

    for(vector<string>::iterator it=words.begin();it!=words.end();it++){
        cout << *it <<" "<<endl;
    }

    // int count = count_if(words.begin(),words.end(),test);
    int count = count_if(words.begin(),words.end(),GT_cls(6));
    cout << count << endl;
}