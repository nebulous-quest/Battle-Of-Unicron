#define LEVEL1_H_INCLUDED
#include<stdio.h>
using namespace std;

struct button
{
	int x;
	int y;
}bCordinate[7];

char button[20][25] = { "image\\Start.bmp", "image\\High.bmp", "image\\Control.bmp", "image\\About.bmp", "image\\Credit.bmp" }; //For menu button
char homeMenu[25] = "image\\Home.bmp"; //For Home page
char menubar[25] = "image\\Menu.bmp";
char about[21] = "image\\Menu_about.bmp";
char level[25] = "image\\Menu_level.bmp";
char control[25] = "image\\Controlsfinal.bmp";
char credit[25] = "image\\Menu_credits.bmp";
char bC[25] = "image\\GameBc.bmp"; //For game Background
char spaceZet[25] = "image\\SpaceCraft.bmp"; //For spacecraft
char enemy[25] = "image\\Enemy.bmp"; //For Enemy
char bullet[25] = "image\\Bullet.bmp"; //For BUllet
char congo[30] = "image\\Congratulations.bmp";
char gmover[25] = "image\\GameOver.bmp";
int count = 0;
int gameState = -2;
int t2, t3;
//For score part
char converted_score[20];
int score = 0;
//For score part

//Spacecraft co-ordinate
int zet_x = 550;
int zet_y = 10;
//Spacecraft co-ordinate

//Bullet co-ordinate
int bullet_x = 607;
int bullet_y = 125;
int bullet_cx = 607;
int bullet_cy = 125;
//Bullet co-ordinate


//Enemy co-ordinate
int enemy_x = 100;
int enemy_x1 = 250;
int enemy_x2 = 400;
int enemy_x3 = 600;
int enemy_x4 = 800;
int enemy_x5 = 1000;

int enemy_y = 567;
int enemy_y1 = 563;
int enemy_y2 = 569;
int enemy_y3 = 567;
int enemy_y4 = 565;
int enemy_y5 = 555;
//Enemy co-ordinate
int rec_x = 20;
int rec_y = 30;

bool isResume = true;
bool isPause = false;
int highScore = 0;
char userNameInput[100];


void HighScoreShow(){
	FILE *fp = fopen("hellow.txt", "r");
	fscanf(fp, "%d", &highScore);

	sprintf(converted_score, "%d", highScore);
	iSetColor(0, 0, 0);
	iText(500, 330, converted_score, GLUT_BITMAP_TIMES_ROMAN_24);

	iText(400, 330, userNameInput, GLUT_BITMAP_TIMES_ROMAN_24);
	fclose(fp);
}


//function for calculating highscore
void HighScoreCalculate(){
	int FinalScore = score;
	FILE *fp = fopen("hellow.txt", "r");
	fscanf(fp, "%d", &highScore);
	if (highScore < FinalScore){
		highScore = FinalScore;
		FILE *fp = fopen("hellow.txt", "a");
		fprintf(fp, "%s  ", userNameInput);
		fprintf(fp, "%d\n", highScore);

		fclose(fp);
	}
	fclose(fp);
}

//Function for loading index change
void loading()
{
	if (rec_x < 300)
	{
		rec_x += 10;
		if (rec_x >= 300)
		{
			gameState = -1;
		}
	}
}

//Function for enemy movement
void enemy_cordinate_change()
{
	if (enemy_y >= 0)
	{
		enemy_y -= 8;
		if (enemy_y < 0)
		{   
			count += 1;
			enemy_y = 550;
			
		}
	}
	if (enemy_y1 >= 0)
	{
		enemy_y1 -= 6;
		if (enemy_y1 < 0)
		{
			count += 1;
			enemy_y1 = 550;
			
		}
	}
	if (enemy_y2 >= 0)
	{
		enemy_y2 -= 8;
		if (enemy_y2 < 0)
		{
			count += 1;
			enemy_y2 = 550;
			
		}
	}
	if (enemy_y3 >= 0)
	{
		enemy_y3 -= 5;
		if (enemy_y3 < 0)
		{
			count += 1;
			enemy_y3 = 550;
			
		}
	}
	if (enemy_y4 >= 0)
	{
		enemy_y4 -= 7;
		if (enemy_y4 < 0)
		{
			count += 1;
			enemy_y4 = 550;
			
		}
	}
	if (enemy_y5 >= 0)
	{
		enemy_y5 -= 5;
		if (enemy_y5 < 0)
		{
			count += 1;
			enemy_y5 = 550;
			
		}
	}
	else
	{

	}
}
//gameover
void Gameover(){

	if (count == 3)
	{
		gameState = 5;
		HighScoreCalculate();
		score = 0;
	}

}
// game over 

bool temp;
//level cheack
void level2()
{
	if (score == 100){

		gameState = 6;
		temp = true;
	}
}
//level cheack

void clash()
{
	if (zet_y >= enemy_y && zet_y <= enemy_y + 130 && zet_x >= enemy_x && zet_x <= enemy_x + 180)
	{
		enemy_y = 1000;
		
	}
	else if (zet_y >= enemy_y1 && zet_y <= enemy_y1 + 130 && zet_x >= enemy_x1 && zet_x <= enemy_x1 + 180)
	{
		enemy_y1 = 800;
		
	}
	else if (zet_y >= enemy_y2 && zet_y <= enemy_y2 + 130 && zet_x >= enemy_x2 && zet_x <= enemy_x2 + 180)
	{
		enemy_y2 = 900;
		
	}
	else if (zet_y >= enemy_y3 && zet_y <= enemy_y3 + 130 && zet_x >= enemy_x3 && zet_x <= enemy_x3 + 180)
	{
		enemy_y3 = 1060;
		
	}
	else if (zet_y >= enemy_y4 && zet_y <= enemy_y4 + 130 && zet_x >= enemy_x4 && zet_x <= enemy_x4 + 180)
	{
		enemy_y4 = 1000;
		
	}
	else if (zet_y >= enemy_y5 && zet_y <= enemy_y5 + 130  && zet_x <=enemy_x5+400)
	{
		enemy_y5 = 850;
	}
}

//Function for Enemy & Bullet collision
void collision_check()
{
	if (bullet_cy >= enemy_y && bullet_cy <= enemy_y + 86 && bullet_cx >= enemy_x && bullet_cx <= enemy_x + 100)
	{
		enemy_y = 1000;
		bullet_cy = 650;
		score = score + 10;
		sprintf(converted_score, "%d", score);
		level2();
	}
	else if (bullet_cy >= enemy_y1 && bullet_cy <= enemy_y1 + 86 && bullet_cx >= enemy_x1 && bullet_cx <= enemy_x1 + 100)
	{
		enemy_y1 = 800;
		bullet_cy = 650;
		score = score + 10;
		sprintf(converted_score, "%d", score);
		level2();
	}
	else if (bullet_cy >= enemy_y2 && bullet_cy <= enemy_y2 + 86 && bullet_cx >= enemy_x2 && bullet_cx <= enemy_x2 + 100)
	{
		enemy_y2 = 900;
		bullet_cy = 650;
		score = score + 10;
		sprintf(converted_score, "%d", score);
		level2();
	}
	else if (bullet_cy >= enemy_y3 && bullet_cy <= enemy_y3 + 86 && bullet_cx >= enemy_x3 && bullet_cx <= enemy_x3 + 100)
	{
		enemy_y3 = 1060;
		bullet_cy = 650;
		score = score + 10;
		sprintf(converted_score, "%d", score);
		level2();
	}
	else if (bullet_cy >= enemy_y4 && bullet_cy <= enemy_y4 + 86 && bullet_cx >= enemy_x4 && bullet_cx <= enemy_x4 + 100)
	{
		enemy_y4 = 1000;
		bullet_cy = 650;
		score = score + 10;
		sprintf(converted_score, "%d", score);
		level2();
	}
	else if (bullet_cy >= enemy_y5 && bullet_cy <= enemy_y5 + 86 && bullet_cx >= enemy_x5 && bullet_cx <= enemy_x5 + 100)
	{
		enemy_y5 = 850;
		bullet_cy = 650;
		score = score + 10;
		sprintf(converted_score, "%d", score);
		level2();
	}
}
//Function for Enemy & Bullet collision


//Function for bullet move
void bullet_move()
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
	collision_check();
}
//Function for bullet move


void Play1()
{
	if (isResume)
	{
		iResumeTimer(t2);
		iResumeTimer(t3);
	}
	if (isPause)
	{
		iPauseTimer(t2);
		iPauseTimer(t3);
	}
	
	//Present Start
	iShowBMP(0, 0, bC); //Game background show
	iShowBMP2(zet_x, zet_y, spaceZet, 255); //spacecraft show
	iShowBMP2(bullet_x, bullet_y, bullet, 0);
	iShowBMP2(bullet_cx, bullet_cy, bullet, 0);
	iShowBMP2(enemy_x, enemy_y, enemy, 0);
	iShowBMP2(enemy_x1, enemy_y1, enemy, 0);
	iShowBMP2(enemy_x2, enemy_y2, enemy, 0);
	iShowBMP2(enemy_x3, enemy_y3, enemy, 0);
	iShowBMP2(enemy_x4, enemy_y4, enemy, 0);
	iShowBMP2(enemy_x5, enemy_y5, enemy, 0);
	iSetColor(255, 255, 255);
	iFilledRectangle(945, 545, 150, 30);
	iFilledRectangle(10, 545, 100, 30);
	iSetColor(0, 0, 0);
	iText(20, 550, "Level 1", GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(0, 0, 0);
	iText(950, 550, "SCORE:", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1040, 550, converted_score, GLUT_BITMAP_TIMES_ROMAN_24);
	Gameover();
	clash();
}