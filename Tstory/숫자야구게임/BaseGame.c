#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ### Global Variable */
signed int g_answer[5]; /* 입력된 정답 */
signed int g_exam[5]; /* 문제 */
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
				printf("\n### 축하합니다!! 정답입니다~!\n");
				printf("게임을 종료합니다...\n");
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
		/* 3자리 */
		for(loopidx = 0; loopidx < 3; loopidx++)
		{
			for(loopjdx = 0; loopjdx < 3; loopjdx++)
			{
				/* 스트라이크 판별 */
				if((g_exam[loopjdx] == g_answer[loopidx]) && (loopjdx == loopidx))
				{
					strike_ball_out.strike += 1;
				}
				/* 볼 판별 */
				else if(g_exam[loopjdx] == g_answer[loopidx])
				{
					strike_ball_out.ball += 1;
				}
				else
				{
					/* 아웃 판별 */
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
		/* 4자리 */
		break;
	case 3:
	default:
		/* 5자리 */
		break;
	}

	printf("### 현재 스코어 : S(%d) B(%d) O(%d)\n\n", strike_ball_out.strike, strike_ball_out.ball, strike_ball_out.out);

	return answer_flag;
}

unsigned char insert_answer(void)
{
	unsigned int get_answer = 0;
	unsigned char value_check = 1;
	//signed int value_temp = 0;

	printf("### 정답 입력 : ");
	scanf("%d", &get_answer);

	/* 숫자에 대한 예외처리 하기 */
	switch(select_level)
	{
	case 1:
		/* 3자리 */
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
		/* 4자리 */
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
		/* 5자리 */
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
		printf("### 잘못된 범위의 수를 입력하였습니다\n");
	} else{/**/}
	return value_check;
}

void select_level_func(void)
{
	printf("=============================\n");
	printf("1. 3자리\n");
	printf("2. 4자리\n");
	printf("3. 5자리\n");
	printf("=============================\n");
	printf("난이도를 선택하세요 : ");

	scanf("%d", &select_level);

	switch(select_level)
	{
	case 1:
		printf("3자리를 선택하셨습니다\n");
		break;
	case 2:
		printf("4자리를 선택하셨습니다\n");
		break;
	default:
		printf("5자리를 선택하셨습니다\n");
		break;
	}

	printf("### 숫자 야구 게임을 시작합니다!!\n\n\n");

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

