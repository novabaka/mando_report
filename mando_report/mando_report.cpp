

#include <iostream>
#include <string>
#include <ctime>//시간을 가져오는 헤더파일
#include <cstdlib>

using namespace std;


void map(int* arr) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (*(arr + i * 3 + j) == 0)
				cout << "  |";
			else if (*(arr + i * 3 + j) == 1)
				cout << " x|";
			else if (*(arr + i * 3 + j) == 2)
				cout << " o|";
		}
		cout << endl;
	}

}

int check_win(int game_arr[3][3]) {
	for (int i = 0; i < 3; i++) {
		if (game_arr[i][0] == game_arr[i][1] && game_arr[i][1] == game_arr[i][2]) {
			return game_arr[i][0];
		}
	}

	for (int i = 0; i < 3; i++) {
		if (game_arr[0][i] == game_arr[1][i] && game_arr[1][i] == game_arr[2][i]) {
			return game_arr[0][i];
		}
	}

	if (game_arr[0][0] == game_arr[1][1] && game_arr[1][1] == game_arr[2][2]) {
		return game_arr[0][0];
	}
	if (game_arr[0][2] == game_arr[1][1] && game_arr[1][1] == game_arr[2][0]) {
		return game_arr[0][2];
	}

	return 0;
}
int main() {
	int game_arr[3][3] = { 0 };
	int arr_n;
	bool attack = true; // 0은 o의 선공

	for (;;) {

		map((int*)game_arr);
		if (check_win(game_arr)) {
			cout << "게임이 종료되었습니다. 승리자: " << ((check_win(game_arr)) == 1 ? "x" : "o") << endl;
			break;
		}
		cout << "좌표를 입력하세요 예 12" << endl;
		arr_n = 0;
		cin >> arr_n;

		if (attack == true) {
			if (game_arr[arr_n / 10 - 1][arr_n % 10 - 1] == 0)
				game_arr[arr_n / 10 - 1][arr_n % 10 - 1] = 2;
			else {
				attack = !attack;
				cout << "다메다메 다메요 안돼 안돼요 그곳은 이미 차있어요 " << endl;
			}
		}
		else if (attack == false) {
			if (game_arr[arr_n / 10 - 1][arr_n % 10 - 1] == 0)
				game_arr[arr_n / 10 - 1][arr_n % 10 - 1] = 1;
			else {
				cout << "다메다메 다메요 안돼 안돼요 그곳은 이미 차있어요 " << endl;
				attack = !attack;
			}
		}
		attack = !attack;

	}

}