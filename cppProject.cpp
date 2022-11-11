#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

// Function used to split the marks string and convert into intgers
vector<int> split(string str, char delimiter)
{
    vector<string> internal;
    stringstream ss(str); // Turn the string into a stream.
    string tok;

    while (getline(ss, tok, delimiter))
    {
        internal.push_back(tok);
    }
    vector<int> Data;
    transform(internal.begin(), internal.end(), std::back_inserter(Data),[](const std::string &str){
        return std::stoi(str);
    });
    return Data;
}

class Student
{
private:
    string name;
    string roll_no;
    vector<int> marks;

public:
    void add(string name, string roll_no, string mrks)
    {
        this->name = name;
        this->roll_no = roll_no;
        marks = split(mrks,' ');
        print();
    }

    void print()
    {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << roll_no << endl;
        for (int i = 0; i < marks.size(); i++)
        {
            cout<<marks[i]<<" ";
        }
        
        cout << "\n";
    }

    friend void modify();

}s[20];

void modify(){
    string find;
    cout<<"Enter student name to find: ";
    cin>>find;
    for (int i = 0; i < 20; i++)
    {
        if (s[i].name == find)
        {
            cout<<"Please Select which data you want to Change"<<endl;
            cout<<"1. Name"<<endl;
            cout<<"2. Roll Nummber"<<endl;
            cout<<"2. Marks"<<endl;
            int choose;
            cin>>choose;
            switch (choose)
            {
            case 1:{
                string tempn;
                cout<<"Enter New Name: ";
                cin>>tempn;
                s[i].name = tempn;
                break;
            }
            case 2:{
                string tempr;
                cout<<"Enter New Roll Number: ";
                cin>>tempr;
                s[i].roll_no = tempr;
                break;
            }
            case 3:{
                vector<int> tempm;
                cout<<"Enter Your New Marks: ";
                for (int i = 0; i < 5; i++)
                {
                    int temp;
                    cin>>temp;
                    tempm.push_back(temp);
                }
                s[i].marks = tempm;
                break;
            }
            }
            s[i].print();
        }
    }
}
 
int main()
{
    ifstream readFile("studentData.txt");

    for (int i = 0; i < 20; i++)
    {
        string name, roll_no;
        getline(readFile, name);
        getline(readFile, roll_no);
        string t;
        getline(readFile, t);
        s[i].add(name, roll_no, t);
    }

    modify();

    return 0;
}