#include <stdio.h>
#include <string.h>
#include <io.h>
#include <Windows.h>


#define ADDRESSMAX 1000 /* ������ �ּ��� �ִ� ��*/
#define LINE_MAX 1024 /* csv ���Ͽ��� �����ڸ� �о���� �ִ� ���� ��*/

/* �ʱ� ȭ�� ��� ���� */
unsigned int SelectMode(unsigned char);

/* �ű� ����ó ��� */
void NewAddress(void);

/* ����� ����ó ���� */
void PrintAddress(void);

/* ��ȭ��ȣ �� �������� */
void export_contact(void);

/* ��ȭ��ȣ �� �������� */
unsigned char load_contact(void);

/* ����ó ����*/
void change_contact(void);


/* ��ȭ��ȣ�� ������ ����ü */
typedef struct Addr
{
	char Name[100]; /* �̸� */
	char Number[100]; /* ��ȣ */
	char Grp[100]; /* �׷� */
} addr_str;

addr_str addr_arr[ADDRESSMAX];

/* ���� ����� ��ȣ�� ������ ��Ÿ���� ���� */
static unsigned int addr_arr_cnt;

void main(void)
{
	unsigned int mode = 0;
	unsigned char load_check = 0;
	addr_arr_cnt = 0;

	/* ��ȭ��ȣ �� �ε� */
	load_check = load_contact();

	while(1)
	{
        /* ��� ���� */
		mode = SelectMode(load_check);
		switch(mode)
		{
		case 1: /* �ű� ����ó ��� */
			NewAddress();
			break;

		case 2: /* ����ó ����*/
			change_contact(); 
			break;

		case 3: /* ����� ����ó ����*/
			PrintAddress();
			break;

		case 4: /* ��ȭ��ȣ�� ��������*/
			export_contact();
			break;

		default:
			printf("### �޴��� �ٽ� �������ּ���\n");
			break;
		}

		load_check = 1;
	} /* end while */
	return;
}


/*### Sub Function List #############################################################*/
/* ��ȭ��ȣ ���� */
void change_contact(void)
{
	unsigned int change_number = 0;
	unsigned int _change_num = 0;
	char _change[100] = {0,};
	char _clean_arr[100] = {0,};
	system("cls");
	PrintAddress();
	printf("### ������ ��ȭ��ȣ�� �Է��ϼ��� : ");
	scanf("%d", &change_number);

	_change_num = (change_number - 1);

	system("cls");

	printf("### %d�� ����ó�� �����մϴ�\n", change_number);

	printf("- ���� �̸� : %s\n", addr_arr[_change_num].Name);
	printf("- ������ �̸� : ");
	scanf("%s", _change);
	memcpy(addr_arr[_change_num].Name, _change, sizeof(_change));

	/* �迭 �ʱ�ȭ */
	memcpy(_change, _clean_arr, sizeof(_change));

	printf("\n- ���� ��ȭ��ȣ : %s\n", addr_arr[_change_num].Number);
	printf("- ������ ��ȭ��ȣ : ");
	scanf("%s", _change);
	memcpy(addr_arr[_change_num].Number, _change, sizeof(_change));

	/* �迭 �ʱ�ȭ */
	memcpy(_change, _clean_arr, sizeof(_change));

	printf("\n- ���� �׷�� : %s", addr_arr[_change_num].Grp);
	printf("- ������ �׷�� : ");
	scanf("%s", _change);
	sprintf(_change, "%s\n", _change);
	memcpy(addr_arr[_change_num].Grp, _change, sizeof(_change));

	return;
}



/* ��ȭ��ȣ�� �������� ----------------------------------*/
void export_contact(void)
{
	unsigned int loopidx = 0;
	const char *path = ".\\contact.csv";
	FILE *fp;

	/* ��ȭ��ȣ�ΰ� �߰� �Ǿ��ٸ�... */
	if (addr_arr_cnt == 0) 
	{ 
		return;
	} 
	else
	{
		/* ��ȭ��ȣ�� ������ �����Ѵٸ�... */
		if(_access(path, 0) == 0)
		{
			/* ���� ���� ���� */
			printf("### ���������� �����մϴ�\n");
			remove(path);
		} else{/**/}
		
		printf("### ��ȭ��ȣ�θ� �ܺ����Ϸ� �����մϴ�\n");
	}

	/* ��ȭ��ȣ�� ���� �ۼ� */
	fp = fopen(path, "w");
	for(loopidx = 0; loopidx < addr_arr_cnt; loopidx++)
	{
		fprintf(fp, "%s,%s,%s", addr_arr[loopidx].Name, addr_arr[loopidx].Number, addr_arr[loopidx].Grp);
	}

	printf("### �������� �Ϸ�!!\n");

	fclose(fp);
}


/* ��ȭ��ȣ�� �ε� ----------------------------------*/
unsigned char load_contact(void)
{
	const char *path = ".\\contact.csv";
	char *tok;
	char line[LINE_MAX];
	FILE *fp;
	unsigned char result = 1;

	if(_access(path, 0) == 0)
	{
		printf("### ����� ��ȭ��ȣ�θ� �ε��մϴ�...\n\n");

		fp = fopen(path, "r");
		/* fgets :: ������ ���پ� �о�, ù��° ���ڿ� ����(���̴� 2��° ���� ��ŭ �Ǵ� NULL�� ���ö�����)*/
		while(fgets(line, LINE_MAX, fp) != NULL)
		{
			tok = strtok(line, ",");
			while(tok != NULL)
			{
				/* Name �Է� Ȯ�� */
				if (addr_arr[addr_arr_cnt].Name[0] == NULL) 
				{
					strcpy(addr_arr[addr_arr_cnt].Name, tok);
				}
				/* Number �Է� Ȯ�� */
				else if (addr_arr[addr_arr_cnt].Number[0] == NULL)
				{
					strcpy(addr_arr[addr_arr_cnt].Number, tok);
				}
				/* Grp �Է� Ȯ�� */
				else if(addr_arr[addr_arr_cnt].Grp[0] == NULL)
				{
					strcpy(addr_arr[addr_arr_cnt].Grp, tok);
					addr_arr_cnt++;
				} else{/**/}
				/* strtok :: ù��° ���ڷ� NULL�� ������ ������ �ڱⰡ ����� �����κ��� �и� ���� */
				tok = strtok(NULL, ",");

				if(tok == NULL)
				{
					break;
				} else{/**/}
			}
		}
		fclose(fp);
		printf("### ����ó �������� ��� : �� %d ���� ����ó�� �����Խ��ϴ�.\n", addr_arr_cnt);
	}
	else
	{
		printf("### ��ϵ� ��ȭ��ȣ�� �����ϴ�. ����ó�� ������ּ���\n\n");
		result = 0;
	}
	return result;
}

/* �޴� ���� ----------------------------------*/
unsigned int SelectMode(unsigned char load_check)
{
	unsigned int select_num = 0;
	printf("======================================\n");
	if(load_check == 1)
	{
		printf("1. �ű� ��ȭ��ȣ ���\n");
		printf("2. ����ó ����\n");
		printf("3. ����� ����ó ����\n");
		printf("3. ��ȭ��ȣ�� ��������\n");
	}
	else
	{
        /* ��ȭ��ȣ ������ �������� ���� ���, 1�� �޴��� �����ֵ��� �ϱ� */
		printf("1. �ű� ��ȭ��ȣ ���(��ϵ� ��ȭ��ȣ�� ����)\n");
	}
	printf("======================================\n");
	printf("�޴��� �����ϼ��� : ");
	scanf("%d", &select_num);
	
	return select_num;
}

/* ��ȭ��ȣ �߰� ----------------------------------*/
void NewAddress(void)
{
	char select_num[100] = {0,};
	char temp_num[100] = {0,};

	/* �ܼ� ȭ�� �ʱ�ȭ */
	system("cls");

	printf("=================== �ű� ��ȭ ��ȣ ���===================\n");

	printf("�̸� : ");
	scanf("%s", &select_num);
	memcpy(addr_arr[addr_arr_cnt].Name, select_num, sizeof(select_num));
	
	/* �迭 �ʱ�ȭ */
	memcpy(select_num, temp_num, sizeof(select_num));

	printf("��ȭ��ȣ : ");
	scanf("%s", &select_num);
	memcpy(addr_arr[addr_arr_cnt].Number, select_num, sizeof(select_num));

	/* �迭 �ʱ�ȭ */
	memcpy(select_num, temp_num, sizeof(select_num));

	printf("�׷� : ");
	scanf("%s", &select_num);
	memcpy(addr_arr[addr_arr_cnt].Grp, select_num, sizeof(select_num));

	addr_arr_cnt++;
}

/* ��ȭ��ȣ�� ���� -------------------------------------------------------------------- */
void PrintAddress(void)
{
	unsigned int loopidx = 0;
	if(addr_arr_cnt == 0)
	{
		printf("��ȭ��ȣ�� �߰��Ͽ��� �մϴ� --- ����� ��ȭ��ȣ�� ����\n");
	}
	else
	{
		/* �ܼ� ȭ�� �ʱ�ȭ */
		system("cls");
		printf("---------------------------------------------\n");
		printf("     �̸�  \t��ȭ��ȣ \t�׷�\n");
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