#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int N, M;
    int A, B, d;
    int num, cnt = 0;
    int st=0;    

    vector<vector<int>> map;
    vector<vector<int>> move = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}; // 북, 동, 남, 서
    vector<int> di = {0, 1, 2, 3};                                 // 북동남서

    cin >> N >> M;
    cin >> A >> B >> d;

    for (int i = 0; i < N; i++)
    {
        vector<int> v;

        for (int j = 0; j < M; j++)
        {
            cin >> num;
            v.push_back(num);
        }
        map.push_back(v);
    }

    while (A<N&&B<M&&st<4){
        if (map[A][B] == 0)
        {
            map[A][B] = 1;
            A += move[d][0];
            B += move[d][1];
            cnt++;
            st=0;
        }
        else{
            d = di[(d+1) % 4];
            st++;
        }

    }

    cout<<cnt;
    
    return 0;
}