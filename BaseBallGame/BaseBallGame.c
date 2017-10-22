#include "BaseBallGame.h"
#define MAX_CNT 3

/* 
1. 3자리 난수 생성
2. 정답 입력
3. 기회는 총 5번
4. 판정 출력
*/


// 정답 입력 및 기회 출력
void input_answer(int get_score[])
{
	baseball_cnt_Str bb_cnt = {0,0,0};
	char get_input[MAX_CNT+1];
	int loopidx, loopjdx = 0;
	int temp_value = 0;

	printf("정답 입력 : ");
	scanf_s("%s", get_input, sizeof(get_input));

	for(loopidx = 0; loopidx < MAX_CNT; loopidx++)
	{
		temp_value = get_input[loopidx] - 48;

		if(temp_value == get_score[loopidx])
		{
			// 스트라이크
			bb_cnt.strike_value += 1;
		}
		else
		{
			for(loopjdx = 0; loopjdx < MAX_CNT; loopjdx++)
			{
				if(temp_value == get_score[loopjdx])
				{
					// 볼
					bb_cnt.ball_value += 1;
					break;
				}
				else if(loopjdx == 2)
				{
					// 스트라이크
					bb_cnt.out_value += 1;
				}
				else{}
			}
		}
	}

	printf("%dS, %dB, %dO\n", bb_cnt.strike_value, bb_cnt.ball_value, bb_cnt.out_value);
}


// 3자리 난수 생성
void create_score(int set_scroe[])
{
	int loopidx = 0;
	printf("3자리 난수를 생성합니다...");

	srand((unsigned)time(NULL));

	for(loopidx = 0; loopidx < MAX_CNT;  loopidx++)
	{
		set_scroe[loopidx] = (rand()%9)+1; // 1~9까지
		// 중복값 제거
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