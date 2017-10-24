#include "BaseBallGame.h"

/* 
1. 3자리 난수 생성
2. 정답 입력
4. 판정 출력
*/

class GameLuncher
{
public:
	int strike_value;
	int ball_value;
	int out_value;

	// 생성자
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
				cout << "실패 -------------------- 남은기회(" << coin_set << ")번" << endl;
				this->strike_value = 0;
				this->ball_value = 0;
				this->out_value = 0;
				
			}
			else
			{
				cout << "성공!!";
				break;
			}
		}

		/*cout << "모든 기회가 끝났습니다... 3초 뒤 종료됩니다.";
		Sleep(3000);*/
	}

private:
	bool AnswerMatch(vector<int> numlist)
	{
		bool match_chk = false;
		int answer_arr[3];
		int loopidx, loopjdx = 0;
		cout << "정답을 입력하세요(3자리 숫자)" << endl;


		for(loopidx = 0; loopidx < 3; loopidx++)
		{
			cout << loopidx + 1 <<"번째 자리 입력 : ";
			cin >> answer_arr[loopidx];

			if(cin.fail() == 1)
			{
				cout << "숫자가 아닌 문자를 입력하였습니다..." << endl;
				// 에러 플래그 초기화(이 코드가 없으면, cin.fail()의 값이 계속 1로 유지)
				cin.clear();
				// 입력 버퍼를 지움.. C언어의 fflush(stdin)과 같음..
				cin.ignore();
				cout << loopidx + 1 <<"번째 자리 입력 : ";
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
				// 같은 원소가 있다면
				if(answer_arr[loopidx] == numlist.at(loopjdx))
				{
					// 같은 위치인지 확인
					if(loopidx == loopjdx)
					{
						strike_value = strike_value + 1;
						break;
					}
					// 같은 위치가 아니라면
					else
					{
						ball_value = ball_value + 1;
						break;
					}
				}
				else
				{
					// 같은것이 없다면..
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

		// srand 시드값 생성
		srand((unsigned int)time(NULL));

		while(1)
		{
			if(store_rand.size() == 3)
			{
				// 데이터 섞기
				store_rand = this->Rand_Sort(store_rand);
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
	cout << "========= 총 기회 " << set_coin <<"번=========" << endl; 
	game.GameMain(set_coin);

}