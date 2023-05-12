#include <bits/stdc++.h>
using namespace std;

struct Polynomial            //建立各项组成
{
    float coef;
    char symb;
    char vari;
    int expn;
};

void EnterPoly(Polynomial a[], int n){      //输入目标多项式
    for (int i = 0; i < n; i++){
        cin >> a[i].coef >> a[i].vari >> a[i].expn;
    }
}

void SortPoly(Polynomial a[], int n){      //将多项式的各项按指数升序排列
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - 1 - i; j++){
            if (a[j].expn > a[j + 1].expn){
                Polynomial t;
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

int OrgnPoly(Polynomial a[], int n){         //整理多项式，对同类项进行合并
    SortPoly(a, n);
    for(int i = 1; i < n;){
        if (a[i].expn == a[i - 1].expn){
            a[i - 1].coef += a[i].coef;
            for (int j = i; j < n; j++){
                a[j] = a[j + 1];
            }
            n--;
        }
        else i++;
    }
    return n;
}

void ShowPoly(Polynomial a[],int n){            //按照数学规则及习惯打印排序整理后的多项式
    SortPoly(a,n);
    for (int i = 0; i < n; i++)
    {
        if (a[i].coef > 0){
            a[i].symb = '+';
            if (a[i].coef == 1) {
                if (a[i].expn == 0) cout << a[i].symb << '(' << a[i].coef << ')';
                else if (a[i].expn == 1) cout << a[i].symb << '('<< a[i].vari << ')';
                else if (a[i].expn != 0 && a[i].expn != 1) cout << a[i].symb << '('<< a[i].vari << a[i].expn << ')';
            }
            else if (a[i].coef != 1){
                if (a[i].expn == 0) cout << a[i].symb << '(' << a[i].coef << ')';
                else if (a[i].expn == 1) cout << a[i].symb << '(' << a[i].coef << a[i].vari << ')';
                else if (a[i].expn != 0 && a[i].expn != 1) cout << a[i].symb << '(' << a[i].coef << a[i].vari << a[i].expn << ')';
            }
        }
        else if (a[i].coef < 0){
            a[i].symb = '-';
            if (a[i].coef == -1) {
                if (a[i].expn == 0) cout << a[i].symb << '(' << fabs(a[i].coef) << ')';
                else if (a[i].expn == 1) cout << a[i].symb << '(' << a[i].vari << ')';
                else if (a[i].expn != 0 && a[i].expn != 1) cout << a[i].symb << '('<< a[i].vari << a[i].expn << ')';
            }
            else if (a[i].coef != -1){
                if (a[i].expn == 0) cout << a[i].symb << '(' << fabs(a[i].coef) << ')';
                else if (a[i].expn == 1) cout << a[i].symb << '(' << fabs(a[i].coef) << a[i].vari << ')';
                else if (a[i].expn != 0 && a[i].expn != 1) cout << a[i].symb << '(' << fabs(a[i].coef) << a[i].vari << a[i].expn << ')';
            }
        }
    }   
}

void DeriPoly(Polynomial a[], int n){       //对目标多项式进行求导并输出
    Polynomial a1[n];
    for (int i = 0; i < n; i++){
        a1[i].coef = a[i].coef * a[i].expn;
        a1[i].expn = a[i].expn - 1;
        a1[i].symb = a[i].symb;
        a1[i].vari = a[i].vari;
    }
    ShowPoly(a1, n);
}

void PlusPoly(Polynomial a[], int n, Polynomial b[], int m){     //将两个目标多项式相加
    Polynomial c[m + n];
    for (int i = 0; i < n; i++){
        c[i] = a[i];
    }
    for (int j = 0; j < m; j++){
        c[j + n] = b[j];
    }
    ShowPoly(c, OrgnPoly(c, m + n));
}

void SubtPoly(Polynomial a[], int n, Polynomial b[], int m){     //用前多项式减去后多项式
    Polynomial c[m + n];
    Polynomial arc_b[m];
    for (int i = 0; i < m; i++){
        arc_b[i] = b[i];
        arc_b[i].coef = -b[i].coef;
    } 
    for (int i = 0; i < n; i++){
        c[i] = a[i];
    }
    for (int j = 0; j < m; j++){
        c[j + n] = arc_b[j];
    }
    ShowPoly(c, OrgnPoly(c, m + n));
}

int main ()            //主函数用于测试各项功能的调用情况
{
    Polynomial Pol1[100];
    Polynomial Pol2[100];
    int n, m;
    cout << "输入多项式Pol1的项数及各项:" << endl;
    cin >> n;
    EnterPoly(Pol1, n);
    n = OrgnPoly(Pol1, n);
    ShowPoly(Pol1, n);
    cout << endl;
    cout << "输入多项式Pol2的项数及各项:" << endl;
    cin >> m;
    EnterPoly(Pol2, m);
    m = OrgnPoly(Pol2, m);
    ShowPoly(Pol2, m);
    cout << endl;
    cout << "对Pol1求导得:" << endl;
    DeriPoly(Pol1, n);
    cout << endl;
    cout << "Pol1与Pol2相加得:" << endl;
    PlusPoly(Pol1, n, Pol2, m);
    cout << endl;
    cout << "Pol1减去Pol2得:" << endl;
    SubtPoly(Pol1, n, Pol2, m);
    system("PAUSE");
    return 0;
}