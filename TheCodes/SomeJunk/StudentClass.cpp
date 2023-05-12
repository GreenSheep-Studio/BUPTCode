#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class student
{
public:
    void Print(string s, string n, int a){
        school = s;
        name = n;
        age = a;
        cout << school << "大学的" << name << "年龄" << age;
    }
protected:
    string school = "MIT";
    string name = "Kate";
    int age = 20;
};

class G_student : public student
{
public:
    void Print(string s, string n, int a, string g)
    {
        school = s;
        name = n;
        age = a;
        G_name = g;
        student::Print(school, name, age);
        cout << "导师是" << G_name <<endl;
    }
private:
    string G_name = "Smith";
};

int main ()
{
    G_student s1;
    string s;
    string n;
    int a;
    string g;
    cin >> s >> n >> a >> g;
    s1.Print(s, n, a, g);
    system("PAUSE");
    return 0;
}