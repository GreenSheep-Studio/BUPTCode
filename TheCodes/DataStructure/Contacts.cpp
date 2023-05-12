///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//          这是一个可以实现简单通讯录的程序，是本人自主完成开发的，可能会存在很多不足                           //
//                                 2023.3.31  第一次开始开发                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include<cstdlib>
#include <cstring>
using namespace std;

//-----------成员节点---------------------------------------------------------------------------------------------------------------------------------------------

struct Person{
    int ID;            //编号
    string Name;        //姓名
    string Gender;     //性别
    string Num;         //电话号码
    string Addr;         //地址
    Person * next;       //链表指针
};

//-----------创建一个通信录类，以链表形式存储---------------------------------------------------------------------------------------------------------------------------------

class Contacts{
protected:
    Person * front;
public:
    Contacts();           //构造
    ~Contacts();             //析构
    void ShowList();       //展示
    void AddPerson();          //添加
    Person * DeletePerson(string);         //删除
    Person * SearchPerson(string);        //查找
    Person * EditPerson(string);             //编辑
};

//-----------构造函数，且建立链表以存入联系人---------------------------------------------------------------------------------------------------------------------------------------------

Contacts::Contacts(){
    front  = new Person;
    Person * s = front;
    char x;
    int i;
    cout << "Now You Should Enter Some Informations To Setup Your New Contacts --" <<endl;
    cout << "TheID TheName TheGender ThePhoneNumber TheAddress like:"<< endl <<  "1111 Tom man 17722254040 N303" <<endl;
    while(1){
        s ->next = new Person;
        s = s ->next;
        cin >> s ->ID >> s ->Name >> s ->Gender >> s ->Num >> s ->Addr;
        cout << "Continue To Add More Person?(Y or N)" << endl;
        cin >> x;
        if (x == 'N') break;
        else if (x == 'Y')
            cout << "Enter The Information Of The Person You Want To Add:" << endl;
            i++;
    }
    s ->next = NULL;
    cout << "Now Is Loading Your New Contact,Please Wait a Moment..." << endl;
    //sleep(3);
    cout << "Now Is Building The List..." << endl;
    //sleep(7);
    cout << "Final Preparations Are Being Made..." << endl;
    //sleep(4);
    system("cls");
}

//------------展示通讯录中的成员-------------------------------------------------------------------------------------------------------------------

void Contacts::ShowList(){
    Person * p = front ->next;
    while (p){
        cout << p ->ID << " " << p ->Name << " " << p ->Gender << " " << p ->Num << " " << p ->Addr << endl;
        p = p ->next;
    }
    system("PAUSE");
}

//------------添加联系人的操作--------------------------------------------------------------------------------------------------------------------------------------------

void Contacts::AddPerson(){
    Person * s = front;
    char x;
    cout << "Enter The Information Of The Person You Want To Add:" << endl;
    while (1){
        while (s ->next)
            s = s ->next;
        s ->next = new Person;
        s = s ->next;
        cin >> s ->ID >> s ->Name >> s ->Gender >> s ->Num >> s ->Addr;
        s ->next = NULL;
        cout << "Continue To Add More Person?(Y or N)" << endl;
        cin >> x;
        if (x == 'N') break;
    }
}

//-------------删除联系人操作-------------------------------------------------------------------------------------------------------------------------------------------

Person * Contacts::DeletePerson(string s){
    Person * p = front;
    while (p ->next){
        if ((p ->next) ->Name == s) {
            Person * q = p ->next;
            p ->next = p ->next ->next;
            delete q;
            cout << s << " Has Been Deleted Successfully" <<endl;
            cout << "Please Wait For 5 Seconds" << endl;
            sleep(5);
            return p;
        }
        else p = p ->next;
    }
    cout << "No Answer" <<endl;
    system("PAUSE");
    return p;
}

//-------------查找联系人操作-------------------------------------------------------------------------------------------------------------------------------------------

Person * Contacts::SearchPerson(string s){
    char x;
    Person * p = front;
    while (p){
        if (p ->Name == s){
            cout << p ->ID << " " << p ->Name << " " << p ->Gender << " " << p ->Num << " " << p ->Addr << endl;
            system("PAUSE");
            return p;
        }
        else
            p = p ->next;
    }
    cout << "No Answer" << endl;
    cout << "Would You Want To Add This Person Into Your Contacts?(Y or N)" << endl;
    cin >> x;
    if (x == 'Y') AddPerson();
    else if (x == 'N')
        sleep(3);
        return p;
}

//--------------编辑联系人操作------------------------------------------------------------------------------------------------------------------------------------------

Person * Contacts::EditPerson(string s){
    Person r;
    char x;
    Person * p = front;
    while (p){
        if (p ->Name == s){
            cout << "Enter The Information Of The Person After Modifying:" << endl;
            cin >> r.ID >> r.Name >> r.Gender >> r.Num >> r.Addr;
            p ->ID = r.ID;
            p ->Name = r.Name;
            p ->Gender = r.Gender;
            p ->Num = r.Num;
            p ->Addr = r.Addr;
            system("PAUSE");
            return p;
        }
        p = p ->next;
    }
    cout << "No Answer" << endl;
    cout << "Would You Want To Add This Person Into Your Contacts?(Y or N)" << endl;
    cin >> x;
    if (x == 'Y') AddPerson();
    else if (x == 'N')
        sleep(3);
        return p;
}

//--------------析构函数，用于清除数据-----------------------------------------------------------------------------------------------------------------------------------------

Contacts::~Contacts(){
    while (front){
        Person * p = front;
        front = front ->next;
        delete p;
    }
}

//---------------黑名单子类----------------------------------------------------------------------------------------------------------------------------------------------------------

class BlackList : public Contacts{
private:
    Person * Bhead;
public:
    BlackList();
    ~BlackList();
    void AddBlack();
    void ShowBlack();
};

BlackList::BlackList(){
    Bhead = new Person;
    Bhead ->next = NULL;
}

void BlackList::AddBlack(){
    string s;
    char x;
    cin >> s;
    Person * p = front;
    Person * q = Bhead;
    while (p){
        if (p ->Name == s){
            while (1){
                Person * q = new Person;
                q ->next = Bhead ->next;
                q ->ID = p ->ID;
                q ->Name = p ->Name;
                q ->Gender = p ->Gender;
                q ->Num = p ->Num;
                q ->Addr = p ->Addr;
                Bhead ->next = q;
                DeletePerson(s);
                cin >> x;
                if (x == 'N') break;
            }
        }
        p = p ->next;
    }
}

void BlackList::ShowBlack(){
    Person * s = Bhead;
    while (s)
    {
        cout << s ->ID << s ->Name <<s ->Gender << s ->Num << s ->Addr << endl;
        s = s ->next;
    }
    sleep(20);
}

BlackList::~BlackList(){
    while (Bhead){
        Person * p = Bhead;
        Bhead = Bhead ->next;
        delete p;
    }
}


//-----------展示菜单---------------------------------------------------------------------------------------------------------------------------------------------

void Menu(){
    cout << "(````````````````M E N U``````````````````)" << endl;
    cout << ".=========================================." << endl;
    cout << "|            1.SHOW THE LIST              |" << endl;
    cout << "+-----------------------------------------+" << endl;
    cout << "|           2.SEARCH THE PERSON           |" << endl;
    cout << "+-----------------------------------------+" << endl;
    cout << "|            3.ADD NEW PERSON             |" << endl;
    cout << "+-----------------------------------------+" << endl;
    cout << "|           4.DELETE THE PERSON           |" << endl;
    cout << "+-----------------------------------------+" << endl;
    cout << "|           5.MODIFY THE PERSON           |" << endl;
    cout << "+-----------------------------------------+" << endl;
    cout << "|                6.EXIT                   |" << endl;
    cout << ".=========================================." << endl;
    cout << "*********** Form Of Information: **********" << endl;
    cout << "*****ID Name Gender PhoneNumber Address****" << endl;
    cout << "      Select The Option Your Want To Do:   " << endl;
}

//---------主函数，用于调试-----------------------------------------------------------------------------------------------------------------------------------------------

int main ()
{
    BlackList Cont;
    int n;
    string s;
    while (1){
        system("cls");
        Menu();
        cin >> n;
        switch (n){
            case 1:
                Cont.ShowList();
                break;
            case 2:    
                cout << "Enter The Name Of The Person You Want To Search:" << endl;
                cin >> s;
                Cont.SearchPerson(s);
                break;
            case 3:
                Cont.AddPerson();
                break;
            case 4:  
                cout << "Enter The Name Of The Person You Want To Delete:" << endl;
                cin >> s;
                Cont.DeletePerson(s);
                break;
            case 5:
                cout << "Enter The Name Of The Person You Want To Modify:" << endl;
                cin >> s;
                Cont.EditPerson(s);
                break;
            case 6:
                cout << "Please Wait For A Moment..." << endl;
                sleep(5); 
                return 0;
                break;
            case 7:
                Cont.AddBlack();
                Cont.ShowBlack();
                break;
            default:
                break;
        }
    }
    system("PAUSE");
    return 0;
}
//   结束了，实现简单通讯录操作。黑名单，分组等个性化功能还在开发中，可能永远也不会做完(doge)     2023.4.1 V1.0.0开发完成