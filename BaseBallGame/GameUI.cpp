#include "GameUI.h"	

void GameUILuncher::GameUiMain(void)
{
	vector<int> store_rand;
	while(1)
	{
		GameUiTitle();
		// 키 입력을 받으면 넘어가도록 변경
		if(getch())
		{
			// 콘솔에 표시된 화면 지우기
			system("cls");
			break;
		}
		else{/**/}
	}

	// 3자리 난수 생성
	store_rand = GameLuncher::CreateRanNum();

	while(this->get_coin > -1)
	{
		InputAnswer(store_rand, this->get_coin);
		if(this->get_coin == -1)
		{
			// 게임오버 함수 만들기
			break;
		}
	}
} // end GameUiMain Func


void GameUILuncher::GameUiRun(void)
{
	int x = 20;
	int y = 7;
	int loopidx = 0;

	SetConsoleTextAttribute(hC, 7);
	gotoxy(x,y);
	cout << "▒▒▒▒";
	SetConsoleTextAttribute(hC, 10);
	cout << " 정";
	SetConsoleTextAttribute(hC, 11);
	cout << " 답";
	SetConsoleTextAttribute(hC, 12);
	cout << " 입";
	SetConsoleTextAttribute(hC, 13);
	cout << " 력 ";
	SetConsoleTextAttribute(hC, 7);
	cout << " ▒▒▒▒";
	for(loopidx = 1; loopidx < 7; loopidx++)
	{
		gotoxy(x, (y + loopidx));
		cout << "▒                          ▒" << endl;

	}
	gotoxy(x, (y+loopidx));
	cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;


	x = 28; y = 11;
	gotoxy(x,y);
	cout << "━" << endl;
	gotoxy(x+5,y);
	cout << "━" << endl;
	gotoxy(x+10,y);
	cout << "━" << endl;

} // end GameUiRun Func

vector<int> GameUILuncher::InputAnswer(vector<int> store_rand, int get_coin)
{
	int input_list[3];
	int loopidx = 0;
	int temp = 0;
	int x = 30; 
	int y = 2;
	bool check_flag = false;
	vector<int> answerlist;

	// 게임 화면 표시
	GameUiRun();

	// 코인 표시
	gotoxy(x, y);
	cout << "COIN : " << get_coin << endl;

	// 정답 입력
	x = 28; y = 11;
	for(loopidx = 0; loopidx < 3; loopidx++)
	{
		gotoxy((x + temp), (y-1));
		cin >> input_list[loopidx];
		// 숫자가 아닌 문자가 입력되었을 경우...
		if(cin.fail() == 1)
		{
			x = 19; y = 19;
			gotoxy(x, y);
			cout << "숫자가 아닌 문자를 입력하였습니다" << endl;
			// 에러 플래그 초기화(이 코드가 없으면, cin.fail()의 값이 계속 1로 유지)
			cin.clear();
			// 입력 버퍼를 지움... C언어의 fflush(stdin)과 같음
			cin.ignore();
			GameUiRun();
			cin >> input_list[loopidx];
		}
		answerlist.push_back(input_list[loopidx]);
		temp += 5;
	}

	check_flag = GameLuncher::AnswerMatch(store_rand, answerlist);

	x = 25; y = 16;
	gotoxy(x, y);

	if(check_flag == false)
	{
		get_coin = get_coin - 1;
		this->get_coin = get_coin;
		SetConsoleTextAttribute(hC, 12);
		cout << GameLuncher::strike_value <<" Strike ";
		SetConsoleTextAttribute(hC, 9);
		cout << GameLuncher::ball_value <<" Ball ";
		SetConsoleTextAttribute(hC, 10);
		cout << GameLuncher::out_value <<" Out" << endl;
	}
	else
	{
		cout << "정 to the 답" << endl;
	}

	return answerlist;

} // end InputAnswer Func


void GameUILuncher::GameUiTitle(void)
{
	int x = 5;
	int y = 5;
	int loopidx = 0;

	gotoxy(x,y);
	cout << "▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤" << endl;
	for(loopidx = 1; loopidx < 11; loopidx++)
	{
		gotoxy(x, (y+loopidx));
		if( (loopidx == 4) || (loopidx == 6) )
		{
			cout << "▤               +------------------------------+             ▤";

		}
		else if(loopidx == 5)
		{
			cout << "▤";
			SetConsoleTextAttribute(hC, 12);
			cout << "                  | B A S E ";
			SetConsoleTextAttribute(hC, 13);
			cout << "B A L L";
			SetConsoleTextAttribute(hC, 14);
			cout << "  G A M E |";
			SetConsoleTextAttribute(hC, 7);
			cout << "              ▤";
		}
		else if(loopidx == 8)
		{
			cout << "▤                   Press any key to start                   ▤";
		}
		else
		{
			cout << "▤                                                            ▤";
		}

	}

	gotoxy(x, (y+loopidx));
	cout << "▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤" << endl;

} // end GameUiTitle Func


void GameUILuncher::gotoxy(int x, int y)
{
	COORD Pos = {x-1, y-1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

} // end gotoxy Func