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
	printf("<Temp> :: ���� : %d\n", num_problem);

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
				printf("<Info> :: ��ȸ�� ��� �����Ǿ����ϴ�. ������ �����մϴ�\n");
			} else{/**/}
		}
	}
	return;
}

void init_game(void)
{
	printf("============================================================\n");
	printf("### Up and Down Game\n");
	printf("> 0~99 ������ ���ڸ� �� 10���� ��ȸ�� ���� ���ߴ� �����Դϴ�\n");
	printf("> ���� �����մϴ�!!\n");
	printf("============================================================\n");
	
	return;
}

unsigned int create_rand(void)
{
	unsigned int ex_rand = 0;
	unsigned int loopidx = 0;

	/* ���� �ð��� Ȱ���� srand �Լ� ���, �̷��� ����ϰ� �Ǹ� ���� ���ڰ� ���� Ȯ���� �����Ѵ� */
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
		printf("%d ��° ��ȸ : ", chance);
		scanf("%d", &answer);
		if((answer < 0) || (answer > 99))
		{
			printf("<Error> :: ������ ������ 0~99���� �Դϴ�\n");
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
		/* ������ �� ū ���� ��� */
		printf("<Info> :: Down!\n");
	}
	else if(problem > answer)
	{
		/* ������ �� ���� ���� ��� */
		printf("<Info> :: Up!\n");
	}
	else
	{
		/* ����� ������ ���� ��� */
		printf("<Info> :: �����մϴ�!! �����Դϴ�!\n");
		answer_flag = 1;
	}

	return answer_flag;
}

