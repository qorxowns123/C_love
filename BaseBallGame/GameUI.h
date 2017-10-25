#ifndef _GAMEUI_H__
#define _GAMEUI_H__

#include "IncludeHeader.h"
#include "GameEngin.h"


class GameUILuncher : GameLuncher
{

public:
	int get_coin;

	// »ý¼ºÀÚ
	GameUILuncher()
	{
		this->get_coin = GameLuncher::set_coin;
	}

	void GameUiMain(void);

private:
	void GameUiRun(void);
	void GameUiTitle(void);
	void gotoxy(int x, int y);
	vector<int> InputAnswer(vector<int> store_rand, int get_coin);

}; // end GameUILuncher Class

#endif