#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>


bool cal(std::string, std::vector<std::string>);

std::vector<std::vector<std::string>> rst;

int main() {
    std::ios::sync_with_stdio(false);

    int T;
    int num = 0;

    std::vector<bool> TF;

    std::cin >> T;

    while (num < T) {
        std::string p, arr;
        int n;
        std::vector<std::string> vec;

        std::cin >> p;

        std::cin >> n;
        std::cin >> arr;

        arr.pop_back();
        reverse(arr.begin(), arr.end());
        arr.pop_back();
        reverse(arr.begin(), arr.end());

        std::vector<std::string> words;
        std::stringstream sstream(arr);
        std::string word;

        while (getline(sstream, word, ','))
        {
            words.push_back(word);
        }

        TF.push_back(cal(p, words));

        num++;
    }

    for (int i = 0; i < T; i++) {
        if (TF[i]) {
            std::vector<std::string> rt;

            rt.push_back("[");
            for (int j = 0; j < rst[i].size(); j++) {
                rt.push_back(rst[i][j]);
                rt.push_back(",");
            }

            rt.pop_back();
            rt.push_back("]");

            for (int j = 0; j < rt.size(); j++) {
                std::cout << rt[j];
            }
            std::cout << "\n";
        }
        else
            std::cout << "error" << "\n";
    }
    return 0;
}

bool cal(std::string p, std::vector<std::string> vec) {
    int a = 0;

    for (int i = 0; i < p.size(); i++) {
        switch (p[i])
        {
        case 'R':
            reverse(vec.begin(), vec.end());
            a++;
            break;
        case 'D':
            if (vec.empty())
                break;
            reverse(vec.begin(), vec.end());
            vec.pop_back();
            reverse(vec.begin(), vec.end());
            a++;
            break;
        }
    }
    rst.push_back(vec);

    if (a < p.size())
        return false;

    return true;
}