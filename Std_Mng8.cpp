#include <iostream>
#include <string>
#include <limits>
#include <cstring>

using namespace std;

class Department{
protected:
    int noStudents;
    int* totalMarks;
    string* studentNames;
    string* studentRegNos;
    int** studentMarks;
    char sub[5][50];

public:
    Department();
    ~Department();
    void enterDetails();
    void printStudentMarks(int studentIndex);
    void totalMarksFunc(int a);
    void findHighestScorer();
    void printStudentList();

    int getNoStudents() const { return noStudents; }
    int getTotalMarks(int index) const { return totalMarks[index]; }
    string getStudentName(int index) const { return studentNames[index]; }
    string getStudentRegNo(int index) const { return studentRegNos[index]; }
};

Department::Department(){
    noStudents=0;
    totalMarks=NULL;
    studentNames=NULL;
    studentRegNos=NULL;
    studentMarks=NULL;
}

Department::~Department(){
    delete[] totalMarks;
    delete[] studentNames;
    delete[] studentRegNos;
    for(int i=0;i<noStudents;++i){
        delete[] studentMarks[i];
    }
    delete[] studentMarks;
}

void Department::enterDetails(){
    cout<<"Enter the number of students: ";
    cin>>noStudents;

    totalMarks=new int[noStudents];
    studentNames=new string[noStudents];
    studentRegNos=new string[noStudents];
    studentMarks=new int*[noStudents];

    for(int j=0;j<noStudents;j++){
        studentMarks[j]=new int[5];
        cout<<"Enter details for student "<<j+1<<":"<<endl;
        cin.ignore();
        cout<<"Enter your name: ";
        getline(cin,studentNames[j]);
        cout<<"Enter your registration no.: ";
        getline(cin,studentRegNos[j]);
        cout<<"Enter your marks: "<<endl;
        for(int i=0;i<5;i++){
            do{
                cout<<i+1<<". "<<sub[i]<<" (out of 100): ";
                cin>>studentMarks[j][i];
                if(studentMarks[j][i]>100){
                    cout<<"Invalid input. Please enter a value less than or equal to 100."<<endl;
                }
            }while(studentMarks[j][i]>100);
        }
        totalMarksFunc(j);
    }
}

void Department::printStudentMarks(int studentIndex){
    if(studentIndex<0||studentIndex>=noStudents){
        cout<<"Invalid student index!"<<endl;
        return;
    }
    cout<<"Your received marks are:"<<endl;
    for(int i=0;i<5;i++){
        cout<<i+1<<". "<<sub[i]<<": "<<studentMarks[studentIndex][i]<<endl;
    }
}

void Department::totalMarksFunc(int a){
    int sum=0;
    for(int i=0;i<5;i++){
        sum+=studentMarks[a][i];
    }
    totalMarks[a]=sum;
    cout<<"Total: "<<sum<<endl;
}

void Department::findHighestScorer(){
    if(noStudents==0){
        cout<<"No students available."<<endl;
        return;
    }
    int highestIndex=0;
    for(int i=1;i<noStudents;i++){
        if(totalMarks[i]>totalMarks[highestIndex]){
            highestIndex=i;
        }
    }
    cout<<"\nDetails of student with highest marks:\n";
    cout<<"Total Marks: "<<totalMarks[highestIndex]<<endl;
    cout<<"Name: "<<studentNames[highestIndex]<<endl;
    cout<<"Registration No.: "<<studentRegNos[highestIndex]<<endl;
    cout<<"Marks:\n";
    for(int i=0;i<5;i++){
        cout<<sub[i]<<": "<<studentMarks[highestIndex][i]<<endl;
    }
}

void Department::printStudentList(){
    cout<<"Name                "<<"Registration No.    "<<"Total Marks"<<endl;
    for(int i=0;i<noStudents;i++){
        cout<<studentNames[i];
        for(int j=studentNames[i].length();j<20;j++)cout<<' ';
        cout<<studentRegNos[i];
        for(int j=studentRegNos[i].length();j<20;j++)cout<<' ';
        cout<<totalMarks[i]<<endl;
    }
}

class CSE:public Department{
public:
    CSE(){
        strcpy(sub[0],"DSA");
        strcpy(sub[1],"TOC");
        strcpy(sub[2],"Data Comm");
        strcpy(sub[3],"Maths");
        strcpy(sub[4],"OOPs");
    }
};

class EE:public Department{
public:
    EE(){
        strcpy(sub[0],"Circuits");
        strcpy(sub[1],"EMF");
        strcpy(sub[2],"Power Systems");
        strcpy(sub[3],"Maths");
        strcpy(sub[4],"Control Systems");
    }
};

class ECE:public Department{
public:
    ECE(){
        strcpy(sub[0],"Signals");
        strcpy(sub[1],"Networks");
        strcpy(sub[2],"Digital Comm");
        strcpy(sub[3],"Maths");
        strcpy(sub[4],"VLSI");
    }
};

class ME:public Department{
public:
    ME(){
        strcpy(sub[0],"Thermo");
        strcpy(sub[1],"Fluid Mech");
        strcpy(sub[2],"Dynamics");
        strcpy(sub[3],"Maths");
        strcpy(sub[4],"Manufacturing");
    }
};

class CE:public Department{
public:
    CE(){
        strcpy(sub[0],"Structures");
        strcpy(sub[1],"Geotech");
        strcpy(sub[2],"Transport");
        strcpy(sub[3],"Maths");
        strcpy(sub[4],"Hydraulics");
    }
};

void printOverallTopper(CSE& cse,ECE& ece,ME& me,CE& ce,EE& ee){
    string topStudentName="";
    string topStudentRegNo="";
    int topMarks=-1;
    string department="";

    for(int i=0;i<cse.getNoStudents();i++){
        if(cse.getTotalMarks(i)>topMarks){
            topMarks=cse.getTotalMarks(i);
            topStudentName=cse.getStudentName(i);
            topStudentRegNo=cse.getStudentRegNo(i);
            department="CSE";
        }
    }

    for(int i=0;i<ece.getNoStudents();i++){
        if(ece.getTotalMarks(i)>topMarks){
            topMarks=ece.getTotalMarks(i);
            topStudentName=ece.getStudentName(i);
            topStudentRegNo=ece.getStudentRegNo(i);
            department="ECE";
        }
    }

    for(int i=0;i<me.getNoStudents();i++){
        if(me.getTotalMarks(i)>topMarks){
            topMarks=me.getTotalMarks(i);
            topStudentName=me.getStudentName(i);
            topStudentRegNo=me.getStudentRegNo(i);
            department="ME";
        }
    }

    for(int i=0;i<ce.getNoStudents();i++){
        if(ce.getTotalMarks(i)>topMarks){
            topMarks=ce.getTotalMarks(i);
            topStudentName=ce.getStudentName(i);
            topStudentRegNo=ce.getStudentRegNo(i);
            department="CE";
        }
    }

    for(int i=0;i<ee.getNoStudents();i++){
        if(ee.getTotalMarks(i)>topMarks){
            topMarks=ee.getTotalMarks(i);
            topStudentName=ee.getStudentName(i);
            topStudentRegNo=ee.getStudentRegNo(i);
            department="EE";
        }
    }

    cout<<"\nOverall Topper:\n";
    cout<<"Name: "<<topStudentName<<endl;
    cout<<"Registration No.: "<<topStudentRegNo<<endl;
    cout<<"Department: "<<department<<endl;
    cout<<"Total Marks: "<<topMarks<<endl;
}

int main(){
    CSE cse;
    ECE ece;
    ME me;
    CE ce;
    EE ee;
    int choice;
    do{
        cout<<"\nMain Menu\n";
        cout<<"1. Enter Details\n";
        cout<<"2. Find Highest Scorer\n";
        cout<<"3. Print Student List\n";
        cout<<"4. Print Overall Topper\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:{
                int deptChoice1;
                do{
                    cout<<"\nSelect Department\n";
                    cout<<"1. CSE\n";
                    cout<<"2. ECE\n";
                    cout<<"3. ME\n";
                    cout<<"4. CE\n";
                    cout<<"5. EE\n";
                    cout<<"6. Exit\n";
                    cout<<"Enter your choice: ";
                    cin>>deptChoice1;
                    switch(deptChoice1){
                        case 1:
                            cse.enterDetails();
                            break;
                        case 2:
                            ece.enterDetails();
                            break;
                        case 3:
                            me.enterDetails();
                            break;
                        case 4:
                            ce.enterDetails();
                            break;
                        case 5:
                            ee.enterDetails();
                            break;
                        case 6:
                            cout<<"Exiting...\n";
                            break;
                        default:
                            cout<<"Invalid choice. Please try again.\n";
                    }
                }while(deptChoice1!=6);
                break;
            }
            case 2:{
                int deptChoice2;
                do{
                    cout<<"\nSelect Department\n";
                    cout<<"1. CSE\n";
                    cout<<"2. ECE\n";
                    cout<<"3. ME\n";
                    cout<<"4. CE\n";
                    cout<<"5. EE\n";
                    cout<<"6. Exit\n";
                    cout<<"Enter your choice: ";
                    cin>>deptChoice2;
                    switch(deptChoice2){
                        case 1:
                            cse.findHighestScorer();
                            break;
                        case 2:
                            ece.findHighestScorer();
                            break;
                        case 3:
                            me.findHighestScorer();
                            break;
                        case 4:
                            ce.findHighestScorer();
                            break;
                        case 5:
                            ee.findHighestScorer();
                            break;
                        case 6:
                            cout<<"Exiting...\n";
                            break;
                        default:
                            cout<<"Invalid choice. Please try again.\n";
                    }
                }while(deptChoice2!=6);
                break;
            }
            case 3:{
                int deptChoice3;
                do{
                    cout<<"\nSelect Department\n";
                    cout<<"1. CSE\n";
                    cout<<"2. ECE\n";
                    cout<<"3. ME\n";
                    cout<<"4. CE\n";
                    cout<<"5. EE\n";
                    cout<<"6. Exit\n";
                    cout<<"Enter your choice: ";
                    cin>>deptChoice3;
                    switch(deptChoice3){
                        case 1:
                            cse.printStudentList();
                            break;
                        case 2:
                            ece.printStudentList();
                            break;
                        case 3:
                            me.printStudentList();
                            break;
                        case 4:
                            ce.printStudentList();
                            break;
                        case 5:
                            ee.printStudentList();
                            break;
                        case 6:
                            cout<<"Exiting...\n";
                            break;
                        default:
                            cout<<"Invalid choice. Please try again.\n";
                    }
                }while(deptChoice3!=6);
                break;
            }
            case 4:
                printOverallTopper(cse,ece,me,ce,ee);
                break;
            case 5:
                cout<<"Exiting program...\n";
                break;
            default:
                cout<<"Invalid choice. Please try again.\n";
        }
    }while(choice!=5);
    return 0;
}

