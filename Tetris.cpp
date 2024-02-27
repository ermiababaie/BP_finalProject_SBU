#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>

#define HL HANDLE
#define SCT SetConsoleTextAttribute
#define GS GetStdHandle(STD_OUTPUT_HANDLE)

using namespace std;

struct detail{
	string name;
	string mode;
	int score;
	double time;
};

struct obj{
	int shekl[2][4];
};

struct object{
	int shekl[4][4];
	int rot;
	
};

double timee;
int tet[100][100];
int player;
detail user;
detail history[10000];
int score;
object tet_obj[25];
obj tet_obj2[7];
bool game_over = false;

void pre();
void logo();
void How_To_Play(string call, int x, int y, object gameobj);
void menu();
void New_Game_Menu();
void Fast_Columns_Maker1(int col, int row, int space);
void Fast_Columns_Maker2(int col, int row, int space);
void Exit();
void Chap(int row, int col, obj arr[]);
bool game_operation(int row, int col, obj arr[]);
void Easy_start_game(int row, int col);
void Hard_start_game(int row, int col);
void Pause_Menu(int &x, int &y, object &gameobj);
void Quit();
double cast_to_double(string s);
void Leader_Board(); 
void Easy_leader_board(); 
void Hard_leader_board();

int Digit_Number(int x) {
	int cnt = 0;
	if (x == 0)
		cnt++;
	while (x > 0) {
		x /= 10;
		cnt++;
	}
	return cnt;
}

int main() {
	pre();
	menu();
}

void Easy_leader_board() {
	system("cls");
	logo();
	HL hc = GS;
	vector<int> players_num;
	for (int i = 0; i < player; i++) {
		if (history[i].mode == "Easy")
			players_num.push_back(i);
	}
	for (int i = 0; i < players_num.size(); i++) {
		int loc = i - 1;
		while (loc >= 0 && history[players_num[loc]].score < history[players_num[loc + 1]].score) {
			swap(players_num[loc], players_num[loc + 1]);
			loc--;
		}
	}
	SCT(hc, 5);
	cout << "Easy mode Leader_board:\n";
	if (players_num.size() >= 1) {
		SCT(hc, 6);
		cout << "Rank one: " << history[players_num[0]].name << "  " << history[players_num[0]].score << "  " << history[players_num[0]].time << "s\n";
	}
	if (players_num.size() >= 2) {
		SCT(hc, 8);
		cout << "Rank two: " << history[players_num[1]].name << "  " << history[players_num[1]].score << "  " << history[players_num[1]].time << "s\n";
	}
	if (players_num.size() >= 3) {
		SCT(hc, 4);
		cout << "Rank three: " << history[players_num[2]].name << "  " << history[players_num[2]].score << "  " << history[players_num[2]].time << "s\n\n";
	}
	for (int i = 3; i < players_num.size(); i++) {
		SCT(hc, 7);
		cout << i + 1 << ": " << history[players_num[i]].name << "  " << history[players_num[i]].score << "  " << history[players_num[i]].time << "s\n";
	}
	SCT(hc, 5);
	system("pause");
}

void Hard_leader_board() {
	system("cls");
	logo();
	HL hc = GS;
	vector<int> players_num;
	for (int i = 0; i < player; i++) {
		if (history[i].mode != "Easy")
			players_num.push_back(i);
	}
	for (int i = 0; i < players_num.size(); i++) {
		int loc = i - 1;
		while (loc >= 0 && history[players_num[loc]].score < history[players_num[loc + 1]].score) {
			swap(players_num[loc], players_num[loc + 1]);
			loc--;
		}
	}
	SCT(hc, 5);
	cout << "Hard mode Leader_board:\n";
	if (players_num.size() >= 1) {
		SCT(hc, 6);
		cout << "Rank one: " << history[players_num[0]].name << "  " << history[players_num[0]].score << "  " << history[players_num[0]].time << "s\n";
	}
	if (players_num.size() >= 2) {
		SCT(hc, 8);
		cout << "Rank two: " << history[players_num[1]].name << "  " << history[players_num[1]].score << "  " << history[players_num[1]].time << "s\n";
	}
	if (players_num.size() >= 3) {
		SCT(hc, 4);
		cout << "Rank three: " << history[players_num[2]].name << "  " << history[players_num[2]].score << "  " << history[players_num[2]].time << "s\n\n";
	}
	for (int i = 3; i < players_num.size(); i++) {
		SCT(hc, 7);
		cout << i + 1 << ": " << history[players_num[i]].name << "  " << history[players_num[i]].score << "  " << history[players_num[i]].time << "s\n";
	}
	SCT(hc, 5);
	system("pause");
}

void Leader_Board() {
	system("cls");
	HL hc = GS;
	logo();
	SCT(hc, 4);
	for (int i = 1; i <= 51; i++)
		cout << " ";
	cout << "\u2554";
	for (int i = 1; i <= 16; i++)
		cout << "\u2550";
	cout << "\u2557\n";
	for (int i = 1; i <= 51; i++)
		cout << " ";
	cout << "\u2551";
	SCT(hc, 3);
	cout << "1)Easy ranking";
	SCT(hc, 2);
	for (int i = 1; i <= 2; i++)
		cout << ' ';
	cout << "\u2551\n";
	for (int i = 1; i <= 51; i++)
		cout << " ";
	cout << "\u255A";
	for (int i = 1; i <= 16; i++)
		cout << "\u2550";
	cout << "\u255D\n";

	for (int i = 1; i <= 51; i++)
		cout << " ";
	
	cout << "\u2554";
	for (int i = 1; i <= 16; i++)
		cout << "\u2550";
	cout << "\u2557\n";
	for (int i = 1; i <= 51; i++)
		cout << " ";
	cout << "\u2551";
	SCT(hc, 3);
	cout << "2)Hard ranking";
	SCT(hc, 5);
	for (int i = 1; i <= 2; i++)
		cout << ' ';
	cout << "\u2551\n";
	for (int i = 1; i <= 51; i++)
		cout << " ";
	cout << "\u255A";
	for (int i = 1; i <= 16; i++)
		cout << "\u2550";
	cout << "\u255D\n";
	
	for (int i = 1; i <= 51; i++)
		cout << " ";
	cout << "\u2554";
	for (int i = 1; i <= 16; i++)
		cout << "\u2550";
	cout << "\u2557\n";
	for (int i = 1; i <= 51; i++)
		cout << " ";
	cout << "\u2551";
	SCT(hc, 3);
	cout << "3)Menu";
	SCT(hc, 4);
	for (int i = 1; i <= 10; i++)
		cout << ' ';
	cout << "\u2551\n";
	for (int i = 1; i <= 51; i++)
		cout << " ";
	cout << "\u255A";
	for (int i = 1; i <= 16; i++)
		cout << "\u2550";
	cout << "\u255D\n";
	
	SCT(hc, 7);
	char c = getch();
	while (c != '1' && c != '2' && c != '3')
		c = getch();
	if (c == '1') {
		Easy_leader_board();
	}
	else if (c == '2') {
		Hard_leader_board();
	}
	else if (c == '3') {
		menu();
	}
	menu();
}

double cast_to_double(string s) {
	int i = 0;
	for (; i < s.size(); i++) {
		if (s[i] == '.')
			break;
	}
	double num = 0.0, zarib1 = 1.0;
	for (int j = i - 1; j >= 0; j--) {
		num += zarib1 * (s[j] - '0');
		zarib1 *= 10.0;
	}
	double zarib = 0.1;
	for (int j = i + 1; j < s.size(); j++) {
		num += zarib * (s[j] - '0');
		zarib /= 10.0;
	}
	return num;
}

void Quit() {
	game_over = true;
	int loc = -1;
	for (int i = 0; i < player; i++) {
		if (history[i].name == user.name && history[i].mode == user.mode)
			loc = i;
	}
	if (loc == -1) {
		loc = player;
		history[loc].score = user.score;
		history[loc].time = user.time;
		history[loc].name = user.name;
		history[loc].mode = user.mode;
		player++;
	}
	else {
		if (user.score > history[loc].score) {
			history[loc].score = user.score;
			history[loc].time = user.time;
		}
		else if (user.score == history[loc].score && user.time < history[loc].time) {
			history[loc].time = user.time;
		}
	}
	ofstream details("details.txt");
	for (int i = 0; i < player; i++) {
		details << history[i].name << "#" << history[i].mode << "#" << history[i].score << "#" << history[i].time << "\n"; 
	}
	details.close();
	menu();
}

void Pause_Menu(int &x, int &y, object &gameobj) {
	system("cls");
	HL hc = GS;
	logo();
	SCT(hc, 4);
	for (int i = 1; i <= 51; i++)
		cout << " ";
	cout << "\u2554";
	for (int i = 1; i <= 16; i++)
		cout << "\u2550";
	cout << "\u2557\n";
	for (int i = 1; i <= 51; i++)
		cout << " ";
	cout << "\u2551";
	SCT(hc, 3);
	cout << "1)Resume";
	SCT(hc, 5);
	for (int i = 1; i <= 8; i++)
		cout << ' ';
	cout << "\u2551\n";
	for (int i = 1; i <= 51; i++)
		cout << " ";
	cout << "\u255A";
	for (int i = 1; i <= 16; i++)
		cout << "\u2550";
	cout << "\u255D\n";

	for (int i = 1; i <= 51; i++)
		cout << " ";
	cout << "\u2554";
	for (int i = 1; i <= 16; i++)
		cout << "\u2550";
	cout << "\u2557\n";
	for (int i = 1; i <= 51; i++)
		cout << " ";
	cout << "\u2551";
	SCT(hc, 3);
	cout << "2)Restart";
	SCT(hc, 2);
	for (int i = 1; i <= 7; i++)
		cout << ' ';
	cout << "\u2551\n";
	for (int i = 1; i <= 51; i++)
		cout << " ";
	cout << "\u255A";
	for (int i = 1; i <= 16; i++)
		cout << "\u2550";
	cout << "\u255D\n";
	
	
	for (int i = 1; i <= 51; i++)
		cout << " ";
	cout << "\u2554";
	for (int i = 1; i <= 16; i++)
		cout << "\u2550";
	cout << "\u2557\n";
	for (int i = 1; i <= 51; i++)
		cout << " ";
	cout << "\u2551";
	SCT(hc, 3);
	cout << "3)How To Play";
	SCT(hc, 1);
	for (int i = 1; i <= 3; i++)
		cout << ' ';
	cout << "\u2551\n";
	for (int i = 1; i <= 51; i++)
		cout << " ";
	cout << "\u255A";
	for (int i = 1; i <= 16; i++)
		cout << "\u2550";
	cout << "\u255D\n";

	for (int i = 1; i <= 51; i++)
		cout << " ";
	cout << "\u2554";
	for (int i = 1; i <= 16; i++)
		cout << "\u2550";
	cout << "\u2557\n";
	for (int i = 1; i <= 51; i++)
		cout << " ";
	cout << "\u2551";
	SCT(hc, 3);
	cout << "4)Quit";
	SCT(hc, 4);
	for (int i = 1; i <= 10; i++)
		cout << ' ';
	cout << "\u2551\n";
	for (int i = 1; i <= 51; i++)
		cout << " ";
	cout << "\u255A";
	for (int i = 1; i <= 16; i++)
		cout << "\u2550";
	cout << "\u255D\n";

	char c = getch();
	while (c != '1' && c != '2' && c != '3' && c != '4' && c != '\t')
		c = getch();

	if (c == '1')
		return;
	else if (c == '2') {
		user.score = 0;
		user.time = 0;
		for (int i = 0; i < 99; i++)
			for (int j = 0; j < 99; j++)
				tet[i][j] = 7;
		int first_obj_num = rand() % 7;
		gameobj = tet_obj[first_obj_num];
		if (first_obj_num == 0) {
			x = 0;
			y = 1;
		}
		else {
			x = 1;
			y = 1;
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				tet[i + x][j + y] = gameobj.shekl[i][j];
			}
		}
		return;
	}
	else if (c == '3') {
		How_To_Play("pause", x, y, gameobj);
	}
	else if (c == '4') {
		Quit();
	}
	else if (c == '\t') {
		string s;
		cin >> s;
		if (s == "13840531") {
			user.time = 0;
			for (int i = 0; i < 99; i++)
				for (int j = 0; j < 99; j++)
					tet[i][j] = 7;
			int first_obj_num = rand() % 7;
			gameobj = tet_obj[first_obj_num];
			if (first_obj_num == 0) {
				x = 0;
				y = 1;
			}
			else {
				x = 1;
				y = 1;
			}
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					tet[i + x][j + y] = gameobj.shekl[i][j];
				}
			}
			return;			
		}
	}
	SCT(hc, 7);
}

bool game_operation(int row, int col, obj arr[], int x, int y, object gameobj) {
	clock_t start1 = clock();
	double pause_time = 0.0; 
	while (!game_over) {
		Chap(row, col, arr);	
		clock_t st = clock();
		while (true) {
			clock_t now = clock();
			if (now - st > timee)
				break;
			if (kbhit()) {
				char ch = getch();
				if ((int)ch == 27) {
					clock_t start2 = clock();
					Pause_Menu(x, y, gameobj);
					clock_t finish2 = clock();
					pause_time += (double)(finish2 - start2) / (double)(CLOCKS_PER_SEC);
					if (game_over)
						return false;
				}
				else if (ch == 'w' || ch == 'W') {
					for (int i = 0; i < 4; i++) {
						for (int j = 0; j < 4; j++) {
							if (gameobj.shekl[i][j] != 7)
								tet[i + x][j + y] = 7;
						}
					}
					object save = gameobj;
					gameobj = tet_obj[gameobj.rot];
					bool check = true;
					for (int i = 0; i < 4; i++) {
						for (int j = 0; j < 4; j++) {
							if (gameobj.shekl[i][j] != 7 && (tet[i + x][j + y] != 7 || (i + x) < 1 || (j + y) > col || (i + x) > row || (j + y) < 1))
								check = false;
						}
					}
					if (check == false)
						gameobj = save;
					for (int i = 0; i < 4; i++) {
						for (int j = 0; j < 4; j++) {
							if (gameobj.shekl[i][j] != 7)
								tet[i + x][j + y] = gameobj.shekl[i][j];
						}
					}
					if (check)
						Chap(row, col, arr);	
				}
				else if (ch == 'a' || ch == 'A') {
					int l = 10;
					for (int i = 0; i < 4; i++) {
						for (int j = 0; j < 4; j++) {
							if (gameobj.shekl[i][j] != 7)
								l = min(l, j);
						}
					}
					bool check = true;
					if (l + y <= 1)
						check = false;
					for (int j = 0; j <= 3; j++) {
						for (int i = 0; i <= 3; i++) {
							if (gameobj.shekl[i][j] != 7 && tet[x + i][y + j - 1] != 7)
								check = false;
							if (gameobj.shekl[i][j] != 7)
								swap(tet[x + i][y + j], tet[x + i][y + j - 1]);
						}
					}
					if (check) {
						y--;
						Chap(row, col, arr);
					}
					else {
						for (int j = 3; j >= 0; j--) {
							for (int i = 0; i <= 3; i++) {
								if (gameobj.shekl[i][j] != 7 && tet[x + i][y + j - 1] != 7)
									check = false;
								if (gameobj.shekl[i][j] != 7)
									swap(tet[x + i][y + j], tet[x + i][y + j - 1]);
							}
						}	
					}
				}
				else if (ch == 'd' || ch == 'D') {
					int l = 0;
					for (int i = 0; i < 4; i++) {
						for (int j = 0; j < 4; j++) {
							if (gameobj.shekl[i][j] != 7)
								l = max(l, j);
						}
					}
					bool check = true;
					if (l + y >= col)
						check = false;
					for (int j = 3; j >= 0; j--) {
						for (int i = 0; i <= 3; i++) {
							if (gameobj.shekl[i][j] != 7 && tet[x + i][y + j + 1] != 7)
								check = false;
							if (gameobj.shekl[i][j] != 7)
								swap(tet[x + i][y + j], tet[x + i][y + j + 1]);
						}
					}
					if (check) {
						y++;
						Chap(row, col, arr);
					}
					else {
						for (int j = 0; j <= 3; j++) {
							for (int i = 0; i <= 3; i++) {
								if (gameobj.shekl[i][j] != 7 && tet[x + i][y + j + 1] != 7)
									check = false;
								if (gameobj.shekl[i][j] != 7)
									swap(tet[x + i][y + j], tet[x + i][y + j + 1]);
							}
						}	
					}
				}
				else if (ch == 's' || ch == 'S') {
					bool check = true;
					int h = 0;
					for (int i = 0; i < 4; i++) {
						for (int j = 0; j < 4; j++) {
							if (gameobj.shekl[i][j] != 7)
								h = i;
							}
						}
					if (x + h >= row) {
						break;
					}
					for (int i = 3; i >= 0; i--) {
						for (int j = 0; j < 4; j++) {
							if (gameobj.shekl[i][j] != 7 && tet[i + x + 1][y + j] != 7) {
								check = false;
							}
							if (gameobj.shekl[i][j] != 7)
								swap(tet[i + x + 1][y + j], tet[i + x][y + j]);
						}
					}
					if (check == false) {
						for (int i = 0; i <= 3; i++) {
							for (int j = 0; j < 4; j++) {
								if (gameobj.shekl[i][j] != 7)				
									swap(tet[i + x + 1][y + j], tet[i + x][y + j]);
							}
						}			
					}
					else {
						x++;
						Chap(row, col, arr);
					}
				}
				else {
					continue;
				}
			}	
		}
		bool check = true;
		int h = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (gameobj.shekl[i][j] != 7)
					h = i;
			}
		}
		if (x + h == row) {
			break;
		}
		for (int i = 3; i >= 0; i--) {
			for (int j = 0; j < 4; j++) {
				if (gameobj.shekl[i][j] != 7 && tet[i + x + 1][y + j] != 7) {
					check = false;
				}
				if (gameobj.shekl[i][j] != 7)
					swap(tet[i + x + 1][y + j], tet[i + x][y + j]);
			}
		}
		if (check == false) {
			for (int i = 0; i <= 3; i++) {
				for (int j = 0; j < 4; j++) {
					if (gameobj.shekl[i][j] != 7)				
						swap(tet[i + x + 1][y + j], tet[i + x][y + j]);
				}
			}
			break;			
		}
		else
			x++;
	}
	int cnt = 0;
	vector<int> satr;
	for (int i = 1; i <= row; i++) {	
		bool check = true;
		for (int j = 1; j <= col; j++) {
			if (tet[i][j] == 7)
				check = false;
		}
		if (check) {
			cnt++;
			satr.push_back(i);
			for (int j = 1; j <= col; j++) {
				tet[i][j] = 8;
			}
		}
	}
	user.score += ((cnt * (cnt + 1)) / 2) * col;
	Chap(row, col, arr);
	usleep(1000);
	for (int ii = 0; ii < satr.size(); ii++) {
		int i = satr[ii];
		for (int j = 1; j <= col; j++) {
			tet[i][j] = 7;
		}
		for (int j = i - 1; j >= 1; j--) {
			for (int k = 1; k <= col; k++) {
				swap(tet[j][k], tet[j + 1][k]);
			}
		}
	}
	clock_t finish1 = clock();
	user.score += 4;
	user.time += ((double)(finish1 - start1) / (double)(CLOCKS_PER_SEC)) - pause_time;
	return false;
}

void Easy_start_game(int row, int col) {
	system("cls");
	logo();
	srand(time(nullptr));
	timee = 2000;
	obj arr[3];
	int obj_arr[3];
	obj_arr[0] = ((rand() % 7) + (rand() % 7) * (rand() % 7)) % 7;
	obj_arr[1] = ((rand() % 7) + (rand() % 7) * (rand() % 7)) % 7;
	obj_arr[2] = ((rand() % 7) + (rand() % 7) * (rand() % 7)) % 7;
	int first_obj_num = rand() % 7;
	for (int i = 0; i < 3; i++) {
		arr[i] = tet_obj2[obj_arr[i]];
	}
	object first_obj = tet_obj[first_obj_num];
	int x, y = 0;
	if (first_obj_num == 0) {
		x = 0;
		y = 1;
	}
	else {
		x = 1;
		y = 1;
	}
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			tet[x + i][y + j] = first_obj.shekl[i][j];
		}
	}
	game_operation(row, col, arr, x, y, first_obj);
	bool gameover = false;
	while (true && !game_over) {
		timee *= 0.98;
		int other_obj_num = obj_arr[0];
		swap(obj_arr[0], obj_arr[1]);
		swap(obj_arr[1], obj_arr[2]);
		obj_arr[2] = ((rand() % 7) + (rand() % 7) * (rand() % 7)) % 7;
		object other_obj = tet_obj[other_obj_num];
		for (int i = 0; i < 3; i++) {
			arr[i] = tet_obj2[obj_arr[i]];
		}
		if (other_obj_num == 0) {
			x = 0;
			y = 1;
		}
		else {
			x = 1;
			y = 1;
		}
		vector<int> v;
		for (int i = 0; i < col; i++) {
			bool check = true;
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					if (other_obj.shekl[j][k] != 7 && tet[x + j][y + i + k] != 7) {
						check = false;
					}
					if (other_obj.shekl[j][k] != 7 && (y + i + k) > col) {
						check = false;
					}
				}
			}
			if (check)
				v.push_back(i);
		}
		if (v.empty()) {
			gameover = true;
			break;
		}
		int loc = rand() % ((int)v.size());
		loc = v[loc];
		y += loc;
		for (int i = 0; i <= 3; i++) {
			for (int j = 0; j <= 3; j++) {
				if (other_obj.shekl[i][j] != 7)
					tet[x + i][y + j] = other_obj.shekl[i][j];
			}
		}
		game_operation(row, col, arr, x, y, other_obj);
	}
	if (gameover) {
		HL hc = GS;
		system("cls");
		logo();
		for (int i = 0; i <= 54; i++)
			cout << " ";
		SCT(hc, 4);
		cout << "Game over:(\n";
		for (int i = 0; i <= 54; i++)
			cout << " ";
		SCT(hc, 5);
		cout << "Your score: " << user.score << '\n';
		for (int i = 0; i <= 54; i++)
			cout << " ";
		SCT(hc, 11);
		cout << "Your time: " << user.time << '\n';
		system("pause");
	}
	Quit();
}

void Hard_start_game(int row, int col) {
	system("cls");
	logo();
	srand(time(nullptr));
	timee = 1000;
	obj arr[3];
	int obj_arr[3];
	obj_arr[0] = ((rand() % 7) * (rand() % 7) + (rand() % 7) * (rand() % 7) + (rand() % 7) * (rand() % 7)) % 7;
	obj_arr[1] = ((rand() % 7) * (rand() % 7) + (rand() % 7) * (rand() % 7) + (rand() % 7) * (rand() % 7)) % 7;
	obj_arr[2] = ((rand() % 7) * (rand() % 7) + (rand() % 7) * (rand() % 7) + (rand() % 7) * (rand() % 7)) % 7;
	int first_obj_num = rand() % 7;
	for (int i = 0; i < 3; i++) {
		arr[i] = tet_obj2[obj_arr[i]];
	}
	object first_obj = tet_obj[first_obj_num];
	int x, y = 0;
	if (first_obj_num == 0) {
		x = 0;
		y = 1;
	}
	else {
		x = 1;
		y = 1;
	}
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			tet[x + i][y + j] = first_obj.shekl[i][j];
		}
	}
	game_operation(row, col, arr, x, y, first_obj);
	bool gameover = false;
	while (true && !game_over) {
		timee *= 0.95;
		int other_obj_num = obj_arr[0];
		swap(obj_arr[0], obj_arr[1]);
		swap(obj_arr[1], obj_arr[2]);
		obj_arr[2] = ((rand() % 7) * (rand() % 7) + (rand() % 7) * (rand() % 7) + (rand() % 7) * (rand() % 7)) % 7;
		object other_obj = tet_obj[other_obj_num];
		for (int i = 0; i < 3; i++) {
			arr[i] = tet_obj2[obj_arr[i]];
		}
		if (other_obj_num == 0) {
			x = 0;
			y = 1;
		}
		else {
			x = 1;
			y = 1;
		}
		vector<int> v;
		for (int i = 0; i < col; i++) {
			bool check = true;
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					if (other_obj.shekl[j][k] != 7 && tet[x + j][y + i + k] != 7) {
						check = false;
					}
					if (other_obj.shekl[j][k] != 7 && (y + i + k) > col) {
						check = false;
					}
				}
			}
			if (check)
				v.push_back(i);
		}
		if (v.empty()) {
			gameover = true;
			break;
		}
		int loc = rand() % ((int)v.size());
		loc = v[loc];
		y += loc;
		for (int i = 0; i <= 3; i++) {
			for (int j = 0; j <= 3; j++) {
				if (other_obj.shekl[i][j] != 7)
					tet[x + i][y + j] = other_obj.shekl[i][j];
			}
		}
		game_operation(row, col, arr, x, y, other_obj);
	}
	if (gameover) {
		HL hc = GS;
		system("cls");
		logo();
		for (int i = 0; i <= 54; i++)
			cout << " ";
		SCT(hc, 4);
		cout << "Game over:(\n";
		for (int i = 0; i <= 54; i++)
			cout << " ";
		SCT(hc, 5);
		cout << "Your score: " << user.score << '\n';
		for (int i = 0; i <= 54; i++)
			cout << " ";
		SCT(hc, 11);
		cout << "Your time: " << user.time << '\n';
		system("pause");
	}
	Quit();
}

void Chap(int row, int col, obj arr[]) {
	HL hc = GS;
	system("cls");
	logo();
	for (int i = 1; i <= 16; i++)
		cout << " ";
	cout << "\u2554\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2557";
	Fast_Columns_Maker1(col, 1, 28);
	for (int i = 1; i <= 33 - col; i++)
		cout << " ";
	cout << "\u250F\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2513";
	cout << '\n';
	for (int i = 1; i <= 16; i++)
		cout << " ";
	cout << "\u2551   Next   \u2551";
	Fast_Columns_Maker2(col, 1, 28);
	for (int i = 1; i <= 33 - col; i++)
		cout << " ";
	cout << "\u2503";
	if (user.mode == "Easy") {
		SCT(hc, 2);
		cout << "     Easy     ";
		SCT(hc, 7);
		cout << "\u2503";
	}
	else {
		SCT(hc, 4);
		cout << "     Hard     ";
		SCT(hc, 7);
		cout << "\u2503";
	}
	cout << '\n';	
	for (int i = 1; i <= 16; i++)
		cout << " ";
	cout << "\u2551          \u2551";
	Fast_Columns_Maker1(col, 2, 28);
	for (int i = 1; i <= 33 - col; i++)
		cout << ' ';
	cout << "\u2523\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u252B";
	cout << '\n';
	for (int i = 1; i <= 16; i++)
		cout << " ";
	cout << "\u2560\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2563";
	Fast_Columns_Maker2(col, 2, 28);
	for (int i = 1; i <= 33 - col; i++)
		cout << ' ';
	cout << "\u2503";
	for (int i = 1; i <= (6 - Digit_Number(user.score)) / 2; i++)
		cout << " ";
	SCT(hc, 11);
	cout << "score = " << user.score;
	SCT(hc, 7);
	for (int i = 1; i <= (7 - Digit_Number(user.score)) / 2; i++)
		cout << " ";
	cout << "\u2503";
	cout << '\n';
	int save = 3;
	int line = 1;
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 2; k++) {
			for (int j = 1; j <= 16; j++)
				cout << " ";
			cout << "\u2551 ";
			for (int j = 0; j <= 3; j++) {
				SCT(hc, arr[i].shekl[k][j]);
				cout << "\u2554\u2557";
				SCT(hc, 7);
			}
			cout << " \u2551";
			if (save <= row) {
				Fast_Columns_Maker1(col, save, 28);
				if (line == 1) {
					for (int spce = 1; spce <= 33 - col; spce++)
						cout << ' ';					
					cout << "\u2523\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u252B";
					line++;
				}
				if (line == 3) {
					for (int spce = 1; spce <= 33 - col; spce++)
						cout << ' ';					
					cout << "\u2503 ";
					SCT(hc, 12);
					cout << "A --> Left   ";
					SCT(hc, 7);
					cout << "\u2503";
					line++;
				}
				cout << '\n';
			}
			else {
				if (line == 1) {
					for (int spce = 1; spce <= 66; spce++)
						cout << ' ';					
					cout << "\u2523\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u252B";
					line++;
				}
				if (line == 3) {
					for (int spce = 1; spce <= 66; spce++)
						cout << ' ';					
					cout << "\u2503 ";
					SCT(hc, 12);
					cout << "A --> Left   ";
					SCT(hc, 7);
					cout << "\u2503";
					line++;
				}
				cout << '\n';
			}
			for (int j = 1; j <= 16; j++)
				cout << " ";
			cout << "\u2551 ";
			for (int j = 0; j < 4; j++) {
				SCT(hc, arr[i].shekl[k][j]);
				cout << "\u255A\u255D";
				SCT(hc, 7);
			}
			cout << " \u2551";
			if (save <= row) {
				Fast_Columns_Maker2(col, save++, 28);
				if (line == 2) {
					for (int spce = 1; spce <= 33 - col; spce++)
						cout << ' ';					
					cout << "\u2503 ";
					SCT(hc, 12);
					cout << "W --> Rotate";
					SCT(hc, 7);
					cout << " \u2503";
					line++;
				}
				if (line == 4) {
					for (int spce = 1; spce <= 33 - col; spce++)
						cout << ' ';					
					cout << "\u2503 ";
					SCT(hc, 12);
					cout << "D --> Right ";
					SCT(hc, 7);
					cout << " \u2503";
					line++;					
				}
				cout << '\n';
			}
			else {
				if (line == 2) {
					for (int spce = 1; spce <= 66; spce++)
						cout << ' ';					
					cout << "\u2503 ";
					SCT(hc, 12);
					cout << "W --> Rotate";
					SCT(hc, 7);
					cout << " \u2503";
					line++;
				}
				if (line == 4) {
					for (int spce = 1; spce <= 66; spce++)
						cout << ' ';					
					cout << "\u2503 ";
					SCT(hc, 12);
					cout << "D --> Right ";
					SCT(hc, 7);
					cout << " \u2503";
					line++;					
				}
				cout << '\n';
			}
		}
		
		for (int j = 1; j <= 16; j++)
			cout << " ";
		cout << "\u2551 ";
		for (int j = 0; j <= 3; j++) {
			SCT(hc, 7);
			cout << "\u2554\u2557";
		}
		cout << " \u2551";
		if (save <= row) {
			Fast_Columns_Maker1(col, save, 28);
			if (line == 5) {
				for (int spce = 1; spce <= 33 - col; spce++)
					cout << ' ';					
				cout << "\u2503 ";
				SCT(hc, 12);
				cout << "S --> Boost ";
				SCT(hc, 7);
				cout << " \u2503";
				line++;					
			}
			cout << '\n';
		}
		else {
			if (line == 5) {
				for (int spce = 1; spce <= 66; spce++)
					cout << ' ';					
				cout << "\u2503 ";
				SCT(hc, 12);
				cout << "S --> Boost ";
				SCT(hc, 7);
				cout << " \u2503";
				line++;					
			}
			cout << '\n';
		}
		for (int j = 1; j <= 16; j++)
			cout << " ";
		cout << "\u2551 ";
		for (int j = 0; j < 4; j++) {
			SCT(hc, 7);
			cout << "\u255A\u255D";
		}
		cout << " \u2551";

		if (save <= row) {
			Fast_Columns_Maker2(col, save++, 28);
			if (line == 6) {
				for (int spce = 1; spce <= 33 - col; spce++)
					cout << ' ';					
				cout << "\u2517\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u251B";
				line++;
			}
			cout << '\n';
		}
		else {
			if (line == 6) {
				for (int spce = 1; spce <= 66; spce++)
					cout << ' ';	
				cout << "\u2517\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u251B";
				line++;					
			}
			cout << '\n';
		}
	}
	
	for (int i = 1; i <= 16; i++)
		cout << " ";
	cout << "\u2551          \u2551";
	if (save <= row) {
		Fast_Columns_Maker1(col, save, 28);
		cout << '\n';
	}
	else
		cout << '\n';
	for (int i = 1; i <= 16; i++)
		cout << " ";
	cout << "\u255A\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u255D";
	if (save <= row) {
		Fast_Columns_Maker2(col, save++, 28);
		cout << '\n';
	}
	else
		cout << '\n';
	
	while (save <= row) {
		Fast_Columns_Maker1(col, save, 0);
		cout << '\n';
		Fast_Columns_Maker2(col, save++, 0);
		cout << '\n';
	}
}

void Exit() {
	system("cls");
	logo();
	HL hc = GS;
	SCT(hc, 5);
	string s = "See You Later :)";
	for (int i = 0; i < s.size(); i++) {
		cout << s[i];
		usleep(10000);
	}
	SCT(hc, 7);
}

void pre() {
	game_over = false;
	user.mode = "";
	user.name = "";
	user.score = 0;
	user.time = 0;
	string s;
	ifstream details("details.txt");
	player = 0;
	while (getline(details, s)) {
		string name = "", mode = "", score = "", time = "";
		int i = 0;
		for (; i < s.size(); i++) {
			if (s[i] == '#')
				break;
			name += s[i];
		}
		
		i++;
		for (; i < s.size(); i++) {
			if (s[i] == '#')
				break;
			mode += s[i];
		}
		
		i++;
		for (; i < s.size(); i++) {
			if (s[i] == '#')
				break;
			score += s[i];
		}
		
		i++;
		for (; i < s.size(); i++) {
			if (s[i] == '#')
				break;
			time += s[i];
		}
		history[player].mode = mode;
		history[player].name = name;
		history[player].score = cast_to_double(score);
		history[player++].time = cast_to_double(time);
	}
	for (int i = 0; i < 99; i++)
		for (int j = 0; j < 99; j++)
			tet[i][j] = 7;
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				tet_obj[i].shekl[j][k] = 7;
			}
		}
	}
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 4; k++) {
				tet_obj2[i].shekl[j][k] = 7;
			}
		}
	}
	tet_obj[0].shekl[1][0] = 5; // 
	tet_obj[0].shekl[1][1] = 5; // * * * *
	tet_obj[0].shekl[1][2] = 5; //
	tet_obj[0].shekl[1][3] = 5; //
	tet_obj[0].rot = 7;	

	tet_obj[7].shekl[0][1] = 5; //  *
	tet_obj[7].shekl[1][1] = 5; //  *
	tet_obj[7].shekl[2][1] = 5; //  *
	tet_obj[7].shekl[3][1] = 5; //  *
	tet_obj[7].rot = 8;	

	tet_obj[8].shekl[2][0] = 5; //
	tet_obj[8].shekl[2][1] = 5; //
	tet_obj[8].shekl[2][2] = 5; // * * * *
	tet_obj[8].shekl[2][3] = 5; //
	tet_obj[8].rot = 9;	

	tet_obj[9].shekl[0][2] = 5; //     *
	tet_obj[9].shekl[1][2] = 5; //     *
	tet_obj[9].shekl[2][2] = 5; //     *
	tet_obj[9].shekl[3][2] = 5; //     *
	tet_obj[9].rot = 0;
	
	
	
	tet_obj[1].shekl[0][1] = 12; //   *
	tet_obj[1].shekl[1][0] = 12; // * * * 
	tet_obj[1].shekl[1][1] = 12; //
	tet_obj[1].shekl[1][2] = 12; //
	tet_obj[1].rot = 10;	

	tet_obj[10].shekl[0][1] = 12; //    *
	tet_obj[10].shekl[1][0] = 12; //  * *
	tet_obj[10].shekl[1][1] = 12; //    *
	tet_obj[10].shekl[2][1] = 12; //  
	tet_obj[10].rot = 11;	

	tet_obj[11].shekl[1][0] = 12; //
	tet_obj[11].shekl[1][1] = 12; // * * *
	tet_obj[11].shekl[1][2] = 12; //   *
	tet_obj[11].shekl[2][1] = 12; //
	tet_obj[11].rot = 12;	

	tet_obj[12].shekl[0][1] = 12; //   * 
	tet_obj[12].shekl[1][1] = 12; //   * *
	tet_obj[12].shekl[1][2] = 12; //   *  
	tet_obj[12].shekl[2][1] = 12; //    
	tet_obj[12].rot = 1;
		
	
	
	tet_obj[2].shekl[0][2] = 4; //     *
	tet_obj[2].shekl[1][0] = 4; // * * * 
	tet_obj[2].shekl[1][1] = 4; //
	tet_obj[2].shekl[1][2] = 4; //
	tet_obj[2].rot = 13;	

	tet_obj[13].shekl[0][0] = 4; // * * 
	tet_obj[13].shekl[0][1] = 4; //   *
	tet_obj[13].shekl[1][1] = 4; //   *
	tet_obj[13].shekl[2][1] = 4; //  
	tet_obj[13].rot = 14;	

	tet_obj[14].shekl[1][0] = 4; //
	tet_obj[14].shekl[1][1] = 4; // * * *
	tet_obj[14].shekl[1][2] = 4; // *
	tet_obj[14].shekl[2][0] = 4; //
	tet_obj[14].rot = 15;	

	tet_obj[15].shekl[0][1] = 4; //   *   
	tet_obj[15].shekl[1][1] = 4; //   * 
	tet_obj[15].shekl[2][1] = 4; //   * * 
	tet_obj[15].shekl[2][2] = 4; //    
	tet_obj[15].rot = 2;
	
	
	
	tet_obj[3].shekl[0][0] = 4; // *
	tet_obj[3].shekl[1][0] = 4; // * * * 
	tet_obj[3].shekl[1][1] = 4; //
	tet_obj[3].shekl[1][2] = 4; //
	tet_obj[3].rot = 16;	

	tet_obj[16].shekl[0][1] = 4; //   * 
	tet_obj[16].shekl[1][1] = 4; //   *
	tet_obj[16].shekl[2][0] = 4; // * *
	tet_obj[16].shekl[2][1] = 4; //  
	tet_obj[16].rot = 17;	

	tet_obj[17].shekl[1][0] = 4; //
	tet_obj[17].shekl[1][1] = 4; // * * *
	tet_obj[17].shekl[1][2] = 4; //     *
	tet_obj[17].shekl[2][2] = 4; //
	tet_obj[17].rot = 18;	

	tet_obj[18].shekl[0][1] = 4; //   * *
	tet_obj[18].shekl[0][2] = 4; //   * 
	tet_obj[18].shekl[1][1] = 4; //   *  
	tet_obj[18].shekl[2][1] = 4; //    
	tet_obj[18].rot = 3;
	
	
	
	tet_obj[4].shekl[0][0] = 9; // * *
	tet_obj[4].shekl[0][1] = 9; //   * * 
	tet_obj[4].shekl[1][1] = 9; //
	tet_obj[4].shekl[1][2] = 9; //
	tet_obj[4].rot = 19;	

	tet_obj[19].shekl[0][1] = 9; //   *
	tet_obj[19].shekl[1][0] = 9; // * *
	tet_obj[19].shekl[1][1] = 9; // * 
	tet_obj[19].shekl[2][0] = 9; //  
	tet_obj[19].rot = 20;	 

	tet_obj[20].shekl[1][0] = 9; //
	tet_obj[20].shekl[1][1] = 9; // * * 
	tet_obj[20].shekl[2][1] = 9; //   * *
	tet_obj[20].shekl[2][2] = 9; //
	tet_obj[20].rot = 21;

	tet_obj[21].shekl[0][2] = 9; //     * 
	tet_obj[21].shekl[1][1] = 9; //   * * 
	tet_obj[21].shekl[1][2] = 9; //   *  
	tet_obj[21].shekl[2][1] = 9; //    
	tet_obj[21].rot = 4;
	
	
	
	tet_obj[5].shekl[0][1] = 9; //   * *
	tet_obj[5].shekl[0][2] = 9; // * * 
	tet_obj[5].shekl[1][0] = 9; //
	tet_obj[5].shekl[1][1] = 9; //
	tet_obj[5].rot = 22;	

	tet_obj[22].shekl[0][0] = 9; // * 
	tet_obj[22].shekl[1][0] = 9; // * *
	tet_obj[22].shekl[1][1] = 9; //   * 
	tet_obj[22].shekl[2][1] = 9; //  
	tet_obj[22].rot = 23;	

	tet_obj[23].shekl[1][1] = 9; //
	tet_obj[23].shekl[1][2] = 9; //   * *
	tet_obj[23].shekl[2][0] = 9; // * * 
	tet_obj[23].shekl[2][1] = 9; //
	tet_obj[23].rot = 24;

	tet_obj[24].shekl[0][1] = 9; //   *  
	tet_obj[24].shekl[1][1] = 9; //   * * 
	tet_obj[24].shekl[1][2] = 9; //     *  
	tet_obj[24].shekl[2][2] = 9; //    
	tet_obj[24].rot = 5;
		


	tet_obj[6].shekl[0][0] = 10; // * *
	tet_obj[6].shekl[0][1] = 10; //   * * 
	tet_obj[6].shekl[1][0] = 10; //
	tet_obj[6].shekl[1][1] = 10; //
	tet_obj[6].rot = 6;		
	
	tet_obj2[0].shekl[0][0] = 5;
	tet_obj2[0].shekl[0][1] = 5;
	tet_obj2[0].shekl[0][2] = 5;
	tet_obj2[0].shekl[0][3] = 5;
	
	tet_obj2[1].shekl[0][1] = 12;
	tet_obj2[1].shekl[1][0] = 12;
	tet_obj2[1].shekl[1][1] = 12;
	tet_obj2[1].shekl[1][2] = 12;
	
	
	tet_obj2[2].shekl[0][2] = 4;
	tet_obj2[2].shekl[1][0] = 4;
	tet_obj2[2].shekl[1][1] = 4;
	tet_obj2[2].shekl[1][2] = 4;
	
	tet_obj2[3].shekl[0][0] = 4;
	tet_obj2[3].shekl[1][0] = 4;
	tet_obj2[3].shekl[1][1] = 4;
	tet_obj2[3].shekl[1][2] = 4;
	
	
	tet_obj2[4].shekl[0][0] = 9;
	tet_obj2[4].shekl[0][1] = 9;
	tet_obj2[4].shekl[1][1] = 9;
	tet_obj2[4].shekl[1][2] = 9;
	
	tet_obj2[5].shekl[0][1] = 9;
	tet_obj2[5].shekl[0][2] = 9;
	tet_obj2[5].shekl[1][0] = 9;
	tet_obj2[5].shekl[1][1] = 9;
	
	tet_obj2[6].shekl[0][0] = 10;
	tet_obj2[6].shekl[0][1] = 10;
	tet_obj2[6].shekl[1][0] = 10;
	tet_obj2[6].shekl[1][1] = 10;
}


void Fast_Columns_Maker1(int col, int row, int space) {
	HL hc = GS;
	for (int i = 1; i <= 61 - col - space; i++)
		cout << ' ';
	for (int i = 1; i <= col; i++) {
		SCT(hc, tet[row][i]);
		cout << "\u2554\u2557";
	}
	SCT(hc, 7);
}

void Fast_Columns_Maker2(int col, int row, int space) {
	HL hc = GS;
	for (int i = 1; i <= 61 - col - space; i++)
		cout << ' ';
	for (int i = 1; i <= col; i++) {
		SCT(hc, tet[row][i]);
		cout << "\u255A\u255D";
	}
	SCT(hc, 7);
}

void logo() {
	HL hc = GS;
	for (int i = 1; i <= 54; i++)
		cout << " ";
	SCT(hc, 11);
	cout << "\u2554";
	for (int i = 1; i <= 11; i++)
		cout << "\u2550";
	cout << "\u2557";
	cout << '\n';
	for (int i = 1; i <= 54; i++)
		cout << " ";
	cout << "\u2551";
	SCT(hc, 4);
	cout << "T ";
	SCT(hc, 12);
	cout << "E ";
	SCT(hc, 6);
	cout << "T ";
	SCT(hc, 2);
	cout << "R ";
	SCT(hc, 9);
	cout << "I ";
	SCT(hc, 5);
	cout << "S";
	SCT(hc, 11);
	
	cout << "\u2551\n";
	for (int i = 1; i <= 54; i++)
		cout << " ";
	cout << "\u255A";
	for (int i = 1; i <= 3; i++)
		cout << "\u2550";
	cout << "\u2557   \u2554";
	for (int i = 1; i <= 3; i++)
		cout << "\u2550";
	cout << "\u255D\n";

	for (int i = 1; i <= 58; i++)
		cout << " ";
	cout << "\u2551   \u2551\n";
	for (int i = 1; i <= 58; i++)
		cout << " ";
	cout << "\u255A\u2550\u2550\u2550\u255D";
	cout << "\n\n";
	SCT(hc, 7);
}

void How_To_Play(string call, int x, int y, object gameobj) {
	system("cls");
	logo();
	HL hc = GS;
	string s;
	
	SCT(hc, 7);
	cout << "\u2573";
	SCT(hc, 4);
	s = "What Is Tetris?\n";
	for (int i = 0; i < s.size(); i++) {
		cout << s[i];
		usleep(1000);
	}
	SCT(hc, 12);
	s = "-Tetris is a puzzle video game, ";
    s += "In Tetris, players complete horizontal lines by moving differently shaped pieces \n(tetrominoes), ";
	s += "which descend onto the playing field. The completed lines disappear and grant the player points, ";
	s += "and \nthe player can proceed to fill the vacated spaces. The game ends when the uncleared lines ";
	s += "reach the top of the\n playing field\n";
	for (int i = 0; i < s.size(); i++) {
		if (kbhit()) {
			for (int j = i; j < s.size(); j++)
				cout << s[j];
			break;
		}
		cout << s[i];
		usleep(1000);
	}
	
	SCT(hc, 7);
	cout << "\n\u2573";
	SCT(hc, 2);
	s = "Gameplay\n";
	for (int i = 0; i < s.size(); i++) {
		cout << s[i];
		usleep(1000);
	}
	SCT(hc, 9);
	s = "-The game is played on a grid-based playing field, and the Tetriminos fall ";
	s += "from the top of the screen. You can move \nthe Tetriminos left or right using";
	s += "the arrow keys or the A and D keys. To rotate the 4.1g44444ljt80, you can use the ";
	s += "up \narrow key or the W key. The down arrow key or the S key can be used to make ";
	s += "the Tetriminos fall faster. The objective \nis to clear as many lines as possible ";
	s += "by filling complete horizontal lines with Tetriminos.\n\n";
	for (int i = 0; i < s.size(); i++) {
		if (kbhit()) {
			for (int j = i; j < s.size(); j++)
				cout << s[j];
			break;
		}
		cout << s[i];
		usleep(1000);
	}
	SCT(hc, 5);
	system("pause");
	if (call[0] == 'p')
		Pause_Menu(x, y, gameobj);
	else
		menu();
}

void menu() {
	system("cls");
	HL hc = GS;
	logo();
	SCT(hc, 4);
	for (int i = 1; i <= 51; i++)
		cout << " ";
	cout << "\u2554";
	for (int i = 1; i <= 16; i++)
		cout << "\u2550";
	cout << "\u2557\n";
	for (int i = 1; i <= 51; i++)
		cout << " ";
	cout << "\u2551";
	SCT(hc, 3);
	cout << "1)New Game";
	SCT(hc, 2);
	for (int i = 1; i <= 6; i++)
		cout << ' ';
	cout << "\u2551\n";
	for (int i = 1; i <= 51; i++)
		cout << " ";
	cout << "\u255A";
	for (int i = 1; i <= 16; i++)
		cout << "\u2550";
	cout << "\u255D\n";

	for (int i = 1; i <= 51; i++)
		cout << " ";
	
	cout << "\u2554";
	for (int i = 1; i <= 16; i++)
		cout << "\u2550";
	cout << "\u2557\n";
	for (int i = 1; i <= 51; i++)
		cout << " ";
	cout << "\u2551";
	SCT(hc, 3);
	cout << "2)How To Play";
	SCT(hc, 5);
	for (int i = 1; i <= 3; i++)
		cout << ' ';
	cout << "\u2551\n";
	for (int i = 1; i <= 51; i++)
		cout << " ";
	cout << "\u255A";
	for (int i = 1; i <= 16; i++)
		cout << "\u2550";
	cout << "\u255D\n";
	
	for (int i = 1; i <= 51; i++)
		cout << " ";
	cout << "\u2554";
	for (int i = 1; i <= 16; i++)
		cout << "\u2550";
	cout << "\u2557\n";
	for (int i = 1; i <= 51; i++)
		cout << " ";
	cout << "\u2551";
	SCT(hc, 3);
	cout << "3)Leaderboard";
	SCT(hc, 6);
	for (int i = 1; i <= 3; i++)
		cout << ' ';
	cout << "\u2551\n";
	for (int i = 1; i <= 51; i++)
		cout << " ";
	cout << "\u255A";
	for (int i = 1; i <= 16; i++)
		cout << "\u2550";
	cout << "\u255D\n";
	for (int i = 1; i <= 51; i++)
		cout << " ";
	cout << "\u2554";
	for (int i = 1; i <= 16; i++)
		cout << "\u2550";
	cout << "\u2557\n";
	for (int i = 1; i <= 51; i++)
		cout << " ";
	cout << "\u2551";
	SCT(hc, 3);
	cout << "4)Exit";
	SCT(hc, 4);
	
	for (int i = 1; i <= 10; i++)
		cout << ' ';
	cout << "\u2551\n";
	for (int i = 1; i <= 51; i++)
		cout << " ";
	cout << "\u255A";
	for (int i = 1; i <= 16; i++)
		cout << "\u2550";
	cout << "\u255D\n\n\n";
	char c = getch();
	while (c != '1' && c != '2' && c != '3' && c != '4')
		c = getch();
	object alaki;
	if (c == '1')
		New_Game_Menu();
	else if (c == '2')
		How_To_Play("menu", 0, 0, alaki);
	else if (c == '3')
		Leader_Board();
	else if (c == '4')
		Exit();
	SCT(hc, 7);
}

void New_Game_Menu() {
	pre();
	system("cls");
	logo();
	string s;
	string name;
	char ch;
	HL hc = GS;
	SCT(hc, 3);
	s = "Enter Your Name without space: ";
	for (int i = 0; i < s.size(); i++) {
		cout << s[i];
		usleep(2000);
	}
	SCT(hc, 7);
	cin >> user.name;
	system("cls");
	logo();
	s = "\nSelect Difficulty: \n";
	for (int i = 0; i < s.size(); i++) {
		cout << s[i];
		usleep(2000);
	}
	SCT(hc, 7);
	s = "    1)";
	for (int i = 0; i < s.size(); i++) {
		cout << s[i];
		usleep(2000);
	}
	SCT(hc, 2);
	s = " Easy  ";
	for (int i = 0; i < s.size(); i++) {
		cout << s[i];
		usleep(2000);
	}
	SCT(hc, 7);
	s = "    2)";
	for (int i = 0; i < s.size(); i++) {
		cout << s[i];
		usleep(2000);
	}
	SCT(hc, 4);
	s = " Hard\n";
	for (int i = 0; i < s.size(); i++) {
		cout << s[i];
		usleep(2000);
	}
	char mod = getch();
	while (mod != '1' && mod != '2')
		mod = getch();
	if (mod == '1') {
		SCT(hc, 2);
		user.mode = "Easy";
		s = "       \u2501\u2501\u2501\u2501\n\n";
		for (int i = 0; i < s.size(); i++) {
			cout << s[i];
			usleep(2000);
		}
	}
	else {
		user.mode = "Hard";
		s = "                    \u2501\u2501\u2501\u2501\n\n";
		for (int i = 0; i < s.size(); i++) {
			cout << s[i];
			usleep(2000);
		}
	}
	usleep(100000);
	system("cls");
	logo();

	SCT(hc, 3);
	s = "Please Enter The Number Of Rows: ";
	for (int i = 0; i < s.size(); i++) {
		cout << s[i];
		usleep(2000);
	}
	SCT(hc, 7);
	int row;
	cin >> row;
	
	SCT(hc, 3);
	s = "Please Enter The Number Of columns: ";
	for (int i = 0; i < s.size(); i++) {
		cout << s[i];
		usleep(2000);
	}
	SCT(hc, 7);
	int col;
	cin >> col;
	
	system("cls");
	logo();
	if (mod == '1')
		Easy_start_game(row, col);
	if (mod == '2')		
		Hard_start_game(row, col);
}