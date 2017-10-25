#include "GameEngin.h"

bool GameLuncher::AnswerMatch(vector<int> numlist, vector<int> answerlist)
{
	// vector<int> numlist : 3�ڸ� ���� ����
	// vector<int> answerlist : ����� �Է� 3�ڸ� ����

	bool match_chk = false;
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


vector<int> GameLuncher::Rand_Sort(vector<int> store_rand)
{
	vector<int> store_temp;

	store_temp.push_back(store_rand[2]);
	store_temp.push_back(store_rand[0]);
	store_temp.push_back(store_rand[1]);

	return store_temp;

} // end Rand_Sort Func