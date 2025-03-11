#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<chrono>
#include<sstream>
#include<exception>
using namespace std;

constexpr int length = 12; 
constexpr int directions[4][2] = { {1, 0}, {0, 1}, {1, 1}, {1, -1} };

class chess {
public:
	vector<vector<int>> chessboard;
	chess() : chessboard(length, vector<int>(length, 0)){
		chessboard[5][5] = 2;
		chessboard[6][6] = 2;
		chessboard[5][6] = 1;
		chessboard[6][5] = 1;
	}
	int checkline(const vector<vector<int>>& cur_board,
		int x, int y, int dx, int dy, int player) {

		for (int i = 0; i < 5; ++i) {
			int nx = x + i * dx;
			int ny = y + i * dy;

			if (nx < 0 || ny < 0 || nx >= 5 || ny >= length
				|| cur_board[nx][ny] != player) {
				return 0;
			}
		}
		return player;
	}
	int check() {

		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				for (auto dir : directions){
					if (checkline(chessboard, i, j, dir[0], dir[1], 1))
						return 1;
					if (checkline(chessboard, i, j, dir[0], dir[1], 2))
						return 2;
				}
			}
		}
		bool _flag = true;
		for (int i = 0; i < length; ++i) {
			for (int j = 0; j < length; ++j) {
				if (chessboard[i][j] != 0)
					_flag = false;
			}
		}
		if (_flag)
			return 3;
		return 0;
	}
	void move1(int i, int j) {
		chessboard[i][j] = 1;
	}
	void move2(int i, int j) {
		chessboard[i][j] = 2;
	}
	void print_chessboard() {
		cout << endl;
		for (int i = 0; i < length; ++i) {
			cout << '\t';
			for (int j = 0; j < length; ++j) {
				cout << chessboard[i][j] << " ";
			}
			cout << endl;
		}
	}
};

string getres(FILE* _pipe) {
	char buffer[128];
	if (fgets(buffer, sizeof(buffer), _pipe) != nullptr) {
		return string(buffer);
	}
	return "";
}


int f() {

	chess Chessboard;

	// 1.exe first
	FILE* pipe1 = popen("\"D:\\VS_program\\Gomoku\\Fight\\1.exe\"", "r+");
	if(!pipe1) cout<<"pipe1 open fail!"<<endl;
	FILE* pipe2 = popen("\"D:\\VS_program\\Gomoku\\Fight\\2.exe\"", "r+");
	if(!pipe2) cout<<"pipe2 open fail!"<<endl;
	string ini_command1 = "START 1\n";
	string ini_command2 = "START 2\n";
	fprintf(pipe1, ini_command1.c_str());  fflush(pipe1);
	fprintf(pipe2, ini_command2.c_str());  fflush(pipe2);
	string recieve1, recieve2;

	auto start = std::chrono::high_resolution_clock::now();
	recieve1 = getres(pipe1);
	auto end = std::chrono::high_resolution_clock::now();
	chrono::duration<double, std::milli> duration = end - start;
	if (recieve1 != "OK" || duration.count() >= 1000) {
		cout<<recieve1<<endl;
		cout << "player 1 lose becasue OK";
		return 2;
	}

	start = std::chrono::high_resolution_clock::now();
	recieve2 = getres(pipe2);
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	if (recieve2 != "OK" || duration.count() >= 1000) {
		cout << "player 2 lose becasue OK";
		return 1;
	}

	int turns = 1;
	string command;

	while (1) {
		int x, y;
		start = std::chrono::high_resolution_clock::now();

		if (turns == 1) {
			command = "TURN\n";
			fprintf(pipe1, command.c_str());

			recieve1 = getres(pipe1);
			stringstream reci(recieve1);
			reci >> x >> y;
			Chessboard.move1(x, y);
			turns = 2;

			command = "PLACE " + to_string(x) + " " + to_string(y) + "\n";
			fprintf(pipe2, command.c_str());
		}
		else {
			command = "TURN\n";
			fprintf(pipe2, command.c_str());

			recieve2 = getres(pipe2);
			stringstream reci(recieve2);
			reci >> x >> y;
			Chessboard.move2(x, y);
			turns = 1;

			command = "PLACE " + to_string(x) + " " + to_string(y) + "\n";
			fprintf(pipe1, command.c_str());
		}


		end = std::chrono::high_resolution_clock::now();
		Chessboard.print_chessboard();
		duration = end - start;
		cout << turns << " Execution time: " << duration.count() << " ms" << endl << endl;

		int check = Chessboard.check();
		if (check != 0) {
			if (check == 1) {
				cout << "Player 1 wins!" << endl;
				return 1;
			}
			else if (check == 2) {
				cout << "Player 2 wins!" << endl;
				return 2;
			}
			else if (check == 3) {
				cout << "No one wins!" << endl;
				return 0;
			}
		}
	}

	return 0;
}
/*
int s() {
	chess Chessboard;

	// 2.exe first

	FILE* pipe1 = _popen("2.exe", "w+");
	if (!pipe1) throw std::runtime_error("Failed to open pipe1.");

	FILE* pipe2 = _popen("1.exe", "w+");
	if (!pipe2) throw std::runtime_error("Failed to open pipe2.");

	string ini_command1 = "START 1\n";
	string ini_command2 = "START 2\n";
	fprintf(pipe1, ini_command1.c_str());  fflush(pipe1);
	fprintf(pipe2, ini_command2.c_str());  fflush(pipe2);
	string recieve1, recieve2;

	auto start = std::chrono::high_resolution_clock::now();
	recieve1 = getres(pipe1);
	auto end = std::chrono::high_resolution_clock::now();
	chrono::duration<double, std::milli> duration = end - start;
	if (recieve1 != "OK" || duration.count() >= 1000) {
		cout << "player 1 lose becasue OK";
		return 2;
	}

	start = std::chrono::high_resolution_clock::now();
	recieve2 = getres(pipe2);
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	if (recieve2 != "OK" || duration.count() >= 1000) {
		cout << "player 2 lose becasue OK";
		return 1;
	}

	int turns = 1;
	string command;

	while (1) {
		int x, y;
		start = std::chrono::high_resolution_clock::now();

		if (turns == 1) {
			command = "TURN";
			fprintf(pipe1, command.c_str());

			recieve1 = getres(pipe1);
			stringstream reci(recieve1);
			reci >> x >> y;
			Chessboard.move1(x, y);
			turns = 2;

			command = "PLACE " + to_string(x) + " " + to_string(y);
			fprintf(pipe2, command.c_str());
		}
		else {
			command = "TURN";
			fprintf(pipe2, command.c_str());

			recieve2 = getres(pipe2);
			stringstream reci(recieve2);
			reci >> x >> y;
			Chessboard.move2(x, y);
			turns = 1;

			command = "PLACE " + to_string(x) + " " + to_string(y);
			fprintf(pipe1, command.c_str());
		}


		end = std::chrono::high_resolution_clock::now();
		Chessboard.print_chessboard();
		duration = end - start;
		cout << turns << " Execution time: " << duration.count() << " ms" << endl << endl;

		int check = Chessboard.check();
		if (check != 0) {
			if (check == 1) {
				cout << "Player 1 wins!" << endl;
				return 1;
			}
			else if (check == 2) {
				cout << "Player 2 wins!" << endl;
				return 2;
			}
			else if (check == 3) {
				cout << "No one wins!" << endl;
				return 0;
			}
		}
	}

	return 0;
}
*/
int main() {
		int res1 = f();


	return 0;
}
