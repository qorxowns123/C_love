#include "BaseBallGame.h"

/* 
1. 3자리 난수 생성(문자열로 리턴)
2. 정답 입력 (문자열로 입력)
3. 기회는 총 5번
4. 판정 출력
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
	int loopidx;

	vector<string> Create_RanNum(void)
	{

		vector<int> store_rand;
		vector<string> store_string;

		// srand 시드값 생성
		srand((unsigned int)time(NULL));

		while(1)
		{
			if(store_rand.size() == 3)
			{
				// 데이터 섞기
				store_rand = Rand_Sort(store_rand);
				break;
			}
			else
			{
				push_value = (rand() % 10);
				// 원소 넣기
				store_rand.push_back(push_value);
				// 오름차순 정렬
				sort(store_rand.begin(), store_rand.end());
				// 중복 제거
				store_rand.erase(unique(store_rand.begin(), store_rand.end()), store_rand.end());
			}
		}

		

		for(loopidx = 0; loopidx < store_rand.size(); loopidx++)
		{
			store_string.push_back(IntToString(store_rand[loopidx]));
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

	string IntToString(int n)
	{
		stringstream s;

		s << n;

		return s.str();

	} // end IntToString Func



}; // end GameLuncher Class




void main(void)
{
	GameLuncher game;
	int coin = 3;
	game.GameMain(coin);
}