#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include "color.h"

enum Seletion {
	가위 = 11,
	바위,
	보
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
	printf("게임을 시작하시겠습니까? Y( 0 ) | N( 1 )\n");
	while (process_Selection(input_Selection()))
		printf("게임을 시작하시겠습니까? Y( 0 ) | N( 1 )\n");

	srand(time(NULL));

	Frist();
	opening();

	

	while (alive())
	{
		print_Game();
		
		int sl = process_Selection(input_Selection() + 10);
		if (sl == -1)
		{
			printf(RED "잘못된 입력입니다.\n" RESET);
			char temp;
			while (temp = getchar() != '\n');
			continue;
		}
		int WL = winORlose(sl);

		print_Select(sl, com_select);

		printf(YELLOW);
		switch (WL)
		{
		case win: printf("이겼습니다.\n");  point += 2; break;
		case lose: printf("졌습니다.\n"); point-=3; break;
		case same: printf("비겼습니다.\n");  break;
		}
		printf(RESET);
	}

	if (point <= 0)
	{
		printf(RED "\n\n#############\n");
		printf("패배하셨습니다.\n");
		printf("##############\n\n" RESET);
	}
	else {
		printf(YELLOW "\n\n#############\n");
		printf("승리하셨습니다.\n");
		printf("##############\n\n" RESET);
	}

	printf("게임 종료\n");
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
	case 11: return 가위;
	case 12: return 바위;
	case 13: return 보;
	default: return -1;
	}
}

void Frist()
{
	printf(YELLOW "@게임 설명@\n");
	printf("이 게임은 컴퓨터와 [가위 바위 보 게임] 게임에서 승리하여 점수를 얻는 게임입니다. \n");
	printf("승리하면 2point 를 획득하며 패배하면 3point 를 잃습니다. 만약 비기게 된다면 0point를 획득합니다. \n");
	printf("목표 점수는 17point(개발 당시 개발자 나이)이며 목표 점수를 달성하면 컴퓨터와의 대결에서 승리합니다. \n");
	printf("하지만 점수가 0이하가 될 경우 컴퓨터와의 대결에서 패배합니다. 기본 점수는 8point 입니다. \n");
	printf("게임에서 승리하거나 패배하면 게임이 종료됩니다. \n");

	printf("Enter plz >> " RESET);

	getch();
}

void opening()
{
	printf(MAGENTA "\n\n-----------------------------게임 시작-----------------------------\n\n" RESET);
}

void print_Game()
{
	printf(GREEN);
	printf("\n현재 point: %d\n", point);
	printf(RESET);

	printf(CYAN "가위( 1 ), 바위( 2 ), 보( 3 )\n" RESET);
	printf("무엇을 내시겠습니까?\n");
}

int winORlose(int select) {
	if (
		select == 가위 && com_select == 바위 ||
		select == 바위 && com_select == 보 ||
		select == 보 && com_select == 가위)
	{
		return lose;
	}
	else if (com_select == 가위 && select == 바위 ||
		com_select == 바위 && select == 보 ||
		com_select == 보 && select == 가위)
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
	printf(RED "나: ");
	switch (m)
	{
	case 가위: printf("가위"); break;
	case 바위: printf("바위"); break;
	case 보: printf("보"); break;
	}
	printf(RESET "\n");

	printf(BLUE "computer: ");

	switch (com)
	{
	case 가위: printf("가위"); break;
	case 바위: printf("바위"); break;
	case 보: printf("보"); break;
	}
	printf(RESET "\n");

}