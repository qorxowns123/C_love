#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ### Global Variable */
signed int g_answer[5]; /* 입력된 정답 */
signed int g_exam[5]; /* 문제 */
unsigned int select_level;

typedef struct strike_ball_out_Str
{
	unsigned char strike; /* 스트라이크 */
	unsigned char ball; /* 볼 */
	unsigned char out; /* 아웃 */

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
		/* 3자리 */
		break;
	case 2:
		game_level = 4;
		/* 4자리 */
		break;
	case 3:
	default:
		game_level = 5;
		/* 5자리 */
		break;
	}

	/* 스트라이크, 볼, 아웃 판별 로직 */
	for(loopidx = 0; loopidx < game_level; loopidx++)
	{
		if(g_answer[loopidx] == g_exam[loopidx])
		{
			/* 스트라이크 먼저 판별 */
			strike_ball_out.strike += 1;
			/* 스트라이크로 판별된 인덱스 저장 */
			strike_flag[loopidx] = 1;
		}
	}

	for(loopidx = 0; loopidx < game_level; loopidx++)
	{
		/* 스트라이크로 판별된 인덱스는 넘어가기 */
		if(strike_flag[loopidx] == 1)
		{
			continue;
		}
		for(loopjdx = 0; loopjdx < game_level; loopjdx++)
		{
			/* 볼 판별*/
			if(g_answer[loopidx] == g_exam[loopjdx])
			{
				strike_ball_out.ball += 1;
				break;
			}
			/* 아웃 판별 */
			else if(loopjdx == (game_level-1))
			{
				strike_ball_out.out += 1;
			}
			else{/**/}
		}
		
	}
	/* 숫자를 모두 맞췄다면.. 게임 클리어! */
	if(strike_ball_out.strike == game_level)
	{
		answer_flag = 1;
	}
	else{/**/};

	printf(">> 현재 스코어 : S(%d) B(%d) O(%d)\n\n", strike_ball_out.strike, strike_ball_out.ball, strike_ball_out.out);

	return answer_flag;
}

/* insert_answer */
unsigned char insert_answer(void)
{
	unsigned int get_answer = 0;
	unsigned char value_check = 1;
	static unsigned char answer_cnt = 1;

	printf("> %d회차 정답 입력 : ", answer_cnt);
	scanf("%d", &get_answer);

	/* 숫자에 대한 예외처리 하기 */
	switch(select_level)
	{
	case 1:
		/* 3자리 범위 설정 */
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
		/* 4자리 범위 설정 */
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
		/* 5자리 범위 설정 */
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

	/* 입력한 정답이 범위를 벗어났을 경우 예외처리 */
	if(value_check == 0)
	{
		printf("### 잘못된 범위의 수를 입력하였습니다\n");
	} else{/**/}

	answer_cnt++;

	return value_check;
}

/* select_level_func */
void select_level_func(void)
{
	printf("=============================\n");
	printf("*** 숫자 야구 게임 ***\n");
	printf("=============================\n");
	
	
	printf("1. 3자리\n");
	printf("2. 4자리\n");
	printf("3. 5자리\n");
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
	case 3:
	default:
		printf("5자리를 선택하셨습니다\n");
		break;
	}

	printf("\n### 숫자 야구 게임을 시작합니다!!\n");

	return;
}

/* create_rand */
void create_rand(void)
{
	unsigned int loopidx = 0;
	unsigned char game_level = 0;

	/* 전역 변수 초기화 */
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
	
	/* 현재 시간을 활용한 srand 함수 사용, 이렇게 사용하게 되면 랜덤 숫자가 나올 확률이 증가한다 */
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
		/* 0~9까지 랜덤함수 생성 및 저장 */
		g_exam[loopidx] = (rand() % 9);
	}

	return;
}
/***********************************************************/

