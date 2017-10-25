#include "GameEngin.h"

bool GameLuncher::AnswerMatch(vector<int> numlist, vector<int> answerlist)
{
	// vector<int> numlist : 3자리 정답 정수
	// vector<int> answerlist : 사용자 입력 3자리 정수

	bool match_chk = false;
	int loopidx, loopjdx = 0;

	this->strike_value = 0;
	this->ball_value = 0;
	this->out_value = 0;


	for(loopidx = 0; loopidx < numlist.size(); loopidx++)
	{
		for(loopjdx = 0; loopjdx < numlist.size(); loopjdx++)
		{
			// 같은 원소가 있다면
			if(answerlist[loopidx] == numlist[loopjdx])
			{
				// 같은 위치인지 확인
				if(loopidx == loopjdx)
				{
					this->strike_value = this->strike_value + 1;
					break;
				}
				// 같은 위치가 아니라면
				else
				{
					this->ball_value = this->ball_value + 1;
					break;
				}
			}
			else
			{
				// 같은것이 없다면..
				if(loopjdx == 2)
				{
					this->out_value = this->out_value + 1;
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

	return match_chk;
}


vector<int> GameLuncher::CreateRanNum(void)
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


vector<int> GameLuncher::Rand_Sort(vector<int> store_rand)
{
	vector<int> store_temp;

	store_temp.push_back(store_rand[2]);
	store_temp.push_back(store_rand[0]);
	store_temp.push_back(store_rand[1]);

	return store_temp;

} // end Rand_Sort Func