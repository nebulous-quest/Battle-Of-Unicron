#define LEVEL2_H_INCLUDED
using namespace std;

char spaceZet2[25] = "image\\SpaceCraft2.bmp"; //For spacecraft

//bool isResume1 = true;
//bool isPause1 = false;
//bool temp ;
int count1 = 0;
int t4, t5;
//Enemy co-ordinate
int enemy_x0 = 100;
int enemy_x11 = 250;
int enemy_x21 = 400;
int enemy_x31 = 600;
int enemy_x41 = 800;
int enemy_x51 = 1000;

int enemy_y0 = 550;
int enemy_y11 = 550;
int enemy_y21 = 550;
int enemy_y31 = 550;
int enemy_y41 = 550;
int enemy_y51 = 550;
//Enemy co-ordinate

void Gameover1()
{

	if (count1 == 11)
	{
		gameState = 5;
		HighScoreCalculate();
		score = 0;
		temp = false;
	}

}

void clash1()
{
	if (zet_y >= enemy_y0 && zet_y <= enemy_y0 + 200 && zet_x >= enemy_x0 && zet_x <= enemy_x0 + 180)
	{
		enemy_y0 = 1000;

	}
	else if (zet_y >= enemy_y11 && zet_y <= enemy_y11 + 200 && zet_x >= enemy_x11 && zet_x <= enemy_x11 + 180)
	{
		enemy_y11 = 800;

	}
	else if (zet_y >= enemy_y21 && zet_y <= enemy_y21 + 200 && zet_x >= enemy_x21 && zet_x <= enemy_x21 + 180)
	{
		enemy_y21 = 900;

	}
	else if (zet_y >= enemy_y31 && zet_y <= enemy_y31 + 200 && zet_x >= enemy_x31 && zet_x <= enemy_x31 + 180)
	{
		enemy_y31 = 1060;

	}
	else if (zet_y >= enemy_y41 && zet_y <= enemy_y41 + 200 && zet_x >= enemy_x41 && zet_x <= enemy_x41 + 180)
	{
		enemy_y41 = 1000;

	}
	else if (zet_y >= enemy_y51 && zet_y <= enemy_y51 + 200 && zet_x <= enemy_x51 + 400)
	{
		enemy_y51 = 850;
	}
}


void enemy_cordinate_change1()
{
	if (enemy_y0 >= 0)
	{
		enemy_y0 -= 10;
		if (enemy_y0 < 0)
		{
			count1 += 1;
			enemy_y0 = 550;

		}
	}
	if (enemy_y11 >= 0)
	{
		enemy_y11 -= 7;
		if (enemy_y11 < 0)
		{
			count1 += 1;
			enemy_y11 = 550;

		}
	}
	if (enemy_y21 >= 0)
	{
		enemy_y21 -= 7;
		if (enemy_y21 < 0)
		{
			count1 += 1;
			enemy_y21 = 550;

		}
	}
	if (enemy_y31 >= 0)
	{
		enemy_y31 -= 8;
		if (enemy_y31 < 0)
		{
			count1 += 1;
			enemy_y31 = 550;

		}
	}
	if (enemy_y41 >= 0)
	{
		enemy_y41 -= 9;
		if (enemy_y41 < 0)
		{
			count1 += 1;
			enemy_y41 = 550;

		}
	}
	if (enemy_y51 >= 0)
	{
		enemy_y51 -= 11;
		if (enemy_y51 < 0)
		{
			count1 += 1;
			enemy_y51 = 550;

		}
	}
	else
	{

	}
}





void collision_check1()
{
	if (bullet_cy >= enemy_y0 && bullet_cy <= enemy_y0 + 86 && bullet_cx >= enemy_x0 && bullet_cx <= enemy_x0 + 100)
	{
		enemy_y0 = 1000;
		bullet_cy = 650;
		score = score + 10;
		sprintf(converted_score, "%d", score);
	}
	else if (bullet_cy >= enemy_y11 && bullet_cy <= enemy_y11 + 86 && bullet_cx >= enemy_x11 && bullet_cx <= enemy_x11 + 100)
	{
		enemy_y11 = 800;
		bullet_cy = 650;
		score = score + 10;
		sprintf(converted_score, "%d", score);
	}
	else if (bullet_cy >= enemy_y21 && bullet_cy <= enemy_y21 + 86 && bullet_cx >= enemy_x21 && bullet_cx <= enemy_x21 + 100)
	{
		enemy_y21 = 900;
		bullet_cy = 650;
		score = score + 10;
		sprintf(converted_score, "%d", score);
	}
	else if (bullet_cy >= enemy_y31 && bullet_cy <= enemy_y31 + 86 && bullet_cx >= enemy_x31 && bullet_cx <= enemy_x31 + 100)
	{
		enemy_y31 = 1060;
		bullet_cy = 650;
		score = score + 10;
		sprintf(converted_score, "%d", score);
	}
	else if (bullet_cy >= enemy_y41 && bullet_cy <= enemy_y41 + 86 && bullet_cx >= enemy_x41 && bullet_cx <= enemy_x41 + 100)
	{
		enemy_y41 = 1000;
		bullet_cy = 650;
		score = score + 10;
		sprintf(converted_score, "%d", score);
	}
	else if (bullet_cy >= enemy_y51 && bullet_cy <= enemy_y51 + 86 && bullet_cx >= enemy_x51 && bullet_cx <= enemy_x51 + 100)
	{
		enemy_y51 = 850;
		bullet_cy = 650;
		score = score + 10;
		sprintf(converted_score, "%d", score);
	}
}
void bullet_move1()
{
	if (bullet_cy <= 600)
	{
		bullet_cy += 20;
	}
	if (bullet_cy > 600)
	{
		bullet_cy = 135;
		bullet_cx = bullet_x;
	}
	collision_check1();
}


void Play2()
{
	//Present Start
	iShowBMP(0, 0, bC); //Game background show
	iShowBMP2(zet_x, zet_y, spaceZet2, 0); //spacecraft show
	iShowBMP2(bullet_x, bullet_y, bullet, 0);
	iShowBMP2(bullet_cx, bullet_cy, bullet, 0);
	iShowBMP2(enemy_x0, enemy_y0, enemy, 0);
	iShowBMP2(enemy_x11, enemy_y11, enemy, 0);
	iShowBMP2(enemy_x21, enemy_y21, enemy, 0);
	iShowBMP2(enemy_x31, enemy_y31, enemy, 0);
	iShowBMP2(enemy_x41, enemy_y41, enemy, 0);
	iShowBMP2(enemy_x51, enemy_y51, enemy, 0);
	iSetColor(255, 255, 255);
	iFilledRectangle(945, 545, 150, 30);
	iFilledRectangle(10, 545, 100, 30);
	iSetColor(0, 0, 0);
	iText(20, 550, "Level 2", GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(0, 0, 0);
	iText(950, 550, "SCORE:", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1040, 550, converted_score, GLUT_BITMAP_TIMES_ROMAN_24);
	t4=iSetTimer(500, enemy_cordinate_change1);
	t5=iSetTimer(10, bullet_move1);
	Gameover1();
	clash1();
}