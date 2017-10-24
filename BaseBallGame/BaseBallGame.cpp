#include "BaseBallGame.h"

/* 
1. 3�ڸ� ���� ����
2. ���� �Է�
4. ���� ���
*/

class GameLuncher
{
public:
	int strike_value;
	int ball_value;
	int out_value;

	// ������
	GameLuncher()
	{
		strike_value = 0;
		ball_value = 0;
		out_value = 0;
	}

	void GameMain(int get_coin)
	{
		vector<int> numlist;
		bool game_over_chk = false;
		int coin_set = get_coin;
		numlist = this->CreateRanNum();

		while(coin_set > 0)
		{
			game_over_chk = this->AnswerMatch(numlist);
			if(game_over_chk == false)
			{
				coin_set--;
				cout << "���� -------------------- ������ȸ(" << coin_set << ")��" << endl;
				this->strike_value = 0;
				this->ball_value = 0;
				this->out_value = 0;
				
			}
			else
			{
				cout << "����!!";
				break;
			}
		}

		/*cout << "��� ��ȸ�� �������ϴ�... 3�� �� ����˴ϴ�.";
		Sleep(3000);*/
	}

private:
	bool AnswerMatch(vector<int> numlist)
	{
		bool match_chk = false;
		int answer_arr[3];
		int loopidx, loopjdx = 0;
		cout << "������ �Է��ϼ���(3�ڸ� ����)" << endl;


		for(loopidx = 0; loopidx < 3; loopidx++)
		{
			cout << loopidx + 1 <<"��° �ڸ� �Է� : ";
			cin >> answer_arr[loopidx];

			if(cin.fail() == 1)
			{
				cout << "���ڰ� �ƴ� ���ڸ� �Է��Ͽ����ϴ�..." << endl;
				// ���� �÷��� �ʱ�ȭ(�� �ڵ尡 ������, cin.fail()�� ���� ��� 1�� ����)
				cin.clear();
				// �Է� ���۸� ����.. C����� fflush(stdin)�� ����..
				cin.ignore();
				cout << loopidx + 1 <<"��° �ڸ� �Է� : ";
				cin >> answer_arr[loopidx];
			}
			else
			{
				continue;
			}
		}


		for(loopidx = 0; loopidx < numlist.size(); loopidx++)
		{
			for(loopjdx = 0; loopjdx < numlist.size(); loopjdx++)
			{
				// ���� ���Ұ� �ִٸ�
				if(answer_arr[loopidx] == numlist.at(loopjdx))
				{
					// ���� ��ġ���� Ȯ��
					if(loopidx == loopjdx)
					{
						strike_value = strike_value + 1;
						break;
					}
					// ���� ��ġ�� �ƴ϶��
					else
					{
						ball_value = ball_value + 1;
						break;
					}
				}
				else
				{
					// �������� ���ٸ�..
					if(loopjdx >= 2)
					{
						out_value = out_value + 1;
						break;
					}
					else{/**/}
				}
			}
		}

		if(strike_value == 3)
		{
			match_chk = true;
		}
		else
		{
			match_chk = false;
		}

		cout << "Strike(" << strike_value <<") Ball(" << ball_value << ") Out(" << out_value <<")" << endl;

		return match_chk;
	}


	vector<int> CreateRanNum(void)
	{

		vector<int> store_rand;
		int push_value;

		// srand �õ尪 ����
		srand((unsigned int)time(NULL));

		while(1)
		{
			if(store_rand.size() == 3)
			{
				// ������ ����
				store_rand = this->Rand_Sort(store_rand);
				break;
			}
			else
			{
				push_value = (rand() % 10);
				// ���� �ֱ�
				store_rand.push_back(push_value);
				// �������� ����
				sort(store_rand.begin(), store_rand.end());
				// �ߺ� ����
				store_rand.erase(unique(store_rand.begin(), store_rand.end()), store_rand.end());
			}
		}

		return store_rand;


	} // end Create_RanNum Func

	vector<int> Rand_Sort(vector<int> store_rand)
	{
		vector<int> store_temp;

		store_temp.push_back(store_rand[2]);
		store_temp.push_back(store_rand[0]);
		store_temp.push_back(store_rand[1]);

		return store_temp;

	} // end Rand_Sort Func


}; // end GameLuncher Class




void main(void)
{
	int set_coin = 2;
	GameLuncher game;
	cout << "========= �� ��ȸ " << set_coin <<"��=========" << endl; 
	game.GameMain(set_coin);

}