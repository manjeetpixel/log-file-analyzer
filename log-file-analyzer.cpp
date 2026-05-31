#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
int main(){
    int error = 0;
    vector<string>errorV;
    int warn = 0;
    vector<string>warnV;
    int fail = 0;
    vector<string>failV;
    int critical = 0;
    vector<string>criticalV;
    int un = 0;
    vector<string>unV;
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
    while(getline(output,line)){
        if(line.find("ERROR") != string::npos){
            errorV.push_back(line);
            error++;
        }
        //warnings
        if(line.find("WARN") != string::npos){
            warnV.push_back(line);
            warn++;
        }
        //fails
        if(line.find("FAILED") != string::npos){
            failV.push_back(line);
            fail++;
        }
        //critical
        if(line.find("CRITICAL") != string::npos){
            criticalV.push_back(line);
            critical++;
        }
        //UNauthrized
        if(line.find("UNAUTHORIZED") != string::npos){
            unV.push_back(line);
            un++;
        }
    }
    if(error != 0){
    report<<"ERRORS: "<<endl;
    cout<<"ERRORS: "<<endl;
    }

    for(int i = 0 ; i < error; i++){
        report<<"Error "<<i+1<<": "<<errorV[i]<<endl;
        cout<<"\e[31m"<<"Error "<<i+1<<": "<<"\e[0m"<<errorV[i]<<endl;
    }
    if(warn != 0){
    report<<"WARNINGS: "<<endl;
    cout<<"WARNINGS: "<<endl;
    }
    for(int w = 0; w <warn; w++){
        report<<"Warning "<<w+1<<": "<<warnV[w]<<endl;
        cout<<"\e[33m"<<"Warning "<<w+1<<": "<<"\e[0m"<<warnV[w]<<endl;
    }

    if(fail != 0){
    report<<"FAILs: "<<endl;
    cout<<"FAILs: "<<endl;
    }
        for(int f = 0; f <fail; f++){
        report<<"Failed: "<<f+1<<": "<<failV[f]<<endl;
        cout<<"\e[35m"<<"failed: "<<f+1<<": "<<"\e[0m"<<failV[f]<<endl;
    }
    if(critical != 0){
        report<<"Criticals: "<<endl;
        cout<<"Criticals: "<<endl;
    }
        for(int c = 0; c <critical; c++){
        report<<"Critical: "<<c+1<<": "<<criticalV[c]<<endl;
        cout<<"\e[34m"<<"Critical: "<<c+1<<": "<<"\e[0m"<<criticalV[c]<<endl;
    }
    if(un !=0 ){
        report<<"Unauthorizeds: "<<endl;
        cout<<"Unauthorizeds: "<<endl;
    }
    for(int u = 0; u <un; u++){
        report<<"Unauthorized: "<<u+1<<": "<<unV[u]<<endl;
        cout<<"\e[36m"<<"Unauthorized: "<<u+1<<": "<<"\e[0m"<<unV[u]<<endl;
    }
    report<<"There are total"<<endl<<"Errors: "<<error<<" "<<endl<<"Warnings: "<<warn<<endl<<" "<<"Fails: "<<fail<<endl<<"Criticals: "<<critical<<endl<<"Unauthorizeds: "<<un<<endl;
    cout<<"There are total"<<endl<<"Errors: "<<error<<" "<<endl<<"Warnings: "<<warn<<endl<<" "<<"Fails: "<<fail<<endl<<"Criticals: "<<critical<<endl<<"Unauthorizeds: "<<un<<endl;
    report.close();
    cout<<"File saved to report.txt";
    return 0;
}
