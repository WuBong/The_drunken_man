#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


void Map(void)
{
	srand(time(NULL));
	int arr1[20][20];//1길과 0벽
	int g = 0, s = 0; int x = 0; int y = 0; int z = 0; int a = 0; int c = 0; int d = 0; int v = 0; int f = 0;
	int timing = 0;  int lengx = 0; int lengy = 0;	int ifs = 0;
	int lilq = 0; int lilw = 0; int qreq = 0; int qrew = 0; int proq = 0; int prow = 0;
	int psul = 0, home = 0;

	int arr2[10][10] = { 0, };//집 H 2 (x,y)
	int arr3[10][10] = { 0, }; //술집 P 3 (z,a)
	int arr4[10][10] = { 0, };//D 4
	int arr5[10][10] = {0, };//F 5 쫓아가는애
	int length[10][10] = { 0, }; int lengthsum = 0;

	for (s = 0; s < 10; s++) { for (g = 0; g < 10; g++) { arr1[s][g] = 1; } } //모두 길로 초기화

	arr1[0][0] = 0; arr1[0][1] = 0; arr1[0][2] = 0; arr1[0][3] = 0; arr1[0][4] = 0; arr1[0][8] = 0; arr1[0][9] = 0;
	arr1[1][8] = 0; arr1[1][9] = 0; arr1[2][1] = 0; arr1[2][2] = 0; arr1[2][3] = 0;
	arr1[3][8] = 0; arr1[6][6] = 0; arr1[6][8] = 0;
	arr1[7][6] = 0; arr1[8][1] = 0; arr1[8][2] = 0; arr1[8][6] = 0; arr1[8][8] = 0;

	/*ex)집이 1사분면이면 술집은 3사분면
	이걸로 F설정후 어떻게 움직이게 할가...
	배열끼리 값바꾸기 
	ex) arr4[s+1][j+1] = arr4[s][j]
	arr4[s][j] = 0;*/
	printf("1000이상의 수를 입력하지마시오 \nex) 1000 = 1초\n 100 = 0.1\n");
	scanf_s("%d", &timing);


	while (1000 < timing)
	{
		printf("1000을 넘었습니다.\n");
		scanf_s("%d", &timing);
	}
	system("cls");
	//처음 출력 술집에서 아무도 나오기 전
	for (s = 0; s < 10; s++) //길과벽
	{
		for (g = 0; g < 10; g++) 
		{
			if (arr1[s][g] == 1)
			{
				printf("□");
			}
			else if (arr1[s][g] == 0)
			{
				printf("■");
			}
			else if (arr1[s][g] == 2)
			{
				printf(" H");
			}
			else if (arr1[s][g] == 3)
			{
				printf(" P");
			}
			else if (arr1[s][g] == 4)
			{
				printf(" D");
			}
			else if (arr1[s][g] == 5)
			{
				printf(" F");
			}


		}
		printf("\n");
	}
	Sleep(timing);
	system("cls");



	s = rand() % 4;

	if (s == 0)//1 술집은 3사분면
	{
		x = rand() % 4;
		y = rand() % 4 + 5;
		while (arr1[x][y] == 0)
		{
			x = rand() % 4;
			y = rand() % 4 + 5;
		}
		arr1[x][y] = 2;
		arr2[x][y] = 2;
		z = rand() % 4 + 5;
		a = rand() % 4;
		while (arr1[z][a] == 0)
		{
			z = rand() % 4 + 5;
			a = rand() % 4;
		}
		arr3[z][a] = 3;
		arr1[z][a] = 3;
		psul = 3;  home = 1;//
	}
	else if (s == 1)  //2 술집은 4사분면
	{
		x = rand() % 4;
		y = rand() % 4;
		while (arr1[x][y] == 0)
		{
			x = rand() % 4;
			y = rand() % 4;
		}
		arr2[x][y] = 2;
		arr1[x][y] = 2;
		z = rand() % 4 + 5;
		a = rand() % 4 + 5;
		while (arr1[z][a] == 0)
		{
			z = rand() % 4 + 5;
			a = rand() % 4 + 5;
		}
		arr3[z][a] = 3; //술집
		arr1[z][a] = 3;
		psul = 4; home = 2;

	}
	else if (s == 2)//3 술집은 1사분면
	{
		x = rand() % 4+5;
		y = rand() % 4;
		while (arr1[x][y] == 0) 
		{
			x = rand() % 4+5;
			y = rand() % 4;
		}
		arr2[x][y] = 2;
		arr1[x][y] = 2;
		z = rand() % 4;
		a = rand() % 4+5;
		while (arr1[z][a] == 0)
		{
			z = rand() % 4;
			a = rand() % 4+5;
		}
		arr3[z][a] = 3;
		arr1[z][a] = 3;
		psul = 1; home = 3;
		
	}
	else //4 술집은 2사분면
	{
		x = rand() % 4 + 5;
		y = rand() % 4 + 5;
		while (arr1[x][y] == 0)
		{
			x = rand() % 4 + 5;
			y = rand() % 4 + 5;
		}
		arr2[x][y] = 2;
		arr1[x][y] = 2;
		z = rand() % 4;
		a = rand() % 4;
		while (arr1[z][a] == 0)
		{
			z = rand() % 4;
			a = rand() % 4;
		}
		arr3[z][a] = 3;
		arr1[z][a] = 3;
		psul = 2; home = 4;
	}



	//출력부
	for (s = 0; s < 10; s++) //길과벽
	{
		for (g = 0; g < 10; g++) //여기함수 고치기 집과 술집 DF가 포함되도록
		{
			if (arr1[s][g] == 1)
			{
				printf("□");
			}
			else if(arr1[s][g] == 0)
			{
				printf("■");
			}
			else if (arr1[s][g] == 2)
			{
				printf(" H");
			}
			else if (arr1[s][g] == 3)
			{
				printf(" P");
			}
			else if (arr1[s][g] == 4)
			{
				printf(" D");
			}
			else if (arr1[s][g] == 5)
			{
				printf(" F");
			}


		}
		printf("\n");
	}
	Sleep(timing);
	system("cls");

	//D가나올 방향설정 //c,d //오 이걸로 랜덤워크
	try1:
	s = rand() % 4;  //D 설정
	if (s == 0)
	{
		d = 0; c = 0;
		c = 0; d = a;
		c = z + 1;
		if (c == 10)
		{
			goto try1;
		}
	}
	else if (s == 1)
	{
		d = 0; c = 0;
		c = 0; d = a;
		c = z - 1;
		if (c == -1)
		{
			goto try1;
		}
	}
	else if (s == 2)
	{
		c = 0; d = 0;
		c = z; d = 0;
		d = a + 1;
		if (d == 10)
		{
			goto try1;
		}
	}
	else
	{
		c = 0; d = 0;
		c = z; d = 0;
		d = a - 1;
		if (d == -1)
		{
			goto try1;
		}
	}
	while (arr1[c][d] == 0)
	{
		try2:
		s = rand() % 4;
		if (s == 0)
		{
			d = 0; c = 0;
			c = 0; d = a;
			c = z + 1;
			if (c == 10)
			{
				goto try2;
			}
		}
		else if (s == 1)
		{
			d = 0; c = 0;
			c = 0; d = a;
			c = z - 1;
			if (c == -1)
			{
				goto try2;
			}
		}
		else if (s == 2)
		{
			c = 0; d = 0;
			c = z; d = 0;
			d = a + 1;
			if (d == 10)
			{
				goto try2;
			}
		}
		else
		{
			c = 0; d = 0;
			c = z; d = 0;
			d = a - 1;
			if (d == -1)
			{
				goto try2;
			}
		}
	}
	arr4[c][d] = 4;
	arr1[c][d] = 4; 

	//술집에서 D가 나오는 출력부.
	for (s = 0; s < 10; s++) //길과벽
	{
		for (g = 0; g < 10; g++) //여기함수 고치기 집과 술집 DF가 포함되도록
		{
			if (arr1[s][g] == 1)
			{
				printf("□");
			}
			else if (arr1[s][g] == 0)
			{
				printf("■");
			}
			else if (arr1[s][g] == 2)
			{
				printf(" H");
			}
			else if (arr1[s][g] == 3)
			{
				printf(" P");
			}
			else if (arr1[s][g] == 4)
			{
				printf(" D");
			}
			else if (arr1[s][g] == 5)
			{
				printf(" F");
			}

		}
		printf("\n");
	}
	Sleep(timing);
	system("cls");


	try3:
	s = rand() % 4; //D의 랜덤워크
	if (s == 0)
	{
		lilq = 0; lilw = 0;
		lilq = c + 1; lilw = d;
		if (lilq == 10)
		{
			goto try3;
		}
	}
	else if (s == 1)
	{
		lilq = 0; lilw = 0;
		lilq = c - 1; lilw = d;
		if (lilq == -1)
		{
			goto try3;
		}
	}
	else if (s == 2)
	{
		lilq = 0; lilw = 0;
		lilq = c; lilw = d + 1;
		if (lilw == 10)
		{
			goto try3;
		}
	}
	else
	{
		lilq = 0; lilw = 0;
		lilq = c; lilw = d - 1;
		if (lilw == -1)
		{
			goto try3;
		}
	}


	//다시 

	while (arr1[lilq][lilw] == 0 || arr1[lilq][lilw] == 3 || arr1[lilq][lilw] == 5)
	{
		try4:
		s = rand() % 4; //D의 랜덤워크
		if (s == 0)
		{
			lilq = 0; lilw = 0;
			lilq = c + 1; lilw = d;
			if (lilq == 10)
			{
				goto try4;
			}
		}
		else if (s == 1)
		{
			lilq = 0; lilw = 0;
			lilq = c - 1; lilw = d;
			if (lilq == -1)
			{
				goto try4;
			}
		}
		else if (s == 2)
		{
			lilq = 0; lilw = 0;
			lilq = c; lilw = d + 1;
			if (lilw == 10)
			{
				goto try4;
			}
		}
		else
		{
			lilq = 0; lilw = 0;
			lilq = c; lilw = d - 1;
			if (lilw == -1)
			{
				goto try4;
			}
		}
	}
	arr1[c][d] = 1; arr4[c][d] = 0;
	arr1[lilq][lilw] = 4; arr4[lilq][lilw] = 4;
	qreq = c; qrew = d; //c,d의 예전위치
	c = lilq; d = lilw;


	//F
	arr1[qreq][qrew] = 5; arr5[qreq][qrew] = 5;
	proq = qreq; prow = qrew;

	//F가 술집에서 나옴.
	for (s = 0; s < 10; s++) //길과벽
	{
		for (g = 0; g < 10; g++) //여기함수 고치기 집과 술집 DF가 포함되도록
		{
			if (arr1[s][g] == 1)
			{
				printf("□");
			}
			else if (arr1[s][g] == 0)
			{
				printf("■");
			}
			else if (arr1[s][g] == 2)
			{
				printf(" H");
			}
			else if (arr1[s][g] == 3)
			{
				printf(" P");
			}
			else if (arr1[s][g] == 4)
			{
				printf(" D");
			}
			else if (arr1[s][g] == 5)
			{
				printf(" F");
			}

		}
		printf("\n");
	}
	Sleep(timing);
	system("cls");








	while (1)  //게임이 끝나는 조건...
	{
		system("cls");

		if (psul == 1) //home 4분면
		{
			if ((c <= 4) && (d <= 4))//2사분면으로 나올때
			{
			sintry1:
				s = rand() % 4; //D의 랜덤워크
				if (s == 0)
				{
					lilq = 0; lilw = 0;
					lilq = c + 1; lilw = d;
					if (lilq == 10)
					{
						goto sintry1;
					}
				}
				else if (s == 1)
				{
					lilq = 0; lilw = 0;
					lilq = c - 1; lilw = d;
					if (lilq == -1)
					{
						goto sintry1;
					}
				}
				else if (s == 2)
				{
					lilq = 0; lilw = 0;
					lilq = c; lilw = d + 1;
					if (lilw == 10)
					{
						goto sintry1;
					}
				}
				else
				{
					lilq = 0; lilw = 0;
					lilq = c; lilw = d - 1;
					if (lilw == -1)
					{
						goto sintry1;
					}
				}

				while (arr1[lilq][lilw] == 0 || arr1[lilq][lilw] == 5 || ((lilq <= 4) && (lilw == 5))) //arr1[lilq][lilw]==3
				{
				sintry2:
					s = rand() % 4; //D의 랜덤워크
					if (s == 0)
					{
						lilq = 0; lilw = 0;
						lilq = c + 1; lilw = d;
						if (lilq == 10)
						{
							goto sintry2;
						}
					}
					else if (s == 1)
					{
						lilq = 0; lilw = 0;
						lilq = c - 1; lilw = d;
						if (lilq == -1)
						{
							goto sintry2;
						}
					}
					else if (s == 2)
					{
						lilq = 0; lilw = 0;
						lilq = c; lilw = d + 1;
						if (lilw == 10)
						{
							goto sintry2;
						}
					}
					else
					{
						lilq = 0; lilw = 0;
						lilq = c; lilw = d - 1;
						if (lilw == -1)
						{
							goto sintry2;
						}

					}
				}
				qreq = 0; qrew = 0;
				arr1[c][d] = 1; arr4[c][d] = 0;
				arr1[lilq][lilw] = 4; arr4[lilq][lilw] = 4;
				qreq = c; qrew = d; //D이전의 값 그리고 F위치값 proq prow
				c = lilq; d = lilw; //D좌표로 초기화
				length[qreq][qrew] = 1;
				arr1[proq][prow] = 1; arr5[proq][prow] = 0;
				arr1[qreq][qrew] = 5; arr5[qreq][qrew] = 5;
				proq = qreq; prow = qrew;
				arr3[z][a] = 3; arr1[z][a] = 3; //술집다시;
				ifs = 1;
				goto end1;
			}
			else if ((c >= 5) && (d >= 5)) //4사분면으로 나올때
			{
			sintry3:
				s = rand() % 4; //D의 랜덤워크
				if (s == 0)
				{
					lilq = 0; lilw = 0;
					lilq = c + 1; lilw = d;
					if (lilq == 10)
					{
						goto sintry3;
					}
				}
				else if (s == 1)
				{
					lilq = 0; lilw = 0;
					lilq = c - 1; lilw = d;
					if (lilq == -1)
					{
						goto sintry3;
					}
				}
				else if (s == 2)
				{
					lilq = 0; lilw = 0;
					lilq = c; lilw = d + 1;
					if (lilw == 10)
					{
						goto sintry3;
					}
				}
				else
				{
					lilq = 0; lilw = 0;
					lilq = c; lilw = d - 1;
					if (lilw == -1)
					{
						goto sintry3;
					}
				}

				while (arr1[lilq][lilw] == 0 || arr1[lilq][lilw] == 5 || ((lilq == 4) && (lilw >= 5))) //arr1[lilq][lilw]==3
				{
				sintry4:
					s = rand() % 4; //D의 랜덤워크
					if (s == 0)
					{
						lilq = 0; lilw = 0;
						lilq = c + 1; lilw = d;
						if (lilq == 10)
						{
							goto sintry4;
						}
					}
					else if (s == 1)
					{
						lilq = 0; lilw = 0;
						lilq = c - 1; lilw = d;
						if (lilq == -1)
						{
							goto sintry4;
						}
					}
					else if (s == 2)
					{
						lilq = 0; lilw = 0;
						lilq = c; lilw = d + 1;
						if (lilw == 10)
						{
							goto sintry4;
						}
					}
					else
					{
						lilq = 0; lilw = 0;
						lilq = c; lilw = d - 1;
						if (lilw == -1)
						{
							goto sintry4;
						}

					}
				}
				qreq = 0; qrew = 0;
				arr1[c][d] = 1; arr4[c][d] = 0;
				arr1[lilq][lilw] = 4; arr4[lilq][lilw] = 4;
				qreq = c; qrew = d; //D이전의 값 그리고 F위치값 proq prow
				c = lilq; d = lilw; //D좌표로 초기화
				length[qreq][qrew] = 1;
				arr1[proq][prow] = 1; arr5[proq][prow] = 0;
				arr1[qreq][qrew] = 5; arr5[qreq][qrew] = 5;
				proq = qreq; prow = qrew;
				arr3[z][a] = 3; arr1[z][a] = 3; //술집다시;
				ifs = 1;
				goto end2;
			}
			else if ((c >= 5) && (d <= 4)) //집3사분면 으로 들어갈때.
			{
			sintry5:
				s = rand() % 4; //D의 랜덤워크
				if (s == 0)
				{
					lilq = 0; lilw = 0;
					lilq = c + 1; lilw = d;
					if (lilq == 10)
					{
						goto sintry5;
					}
				}
				else if (s == 1)
				{
					lilq = 0; lilw = 0;
					lilq = c - 1; lilw = d;
					if (lilq == -1)
					{
						goto sintry5;
					}
				}
				else if (s == 2)
				{
					lilq = 0; lilw = 0;
					lilq = c; lilw = d + 1;
					if (lilw == 10)
					{
						goto sintry5;
					}
				}
				else
				{
					lilq = 0; lilw = 0;
					lilq = c; lilw = d - 1;
					if (lilw == -1)
					{
						goto sintry5;
					}
				}

				while (arr1[lilq][lilw] == 0 || arr1[lilq][lilw] == 5 || ((lilq == 4) && (lilw <= 4)) || ((lilq >= 5) && (lilw == 5))) //arr1[lilq][lilw]==3
				{
				sintry6:
					s = rand() % 4; //D의 랜덤워크
					if (s == 0)
					{
						lilq = 0; lilw = 0;
						lilq = c + 1; lilw = d;
						if (lilq == 10)
						{
							goto sintry6;
						}
					}
					else if (s == 1)
					{
						lilq = 0; lilw = 0;
						lilq = c - 1; lilw = d;
						if (lilq == -1)
						{
							goto sintry6;
						}
					}
					else if (s == 2)
					{
						lilq = 0; lilw = 0;
						lilq = c; lilw = d + 1;
						if (lilw == 10)
						{
							goto sintry6;
						}
					}
					else
					{
						lilq = 0; lilw = 0;
						lilq = c; lilw = d - 1;
						if (lilw == -1)
						{
							goto sintry6;
						}

					}
				}
				qreq = 0; qrew = 0;
				arr1[c][d] = 1; arr4[c][d] = 0;
				arr1[lilq][lilw] = 4; arr4[lilq][lilw] = 4;
				qreq = c; qrew = d; //D이전의 값 그리고 F위치값 proq prow
				c = lilq; d = lilw; //D좌표로 초기화
				length[qreq][qrew] = 1;
				arr3[z][a] = 3; arr1[z][a] = 3; //술집다시;
				ifs = 0;
				goto end3;
			}

		}

		else if (psul == 2) //술집이 2사분면 일때 집은 4분면
		{
		if ((c >= 5) && (d <= 4))//3사분면으로 나올때
		{
		sintry7:
			s = rand() % 4; //D의 랜덤워크
			if (s == 0)
			{
				lilq = 0; lilw = 0;
				lilq = c + 1; lilw = d;
				if (lilq == 10)
				{
					goto sintry7;
				}
			}
			else if (s == 1)
			{
				lilq = 0; lilw = 0;
				lilq = c - 1; lilw = d;
				if (lilq == -1)
				{
					goto sintry7;
				}
			}
			else if (s == 2)
			{
				lilq = 0; lilw = 0;
				lilq = c; lilw = d + 1;
				if (lilw == 10)
				{
					goto sintry7;
				}
			}
			else
			{
				lilq = 0; lilw = 0;
				lilq = c; lilw = d - 1;
				if (lilw == -1)
				{
					goto sintry7;
				}
			}

			while (arr1[lilq][lilw] == 0 || arr1[lilq][lilw] == 5 || ((lilq == 5) && (lilw <= 4))) //arr1[lilq][lilw]==3
			{
			sintry8:
				s = rand() % 4; //D의 랜덤워크
				if (s == 0)
				{
					lilq = 0; lilw = 0;
					lilq = c + 1; lilw = d;
					if (lilq == 10)
					{
						goto sintry8;
					}
				}
				else if (s == 1)
				{
					lilq = 0; lilw = 0;
					lilq = c - 1; lilw = d;
					if (lilq == -1)
					{
						goto sintry8;
					}
				}
				else if (s == 2)
				{
					lilq = 0; lilw = 0;
					lilq = c; lilw = d + 1;
					if (lilw == 10)
					{
						goto sintry8;
					}
				}
				else
				{
					lilq = 0; lilw = 0;
					lilq = c; lilw = d - 1;
					if (lilw == -1)
					{
						goto sintry8;
					}

				}
			}
			qreq = 0; qrew = 0;
			arr1[c][d] = 1; arr4[c][d] = 0;
			arr1[lilq][lilw] = 4; arr4[lilq][lilw] = 4;
			qreq = c; qrew = d; //D이전의 값 그리고 F위치값 proq prow
			c = lilq; d = lilw; //D좌표로 초기화
			length[qreq][qrew] = 1;
			arr1[proq][prow] = 1; arr5[proq][prow] = 0;
			arr1[qreq][qrew] = 5; arr5[qreq][qrew] = 5;
			proq = qreq; prow = qrew;
			arr3[z][a] = 3; arr1[z][a] = 3; //술집다시;
			ifs = 1;
			goto end4;
		}


		else if ((c <= 4) && (d >= 5))  //1사분면으로 나올때
		{
		sintry9:
			s = rand() % 4; //D의 랜덤워크
			if (s == 0)
			{
				lilq = 0; lilw = 0;
				lilq = c + 1; lilw = d;
				if (lilq == 10)
				{
					goto sintry9;
				}
			}
			else if (s == 1)
			{
				lilq = 0; lilw = 0;
				lilq = c - 1; lilw = d;
				if (lilq == -1)
				{
					goto sintry9;
				}
			}
			else if (s == 2)
			{
				lilq = 0; lilw = 0;
				lilq = c; lilw = d + 1;
				if (lilw == 10)
				{
					goto sintry9;
				}
			}
			else
			{
				lilq = 0; lilw = 0;
				lilq = c; lilw = d - 1;
				if (lilw == -1)
				{
					goto sintry9;
				}
			}

			while (arr1[lilq][lilw] == 0 || arr1[lilq][lilw] == 5 || ((lilq <= 4) && (lilw == 5))) //arr1[lilq][lilw]==3
			{
			sintry10:
				s = rand() % 4; //D의 랜덤워크
				if (s == 0)
				{
					lilq = 0; lilw = 0;
					lilq = c + 1; lilw = d;
					if (lilq == 10)
					{
						goto sintry10;
					}
				}
				else if (s == 1)
				{
					lilq = 0; lilw = 0;
					lilq = c - 1; lilw = d;
					if (lilq == -1)
					{
						goto sintry10;
					}
				}
				else if (s == 2)
				{
					lilq = 0; lilw = 0;
					lilq = c; lilw = d + 1;
					if (lilw == 10)
					{
						goto sintry10;
					}
				}
				else
				{
					lilq = 0; lilw = 0;
					lilq = c; lilw = d - 1;
					if (lilw == -1)
					{
						goto sintry10;
					}

				}
			}
			qreq = 0; qrew = 0;
			arr1[c][d] = 1; arr4[c][d] = 0;
			arr1[lilq][lilw] = 4; arr4[lilq][lilw] = 4;
			qreq = c; qrew = d; //D이전의 값 그리고 F위치값 proq prow
			c = lilq; d = lilw; //D좌표로 초기화
			length[qreq][qrew] = 1;
			arr1[proq][prow] = 1; arr5[proq][prow] = 0;
			arr1[qreq][qrew] = 5; arr5[qreq][qrew] = 5;
			proq = qreq; prow = qrew;
			arr3[z][a] = 3; arr1[z][a] = 3; //술집다시;
			ifs = 1;
			goto end5;
		}


		else if ((c >= 5) && (d >= 5)) //집4사분면으로 들어갈때
		{
		sintry11:
			s = rand() % 4; //D의 랜덤워크
			if (s == 0)
			{
				lilq = 0; lilw = 0;
				lilq = c + 1; lilw = d;
				if (lilq == 10)
				{
					goto sintry11;
				}
			}
			else if (s == 1)
			{
				lilq = 0; lilw = 0;
				lilq = c - 1; lilw = d;
				if (lilq == -1)
				{
					goto sintry11;
				}
			}
			else if (s == 2)
			{
				lilq = 0; lilw = 0;
				lilq = c; lilw = d + 1;
				if (lilw == 10)
				{
					goto sintry11;
				}
			}
			else
			{
				lilq = 0; lilw = 0;
				lilq = c; lilw = d - 1;
				if (lilw == -1)
				{
					goto sintry11;
				}
			}

			while (arr1[lilq][lilw] == 0 || arr1[lilq][lilw] == 5 || ((lilq == 4) && (lilw >= 5)) || ((lilq >= 5) && (lilw == 4))) //arr1[lilq][lilw]==3
			{
			sintry12:
				s = rand() % 4; //D의 랜덤워크
				if (s == 0)
				{
					lilq = 0; lilw = 0;
					lilq = c + 1; lilw = d;
					if (lilq == 10)
					{
						goto sintry12;
					}
				}
				else if (s == 1)
				{
					lilq = 0; lilw = 0;
					lilq = c - 1; lilw = d;
					if (lilq == -1)
					{
						goto sintry12;
					}
				}
				else if (s == 2)
				{
					lilq = 0; lilw = 0;
					lilq = c; lilw = d + 1;
					if (lilw == 10)
					{
						goto sintry12;
					}
				}
				else
				{
					lilq = 0; lilw = 0;
					lilq = c; lilw = d - 1;
					if (lilw == -1)
					{
						goto sintry12;
					}

				}
			}
			qreq = 0; qrew = 0;
			arr1[c][d] = 1; arr4[c][d] = 0;
			arr1[lilq][lilw] = 4; arr4[lilq][lilw] = 4;
			qreq = c; qrew = d; //D이전의 값 그리고 F위치값 proq prow
			c = lilq; d = lilw; //D좌표로 초기화
			length[qreq][qrew] = 1;
			arr3[z][a] = 3; arr1[z][a] = 3; //술집다시;
			ifs = 0;
			goto end6;
			}
		
		}






		else if (psul == 3)//집은 1사분면.
			{
			if ((c >= 5) && (d >= 5)) //4분면으로 나올때
			{
			sintry13:
				s = rand() % 4; //D의 랜덤워크
				if (s == 0)
				{
					lilq = 0; lilw = 0;
					lilq = c + 1; lilw = d;
					if (lilq == 10)
					{
						goto sintry13;
					}
				}
				else if (s == 1)
				{
					lilq = 0; lilw = 0;
					lilq = c - 1; lilw = d;
					if (lilq == -1)
					{
						goto sintry13;
					}
				}
				else if (s == 2)
				{
					lilq = 0; lilw = 0;
					lilq = c; lilw = d + 1;
					if (lilw == 10)
					{
						goto sintry13;
					}
				}
				else
				{
					lilq = 0; lilw = 0;
					lilq = c; lilw = d - 1;
					if (lilw == -1)
					{
						goto sintry13;
					}
				}

				while (arr1[lilq][lilw] == 0 || arr1[lilq][lilw] == 5 || ((lilq >= 5) && (lilw == 4))) //arr1[lilq][lilw]==3
				{
				sintry14:
					s = rand() % 4; //D의 랜덤워크
					if (s == 0)
					{
						lilq = 0; lilw = 0;
						lilq = c + 1; lilw = d;
						if (lilq == 10)
						{
							goto sintry14;
						}
					}
					else if (s == 1)
					{
						lilq = 0; lilw = 0;
						lilq = c - 1; lilw = d;
						if (lilq == -1)
						{
							goto sintry14;
						}
					}
					else if (s == 2)
					{
						lilq = 0; lilw = 0;
						lilq = c; lilw = d + 1;
						if (lilw == 10)
						{
							goto sintry14;
						}
					}
					else
					{
						lilq = 0; lilw = 0;
						lilq = c; lilw = d - 1;
						if (lilw == -1)
						{
							goto sintry14;
						}

					}
				}
				qreq = 0; qrew = 0;
				arr1[c][d] = 1; arr4[c][d] = 0;
				arr1[lilq][lilw] = 4; arr4[lilq][lilw] = 4;
				qreq = c; qrew = d; //D이전의 값 그리고 F위치값 proq prow
				c = lilq; d = lilw; //D좌표로 초기화
				length[qreq][qrew] = 1;
				arr1[proq][prow] = 1; arr5[proq][prow] = 0;
				arr1[qreq][qrew] = 5; arr5[qreq][qrew] = 5;
				proq = qreq; prow = qrew;
				arr3[z][a] = 3; arr1[z][a] = 3; //술집다시;
				ifs = 1;
				goto end7;
			}
			else if ((c <= 4) && (d <= 4)) //2분면으로 나올때
			{
			sintry15:
				s = rand() % 4; //D의 랜덤워크
				if (s == 0)
				{
					lilq = 0; lilw = 0;
					lilq = c + 1; lilw = d;
					if (lilq == 10)
					{
						goto sintry15;
					}
				}
				else if (s == 1)
				{
					lilq = 0; lilw = 0;
					lilq = c - 1; lilw = d;
					if (lilq == -1)
					{
						goto sintry15;
					}
				}
				else if (s == 2)
				{
					lilq = 0; lilw = 0;
					lilq = c; lilw = d + 1;
					if (lilw == 10)
					{
						goto sintry15;
					}
				}
				else
				{
					lilq = 0; lilw = 0;
					lilq = c; lilw = d - 1;
					if (lilw == -1)
					{
						goto sintry15;
					}
				}

				while (arr1[lilq][lilw] == 0 || arr1[lilq][lilw] == 5 || ((lilq == 5) && (lilw <= 4))) //arr1[lilq][lilw]==3
				{
				sintry16:
					s = rand() % 4; //D의 랜덤워크
					if (s == 0)
					{
						lilq = 0; lilw = 0;
						lilq = c + 1; lilw = d;
						if (lilq == 10)
						{
							goto sintry16;
						}
					}
					else if (s == 1)
					{
						lilq = 0; lilw = 0;
						lilq = c - 1; lilw = d;
						if (lilq == -1)
						{
							goto sintry16;
						}
					}
					else if (s == 2)
					{
						lilq = 0; lilw = 0;
						lilq = c; lilw = d + 1;
						if (lilw == 10)
						{
							goto sintry16;
						}
					}
					else
					{
						lilq = 0; lilw = 0;
						lilq = c; lilw = d - 1;
						if (lilw == -1)
						{
							goto sintry16;
						}

					}
				}
				qreq = 0; qrew = 0;
				arr1[c][d] = 1; arr4[c][d] = 0;
				arr1[lilq][lilw] = 4; arr4[lilq][lilw] = 4;
				qreq = c; qrew = d; //D이전의 값 그리고 F위치값 proq prow
				c = lilq; d = lilw; //D좌표로 초기화
				length[qreq][qrew] = 1;
				arr1[proq][prow] = 1; arr5[proq][prow] = 0;
				arr1[qreq][qrew] = 5; arr5[qreq][qrew] = 5;
				proq = qreq; prow = qrew;
				arr3[z][a] = 3; arr1[z][a] = 3; //술집다시;
				ifs = 1;
				goto end8;
			}


			else if ((c <= 4) && (d >= 5))// 집 1사분면으로 들어갈때
			{
			sintry17:
				s = rand() % 4; //D의 랜덤워크
				if (s == 0)
				{
					lilq = 0; lilw = 0;
					lilq = c + 1; lilw = d;
					if (lilq == 10)
					{
						goto sintry17;
					}
				}
				else if (s == 1)
				{
					lilq = 0; lilw = 0;
					lilq = c - 1; lilw = d;
					if (lilq == -1)
					{
						goto sintry17;
					}
				}
				else if (s == 2)
				{
					lilq = 0; lilw = 0;
					lilq = c; lilw = d + 1;
					if (lilw == 10)
					{
						goto sintry17;
					}
				}
				else
				{
					lilq = 0; lilw = 0;
					lilq = c; lilw = d - 1;
					if (lilw == -1)
					{
						goto sintry17;
					}
				}

				while (arr1[lilq][lilw] == 0 || arr1[lilq][lilw] == 5 || ((lilq == 5) && (lilw >= 5)) || ((lilq <= 4) && (lilw == 4))) //arr1[lilq][lilw]==3
				{
				sintry18:
					s = rand() % 4; //D의 랜덤워크
					if (s == 0)
					{
						lilq = 0; lilw = 0;
						lilq = c + 1; lilw = d;
						if (lilq == 10)
						{
							goto sintry18;
						}
					}
					else if (s == 1)
					{
						lilq = 0; lilw = 0;
						lilq = c - 1; lilw = d;
						if (lilq == -1)
						{
							goto sintry18;
						}
					}
					else if (s == 2)
					{
						lilq = 0; lilw = 0;
						lilq = c; lilw = d + 1;
						if (lilw == 10)
						{
							goto sintry18;
						}
					}
					else
					{
						lilq = 0; lilw = 0;
						lilq = c; lilw = d - 1;
						if (lilw == -1)
						{
							goto sintry18;
						}

					}
				}
				qreq = 0; qrew = 0;
				arr1[c][d] = 1; arr4[c][d] = 0;
				arr1[lilq][lilw] = 4; arr4[lilq][lilw] = 4;
				qreq = c; qrew = d; //D이전의 값 그리고 F위치값 proq prow
				c = lilq; d = lilw; //D좌표로 초기화
				length[qreq][qrew] = 1;
				arr3[z][a] = 3; arr1[z][a] = 3; //술집다시;
				ifs = 0;
				goto end9;
			}
		}







		else if (psul == 4) //집은 2사분면
			{
			if ((c <= 4) && (d >= 5)) //1분면으로 나올때
			{
			sintry19:
				s = rand() % 4; //D의 랜덤워크
				if (s == 0)
				{
					lilq = 0; lilw = 0;
					lilq = c + 1; lilw = d;
					if (lilq == 10)
					{
						goto sintry19;
					}
				}
				else if (s == 1)
				{
					lilq = 0; lilw = 0;
					lilq = c - 1; lilw = d;
					if (lilq == -1)
					{
						goto sintry19;
					}
				}
				else if (s == 2)
				{
					lilq = 0; lilw = 0;
					lilq = c; lilw = d + 1;
					if (lilw == 10)
					{
						goto sintry19;
					}
				}
				else
				{
					lilq = 0; lilw = 0;
					lilq = c; lilw = d - 1;
					if (lilw == -1)
					{
						goto sintry19;
					}
				}

				while (arr1[lilq][lilw] == 0 || arr1[lilq][lilw] == 5 || ((lilq == 5) && (lilw >= 5))) //arr1[lilq][lilw]==3
				{
				sintry20:
					s = rand() % 4; //D의 랜덤워크
					if (s == 0)
					{
						lilq = 0; lilw = 0;
						lilq = c + 1; lilw = d;
						if (lilq == 10)
						{
							goto sintry20;
						}
					}
					else if (s == 1)
					{
						lilq = 0; lilw = 0;
						lilq = c - 1; lilw = d;
						if (lilq == -1)
						{
							goto sintry20;
						}
					}
					else if (s == 2)
					{
						lilq = 0; lilw = 0;
						lilq = c; lilw = d + 1;
						if (lilw == 10)
						{
							goto sintry20;
						}
					}
					else
					{
						lilq = 0; lilw = 0;
						lilq = c; lilw = d - 1;
						if (lilw == -1)
						{
							goto sintry20;
						}

					}
				}
				qreq = 0; qrew = 0;
				arr1[c][d] = 1; arr4[c][d] = 0;
				arr1[lilq][lilw] = 4; arr4[lilq][lilw] = 4;
				qreq = c; qrew = d; //D이전의 값 그리고 F위치값 proq prow
				c = lilq; d = lilw; //D좌표로 초기화
				length[qreq][qrew] = 1;
				arr1[proq][prow] = 1; arr5[proq][prow] = 0;
				arr1[qreq][qrew] = 5; arr5[qreq][qrew] = 5;
				proq = qreq; prow = qrew;
				arr3[z][a] = 3; arr1[z][a] = 3; //술집다시;
				ifs = 1;
				goto end10;
			}


			else if ((c >= 5) && (d <= 4)) //3분면으로 나올때
			{
			sintry21:
				s = rand() % 4; //D의 랜덤워크
				if (s == 0)
				{
					lilq = 0; lilw = 0;
					lilq = c + 1; lilw = d;
					if (lilq == 10)
					{
						goto sintry21;
					}
				}
				else if (s == 1)
				{
					lilq = 0; lilw = 0;
					lilq = c - 1; lilw = d;
					if (lilq == -1)
					{
						goto sintry21;
					}
				}
				else if (s == 2)
				{
					lilq = 0; lilw = 0;
					lilq = c; lilw = d + 1;
					if (lilw == 10)
					{
						goto sintry21;
					}
				}
				else
				{
					lilq = 0; lilw = 0;
					lilq = c; lilw = d - 1;
					if (lilw == -1)
					{
						goto sintry21;
					}
				}

				while (arr1[lilq][lilw] == 0 || arr1[lilq][lilw] == 5 || ((lilq >= 5) && (lilw == 5))) //arr1[lilq][lilw]==3
				{
				sintry22:
					s = rand() % 4; //D의 랜덤워크
					if (s == 0)
					{
						lilq = 0; lilw = 0;
						lilq = c + 1; lilw = d;
						if (lilq == 10)
						{
							goto sintry22;
						}
					}
					else if (s == 1)
					{
						lilq = 0; lilw = 0;
						lilq = c - 1; lilw = d;
						if (lilq == -1)
						{
							goto sintry22;
						}
					}
					else if (s == 2)
					{
						lilq = 0; lilw = 0;
						lilq = c; lilw = d + 1;
						if (lilw == 10)
						{
							goto sintry22;
						}
					}
					else
					{
						lilq = 0; lilw = 0;
						lilq = c; lilw = d - 1;
						if (lilw == -1)
						{
							goto sintry22;
						}

					}
				}
				qreq = 0; qrew = 0;
				arr1[c][d] = 1; arr4[c][d] = 0;
				arr1[lilq][lilw] = 4; arr4[lilq][lilw] = 4;
				qreq = c; qrew = d; //D이전의 값 그리고 F위치값 proq prow
				c = lilq; d = lilw; //D좌표로 초기화
				length[qreq][qrew] = 1;
				arr1[proq][prow] = 1; arr5[proq][prow] = 0;
				arr1[qreq][qrew] = 5; arr5[qreq][qrew] = 5;
				proq = qreq; prow = qrew;
				arr3[z][a] = 3; arr1[z][a] = 3; //술집다시;
				ifs = 1;
				goto end11;
			}


			else if ((c <= 4) && (d <= 4))// 집 2사분면으로 들어갈때
			{
			sintry23:
				s = rand() % 4; //D의 랜덤워크
				if (s == 0)
				{
					lilq = 0; lilw = 0;
					lilq = c + 1; lilw = d;
					if (lilq == 10)
					{
						goto sintry23;
					}
				}
				else if (s == 1)
				{
					lilq = 0; lilw = 0;
					lilq = c - 1; lilw = d;
					if (lilq == -1)
					{
						goto sintry23;
					}
				}
				else if (s == 2)
				{
					lilq = 0; lilw = 0;
					lilq = c; lilw = d + 1;
					if (lilw == 10)
					{
						goto sintry23;
					}
				}
				else
				{
					lilq = 0; lilw = 0;
					lilq = c; lilw = d - 1;
					if (lilw == -1)
					{
						goto sintry23;
					}
				}

				while (arr1[lilq][lilw] == 0 || arr1[lilq][lilw] == 5 || ((lilq == 5) && (lilw <= 4)) || ((lilq <= 4) && (lilw == 5))) //arr1[lilq][lilw]==3
				{
				sintry24:
					s = rand() % 4; //D의 랜덤워크
					if (s == 0)
					{
						lilq = 0; lilw = 0;
						lilq = c + 1; lilw = d;
						if (lilq == 10)
						{
							goto sintry24;
						}
					}
					else if (s == 1)
					{
						lilq = 0; lilw = 0;
						lilq = c - 1; lilw = d;
						if (lilq == -1)
						{
							goto sintry24;
						}
					}
					else if (s == 2)
					{
						lilq = 0; lilw = 0;
						lilq = c; lilw = d + 1;
						if (lilw == 10)
						{
							goto sintry24;
						}
					}
					else
					{
						lilq = 0; lilw = 0;
						lilq = c; lilw = d - 1;
						if (lilw == -1)
						{
							goto sintry24;
						}

					}
				}
				qreq = 0; qrew = 0;
				arr1[c][d] = 1; arr4[c][d] = 0;
				arr1[lilq][lilw] = 4; arr4[lilq][lilw] = 4;
				qreq = c; qrew = d; //D이전의 값 그리고 F위치값 proq prow
				c = lilq; d = lilw; //D좌표로 초기화
				length[qreq][qrew] = 1;
				arr3[z][a] = 3; arr1[z][a] = 3; //술집다시;
				ifs = 0;
				goto end12;
			}
		}









		try5:
			s = rand() % 4; //D의 랜덤워크
			if (s == 0)
			{
				lilq = 0; lilw = 0;
				lilq = c + 1; lilw = d;
				if (lilq == 10)
				{
					goto try5;
				}
			}
			else if (s == 1)
			{
				lilq = 0; lilw = 0;
				lilq = c - 1; lilw = d;
				if (lilq == -1)
				{
					goto try5;
				}
			}
			else if (s == 2)
			{
				lilq = 0; lilw = 0;
				lilq = c; lilw = d + 1;
				if (lilw == 10)
				{
					goto try5;
				}
			}
			else
			{
				lilq = 0; lilw = 0;
				lilq = c; lilw = d - 1;
				if (lilw == -1)
				{
					goto try5;
				}
			}

			while (arr1[lilq][lilw] == 0 || arr1[lilq][lilw] == 5) //arr1[lilq][lilw]==3
			{
			try6:
				s = rand() % 4; //D의 랜덤워크
				if (s == 0)
				{
					lilq = 0; lilw = 0;
					lilq = c + 1; lilw = d;
					if (lilq == 10)
					{
						goto try6;
					}
				}
				else if (s == 1)
				{
					lilq = 0; lilw = 0;
					lilq = c - 1; lilw = d;
					if (lilq == -1)
					{
						goto try6;
					}
				}
				else if (s == 2)
				{
					lilq = 0; lilw = 0;
					lilq = c; lilw = d + 1;
					if (lilw == 10)
					{
						goto try6;
					}
				}
				else
				{
					lilq = 0; lilw = 0;
					lilq = c; lilw = d - 1;
					if (lilw == -1)
					{
						goto try6;
					}

				}
			}
			
			qreq = 0; qrew = 0;
			arr1[c][d] = 1; arr4[c][d] = 0;
			arr1[lilq][lilw] = 4; arr4[lilq][lilw] = 4;
			qreq = c; qrew = d; //D이전의 값 그리고 F위치값 proq prow
			c = lilq; d = lilw; //D좌표로 초기화

			arr1[proq][prow] = 1; arr5[proq][prow] = 0;
			arr1[qreq][qrew] = 5; arr5[qreq][qrew] = 5;
			proq = qreq; prow = qrew;
			arr3[z][a] = 3; arr1[z][a] = 3; //술집다시
			ifs = 1;
			goto end13;
			
			          


			end3: end6: end9: end12:

			lengx = 0; lengy = 0;
			lengx = proq; lengy = prow;
			while ((lengx != c) && (lengy != d)) 
			{
				if (lengx < c)
				{
					lengx = lengx + 1;
					lengthsum = lengthsum + 1;
				}
				else if (lengx > c)
				{
					lengx = lengx - 1;
					lengthsum = lengthsum + 1;
				}

				if (lengy < d)
				{
					lengy = lengy + 1;
					lengthsum = lengthsum + 1;
				}
				else if (lengy > d)
				{
					lengy = lengy - 1;
					lengthsum = lengthsum + 1;
				}
			}
		



			if (lengthsum == 2) //30퍼 오른쪽 왼쪽 위 아래
			{
				if (3 > rand() % 10)
				{
					arr1[proq][prow] = 1; arr5[proq][prow] = 0;
					arr1[qreq][qrew] = 5; arr5[qreq][qrew] = 5;
					proq = qreq; prow = qrew;
					lengthsum = 0;
					arr3[z][a] = 3; arr1[z][a] = 3; //술집다시;
					
				}
			}
			else if (lengthsum == 3) //60퍼
			{
				if (6 > rand() % 10)
				{
					arr1[proq][prow] = 1; arr5[proq][prow] = 0;
					arr1[qreq][qrew] = 5; arr5[qreq][qrew] = 5;
					proq = qreq; prow = qrew;
					lengthsum = 0;
					arr3[z][a] = 3; arr1[z][a] = 3; //술집다시;
					
				}
			}
			else
			{
				arr1[proq][prow] = 1; arr5[proq][prow] = 0;
				arr1[qreq][qrew] = 5; arr5[qreq][qrew] = 5;
				proq = qreq; prow = qrew;
				lengthsum = 0;
				arr3[z][a] = 3; arr1[z][a] = 3; //술집다시;
				
			}
			lengthsum = 0;






			//출력부
			for (s = 0; s < 10; s++) //길과벽
			{
				for (g = 0; g < 10; g++) //여기함수 고치기 집과 술집 DF가 포함되도록
				{
					if (arr1[s][g] == 1)
					{
						printf("□");
					}
					else if (arr1[s][g] == 0)
					{
						printf("■");
					}
					else if (arr1[s][g] == 2)
					{
						printf(" H");
					}
					else if (arr1[s][g] == 3)
					{
						printf(" P");
					}
					else if (arr1[s][g] == 4)
					{
						printf(" D");
					}
					else if (arr1[s][g] == 5)
					{
						printf(" F");
					}
				}
				printf("\n");
			}
			Sleep(timing);




			if (ifs == 1)
			{
			end1: end2: end4: end5:  end7: end8:  end10: end11: end13:


				for (s = 0; s < 10; s++) //길과벽
				{
					for (g = 0; g < 10; g++) //여기함수 고치기 집과 술집 DF가 포함되도록
					{
						if (arr1[s][g] == 1)
						{
							printf("□");
						}
						else if (arr1[s][g] == 0)
						{
							printf("■");
						}
						else if (arr1[s][g] == 2)
						{
							printf(" H");
						}
						else if (arr1[s][g] == 3)
						{
							printf(" P");
						}
						else if (arr1[s][g] == 4)
						{
							printf(" D");
						}
						else if (arr1[s][g] == 5)
						{
							printf(" F");
						}
					}
					printf("\n");

				}
				Sleep(timing);
				system("cls");
			}

			//게임이 끝나는 조건 D가 H에 닿는다.
			if (((lilq == x) && (lilw + 1 == y)))
			{
				printf("게임 종료 \n");
				while (1) {
					
				}
			}
			else if ((lilq == x) && (lilw - 1 == y))
			{
				printf("게임 종료 \n");
				while (1) {
					
				}
			}
			else if ((lilq + 1 == x) && (lilw == y))
			{
				printf("게임 종료 \n");
				while (1) {
					
				}
			}
			else if ((lilq - 1 == x) && (lilw == y))
			{
				printf("게임 종료 \n");
				while (1) {
					
				}
			}
		}
	}
	






int main()
{
	Map();
	return 0;
}

/*
*배열은 좌표로 씀
arr1 길벽 arr2집 arr3 술집 arr4은f arr5은 d
d가 쫓아가는건 랜덤  %로 나머지값으로 퍼센트만듬
이미 갔던길은 안되돌아가게 만들기


*/