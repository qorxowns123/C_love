#include "GameEngin.h"

vector<int> GameLuncher::CreateRanNum(int select_level)
{
	int push_value = 0;
	int choice_level = 0;
	vector<int> store_rand;

	if(select_level == 1)
	{
		choice_level = 3; // 3�ڸ�
	}
	else if(select_level == 2)
	{
		choice_level = 4; // 4�ڸ�
	}
	else
	{
		choice_level = 5; // 5�ڸ�
	}

	// srand �õ尪 ����
	srand((unsigned int)time(NULL));

	while(1)
	{
		if(store_rand.size() == choice_level)
		{
			// ������ ����
			store_rand = this->Rand_Sort(store_rand);
			break;
		}
		else
		{
			push_value = ((rand() % 9) + 1); // 1~9����
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


void GameLuncher::AnswerMatch(vector<int> numlist, vector<int> answerlist)
{
	// vector<int> numlist : 3�ڸ� ���� ����
	// vector<int> answerlist : ����� �Է� 3�ڸ� ����

	int loopidx, loopjdx = 0;
	
	this->strike_value = 0;
	this->ball_value = 0;
	this->out_value = 0;

	for(loopidx = 0; loopidx < numlist.size(); loopidx++)
	{
		for(loopjdx = 0; loopjdx < numlist.size(); loopjdx++)
		{
			// ���� ���Ұ� �ִٸ�
			if(answerlist[loopidx] == numlist[loopjdx])
			{
				// ���� ��ġ���� Ȯ��
				if(loopidx == loopjdx)
				{
					this->strike_value = this->strike_value + 1;
					break;
				}
				// ���� ��ġ�� �ƴ϶��
				else
				{
					this->ball_value = this->ball_value + 1;
					break;
				}
			}
			else
			{
				// �������� ���ٸ�..
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