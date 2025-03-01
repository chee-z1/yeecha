#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd_inner(int a, int b)
{
	int temp;
	while (b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int gcd(int a, int b)
{
	if (a > b) return gcd_inner(a, b);
	else return gcd_inner(b, a);
}

void calc_answer(char *an1, char *an2, int r1u, int r1d, int r2u, int r2d)
{
	int gcd_1 = gcd(r1u, r1d);
	int gcd_2 = gcd(r2u, r2d);
	
	char *sign_1;
	if (r1u * r1d > 0)
		sign_1 = "";
	else
		sign_1 = "-";
	
	if (abs(r1d) == abs(gcd_1))
		sprintf(an1, "%d", r1u);
	else
		sprintf(an1, "%s%d/%d", sign_1, abs(r1u/gcd_1), abs(r1d/gcd_1));
		
	char *sign_2;
	if (r2u * r2d > 0)
		sign_2 = "";
	else
		sign_2 = "-";
	if (abs(r2d) == abs(gcd_2))
		sprintf(an2, "%d", r2u);
	else
		sprintf(an2, "%s%d/%d", sign_2, abs(r2u/gcd_2), abs(r2d/gcd_2));
	return;
}

int main()
{
	srand(time(NULL));
	// (r1dx - r1u)(r2dx - r2u)
	int r1u = (rand() % 8) * ((rand() % 1) * 2 - 1);
	int r1d = (rand() % 8) + ((rand() % 1) * 2 - 1);
	int r2u = (rand() % 8) * ((rand() % 1) * 2 - 1);
	int r2d = (rand() % 8) * ((rand() % 1) * 2 - 1);
	int a = r1d * r2d;
	int b = -(r1d * r2u + r1u * r2d);
	int c = r1u * r2u;
	int a1 = (rand() % 5) * ((rand() % 1) * 2 - 1);
	int b1 = (rand() % 5) * ((rand() % 1) * 2 - 1);
	int c1 = (rand() % 5) * ((rand() % 1) * 2 - 1);
	int a2 = a1 - a;
	int b2 = b1 - b;
	int c2 = c1 - c;
	char an1[20];
	char an2[20];
	char an1_r[20];
	char an2_r[20];
	// printf("%dx²%+dx%+d = %dx²%+dx%+d\n", a1, b1, c1, a2, b2, c2);
	printf("%dx²%+dx%+d = 0\n", a, b, c);
	calc_answer(an1_r, an2_r, r1u, r1d, r2u, r2d);
	scanf("%s %s", an1, an2);
	if (!strcmp(an1, an1_r))
		if (!strcmp(an2, an2_r))
			printf("CORRECT!\n");
		else
			printf("INCORRECT!: %s, %s\n", an2_r, an1_r);
	else if (!strcmp(an1, an2_r))
		if (!strcmp(an2, an1_r))
			printf("CORRECT!\n");
		else
			printf("INCORRECT!: %s, %s\n", an2_r, an1_r);
	else 
			printf("INCORRECT!: %s, %s\n", an2_r, an1_r);
			
	return 0;
}
