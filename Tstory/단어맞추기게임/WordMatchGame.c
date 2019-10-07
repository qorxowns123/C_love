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
	printf("### �ܾ� ���߱� ����!\n");
	printf("> ���� �ܾ �������� �־�����, ������ ���� Ƚ���� ���Ĺ��� �Է��Ͽ� ���� �ܾ ���ߴ� �����Դϴ�!\n");
	printf("> ���� �����մϴ�~!\n");
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

	printf("<Info> :: ���� �ܾ �Է��ϼ���(a~z) : ");
	scanf("%c", &word);

	return word;
}