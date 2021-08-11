#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

class Student
{
public:
    int rollNo;
    char name[20], division, address[20];
    // constructor of class student
    Student()
    {
        rollNo = 0;
        strcpy(name, "NULL");
        division = 'N';
        strcpy(address, "NULL");
    }

    void setStudent(int, int);
    void displayStudent();
};

// this function is used to take input from user
void Student::setStudent(int r, int choice)
{
    if (choice == 2)    // this part will run when we are trying to modify the contents
    {
        cout << "\nEnter Student Data: ";
        rollNo = r;
        cout << "\nName: ";
        cin >> name;
        cout << "Division: ";
        cin >> division;
        cout << "Address: ";
        cin >> address;
        return;
    }
    cout << "\nEnter Student Data:";
    cout << "\nRoll Number: ";
    cin >> rollNo;
    cout << "Name: ";
    cin >> name;
    cout << "Division: ";
    cin >> division;
    cout << "Address: ";
    cin >> address;
}

// this function is used to display student data
void Student::displayStudent()
{
    cout << rollNo << "\t" << name << "\t\t" << division << "\t\t" << address << endl;
}


class Files
{
private:
    char fileName[20];
    char tempFileName[20];

public:
    // constructor of class files
    Files()
    {
        strcpy(fileName, "StudentData.txt");
        strcpy(tempFileName, "TempStudent.txt");
    }

    void createFile();
    void displayFile();
    int searchData(int);
    bool deleteData(int);
    void modifyData(int);
};

// this function is used to create a file
void Files::createFile()
{
    ofstream out;
    Student S;
    out.open(fileName, ios::app);
    S.setStudent(0, 1);
    out.write((char *)&S, sizeof(S));
    out.close();
}

// this function is used to display a file
void Files::displayFile()
{
    ifstream in;
    Student S;
    in.open(fileName);

    in.read((char *)&S, sizeof(S));
    if (!in)
    {
        cout << "Error! File Not Found";
        return;
    }

    cout << "\nRoll No\tStudent\t\tDivision\tAddress\n";
    while (!in.eof())
    {
        S.displayStudent();
        in.read((char *)&S, sizeof(S));
    }
    in.close();
}

// this function is used to search data in a file
int Files::searchData(int r)
{
    Student s;
    ifstream in;
    in.open(fileName);
    if (!in)
    {
        cout << "Error! File Not Found!\n";
        return -1;
    }
    in.read((char *)&s, sizeof(s));
    while (in.eof() == 0)
    {
        if (r == s.rollNo)
        {
            in.close();
            return 1;
        }
        in.read((char *)&s, sizeof(s));
    }
    in.close();
    return 0;
}

// this function is used to delete a content from a file
bool Files::deleteData(int roll)
{
    ifstream in;
    ofstream out;
    Student S;
    int flag = 0;
    in.open(fileName);
    out.open(tempFileName);
    if (!in)
    {
        cout << "Error! File Not Found";
        return false;
    }
    in.read((char *)&S, sizeof(S));
    while (!in.eof())
    {
        if (roll == S.rollNo)
        {
            S.displayStudent();
            flag = 1;
        }
        else
            out.write((char *)&S, sizeof(S));
        in.read((char *)&S, sizeof(S));
    }
    in.close();
    out.close();
    remove(fileName);
    rename(tempFileName, fileName);
    if (flag == 0)
    {
        cout << "Record for Roll No. " << roll << " not found! \n";
        return false;
    }
    else
    {
        cout << "\nRecord Deleted Successfully!\n";
        return true;
    }
}

// this function is used to modify contents of the file
void Files::modifyData(int roll)
{
    ifstream in;
    ofstream out;
    Student S;
    int flag = 0;
    in.open(fileName);
    out.open(tempFileName);
    if (!in)
    {
        cout << "Error! File Not Found";
        return;
    }
    in.read((char *)&S, sizeof(S));
    while (!in.eof())
    {
        if (roll == S.rollNo)
        {
            S.displayStudent();
            cout << "\nEnter data to modify: ";
            S.setStudent(roll, 2);
            flag = 1;
        }
        out.write((char *)&S, sizeof(S));
        in.read((char *)&S, sizeof(S));
    }
    if (flag == 0)
        cout << "Record for Roll No. " << roll << " not found!\n";
    else
        cout << "Record Modified Successfully!\n";
    in.close();
    out.close();
    remove(fileName);
    rename(tempFileName, fileName);
}

int main()
{
    int choice, searchRollNo;
    Files obj;
    do
    {
        cout << endl;
        cout << "1) Create a File\n";
        cout << "2) Display contents of File\n";
        cout << "3) Search contents of File\n";
        cout << "4) Delete contents of File\n";
        cout << "5) Modify contents of File\n";
        cout << "Press 0 to exit\n";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << endl;
            cout << "Exiting...\n";
            cout << endl;
            break;
        case 1:
            cout << endl;
            obj.createFile();
            cout << endl;
            break;
        case 2:
            cout << endl;
            obj.displayFile();
            cout << endl;
            break;
        case 3:
            cout << endl;
            cout << "Enter the Roll No you want to search: ";
            cin >> searchRollNo;
            if (obj.searchData(searchRollNo))
            {
                cout << "Record Found\n";
            }
            else
            {
                cout << "Error! Record Not Found\n";
            }
            cout << endl;
            break;
        case 4:
            cout << endl;
            cout << "Enter Roll No: ";
            cin >> searchRollNo;
            obj.deleteData(searchRollNo);
            cout << endl;
            break;
        case 5:
            cout << endl;
            cout << "Enter Roll No: ";
            cin >> searchRollNo;
            obj.modifyData(searchRollNo);
            cout << endl;
            break;
        default:
            cout << "Invalid Input\n";
            break;
        }
    } while (choice != 0);
    return 0;
}
