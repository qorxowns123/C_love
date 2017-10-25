#ifndef _GAMEUI_H__
#define _GAMEUI_H__

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
	vector<int> InputAnswer(void);

}; // end GameUILuncher Class

#endif