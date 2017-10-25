#include "GameUI.h"	

void GameUILuncher::GameUiMain(void)
{
	vector<int> store_rand;

	while(1)
	{
		GameUiTitle();
		// Ű �Է��� ������ �Ѿ���� ����
		if(getch())
		{
			// �ֿܼ� ǥ�õ� ȭ�� �����
			system("cls");
			// ���� ȭ�� ǥ��
			GameUiRun();
			// 3�ڸ� ���� ����
			store_rand = GameLuncher::CreateRanNum();
			break;
		}
		else{/**/}
	}
} // end GameUiMain Func


void GameUILuncher::GameUiRun(void)
{
	int x = 20;
	int y = 7;
	int loopidx = 0;

	SetConsoleTextAttribute(hC, 7);
	gotoxy(x,y);
	cout << "�ƢƢƢ�";
	SetConsoleTextAttribute(hC, 10);
	cout << " ��";
	SetConsoleTextAttribute(hC, 11);
	cout << " ��";
	SetConsoleTextAttribute(hC, 12);
	cout << " ��";
	SetConsoleTextAttribute(hC, 13);
	cout << " �� ";
	SetConsoleTextAttribute(hC, 7);
	cout << " �ƢƢƢ�";
	for(loopidx = 1; loopidx < 7; loopidx++)
	{
		gotoxy(x, (y + loopidx));
		cout << "��                          ��" << endl;

	}
	gotoxy(x, (y+loopidx));
	cout << "�ƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�" << endl;


	x = 28; y = 11;
	gotoxy(x,y);
	cout << "��" << endl;
	gotoxy(x+5,y);
	cout << "��" << endl;
	gotoxy(x+10,y);
	cout << "��" << endl;

} // end GameUiRun Func

vector<int> GameUILuncher::InputAnswer(void)
{
	int input_list;
	int loopidx = 0;
	int temp = 0;
	int x = 30; 
	int y = 2;
	bool check_flag = false;
	vector<int> answerlist;

	// ���� �Է�
	x = 28; y = 11;
	for(loopidx = 0; loopidx < 3; loopidx++)
	{
		gotoxy((x + temp), (y-1));
		cin >> input_list;
		answerlist.push_back(input_list);
		input_list = 0;
		temp += 5;
	}

	//check_flag = GameLuncher::AnswerMatch(store_rand, answerlist);

	return answerlist;

} // end InputAnswer Func


void GameUILuncher::GameUiTitle(void)
{
	int x = 5;
	int y = 5;
	int loopidx = 0;

	gotoxy(x,y);
	cout << "�ǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢ�" << endl;
	for(loopidx = 1; loopidx < 11; loopidx++)
	{
		gotoxy(x, (y+loopidx));
		if( (loopidx == 4) || (loopidx == 6) )
		{
			cout << "��               +------------------------------+             ��";

		}
		else if(loopidx == 5)
		{
			cout << "��";
			SetConsoleTextAttribute(hC, 12);
			cout << "                  | B A S E ";
			SetConsoleTextAttribute(hC, 13);
			cout << "B A L L";
			SetConsoleTextAttribute(hC, 14);
			cout << "  G A M E |";
			SetConsoleTextAttribute(hC, 7);
			cout << "              ��";
		}
		else if(loopidx == 8)
		{
			cout << "��                   Press any key to start                   ��";
		}
		else
		{
			cout << "��                                                            ��";
		}

	}

	gotoxy(x, (y+loopidx));
	cout << "�ǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢ�" << endl;

} // end GameUiTitle Func


void GameUILuncher::gotoxy(int x, int y)
{
	COORD Pos = {x-1, y-1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

} // end gotoxy Func