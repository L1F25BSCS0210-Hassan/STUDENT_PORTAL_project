#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

void addStudent(int &count,char NAME[][30],char DEPT[][25],char ID[][25],float CGPA[]);
void showStudent(int count,char NAME[][30],char DEPT[][25],char ID[][25],float CGPA[]);
void searchStudent(int choice,int &count,char searchNAME[],char searchID[],char NAME[][30],char DEPT[][25],char ID[][25],float CGPA[]);
void deptFilter(int &count,char searchDEPT[],char NAME[][30],char DEPT[][25],char ID[][25],float CGPA[]);

int main()
{
    char NAME[25][30];
    char searchNAME[30];
    char DEPT[25][25];
    char searchDEPT[25];
    char ID[25][25];
    char searchID[25];
    float CGPA[50];
    int count=0;
    int choice;
    
    cout<<"Enter 1 to search by NAME...\nEnter 2 to search by ID....\n";
    cin>>choice;
    if(choice==1)
    {
        cout<<"Enter the student's NAME you want to search...\n";
        cin.getline(searchNAME,30);
    }
    else if(choice==2)
    {
        cout<<"Enter the student's ID you want to search...\n";
        cin.getline(searchNAME,30);
    }
    else
    {
        cout<<"Invalid Choice..\n";
    }
    
    
    cout<<"Enter the department according to which you want to filter students: \n";
    cin.getline(searchDEPT,25);
    addStudent(count,NAME,DEPT,ID,CGPA);
    showStudent(count,NAME,DEPT,ID,CGPA);
    searchStudent(choice,count,searchNAME,searchID,NAME,DEPT,ID,CGPA);
    deptFilter(count,searchDEPT,NAME,DEPT,ID,CGPA);
    return 0;
}


void addStudent(int &count,char NAME[][30],char DEPT[][25],char ID[][25],float CGPA[])
{
    char name[50];
    char dept[30];
    char id[25];
    float cgpa;
    int i=0;
    
    cout<<"Enter the student name:\n";
    cin.getline(name,50);
    
    while(name[i]!='\0')
    {
        NAME[count][i]=name[i];
        i++;
    }
    
    NAME[count][i]='\0';
    
    i=0;
    cout<<"Enter student's department:\n";
    cin.getline(dept,30);
    
    while(dept[i]!='\0')
    {
        DEPT[count][i]=dept[i];
        i++;
    }
    DEPT[count][i]='\0';
    
    i=0;
    cout<<"Enter student's ID:\n";
    cin>>id;
    while(id[i]!='\0')
    {
        ID[count][i]=id[i];
        i++;
    }
    ID[count][i]='\0';
    
    cout<<"Enter student's CGPA: \n";
    cin>>cgpa;
    CGPA[count]=cgpa;
    
    count++;
}


void showStudent(int count,char NAME[][30],char DEPT[][25],char ID[][25],float CGPA[])
{
    if(count==0)
    {
        cout<<"No student data to show...\n";
        return;
    }
    
    cout<<"===================STUDENT DATA====================";
    for(int i=0;i<count;i++)
    {
        cout << "\nStudent " << i + 1 << ":\n";
        cout<<fixed;
        cout.width(20);

        cout<<left<<"Student's name ";
        cout<<" : ";
        
        cout<<NAME[i]<<endl;
        cout.width(20);
        cout<<left<<"Student's Department : ";
        
        cout<<DEPT[i]<<endl;
        cout.width(20);
        cout<<left<<"Student's ID ";
        
        cout<<" : ";
        
        cout<<ID[i]<<endl;
        cout.width(20);
        cout<<left<<"Student's CGPA ";
        
        cout<<" : ";
        cout.precision(2);
        cout<<CGPA[i]<<endl;
        cout<<endl;
    }
    cout<<"===================================================";
    cout<<endl;
}

void searchStudent(int choice,int &count,char searchNAME[],char searchID[],char NAME[][30],char DEPT[][25],char ID[][25],float CGPA[])
{
    if(choice==1)
    {
        for(int i=0;i<count;i++)
        {
            if(strcmp(searchNAME,NAME[i])==0)
            {
                cout<<fixed;
                cout.width(20);
        
                cout<<left<<"Student's name ";
                cout<<" : ";
                
                cout<<NAME[i]<<endl;
                cout.width(20);
                cout<<left<<"Student's Department : ";
                
                cout<<DEPT[i]<<endl;
                cout.width(20);
                cout<<left<<"Student's ID ";
                
                cout<<" : ";
                
                cout<<ID[i]<<endl;
                cout.width(20);
                cout<<left<<"Student's CGPA ";
                
                cout<<" : ";
                cout.precision(2);
                cout<<CGPA[i]<<endl;
            }
        }
    }
    
    else if(choice==2)
    {
        
        for(int i=0;i<count;i++)
        {
            if(strcmp(searchID,ID[i])==0)
            {
                cout<<fixed;
                cout.width(20);
        
                cout<<left<<"Student's name ";
                cout<<" : ";
                
                cout<<NAME[i]<<endl;
                cout.width(20);
                cout<<left<<"Student's Department : ";
                
                cout<<DEPT[i]<<endl;
                cout.width(20);
                cout<<left<<"Student's ID ";
                
                cout<<" : ";
                
                cout<<ID[i]<<endl;
                cout.width(20);
                cout<<left<<"Student's CGPA ";
                
                cout<<" : ";
                cout.precision(2);
                cout<<CGPA[i]<<endl;
            }
        }
    }
    else
    {
        cout<<"INVALID CHOICE...\n";
    }
}


void deptFilter(int &count,char searchDEPT[],char NAME[][30],char DEPT[][25],char ID[][25],float CGPA[])
{
    for(int i=0;i<count;i++)
    {
        if(strcmp(searchDEPT,DEPT[i])==0)
        {
            cout<<fixed;
            cout.width(20);
        
            cout<<left<<"Student's name ";
            cout<<" : ";
                
            cout<<NAME[i]<<endl;
            cout.width(20);
            cout<<left<<"Student's Department : ";
                
            cout<<DEPT[i]<<endl;
            cout.width(20);
            cout<<left<<"Student's ID ";
                
            cout<<" : ";
                
            cout<<ID[i]<<endl;
            cout.width(20);
            cout<<left<<"Student's CGPA ";
                
            cout<<" : ";
            cout.precision(2);
            cout<<CGPA[i]<<endl;
        }
    }     
}
