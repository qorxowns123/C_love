#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ### Global Variable */
signed int g_answer[5]; /* �Էµ� ���� */
signed int g_exam[5]; /* ���� */
unsigned int select_level;

typedef struct strike_ball_out_Str
{
	unsigned char strike; /* ��Ʈ����ũ */
	unsigned char ball; /* �� */
	unsigned char out; /* �ƿ� */

} strike_ball_out_str;

strike_ball_out_str strike_ball_out;

/* ### Function List */
void select_level_func(void);
void create_rand(void);
unsigned char insert_answer(void);
unsigned char answer_match(void);

/***********************************************************/
void main(void)
{
	unsigned char answer = 0;
	unsigned char value_check = 0;
	
	select_level_func();
	create_rand();

	while(answer == 0)
	{
		value_check = insert_answer();
		if(value_check == 1)
		{
			answer = answer_match();
			if (answer == 1)
			{
				printf("\n### �����մϴ�!! �����Դϴ�~!\n");
				printf("������ �����մϴ�...\n");
				break;
			}
			else{/**/}
		}
		else{/**/}
	}
	return;
}

/* answer_match */
unsigned char answer_match(void)
{
	unsigned int loopidx = 0;
	unsigned int loopjdx = 0;

	unsigned char game_level = 0;
	unsigned char answer_flag = 0;
	unsigned char strike_flag[5] = {0,};

	strike_ball_out.strike = 0;
	strike_ball_out.ball = 0;
	strike_ball_out.out = 0;

	switch(select_level)
	{
	case 1:
		game_level = 3;
		/* 3�ڸ� */
		break;
	case 2:
		game_level = 4;
		/* 4�ڸ� */
		break;
	case 3:
	default:
		game_level = 5;
		/* 5�ڸ� */
		break;
	}

	/* ��Ʈ����ũ, ��, �ƿ� �Ǻ� ���� */
	for(loopidx = 0; loopidx < game_level; loopidx++)
	{
		if(g_answer[loopidx] == g_exam[loopidx])
		{
			strike_ball_out.strike += 1;
			strike_flag[loopidx] = 1;
		}
	}

	for(loopidx = 0; loopidx < game_level; loopidx++)
	{
		if(strike_flag[loopidx] == 1)
		{
			continue;
		}
		for(loopjdx = 0; loopjdx < game_level; loopjdx++)
		{
			if(g_answer[loopidx] == g_exam[loopjdx])
			{
				strike_ball_out.ball += 1;
				break;
			}
			else if(loopjdx == (game_level-1))
			{
				strike_ball_out.out += 1;
			}
			else{/**/}
		}
		
	}


	/* ���ڸ� ��� ����ٸ�.. ���� Ŭ����! */
	if(strike_ball_out.strike == game_level)
	{
		answer_flag = 1;
	}
	else{/**/};

	printf(">> ���� ���ھ� : S(%d) B(%d) O(%d)\n\n", strike_ball_out.strike, strike_ball_out.ball, strike_ball_out.out);

	return answer_flag;
}

/* insert_answer */
unsigned char insert_answer(void)
{
	unsigned int get_answer = 0;
	unsigned char value_check = 1;
	static unsigned char answer_cnt = 1;

	printf("> %dȸ�� ���� �Է� : ", answer_cnt);
	scanf("%d", &get_answer);

	/* ���ڿ� ���� ����ó�� �ϱ� */
	switch(select_level)
	{
	case 1:
		/* 3�ڸ� */
		if ((get_answer < 0) || (get_answer > 999))
		{
			value_check = 0;
		}
		else
		{
			g_answer[0] = get_answer / 100;

			get_answer = get_answer % 100;
			g_answer[1] = get_answer / 10;

			g_answer[2] = get_answer % 10;
		}
		break;
	case 2:
		/* 4�ڸ� */
		if ((get_answer < 1000) || (get_answer > 9999))
		{
			value_check = 0;
		}
		else
		{
			g_answer[0] = get_answer / 1000;

			get_answer = get_answer % 1000;
			g_answer[1] = get_answer / 100;

			get_answer = get_answer % 100;
			g_answer[2] = get_answer / 10;

			g_answer[3] = get_answer % 10;
		}
		break;
	case 3:
	default:
		/* 5�ڸ� */
		if ((get_answer < 10000) || (get_answer > 99999))
		{
			value_check = 0;
		}
		else
		{
			g_answer[0] = get_answer / 10000;

			get_answer = get_answer % 10000;
			g_answer[1] = get_answer / 1000;

			get_answer = get_answer % 1000;
			g_answer[2] = get_answer / 100;

			get_answer = get_answer % 100;
			g_answer[3] = get_answer / 10;

			g_answer[4] = get_answer % 10;
		}
		break;
	}

	if(value_check == 0)
	{
		printf("### �߸��� ������ ���� �Է��Ͽ����ϴ�\n");
	} else{/**/}

	answer_cnt++;

	return value_check;
}

/* select_level_func */
void select_level_func(void)
{
	printf("=============================\n");
	printf("*** ���� �߱� ���� ***\n");
	printf("=============================\n");
	
	
	printf("1. 3�ڸ�\n");
	printf("2. 4�ڸ�\n");
	printf("3. 5�ڸ�\n");
	printf("���̵��� �����ϼ��� : ");

	scanf("%d", &select_level);

	switch(select_level)
	{
	case 1:
		printf("3�ڸ��� �����ϼ̽��ϴ�\n");
		break;
	case 2:
		printf("4�ڸ��� �����ϼ̽��ϴ�\n");
		break;
	case 3:
	default:
		printf("5�ڸ��� �����ϼ̽��ϴ�\n");
		break;
	}

	printf("\n### ���� �߱� ������ �����մϴ�!!\n");

	return;
}

/* create_rand */
void create_rand(void)
{
	unsigned int loopidx = 0;
	unsigned char game_level = 0;

	g_exam[0] = -1;
	g_exam[1] = -1;
	g_exam[2] = -1;
	g_exam[3] = -1;
	g_exam[4] = -1;

	g_answer[0] = -1;
	g_answer[1] = -1;
	g_answer[2] = -1;
	g_answer[3] = -1;
	g_answer[4] = -1;
	
	srand(time(NULL));

	switch(select_level)
	{
	case 1:
		game_level = 3;
		break;
	case 2:
		game_level = 4;
		break;
	case 3:
	default:
		game_level = 5;
		break;
	}

	for(loopidx = 0; loopidx < game_level; loopidx++)
	{
		g_exam[loopidx] = (rand() % 9);
	}

	return;
}
/***********************************************************/

