
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;
int main(){
    int error = 0;
    int warn = 0;
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
    report<<"Here is the report:"<<endl<<endl;
    string line;
    report<<"Errors: "<<endl;
    while(getline(output,line)){
        if(line.find("ERROR") != string::npos){
            report<<"Error "<<error+1<<": ";
            report<<line<<endl;
            error++;
        }
    }
    output.clear(); //here i remove EOF 
    output.seekg(0); // then get the line on top
    report<<"Warnings: "<<endl;
    while(getline(output,line)){
                if(line.find("WARN") != string::npos){
            report<<"warning "<<warn+1<<": ";
            report<<line<<endl;
            warn++;
        }
    }
    report<<"There are total"<<endl<<"Errors: "<<error<<" "<<endl<<"Warnings: "<<warn<<" "<<endl;
    report.close();
    cout<<"File saved to report.txt";
    return 0;
}
