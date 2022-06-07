#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void CreateBIN(char* fname)
{
    ofstream fout(fname, ios::binary);
    char ch;
    double arr;
    do
    {
        cout << "enter number: "; cin >> arr;
        fout.write((char*)&arr, sizeof(double));
        cout << "continue? (y/n) "; cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

void PrintBIN(char* fname)
{
    ifstream fin(fname, ios::binary);
    double c;
    while (fin.read((char*)&c, sizeof(double)))
    {
        cout << c << endl;
    }
}

bool SqrtCheck(double c)
{
    if (c >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void ProcessBIN(char* fname, char* gname)
{
    ifstream f(fname, ios::binary);
    ofstream g(gname, ios::binary);
    double c;
    while (f.read((char*)&c, sizeof(c)))
    {
        if (!SqrtCheck(c))
            g.write((char*)&c, sizeof(c));
    }
}

int main()
{
    char fname[100];
    char gname[100];
    cout << "enter file name 1: "; cin >> fname;
    CreateBIN(fname);
    PrintBIN(fname);
    cout << "enter file name 2: "; cin >> gname;
    ProcessBIN(fname, gname);
    PrintBIN(gname);
    return 0;
}