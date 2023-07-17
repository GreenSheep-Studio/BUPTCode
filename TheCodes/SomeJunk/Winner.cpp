#include <iostream>
#include <cstring>
using namespace std;

struct Game{
    string name;
    int score;
};

struct Player
{
    int number;
    string name;
    int score;
};


int main ()
{
    int n;
    Game game[1000];
    Player P[100];
    int N = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> game[i].name >> game[i].score;
    for (int i = 0; i < n; i++)
    {
        
    }
    
    system("PASUE");
    return 0;
}