#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_game(void);
unsigned int create_rand(void);
unsigned int insert_answer(unsigned int chance);
unsigned char match_answer(unsigned int problem, unsigned int answer);


void main(void)
{
	unsigned int num_problem = 0;
	unsigned int num_answer = 0;
	unsigned char result = 0;
	static unsigned int chance = 1;

	init_game();
	num_problem = create_rand();
	printf("<Temp> :: 정답 : %d\n", num_problem);

	while(result == 0)
	{	
		num_answer = insert_answer(chance);
		result = match_answer(num_problem, num_answer);
		if(result == 1)
		{
			break;
		}
		else
		{
			chance++;
			if(chance == 11)
			{
				printf("<Info> :: 기회가 모두 소진되었습니다. 게임을 종료합니다\n");
			} else{/**/}
		}
	}
	return;
}

void init_game(void)
{
	printf("============================================================\n");
	printf("### Up and Down Game\n");
	printf("> 0~99 사이의 숫자를 총 10번의 기회를 통해 맞추는 게임입니다\n");
	printf("> 게임 시작합니다!!\n");
	printf("============================================================\n");
	
	return;
}

unsigned int create_rand(void)
{
	unsigned int ex_rand = 0;
	unsigned int loopidx = 0;

	/* 현재 시간을 활용한 srand 함수 사용, 이렇게 사용하게 되면 랜덤 숫자가 나올 확률이 증가한다 */
	srand(time(NULL));

	for(loopidx = 0; loopidx < 9; loopidx++)
	{
		ex_rand = ((rand() % 99) + 1);
	}
	
	return ex_rand;
}

unsigned int insert_answer(unsigned int chance)
{
	unsigned int answer = 0;
	unsigned char check_flag = 0;

	do
	{
		printf("%d 번째 기회 : ", chance);
		scanf("%d", &answer);
		if((answer < 0) || (answer > 99))
		{
			printf("<Error> :: 숫자의 범위는 0~99까지 입니다\n");
			check_flag = 1;
		}
		else
		{
			check_flag = 0;
		}
	} while(check_flag);

	return answer;
}

unsigned char match_answer(unsigned int problem, unsigned int answer)
{
	unsigned char answer_flag = 0;

	if(problem < answer)
	{
		/* 정답이 더 큰 수인 경우 */
		printf("<Info> :: Down!\n");
	}
	else if(problem > answer)
	{
		/* 정답이 더 작은 수인 경우 */
		printf("<Info> :: Up!\n");
	}
	else
	{
		/* 정답과 문제가 같은 경우 */
		printf("<Info> :: 축하합니다!! 정답입니다!\n");
		answer_flag = 1;
	}

	return answer_flag;
}

