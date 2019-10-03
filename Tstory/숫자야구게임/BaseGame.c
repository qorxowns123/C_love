#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ### Global Variable */
signed int g_answer[5]; /* �Էµ� ���� */
signed int g_exam[5]; /* ���� */
unsigned int select_level;

typedef struct strike_ball_out_Str
{
	unsigned char strike;
	unsigned char ball;
	unsigned char out;

} strike_ball_out_str;

strike_ball_out_str strike_ball_out;

/* ### Function List */
void select_level_func(void);
void create_rand(void);
unsigned char insert_answer(void);
unsigned char answer_match(void);

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


unsigned char answer_match(void)
{
	unsigned int loopidx = 0;
	unsigned int loopjdx = 0;
	unsigned char answer_flag = 0;

	strike_ball_out.strike = 0;
	strike_ball_out.ball = 0;
	strike_ball_out.out = 0;

	switch(select_level)
	{
	case 1:
		/* 3�ڸ� */
		for(loopidx = 0; loopidx < 3; loopidx++)
		{
			for(loopjdx = 0; loopjdx < 3; loopjdx++)
			{
				/* ��Ʈ����ũ �Ǻ� */
				if((g_exam[loopjdx] == g_answer[loopidx]) && (loopjdx == loopidx))
				{
					strike_ball_out.strike += 1;
				}
				/* �� �Ǻ� */
				else if(g_exam[loopjdx] == g_answer[loopidx])
				{
					strike_ball_out.ball += 1;
				}
				else
				{
					/* �ƿ� �Ǻ� */
					if((loopjdx == 2) && (strike_ball_out.strike == 0) && (strike_ball_out.ball == 0))
					{
						strike_ball_out.out += 1;
					}
					else{/**/}
				}
			}
		}

		if(strike_ball_out.strike == 3)
		{
			answer_flag = 1;
		}
		else{/**/};

		break;
	case 2:
		/* 4�ڸ� */
		break;
	case 3:
	default:
		/* 5�ڸ� */
		break;
	}

	printf("### ���� ���ھ� : S(%d) B(%d) O(%d)\n\n", strike_ball_out.strike, strike_ball_out.ball, strike_ball_out.out);

	return answer_flag;
}

unsigned char insert_answer(void)
{
	unsigned int get_answer = 0;
	unsigned char value_check = 1;
	//signed int value_temp = 0;

	printf("### ���� �Է� : ");
	scanf("%d", &get_answer);

	/* ���ڿ� ���� ����ó�� �ϱ� */
	switch(select_level)
	{
	case 1:
		/* 3�ڸ� */
		if ((get_answer < 100) || (get_answer > 999))
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
	return value_check;
}

void select_level_func(void)
{
	printf("=============================\n");
	printf("1. 3�ڸ�\n");
	printf("2. 4�ڸ�\n");
	printf("3. 5�ڸ�\n");
	printf("=============================\n");
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
	default:
		printf("5�ڸ��� �����ϼ̽��ϴ�\n");
		break;
	}

	printf("### ���� �߱� ������ �����մϴ�!!\n\n\n");

	return;
}

void create_rand(void)
{
	unsigned int loopidx = 0;

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
		for(loopidx = 0; loopidx < 3; loopidx++)
		{
			g_exam[loopidx] = (rand() % 9);
		}
		break;
	case 2:
		for(loopidx = 0; loopidx < 4; loopidx++)
		{
			g_exam[loopidx] = (rand() % 9);
		}
		break;
	default:
		for(loopidx = 0; loopidx < 5; loopidx++)
		{
			g_exam[loopidx] = (rand() % 9);
		}
		break;
	}

	return;
}

