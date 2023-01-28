#include "iGraphics.h"
#include "Level1.h"
#include "Level2.h"
#define screenWidth 1100
#define screenHeight 600

char HighScore[25] = "image\\Highscorefinal.bmp";
char NameInput[25] = "image\\Nameinput.bmp";

//char userNameInput[100];
int userNameInputIndex;
bool name = false;
bool t = false;


int t1;
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
void pause();
void resume();
void iDraw()
{
	iClear();
	iPauseTimer(t2);
	iPauseTimer(t3);
	if (gameState == -2)
	{
		//Homepage loading
		iShowBMP(0, 0, homeMenu);
		//Rectangle draw for loading animation 
		iSetColor(0, 0, 0);
		iText(480, 60, "LOADING....", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255, 255, 255);
		iRectangle(380, 20, 300, 30);
		iFilledRectangle(380, 20, rec_x, rec_y);
	}
	else if (gameState == -1)
	{
		//Present Menubar
		iShowBMP(0, 0, menubar);
		for (int i = 0; i < 5; i++)
		{
			iShowBMP(bCordinate[i].x, bCordinate[i].y, button[i]);
		}

	}

	else if (gameState == 0)//start
	{
		if (name)
		{
			temp = false;
			Play1();

		}
		//Else block use for nameinput
		else
		{
			iShowBMP(0, 0, NameInput);
			iSetColor(255, 255, 0);
			iFilledRectangle(410, 340, 280, 40);
			iSetColor(0, 0, 0);
			iText(425, 350, "Please Enter Your Name", GLUT_BITMAP_TIMES_ROMAN_24);
			iRectangle(402, 300, 300, 30);
			iText(500, 307, userNameInput, GLUT_BITMAP_TIMES_ROMAN_24);
		}
	}

	else if (gameState == 1)
	{
		iShowBMP(0, 0, HighScore);
		HighScoreShow();
	}

	else if (gameState == 2)
	{
		iShowBMP(0, 0, control);
	}

	else if (gameState == 3)
	{
		iShowBMP(0, 0, about);
	}

	else if (gameState == 4)
	{
		iShowBMP2(0, 0, credit, 255);
	}

	else if (gameState == 5)
	{  
		//game over show
		iShowBMP(0, 0, gmover);
	}
	else if (gameState == 6)
	{
		//level complt congratulations
		iShowBMP(0, 0, congo);
	}
	else if (gameState == 7)
	{
		if (temp)
		{
			Play2();
		}
		//new level	
		//Play2();
	}
	
	else
	{

	}
}


/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{

}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouse(int mx, int my)
{
	printf("%d x %d\n", mx, my);
}

void iMouse(int button, int state, int mx, int my)
{
	if (gameState == -1)
	{

		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			for (int i = 0; i < 5; i++)
			{
				if (mx >= bCordinate[i].x && mx <= bCordinate[i].x + 200 && my >= bCordinate[i].y && my <= bCordinate[i].y + 60)
				{
					gameState = i;
					count = 0;
				}
			}

		}
	}

	
		if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		{
			
		}
	
}


/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == 'm')
	{
		PlaySound("Music\\music1.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	if (key == 'o')
	{
		PlaySound(0,0,0);
	}
	if (key == 'p')
	{
		isPause = true;
		isResume = false;
	}
	if (key == 'r')
	{
		isPause = false;
		isResume = true;
	}
	if (key == 'a')
	{
		//isPause1 = true;
		//isResume1 = false;
	}
	if (key == 'b')
	{
		//isPause1 = false;
		//isResume1 = true;
	}

	if ((key >= 'a' && key <= 'z') || (key >= 'A' && key <= 'Z'))
	{

		userNameInput[userNameInputIndex++] = key;

	}
	if (key == '\b')
	{
		userNameInputIndex--;

		if (userNameInputIndex < 0) // used to prevent array out of index error
		{
			userNameInputIndex = 0;
		}

		userNameInput[userNameInputIndex] = '\0'; //erases the previous character
	}
	if (key == '\r')
	{
		gameState = 0;
		name = true;
	}
}


/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{


	if (key == GLUT_KEY_END)
	{
		exit(0);
	}

	if (key == GLUT_KEY_LEFT)
	{
		zet_x -= 10;
		bullet_x -= 10;
	}
	if (key == GLUT_KEY_RIGHT)
	{
		zet_x += 10;
		bullet_x += 10;
	}

	if (key == GLUT_KEY_HOME)
	{
		gameState = -1;
	}
	
	if (gameState==6)
	{
		if (key == GLUT_KEY_F1)
		{
			gameState = 7;
		}
	}
}



int main()
{
	t1=iSetTimer(20, loading);
	t2=iSetTimer(250, enemy_cordinate_change);
	t3=iSetTimer(1, bullet_move);
	int sum = 100;
	for (int i = 4; i >= 0; i--)
	{
		bCordinate[i].x = 425;
		bCordinate[i].y = sum;
		sum += 80;
	}
	iInitialize(screenWidth, screenHeight, "Battle Of Unicron");
	iStart();
	return 0;
}