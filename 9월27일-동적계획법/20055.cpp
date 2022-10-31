//20055_컨베이어 벨트 위의 로봇
#include <stdio.h>
#include <stdlib.h>

void rotate(int n, int *belt, int *robot)
{
	int newfirst = belt[2 * n];
	for (int i = 2 * n - 1; i >= 1; i--)
		belt[i + 1] = belt[i];
	belt[1] = newfirst;
	for (int i = n - 1; i >= 1; i--)
		robot[i + 1] = robot[i];
	robot[1] = 0;
}

void move(int n, int *belt, int *robot)
{
	if (robot[n] == 1)
		robot[n] = 0;
	for (int i = n - 1; i >= 1; i--)
	{
		if (robot[i] != 1)
			continue;
		if (robot[i + 1] == 0 && belt[i + 1] != 0)
		{
			robot[i + 1] = 1;
			belt[i + 1]--;
			robot[i] = 0;
		}
	}
}

void putrobot(int *belt, int *robot)
{
	if (robot[1] == 0 && belt[1] != 0)
	{
		robot[1] = 1;
		belt[1]--;
	}
}

int check(int n, int *belt, int *robot)
{
	int cnt = 0;
	for (int i = 1; i <= n * 2; i++)
	{
		if (belt[i] == 0)
			cnt++;
	}
	return (cnt);
}

int main()
{
	int n, k, step = 0;
	scanf("%d %d", &n, &k);
	int *belt = (int *)malloc(sizeof(int) * (2 * n + 1));
	int *robot = (int *)malloc(sizeof(int) * (n + 1));
	for (int i = 1; i <= 2 * n; i++)
		scanf("%d", &belt[i]);
	for (int i = 1; i <= n; i++)
		robot[i] = 0;
	while (1)
	{
		step++;
		rotate(n, belt, robot);
		move(n, belt, robot);
		putrobot(belt, robot);
		if (check(n, belt, robot) >= k)
			break;
	}
	free (belt);
	free (robot);
	printf("%d\n", step);
}
