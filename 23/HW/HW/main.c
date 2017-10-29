#include<stdio.h>
#include<stdlib.h>
#include<time.h>

enum Status {CONTINUE,WON,LOSE};
int rollDice(void);

int main(void)
{
	int sum;
	int mypPoint;
	enum Status gameStatus;
	srand(time(NULL));
	sum = rollDice();
	switch (sum)
	{
	case 7:
	case 11:
		gameStatus = WON;
		break;
	case 2:
	case 3:
	case 12:
		gameStatus = LOSE;
		break;
	default:
		gameStatus = CONTINUE;
		mypPoint = sum;
		printf("Point is %d\n", mypPoint);
		break;
	}
	while (gameStatus == CONTINUE)
	{
		sum = rollDice();
		if (sum == mypPoint)
			gameStatus = WON;
		else
		{
			if (sum == 7)
				gameStatus = LOSE;
		}
	}
	if (gameStatus == WON)
		printf("Player wins.\n");
	else
		printf("Player loses.\n");

	system("pause");
	return 0;
}

int rollDice(void)
{
	int die1, die2, worksum;
	die1 = 1 + (rand() % 6);
	die2 = 1 + (rand() % 6);
	worksum = die1 + die2;
	printf("Player rolled %d + %d = %d\n", die1, die2, worksum);
	return worksum;
}