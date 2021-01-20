#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

ifstream& open_file(ifstream& in,const string& file){
    in.close();
    in.clear();
    in.open(file.c_str());
    return in;
}
int main(int argc,char **argv){
    map<string,string> trans_map;
    string key,value;
    ifstream map_file,input;
    string line;

    if(argc != 3)
        throw runtime_error("argc should be 3");
    if(!open_file(map_file,argv[1]))
        throw runtime_error("open map file error");
    if(!open_file(input,argv[2]))
        throw runtime_error("open trans file error");


    while(map_file >> key >> value){
        trans_map.insert(make_pair(key,value));
    }
  
    while(getline(input,line)){
        istringstream stream(line);
        string word;
        while(stream >> word){
            map<string,string>::iterator it = trans_map.find(word);
            if(it!=trans_map.end()){
                cout <<it->second << " ";
            }
        }
        cout << endl;
    }
}
