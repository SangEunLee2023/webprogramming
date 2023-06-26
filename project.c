#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include "color.h"

enum Seletion {
	���� = 11,
	����,
	��
};

enum yesORno {
	y = 0,
	n = 1,
};

enum {
	win = 0,
	lose = 1,
	same = 2
};

int input_Selection();
int process_Selection(int);

void opening();

void Frist();

void print_Game();

int winORlose(int );

int alive();

void print_Select(int m, int com);

int point = 8;
int com_select;
int main(void)
{
	printf("������ �����Ͻðڽ��ϱ�? Y( 0 ) | N( 1 )\n");
	while (process_Selection(input_Selection()))
		printf("������ �����Ͻðڽ��ϱ�? Y( 0 ) | N( 1 )\n");

	srand(time(NULL));

	Frist();
	opening();

	

	while (alive())
	{
		print_Game();
		
		int sl = process_Selection(input_Selection() + 10);
		if (sl == -1)
		{
			printf(RED "�߸��� �Է��Դϴ�.\n" RESET);
			char temp;
			while (temp = getchar() != '\n');
			continue;
		}
		int WL = winORlose(sl);

		print_Select(sl, com_select);

		printf(YELLOW);
		switch (WL)
		{
		case win: printf("�̰���ϴ�.\n");  point += 2; break;
		case lose: printf("�����ϴ�.\n"); point-=3; break;
		case same: printf("�����ϴ�.\n");  break;
		}
		printf(RESET);
	}

	if (point <= 0)
	{
		printf(RED "\n\n#############\n");
		printf("�й��ϼ̽��ϴ�.\n");
		printf("##############\n\n" RESET);
	}
	else {
		printf(YELLOW "\n\n#############\n");
		printf("�¸��ϼ̽��ϴ�.\n");
		printf("##############\n\n" RESET);
	}

	printf("���� ����\n");
	return 0;
}
int input_Selection()
{
	int Select;
	printf(">");
	scanf("%d", &Select);

	return Select;
}

int process_Selection(int Select)
{
	switch (Select)
	{
	case 0: return y;
	case 1: return n;
	case 11: return ����;
	case 12: return ����;
	case 13: return ��;
	default: return -1;
	}
}

void Frist()
{
	printf(YELLOW "@���� ����@\n");
	printf("�� ������ ��ǻ�Ϳ� [���� ���� �� ����] ���ӿ��� �¸��Ͽ� ������ ��� �����Դϴ�. \n");
	printf("�¸��ϸ� 2point �� ȹ���ϸ� �й��ϸ� 3point �� �ҽ��ϴ�. ���� ���� �ȴٸ� 0point�� ȹ���մϴ�. \n");
	printf("��ǥ ������ 17point(���� ��� ������ ����)�̸� ��ǥ ������ �޼��ϸ� ��ǻ�Ϳ��� ��ῡ�� �¸��մϴ�. \n");
	printf("������ ������ 0���ϰ� �� ��� ��ǻ�Ϳ��� ��ῡ�� �й��մϴ�. �⺻ ������ 8point �Դϴ�. \n");
	printf("���ӿ��� �¸��ϰų� �й��ϸ� ������ ����˴ϴ�. \n");

	printf("Enter plz >> " RESET);

	getch();
}

void opening()
{
	printf(MAGENTA "\n\n-----------------------------���� ����-----------------------------\n\n" RESET);
}

void print_Game()
{
	printf(GREEN);
	printf("\n���� point: %d\n", point);
	printf(RESET);

	printf(CYAN "����( 1 ), ����( 2 ), ��( 3 )\n" RESET);
	printf("������ ���ðڽ��ϱ�?\n");
}

int winORlose(int select) {
	if (
		select == ���� && com_select == ���� ||
		select == ���� && com_select == �� ||
		select == �� && com_select == ����)
	{
		return lose;
	}
	else if (com_select == ���� && select == ���� ||
		com_select == ���� && select == �� ||
		com_select == �� && select == ����)
	{
		return win;
	}
	else {
		return same;
	}

}

int alive()
{
	if (point <= 0 || point >= 17)
	{
		return 0;
	}
	else {
		com_select = rand() % 3 + 11;
		return 1;
	}
}

void print_Select(int m, int com)
{
	printf(RED "��: ");
	switch (m)
	{
	case ����: printf("����"); break;
	case ����: printf("����"); break;
	case ��: printf("��"); break;
	}
	printf(RESET "\n");

	printf(BLUE "computer: ");

	switch (com)
	{
	case ����: printf("����"); break;
	case ����: printf("����"); break;
	case ��: printf("��"); break;
	}
	printf(RESET "\n");

}