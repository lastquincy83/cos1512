#include <iostream>
#include <fstream>
#include <fcntl.h>


using namespace std;

class MedicalAidMembers{
private:
    string name;
    int number;
    int nrDependants;
    string dependants[6];
    double contribution;
public:
    void setContribution(double contribution);

    string getName() ;
    int getNumber() ;

    MedicalAidMembers();
    MedicalAidMembers(string name, int number);
//    ~MedicalAidMembers();
    void addDependant(const string dependant);
    friend ostream& operator<<(ostream& io, MedicalAidMembers medicalAidMember);
};

MedicalAidMembers::MedicalAidMembers() :
        name(""), number(0), dependants({"","","","","",""}), contribution(0), nrDependants(0) {}

MedicalAidMembers::MedicalAidMembers(string name, int number) : name(name), number(number), nrDependants(0),
                                                          dependants({"","","","","",""}), contribution(1000) {}

string MedicalAidMembers::getName() {
    return name;
}

int MedicalAidMembers::getNumber() {
    return number;
}

void MedicalAidMembers::addDependant(const string dependant) {
    if(nrDependants<=6){
        nrDependants+=1;
        dependants->append(dependant);
    }
    else cout<<"Member already has 6 dependants"<<endl;
}

ostream &operator<<(ostream &io, MedicalAidMembers medicalAidMember) {
    io<<medicalAidMember.getName()<<endl;
    io<<medicalAidMember.getNumber()<<endl;
    io<<medicalAidMember.nrDependants<<endl;
    for(int i=0;i<medicalAidMember.dependants->length();i++)
        io<<medicalAidMember.dependants<<endl;
    io<<"R "<<medicalAidMember.contribution<<endl;
}

void MedicalAidMembers::setContribution(double contribution) {
    MedicalAidMembers::contribution = contribution;
}
