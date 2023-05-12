#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

struct date           //结构体名
    {
        int month;
        int day;      //成员列表
        int year;
    };           /*此处有个分号*/

struct product
{
    string name;
    string technology;
    int size;
    int prize;
    string owner;
} product1;


int main()
{
    struct date today;
    today.month = 2;
    today.day = 22;
    today.year = 2023;

    printf("Today's date is %i-%i-%i.\n",today.year, today.month, today.day);

    product1 = {"nike aj12", "zoom", 41, 1000};
    //roduct1 = {product1.name="nike aj12", product1.technology="zoom", product1.size=41, product1.prize=1000}; 
    //vc2010下不能忽略变量名与前边成员

    printf("enter the owner's name:\n");
    scanf("%s", &product1.owner);

    printf("name:%s\n", product1.name);
    printf("technology:%s\n", product1.technology);
    printf("size:%d\n", product1.size);
    printf("price:%d\n", product1.prize);
    printf("date:%i-%i-%i.\n",
        today.year, today.month, today.day);
    printf("owner:%s\n", product1.owner);
    
    system("PAUSE");
    return 0;

}