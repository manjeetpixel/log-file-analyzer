#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main(){
    // Creating a map for errortypes
    map<string, vector<string>>logData;
    // Creating color map
    map<string, string> colorMap = {
    {"ERROR", "\e[31m"},
    {"WARN", "\e[33m"},
    {"FAILED", "\e[35m"},
    {"CRITICAL", "\e[34m"},
    {"UNAUTHORIZED", "\e[36m"}
    };
    cout<<"Enter file name: ";
    string file;
    getline(cin,file);
    //reading file
    ifstream output(file);
    if(!output.is_open()){
        cout<<"File Doesn't Exists";
        return 0;
    }
    //save in file
    ofstream report("report.txt");
    report<<"Here is the Report:"<<endl<<endl;
    cout<<"Here is the Report:"<<endl<<endl;
    string line;
    string buffer;
    // Checking through each line from file
    while(getline(output,line)){
        buffer = line;
        transform(buffer.begin(), buffer.end(), buffer.begin(), ::toupper);
        if(buffer.find("ERROR") != string::npos){
            logData["ERROR"].push_back(line);
        }
        //warnings
        if(buffer.find("WARN") != string::npos){
            logData["WARN"].push_back(line);
        }
        //fails
        if(buffer.find("FAILED") != string::npos){
            logData["FAILED"].push_back(line);
        }
        //critical
        if(buffer.find("CRITICAL") != string::npos){
            logData["CRITICAL"].push_back(line);
        }
        //Unauthorized
        if(buffer.find("UNAUTHORIZED") != string::npos){
            logData["UNAUTHORIZED"].push_back(line);
        }
    }
    // Reporting logData
    for(auto &pair : logData){            
    cout<<colorMap[pair.first] << pair.first << ": "<< "\e[0m" << endl;   
    report << pair.first << ": "<<endl;
    for(string line : pair.second){      
        cout << line << endl;
        report << line <<endl;
    }
    }   
    // Looping for count all data
    for (auto &pair : logData){
        cout<<pair.first<<": "<<pair.second.size()<<endl;
        report<<pair.first<<": "<<pair.second.size()<<endl;
    }
    report.close();
    cout<<"File saved to report.txt";
    return 0;
}
