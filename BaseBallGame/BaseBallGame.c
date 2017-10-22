#include "BaseBallGame.h"
#define MAX_CNT 3

/* 
1. 3�ڸ� ���� ����
2. ���� �Է�
3. ��ȸ�� �� 5��
4. ���� ���
*/


// ���� �Է� �� ��ȸ ���
void input_answer(int get_score[])
{
	baseball_cnt_Str bb_cnt = {0,0,0};
	char get_input[MAX_CNT+1];
	int loopidx, loopjdx = 0;
	int temp_value = 0;

	printf("���� �Է� : ");
	scanf_s("%s", get_input, sizeof(get_input));

	for(loopidx = 0; loopidx < MAX_CNT; loopidx++)
	{
		temp_value = get_input[loopidx] - 48;

		if(temp_value == get_score[loopidx])
		{
			// ��Ʈ����ũ
			bb_cnt.strike_value += 1;
		}
		else
		{
			for(loopjdx = 0; loopjdx < MAX_CNT; loopjdx++)
			{
				if(temp_value == get_score[loopjdx])
				{
					// ��
					bb_cnt.ball_value += 1;
					break;
				}
				else if(loopjdx == 2)
				{
					// ��Ʈ����ũ
					bb_cnt.out_value += 1;
				}
				else{}
			}
		}
	}

	printf("%dS, %dB, %dO\n", bb_cnt.strike_value, bb_cnt.ball_value, bb_cnt.out_value);
}


// 3�ڸ� ���� ����
void create_score(int set_scroe[])
{
	int loopidx = 0;
	printf("3�ڸ� ������ �����մϴ�...");

	srand((unsigned)time(NULL));

	for(loopidx = 0; loopidx < MAX_CNT;  loopidx++)
	{
		set_scroe[loopidx] = (rand()%9)+1; // 1~9����
		// �ߺ��� ����
		if( (set_scroe[loopidx] == set_scroe[loopidx-1]) || (set_scroe[loopidx] == set_scroe[loopidx-2]) )
		{
			set_scroe[loopidx] = (rand()%9)+1;
		}
		else{}
	}

	Sleep(1000);
	printf("finish...\n");
}


void main(void)
{
	int scroe[MAX_CNT] = {0,};
	create_score(scroe);
	input_answer(scroe);
}