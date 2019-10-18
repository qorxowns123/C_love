#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WORD_CNT	10

char word_list[WORD_CNT][15] = {"monkey", "elephant", "dog", "sheep", "pig", "lion", "tiger", "puma", "turtle", "fox"};

void init_game(void);
char* select_word(void);
char insert_word(void);
unsigned char match_string(char* string, char* _string, char word);

void main(void)
{
	char *string;
	char *_string;
	char word;
	unsigned char match_check = 0;
	unsigned int string_len = 0;
	unsigned int loopidx = 0;

	init_game();
	string = select_word();
	string_len = strlen(string);
	_string = (char*)malloc(sizeof(char) * (string_len + 1));

	for(loopidx = 0; loopidx < string_len; loopidx++)
	{
		_string[loopidx] = '_';
	}
	_string[string_len] = '\0';


	while(match_check == 0)
	{
		word = insert_word();
		match_check = match_string(string, _string, word);
	}

	printf("### �����մϴ�!!\n");
}

/* ########################## */
/* ### Sub Function List ### */
/* ########################## */
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
		select_index = (rand() % 9);
	}

	return word_list[select_index];
}

char insert_word(void)
{
	char word;

	printf("<Info> :: ���� �ܾ �Է��ϼ���(a~z) : ");
	scanf(" %c", &word);

	return word;
}

unsigned char match_string(char* string, char* _string, char word)
{
	unsigned int string_len = 0;
	unsigned int loopidx = 0;
	unsigned char return_check = 0;

	static unsigned int check_cnt = 0;

	string_len = strlen(string);


	printf("### Result : ");
	for(loopidx = 0; loopidx < string_len; loopidx++)
	{
		if(word == string[loopidx])
		{
			_string[loopidx] = word;
			check_cnt++;
		}
		else{/**/}
	}

	printf("%s\n\n", _string);
	//printf("\n");

	if(check_cnt == string_len)
	{
		return_check = 1;
	}
	else
	{
		return_check = 0;
	}

	return return_check;


}
