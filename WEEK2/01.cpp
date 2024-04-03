#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define Ascii 96

int main()
{
    vector<vector<int>> move = {{2, 1}, {-2, 1}, {2, -1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};
    char a;
    int nx;
    int ny;
    int cnt = 0;

    cin >> a >> ny;

    nx = (int)a - Ascii;

    for (int i = 0; i < move.size(); i++)
    {
        if (nx - move[i][0] > 0 && ny - move[i][1] > 0)
            cnt++;
    }

    cout << cnt;
}