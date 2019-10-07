#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORD_CNT	10

char word_list[WORD_CNT][15] = {"monkey", "elephant", "dog", "sheep", "pig", "lion", "tiger", "puma", "turtle", "fox"};

void init_game(void);
char* select_word(void);
char insert_word(void);

void main(void)
{
	char *word;
	init_game();
	word = select_word();
	insert_word();
}

void init_game(void)
{
	printf("============================================\n");
	printf("### 단어 맞추기 게임!\n");
	printf("> 영어 단어가 랜덤으로 주어지고, 가능한 적은 횟수로 알파뱃을 입력하여 영어 단어를 맞추는 게임입니다!\n");
	printf("> 게임 시작합니다~!\n");
	printf("============================================\n");
}

char* select_word(void)
{
	unsigned int loopidx = 0;
	unsigned int select_index = 0;

	srand(time(NULL));

	for(loopidx = 0; loopidx < 9; loopidx++)
	{
		select_index = (rand() % 14);
	}

	return word_list[select_index];
}

char insert_word(void)
{
	char word;

	printf("<Info> :: 영어 단어를 입력하세요(a~z) : ");
	scanf("%c", &word);

	return word;
}