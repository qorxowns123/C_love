#ifndef _GAMEUI_H__
#define _GAMEUI_H__

#include "GameEngin.h"


class GameUILuncher : GameLuncher
{

public:
	void GameUiMain(void);

private:
	void GameUiRun(vector<int> answerlist);
	void GameUiTitle(void);
	int SelectLevel(void);
	vector<int> InputAnswer(int select_level);
	bool const PrintResult(int select_level);
	void const HistoryPrint(vector<int> answerlist);
	vector<int> CalInValue(int select_level, int input_list);
	void gotoxy(int x, int y);

}; // end GameUILuncher Class

#endif