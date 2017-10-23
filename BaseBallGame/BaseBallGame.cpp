#include "BaseBallGame.h"

/* 
1. 3�ڸ� ���� ����(���ڿ��� ����)
2. ���� �Է� (���ڿ��� �Է�)
3. ��ȸ�� �� 5��
4. ���� ���
*/


class GameLuncher
{
public:
	int strike_value;
	int ball_value;
	int out_value;

	void GameMain(int coin)
	{
		bool game_over_chk = false;
		int f_coin = coin;
		Create_RanNum();
	}

private:
	int push_value;

	vector<string> Create_RanNum(void)
	{

		vector<int> store_rand;

		// srand �õ尪 ����
		srand((unsigned int)time(NULL));

		while(1)
		{
			if(store_rand.size() == 3)
			{
				// ������ ����
				store_rand = Rand_Sort(store_rand);
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
	GameLuncher game;
	int coin = 3;
	game.GameMain(coin);
}