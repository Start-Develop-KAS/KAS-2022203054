#include <iostream>
#include <vector>

int main()
{
    int N, M;

    std::cin >> N;
    std::cin >> M;

    if (N == 1) {
        std::cout << 1;
    } else if (N == 2) {
        std::cout << std::min(4, (M + 1) / 2);
    } else if (M < 6) {
        std::cout << std::min(4, M);
    } else {
        std::cout << M - 2;
    }

    return 0;
}

// int tripA(std::vector<std::vector<int>> map)
// {
//     int N = map.size();
//     int M = map[0].size();
//     std::vector<std::vector<int>> move = {{1, -2}, {2, -1}, {2, 1}, {1, 2}};

//     int num = 0;
//     bool TF = true;
//     int x = 0, y = 0;

//     while (TF == true)
//     {
//         if (map[x][y] == 0)
//         {
//             map[x][y] = 1;
//             num++;
//             std::cout << "map[" << x << "][" << y << "]"
//                       << " is change\n";
//             for (int i = 0; i < map.size(); i++)
//             {
//                 for (int j = 0; j < map[i].size(); j++)
//                 {
//                     std::cout << map[i][j] << " ";
//                 }
//                 std::cout << std::endl;
//             }
//             std::cout << "----------------------------------------\n";
//         }
//         else
//         {
//             int i;

//             for (int i = 0; i < 3; i++)
//             {
//                 if (-1 < x + move[i][0] && x + move[i][0] < N && -1 < y + move[i][1] && y + move[i][1] < M)
//                 {
//                     x += move[i][0];
//                     y += move[i][1];
//                     break;
//                 }
//             }
//             if (i == 3)
//                 TF = false;
//         }
//     }
//     return num;
// }

// int tripB(std::vector<std::vector<int>> map)
// {
//     int N = map.size();
//     int M = map[0].size();

//     std::vector<std::vector<int>> move = {{1, -2}, {2, -1}, {2, 1}, {1, 2}};
//     bool move_TF[4] = {false};
//     int num = 0;
//     bool TF = false, endpoint = true;
//     int x = 0, y = 0;
//     int a = 0;

//     while (endpoint == true)
//     {
//         if (map[x][y] == 0)
//         {
//             map[x][y] = 1;
//             num++;
//             std::cout << "map[" << x << "][" << y << "]"
//                       << " is change\n";
//             for (int i = 0; i < map.size(); i++)
//             {
//                 for (int j = 0; j < map[i].size(); j++)
//                 {
//                     std::cout << map[i][j] << " ";
//                 }
//                 std::cout << std::endl;
//             }
//             std::cout << "----------------------------------------\n";
//         }

//         else
//         {
//             int stk = 0;
//             while (stk < 4)
//             {
//                 int i = 0;
//                 if (!TF&&a>4)
//                 {
//                     for (i = 0; i < 4; i++)
//                     {
//                         if (!move_TF[i])
//                         {
//                             a += i;
//                             break;
//                         }
//                     }
//                     if (i == 4)
//                         TF = true;
//                 }

//                 if (-1 < x + move[a % 4][0] && x + move[a % 4][0] < N - 1 && -1 < y + move[a % 4][1] && y + move[a % 4][1] < M - 1)
//                 {
//                     x += move[a % 4][0];
//                     y += move[a % 4][1];
//                     move_TF[a % 4] = true;
//                     std::cout<<"moveTF["<<a%4<<"] is true\n";
//                     break;
//                 }
//                 stk++;
//                 if(a<2)
//                     a++;
//             }
//             if (stk > 3)
//                 endpoint = false;
//         }
//     }
//     return num;
// }
