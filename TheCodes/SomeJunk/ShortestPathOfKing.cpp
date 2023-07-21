#include <iostream>
#include <cstring>
using namespace std;

struct Board{
    char x;
    int y;
};

struct Path{
    string path;
};

Path p[100];

int PathIF(Board K, Board F, int time){
    if (F.x > K.x && F.y > K.y) {
        p[time].path = "RU";
        K.x += 1;
        K.y += 1;
        time++;
        return PathIF(K, F, time);
    }
    
    else if (F.x > K.x && F.y < K.y) {
        p[time].path = "RD";
        K.x += 1;
        K.y -= 1;
        time++;
        return PathIF(K, F, time);
    }

    else if (F.x < K.x && F.y < K.y) {
        p[time].path = "LD";
        K.x -= 1;
        K.y -= 1;
        time++;
        return PathIF(K, F, time);
    }
    
    else if (F.x < K.x && F.y > K.y) {
        p[time].path = "LU";
        K.x -= 1;
        K.y += 1;
        time++;
        return PathIF(K, F, time);
    }

    else if (F.x > K.x && F.y == K.y) {
        p[time].path = "R";
        K.x += 1;
        time++;
        return PathIF(K, F, time);
    }

    else if (F.x < K.x && F.y == K.y) {
        p[time].path = "L";
        K.x -= 1;
        time++;
        return PathIF(K, F, time);
    }

    else if (F.x == K.x && F.y > K.y) {
        p[time].path = "U";
        K.y += 1;
        time++;
        return PathIF(K, F, time);
    }

    else if (F.x == K.x && F.y < K.y) {
        p[time].path = "D";
        K.y -= 1;
        time++;
        return PathIF(K, F, time);
    }
    return time;
}

int main ()
{
    Board King;
    Board Final;
    int time = 0;
    cin >> King.x >> King.y;
    cin >> Final.x >> Final.y;
    time = PathIF(King, Final, time);
    cout << time << endl;
    for (int i = 0; i < time; i++){
        cout << p[i].path << endl;
    }
    return 0;
}