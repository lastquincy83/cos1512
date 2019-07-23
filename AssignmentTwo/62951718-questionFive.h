#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class MedicalAidMembers{
public:
    MedicalAidMembers();
    MedicalAidMembers(string , int);
    void setContribution(double );

    string getName() ;
    int getNumber() ;

//    ~MedicalAidMembers();
    void addDependant(const string);
    friend ostream& operator<<(ostream&, MedicalAidMembers);

};

#endif // INTERFACE_H