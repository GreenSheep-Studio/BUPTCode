#include <iostream>
#include <cstring>
using namespace std;

struct Game
{
    bool IN = 0;
    string name;
    int score;
};

struct Player
{
    bool IN = 0;
    string name;
    int score;
    int number;
};

int main()
{
    int n;
    Game game[1000];
    Player P[100];
    int N = 0;
    int Order = 1;
    long long int max = -10000000000000;
    string winner;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> game[i].name >> game[i].score;
    }
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        for (j = 0; P[j].IN; j++)
        {
            if (P[j].name == game[i].name)
            {
                P[j].score += game[i].score;
                game[i].IN = 1;
                break;
            }
        }
        if (!game[i].IN)
        {
            P[j].IN = 1;
            P[j].name = game[i].name;
            P[j].score += game[i].score;
        }

        for (int k = 0; P[k].IN; k++)
        {
            if (P[k].score > max)
            {
                max = P[k].score;
                P[k].number = Order;
                Order++;
            }
        }
    }
    int O;
    max = -100000000;
    for (int i = 0; P[i].IN; i++)
    {
        if (P[i].score > max)
        {
            max = P[i].score;
            winner = P[i].name;
            O = P[i].number;
        }
        else if (P[i].score = max)
        {
            if (P[i].number > O)
            {
                max = P[i].score;
                winner = P[i].name;
                O = P[i].number;
            }
        }
    }
    cout << winner;
    system("PAUSE");
    return 0;
}