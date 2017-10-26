#ifndef _GAMEENGIN_H__
#define _GAMEENGIN_H__

#include "IncludeHeader.h"

class GameLuncher
{
protected:
	int strike_value;
	int ball_value;
	int out_value;
	int set_coin;

	// »ý¼ºÀÚ
	GameLuncher()
	{
		this->strike_value = 0;
		this->ball_value = 0;
		this->out_value = 0;
		this->set_coin = 5;
	}

	void AnswerMatch(vector<int> numlist, vector<int> answerlist);
	vector<int> CreateRanNum(void);
	vector<int> Rand_Sort(vector<int> store_rand);


}; // end GameLuncher Class





#endif