#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <deque>


bool cal(std::string, std::deque<std::string>);

std::vector<std::deque<std::string>> rst;

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
        if(arr.size()!=0)
            reverse(arr.begin(), arr.end());

        std::deque<std::string> words;
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
            if(rt.size()>1)
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

bool cal(std::string p, std::deque<std::string> vec) {
    bool isReversed = false; // 뒤집힌 상태를 추적하는 플래그

    for (char cmd : p) {
        if (cmd == 'R') {
            // 뒤집기 명령어가 호출될 때마다 상태를 토글
            isReversed = !isReversed;
        } else if (cmd == 'D') {
            if (vec.empty()) {
                rst.push_back(vec);
                return false;
            }
            // 뒤집힌 상태에 따라 앞 또는 뒤에서 원소 제거
            if (isReversed) {
                vec.pop_back();
            } else {
                vec.pop_front();
            }
        }
    }

    // 최종 상태가 뒤집힌 상태라면 뒤집기
    if (isReversed) {
        std::reverse(vec.begin(), vec.end());
    }

    rst.push_back(vec);

    // 성공적으로 명령어를 처리했다면 true 반환
    return true;
    

}