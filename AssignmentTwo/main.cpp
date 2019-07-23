#include<iostream>
#include "62951718-questionFive.h"
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

int main(){
    ofstream medicalAidFile;
    medicalAidFile.open("MedicalAidData.dat",ios::out);
    ifstream staff;
    staff.open("staff.dat", ios::in);
    string name1;
    int number1=0;
    int nrDependants1=0;
    MedicalAidMembers member;
    string dependant1;
    staff.get()>>name1;
    cout<<name1;
    while (name1.length()){
        number1=rand();
        cout<<name1<<"'s medical aid number is "<<number1<<endl;
        cout<<"How many dependants does this member have? ";
        cin>>nrDependants1;

        member=MedicalAidMembers(name1,number1);

        for(int i=0;i<nrDependants1;i++){
            cout<<"Enter name of dependant: ";
            getline(cin,dependant1);
            member.addDependant(dependant1);
        }
        member.setContribution(nrDependants1*150.55);
        medicalAidFile<<member;
    }
//    member.~MedicalAidMembers();
    return 0;
}
