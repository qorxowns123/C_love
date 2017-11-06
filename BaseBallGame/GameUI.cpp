#include "GameUI.h"	

void GameUILuncher::GameUiMain(void)
{
	vector<int> numlist;
	vector<int> answerlist;
	int select_level = 0;
	bool checkflag = false;

	while(1)
	{
		GameUiTitle();
		if(getch())
		{
			break;
		}
		else{/**/}
	}

	while(1)
	{
		// ���̵� ����
		select_level = SelectLevel();
		// Ű �Է��� ������ �Ѿ���� ����
		if(select_level > 0)
		{
			// �ֿܼ� ǥ�õ� ȭ�� �����
			system("cls");
			// ���� ȭ�� ǥ��
			GameUiRun(answerlist);

			// ���̵� ���ÿ� ���� ���� ����
			numlist = GameLuncher::CreateRanNum(select_level);
			break;
		}
		else{/**/}
	}

	while(checkflag == false)
	{
		// ���� �Է�
		answerlist = InputAnswer(select_level);

		// ���� ��ġ
		GameLuncher::AnswerMatch(numlist, answerlist);
		
		system("cls");
		GameUiRun(answerlist);

		// ���� ���
		checkflag = PrintResult(select_level);

		if(checkflag != false)
		{
			gotoxy(24, 18);
			cout << "Game Over" << endl;
			break;
		}else{/**/}
	}


} // end GameUiMain Func


void GameUILuncher::GameUiRun(vector<int> answerlist)
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


	x = 32; y = 11;
	gotoxy(x,y);
	cout << "��" << endl;
	gotoxy(x+2, y);
	cout << "��" << endl;
	gotoxy(x+4, y);
	cout << "��" << endl;

	gotoxy(62, 2);
	cout << "History" << endl;
	gotoxy(58, 3);
	cout << "==================" << endl;

	if(answerlist.size() != 0)
	{
		HistoryPrint(answerlist);
	}
	else{/**/}

} // end GameUiRun Func

int GameUILuncher::SelectLevel(void)
{
	int x = 5;
	int y = 5;
	int loopidx = 0;
	int select_level = 0;

	gotoxy(x,y);
	cout << "�ǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢ�" << endl;
	for(loopidx = 1; loopidx < 11; loopidx++)
	{
		gotoxy(x, (y+loopidx));
		if (loopidx == 3)
		{
			cout << "��              +---------- ���̵� ���� ----------+           ��";
		}
		else if(loopidx == 5)
		{
			cout << "��";
			SetConsoleTextAttribute(hC, 12);
			cout << "                  1. 3�ڸ�";
			SetConsoleTextAttribute(hC, 13);
			cout << " 2. 4�ڸ�";
			SetConsoleTextAttribute(hC, 14);
			cout << "  3. 5�ڸ�";
			SetConsoleTextAttribute(hC, 7);
			cout << "               ��";
		}
		else if(loopidx == 8)
		{
			cout << "��                     Select Level :                         ��";
		}
		else
		{
			cout << "��                                                            ��";
		}
	}


	gotoxy(x, (y+loopidx));
	cout << "�ǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢ�" << endl;

	gotoxy(x+40, y+8);
	cin >> select_level;
	// ���ڰ� �ƴ� ���� �Է� ��...
	if(cin.fail())
	{
		x = 19; y = 18;
		gotoxy(x, y);
		cout << "�ùٸ� ���̵� ������ ���ֽʽÿ�" << endl;
		gotoxy(x+40, y+8);
		cout << "        ";
		cin.clear();
		cin.ignore();
		select_level = SelectLevel();
	} else{/**/}

	return select_level;

} // end SelectLevel Func

vector<int> GameUILuncher::InputAnswer(int select_level)
{
	int input_list;
	int loopidx = 0;
	int value_min, value_max;
	int x = 30; 
	int y = 2;
	bool check_flag = false;
	vector<int> answerlist;

	// ���� �Է�
	x = 32; y = 10;
	gotoxy(x, y);
	cin >> input_list;

	// ���ڰ� �ƴ� ���� �Է� ��...
	if(cin.fail())
	{
		x = 17; y = 17;
		gotoxy(x, y);
		cout << "�����̿ܿ��� �Է��� ���� �ʽ��ϴ�..." << endl;
		x = 32; y = 10;
		gotoxy(x, y);
		cout << "        ";
		cin.clear();
		cin.ignore();
		answerlist = InputAnswer(select_level);
	}
	// ���ڸ��� �Է��Ͽ��ٸ�..
	else
	{
		if(select_level == 1)
		{
			value_min = 100;
			value_max = 999;
		}
		else if(select_level == 2)
		{
			value_min = 1000;
			value_max = 9999;
		}
		else
		{
			value_min = 10000;
			value_max = 99999;
		}

		// �ڸ����� �Ѿ�� ���� �Է� ��...
		if( (input_list > value_max) || (input_list < value_min) )
		{
			x = 17; y = 17;
			gotoxy(x, y);
			cout << "�Է� ������ �ڸ����� ��Ȯ�� �Է����ּ���..." << endl;
			cin.ignore();
			x = 32; y = 10;
			gotoxy(x, y);
			cout << "        ";
			answerlist = InputAnswer(select_level);
		}
		else
		{
			answerlist = CalInValue(select_level, input_list);
		}
	}
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


bool const GameUILuncher::PrintResult(int select_level)
{
	bool checkflag = false;

	gotoxy(24, 16);
	SetConsoleTextAttribute(hC, 10);
	cout << this->strike_value <<" Strike ";
	SetConsoleTextAttribute(hC, 14);
	cout << this->ball_value <<" Ball ";
	SetConsoleTextAttribute(hC, 12);
	cout << this->out_value <<" Out ";
	SetConsoleTextAttribute(hC, 7);

	if(this->strike_value == (select_level+2))
	{
		checkflag = true;
	}
	else
	{
		checkflag = false;
	}

	return checkflag;

} // end PrintResult Func

void const GameUILuncher::HistoryPrint(vector<int> answerlist)
{
	int tempstore = 0;
	int loopidx = 0;
	int mul_value = 0;
	static vector<int> store_num_list;
	static vector<int> store_strike_list;
	static vector<int> store_ball_list;
	static vector<int> store_out_list;

	if(answerlist.size() == 3)
	{
		mul_value = 100;
	}
	else if(answerlist.size() == 4)
	{
		mul_value = 1000;
	}
	else
	{
		mul_value = 10000;
	}

	for(loopidx = 0; loopidx < answerlist.size(); loopidx++)
	{
		tempstore = tempstore + (answerlist.at(loopidx) * mul_value);
		mul_value = mul_value / 10;
	}

	store_num_list.push_back(tempstore);
	store_strike_list.push_back(GameLuncher::strike_value);
	store_ball_list.push_back(GameLuncher::ball_value);
	store_out_list.push_back(GameLuncher::out_value);

	gotoxy(60, 4);

	for(loopidx = 0; loopidx < store_num_list.size(); loopidx++)
	{
		gotoxy(60, (4 + loopidx));
		
		cout << store_num_list.at(loopidx) << " --- ";
		SetConsoleTextAttribute(hC, 10);
		cout << store_strike_list.at(loopidx) << " ";
		SetConsoleTextAttribute(hC, 14);
		cout << store_ball_list.at(loopidx) << " ";
		SetConsoleTextAttribute(hC, 12);
		cout << store_out_list.at(loopidx);
		SetConsoleTextAttribute(hC, 7);
	}
	

} // end HistoryPrint Func

vector<int> GameUILuncher::CalInValue(int select_level, int input_list)
{
	int temp_value = 0;
	vector<int> temp_vector;

	// 3�ڸ�
	if(select_level == 1)
	{
		temp_vector.push_back(input_list / 100);
		temp_value = input_list % 100;

		temp_vector.push_back(temp_value / 10);
		temp_value = temp_value % 10;

		temp_vector.push_back(temp_value);
	}
	// 4�ڸ�
	else if(select_level == 2)
	{
		temp_vector.push_back(input_list / 1000);
		temp_value = input_list % 1000;

		temp_vector.push_back(temp_value / 100);
		temp_value = temp_value % 100;

		temp_vector.push_back(temp_value / 10);
		temp_value = temp_value % 10;

		temp_vector.push_back(temp_value);
	}
	// 5�ڸ�
	else
	{
		temp_vector.push_back(input_list / 10000);
		temp_value = input_list % 10000;

		temp_vector.push_back(temp_value / 1000);
		temp_value = temp_value % 1000;

		temp_vector.push_back(temp_value / 100);
		temp_value = temp_value % 100;

		temp_vector.push_back(temp_value / 10);
		temp_value = temp_value % 10;

		temp_vector.push_back(temp_value);
	}

	return temp_vector;
} // CalInValue Func



void GameUILuncher::gotoxy(int x, int y)
{
	COORD Pos = {x-1, y-1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

} // end gotoxy Func




