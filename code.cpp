#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

void addStudent(int &count,char NAME[][30],char DEPT[][25],char ID[][25],float CGPA[]);
void showStudent(int count,char NAME[][30],char DEPT[][25],char ID[][25],float CGPA[]);
void searchStudent(int choice,int &count,char searchNAME[],char searchID[],char NAME[][30],char DEPT[][25],char ID[][25],float CGPA[]);
void deptFilter(int &count,char searchDEPT[],char NAME[][30],char DEPT[][25],char ID[][25],float CGPA[]);
void grow(int *&arr,int &size);
void shrink(int *&arr,int &size);
int sizer(char *arr);
bool login(ifstream &fin,char *username,char *password,char &role);
void AdminMenu();
void studentMenu(int count, char NAME[][30], char DEPT[][25],char ID[][25],float CGPA[]);


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
    cout<<"=================STUDENTS OF THE DEPT=================\n";
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
            cout<<left<<"Student's ID ";
                
            cout<<" : ";
                
            cout<<ID[i]<<endl;
            cout.width(20);
            cout<<left<<"Student's CGPA ";
                
            cout<<" : ";
            cout.precision(2);
            cout<<CGPA[i]<<endl;
            cout<<"-----------------------------------------\n";
        }
    }     
}

void grow(int *&arr,int &size)
{
    int *temp=new int[size+1];
    for(int i=0;i<size;i++)
    {
        temp[i]=arr[i];
    }
    delete[] arr;
    arr=temp;
    size++;
}


void shrink(int *&arr,int &size)
{
    int *temp=new int[size-11];
    for(int i=0;i<size-1;i++)
    {
        temp[i]=arr[i];
    }
    delete[] arr;
    arr=temp;
    size--;
}

int sizer(char *arr)
{
    int size=0;
    for(int i=0;i!='\0';i++)
    {
        size++;
    }
    return size;
}

bool login(ifstream &fin, char *username, char *password, char &role)
{
    char fileUser[20];
    char filePass[20];
    char fileRole;

    for(int attempt = 3; attempt > 0; attempt--)
    {
        cout << "Enter username: ";
        cin >> username;

        cout << "Enter password: ";
        cin >> password;

        fin.open("users.txt");

        if(!fin)
        {
            cout << "File not found!\n";
            return false;
        }

        bool found = false;

        while(fin >> fileUser >> filePass >> fileRole)
        {
            if(strcmp(username,fileUser)==0 &&
               strcmp(password,filePass)==0)
            {
                found = true;
                role = fileRole;
                break;
            }
        }

        fin.close();

        if(found)
        {
            cout << "LOGIN SUCCESSFUL\n";
            return true;
        }

        cout << "Wrong credentials. Attempts left: "
             << (attempt - 1) << "\n";
    }

    cout << "ACCOUNT HAS BEEN BLOCKED AFTER 3 FAILED ATTEMPTS\n";
    return false;
}

void AdminMenu()
{
    cout << "\n========== ADMIN MENU ==========\n";
    cout << "1. Add Student\n";
    cout << "2. Show All Students\n";
    cout << "3. Search Student\n";
    cout << "4. Filter by Department\n";
    cout << "5. Update Student\n";
    cout << "6. Delete Student\n";
    cout << "7. Logout\n";    
}

void studentMenu(int count, char NAME[][30], char DEPT[][25],char ID[][25],float CGPA[])
{
    char searchID[25];
    int choice;

    cout << "Enter your ID: ";
    cin >> searchID;

    int pos = -1;

    for(int i = 0; i < count; i++)
    {
        if(strcmp(searchID, ID[i]) == 0)
        {
            pos = i;
            break;
        }
    }

    if(pos == -1)
    {
        cout << "Record not found!\n";
        return;
    }

    do
    {
        cout << "\n===== STUDENT PORTAL =====\n";
        cout << "1. View GPA\n";
        cout << "2. View Attendance\n";
        cout << "3. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Your GPA is: " << CGPA[pos] << endl;
                break;

            case 2:
                cout << "Your attendance is"<< ".\n";
                break;

            case 3:
                cout << "Logging out...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while(choice != 3);
}
