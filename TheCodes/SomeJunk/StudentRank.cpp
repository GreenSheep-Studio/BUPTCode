#include <iostream>
using namespace std;

class student//声明类
{
private:
    char m_name[10];
    int m_math;
    int m_physics;
public:
    void setStudent(){
        cin >> m_name;
        cin >> m_math;//输入数学成绩   
        cin >> m_physics;//输入物理成绩
    }
    char* getName(){
        return m_name;
    }
    int getMath(){
        return m_math;
    }
    int getPhysics(){
        return m_physics;
    }
    int getTotalscore(){
        return m_math + m_physics;//返回总成绩
    }
    void sortTotalscore(student* students,int n){
        int flag=0;
        for(int i=1;i<n;i++){
            flag=((students+flag)->getTotalscore() < (students+i)->getTotalscore())?flag:i;           
        }
        cout << (students+flag)->getName() << " " << (students+flag)->getTotalscore() << endl;     
    }
};

int main()
{
    student students[4];
    for(int i=0;i<4;i++){
    students[i].setStudent();//调用设置成绩函数
    }
    students[0].sortTotalscore(students,4);
    system("PAUSE");
    return 0;
}