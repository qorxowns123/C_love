#include <stdio.h>
#include <string.h>
#include <io.h>
#include <Windows.h>


#define ADDRESSMAX 1000 /* 저장할 주소의 최대 값*/
#define LINE_MAX 1024 /* csv 파일에서 구분자를 읽어들일 최대 글자 수*/

/* 초기 화면 모드 선택 */
unsigned int SelectMode(unsigned char);

/* 신규 연락처 등록 */
void NewAddress(void);

/* 저장된 연락처 보기 */
void PrintAddress(void);

/* 전화번호 부 내보내기 */
void export_contact(void);

/* 전화번호 부 가져오기 */
unsigned char load_contact(void);

/* 연락처 수정*/
void change_contact(void);


/* 전화번호를 저장할 구조체 */
typedef struct Addr
{
	char Name[100]; /* 이름 */
	char Number[100]; /* 번호 */
	char Grp[100]; /* 그룹 */
} addr_str;

addr_str addr_arr[ADDRESSMAX];

/* 현재 저장된 번호의 갯수를 나타내는 변수 */
static unsigned int addr_arr_cnt;

void main(void)
{
	unsigned int mode = 0;
	unsigned char load_check = 0;
	addr_arr_cnt = 0;

	/* 전화번호 부 로드 */
	load_check = load_contact();

	while(1)
	{
        /* 모드 선택 */
		mode = SelectMode(load_check);
		switch(mode)
		{
		case 1: /* 신규 연락처 등록 */
			NewAddress();
			break;

		case 2: /* 연락처 수정*/
			change_contact(); 
			break;

		case 3: /* 저장된 연락처 보기*/
			PrintAddress();
			break;

		case 4: /* 전화번호부 내보내기*/
			export_contact();
			break;

		default:
			printf("### 메뉴를 다시 선택해주세요\n");
			break;
		}

		load_check = 1;
	} /* end while */
	return;
}


/*### Sub Function List #############################################################*/
/* 전화번호 수정 */
void change_contact(void)
{
	unsigned int change_number = 0;
	unsigned int _change_num = 0;
	char _change[100] = {0,};
	char _clean_arr[100] = {0,};
	system("cls");
	PrintAddress();
	printf("### 수정할 전화번호를 입력하세요 : ");
	scanf("%d", &change_number);

	_change_num = (change_number - 1);

	system("cls");

	printf("### %d번 연락처를 수정합니다\n", change_number);

	printf("- 기존 이름 : %s\n", addr_arr[_change_num].Name);
	printf("- 변경할 이름 : ");
	scanf("%s", _change);
	memcpy(addr_arr[_change_num].Name, _change, sizeof(_change));

	/* 배열 초기화 */
	memcpy(_change, _clean_arr, sizeof(_change));

	printf("\n- 기존 전화번호 : %s\n", addr_arr[_change_num].Number);
	printf("- 변경할 전화번호 : ");
	scanf("%s", _change);
	memcpy(addr_arr[_change_num].Number, _change, sizeof(_change));

	/* 배열 초기화 */
	memcpy(_change, _clean_arr, sizeof(_change));

	printf("\n- 기존 그룹명 : %s", addr_arr[_change_num].Grp);
	printf("- 변경할 그룹명 : ");
	scanf("%s", _change);
	sprintf(_change, "%s\n", _change);
	memcpy(addr_arr[_change_num].Grp, _change, sizeof(_change));

	return;
}



/* 전화번호부 내보내기 ----------------------------------*/
void export_contact(void)
{
	unsigned int loopidx = 0;
	const char *path = ".\\contact.csv";
	FILE *fp;

	/* 전화번호부가 추가 되었다면... */
	if (addr_arr_cnt == 0) 
	{ 
		return;
	} 
	else
	{
		/* 전화번호부 파일이 존재한다면... */
		if(_access(path, 0) == 0)
		{
			/* 기존 파일 삭제 */
			printf("### 기존파일을 삭제합니다\n");
			remove(path);
		} else{/**/}
		
		printf("### 전화번호부를 외부파일로 저장합니다\n");
	}

	/* 전화번호부 파일 작성 */
	fp = fopen(path, "w");
	for(loopidx = 0; loopidx < addr_arr_cnt; loopidx++)
	{
		fprintf(fp, "%s,%s,%s", addr_arr[loopidx].Name, addr_arr[loopidx].Number, addr_arr[loopidx].Grp);
	}

	printf("### 내보내기 완료!!\n");

	fclose(fp);
}


/* 전화번호부 로드 ----------------------------------*/
unsigned char load_contact(void)
{
	const char *path = ".\\contact.csv";
	char *tok;
	char line[LINE_MAX];
	FILE *fp;
	unsigned char result = 1;

	if(_access(path, 0) == 0)
	{
		printf("### 저장된 전화번호부를 로드합니다...\n\n");

		fp = fopen(path, "r");
		/* fgets :: 파일을 한줄씩 읽어, 첫번째 인자에 저장(길이는 2번째 인자 만큼 또는 NULL이 나올때까지)*/
		while(fgets(line, LINE_MAX, fp) != NULL)
		{
			tok = strtok(line, ",");
			while(tok != NULL)
			{
				/* Name 입력 확인 */
				if (addr_arr[addr_arr_cnt].Name[0] == NULL) 
				{
					strcpy(addr_arr[addr_arr_cnt].Name, tok);
				}
				/* Number 입력 확인 */
				else if (addr_arr[addr_arr_cnt].Number[0] == NULL)
				{
					strcpy(addr_arr[addr_arr_cnt].Number, tok);
				}
				/* Grp 입력 확인 */
				else if(addr_arr[addr_arr_cnt].Grp[0] == NULL)
				{
					strcpy(addr_arr[addr_arr_cnt].Grp, tok);
					addr_arr_cnt++;
				} else{/**/}
				/* strtok :: 첫번째 인자로 NULL이 들어오면 이전에 자기가 기억한 곳으로부터 분리 진행 */
				tok = strtok(NULL, ",");

				if(tok == NULL)
				{
					break;
				} else{/**/}
			}
		}
		fclose(fp);
		printf("### 연락처 가져오기 결과 : 총 %d 건의 연락처를 가져왔습니다.\n", addr_arr_cnt);
	}
	else
	{
		printf("### 등록된 전화번호가 없습니다. 연락처를 등록해주세요\n\n");
		result = 0;
	}
	return result;
}

/* 메뉴 선택 ----------------------------------*/
unsigned int SelectMode(unsigned char load_check)
{
	unsigned int select_num = 0;
	printf("======================================\n");
	if(load_check == 1)
	{
		printf("1. 신규 전화번호 등록\n");
		printf("2. 연락처 수정\n");
		printf("3. 저장된 연락처 보기\n");
		printf("3. 전화번호부 내보내기\n");
	}
	else
	{
        /* 전화번호 파일이 존재하지 않을 경우, 1번 메뉴만 보여주도록 하기 */
		printf("1. 신규 전화번호 등록(등록된 전화번호부 없음)\n");
	}
	printf("======================================\n");
	printf("메뉴를 선택하세요 : ");
	scanf("%d", &select_num);
	
	return select_num;
}

/* 전화번호 추가 ----------------------------------*/
void NewAddress(void)
{
	char select_num[100] = {0,};
	char temp_num[100] = {0,};

	/* 콘솔 화면 초기화 */
	system("cls");

	printf("=================== 신규 전화 번호 등록===================\n");

	printf("이름 : ");
	scanf("%s", &select_num);
	memcpy(addr_arr[addr_arr_cnt].Name, select_num, sizeof(select_num));
	
	/* 배열 초기화 */
	memcpy(select_num, temp_num, sizeof(select_num));

	printf("전화번호 : ");
	scanf("%s", &select_num);
	memcpy(addr_arr[addr_arr_cnt].Number, select_num, sizeof(select_num));

	/* 배열 초기화 */
	memcpy(select_num, temp_num, sizeof(select_num));

	printf("그룹 : ");
	scanf("%s", &select_num);
	memcpy(addr_arr[addr_arr_cnt].Grp, select_num, sizeof(select_num));

	addr_arr_cnt++;
}

/* 전화번호부 보기 -------------------------------------------------------------------- */
void PrintAddress(void)
{
	unsigned int loopidx = 0;
	if(addr_arr_cnt == 0)
	{
		printf("전화번호를 추가하여야 합니다 --- 저장된 전화번호부 없음\n");
	}
	else
	{
		/* 콘솔 화면 초기화 */
		system("cls");
		printf("---------------------------------------------\n");
		printf("     이름  \t전화번호 \t그룹\n");
		printf("---------------------------------------------\n");

		for(loopidx = 0; loopidx < addr_arr_cnt; loopidx++)
		{
			printf("%d --", (loopidx+1));
			printf("  %s", addr_arr[loopidx].Name);
			printf("\t%s", addr_arr[loopidx].Number);
			printf("\t%s", addr_arr[loopidx].Grp);
		}
		printf("---------------------------------------------\n");
	}
}