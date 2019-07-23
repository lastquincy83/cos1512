#include<iostream>

using namespace std;

class Module {
    private:
        string moduleName;
        string moduleCode;
        string lecturer;
        int nrStudents;

    public:
        Module(){
            moduleName="";
            moduleCode="0000000";
            lecturer="";
            nrStudents=0;
        }

        Module(string modName, string modCode, string lect, int modnrStudents){
            moduleName=modName;
            moduleCode=modCode;
            lecturer=lect;
            nrStudents=modnrStudents;
        }

        void setModuleName(string modName);
        void setModuleCode(string modCode);
        void setLecturer(string lect);
        void setnrStudents(int modnrStudents);

        string getModuleName();
        string getModuleCode();
        string getLecturer();
        int getnrStudents();
};

void Module::setModuleName(string moduleName){
    moduleName = moduleName;
}

void Module::setModuleCode(string modCode){
    moduleCode = modCode;
}

void Module::setLecturer(string lect){
    lecturer = lect;
}

void Module::setnrStudents(int modnrStudents){
    nrStudents = modnrStudents;
}

string Module::getModuleName(){
    return moduleName;
}

string Module::getModuleCode(){
    return moduleCode;
}

string Module::getLecturer(){
    return lecturer;
}

int Module::getnrStudents(){
    return nrStudents;
}

void questionOne(){
    string moduleName;
    string moduleCode;
    string lecturer;
    int nrStudents;

    cout<<"Module name: ";
    getline(cin, moduleName);
    cout<<"Module code: ";
    getline(cin, moduleCode);
    cout<<"Lecturer: ";
    getline(cin, lecturer);
    cout<<"Number of students: ";
    cin>>nrStudents;

    Module module = Module(moduleName, moduleCode, lecturer, nrStudents);

    cout<<"Output: "<<endl;
    cout<<"Module name: "<<module.getModuleName()<<endl;
    cout<<"Module code: "<<module.getModuleCode()<<endl;
    cout<<"Lecturer: "<<module.getLecturer()<<endl;
    cout<<"Number of students: "<<module.getnrStudents()<<endl;
}
