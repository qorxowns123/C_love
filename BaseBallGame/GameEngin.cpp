#include "GameEngin.h"

vector<int> GameLuncher::CreateRanNum(int select_level)
{
	int push_value = 0;
	int choice_level = 0;
	vector<int> store_rand;

	if(select_level == 1)
	{
		choice_level = 3; // 3자리
	}
	else if(select_level == 2)
	{
		choice_level = 4; // 4자리
	}
	else
	{
		choice_level = 5; // 5자리
	}

	// srand 시드값 생성
	srand((unsigned int)time(NULL));

	while(1)
	{
		if(store_rand.size() == choice_level)
		{
			// 데이터 섞기
			store_rand = this->Rand_Sort(store_rand);
			break;
		}
		else
		{
			push_value = ((rand() % 9) + 1); // 1~9까지
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


void GameLuncher::AnswerMatch(vector<int> numlist, vector<int> answerlist)
{
	// vector<int> numlist : 3자리 정답 정수
	// vector<int> answerlist : 사용자 입력 3자리 정수

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
				if(loopjdx == (numlist.size()-1))
				{
					this->out_value = this->out_value + 1;
					break;
				}
				else{/**/}
			}
		}
	}

} // end AnswerMatch Func


vector<int> GameLuncher::Rand_Sort(vector<int> store_rand)
{
	vector<int> store_temp(store_rand.size());
	int loopidx, loopjdx = 0;
	int select_index = 0;
	int insert_index = 0;
	bool equal_flag = false;

	srand((unsigned int)time(NULL));

	for(loopidx = 0; loopidx < 9999; loopidx++)
	{
		select_index = (rand() % store_rand.size()); 
		insert_index = (rand() % store_rand.size());

		for(loopjdx = 0; loopjdx < store_temp.size(); loopjdx++)
		{
			if(store_temp[loopjdx] == store_rand[insert_index])
			{
				equal_flag = true;
			}else{/**/}
		}

		if(equal_flag == true)
		{
			equal_flag = false;
			continue;
		}
		else
		{
			store_temp[select_index] = store_rand[insert_index];
		}
	}

	return store_temp;

} // end Rand_Sort Func