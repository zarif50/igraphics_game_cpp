# include <iostream>
using namespace std;
# include "iGraphics.h"
//# include "level2.h"

#define upperbackgroundspeed 10
#define lowerbackgroundspeed 12
#define screenwidth 1200
#define screenheight 800
#define enemynumber 4
#define gcoinsNumber 2

/*
function iDraw() is called again and again by the system.

*/
void pointdisplay();
int image;
int lf[5];
int coinber[10];
int life = 10;
int lifecount = 0;
int coincount = 0;
int coin = 11;
bool over = false;
bool collided = false;
bool musicOn = true;
bool gameover = false;
bool landingPage = true, mainMenu = false, arena = false, storyLine = false, controls = false,highscore=false;
bool play = false, control = false, story = false, level1 = true, level2 = false, level3=false,level5=false,level4=false,hignscoreshow=false;
void displayLandingPage();
void displayMainMenu();
void displayhighscore();
void mainMenuOptionChooseWithMouse(int mx, int my);
void mainMenuOptionChooseWithPassiveMouse(int mx, int my);
void displayStoryLine();
void displayControls();
void displayArena();
int gamestate = 0;
//char enemytwo[3][20] = { "enemy1\\1.bmp", "enemy1\\2.bmp", "enemy1\\3.bmp" };
//enemy variable
char enemyone[3][20] = { "enemy\\1.bmp", "enemy\\2.bmp", "enemy\\3.bmp" };
char enemytwo[3][20] = { "enemy1\\1.bmp", "enemy1\\2.bmp", "enemy1\\3.bmp" };
char enemythree[3][20] = { "enemy2\\1.bmp", "enemy2\\2.bmp", "enemy2\\3.bmp" };
char enemyfour[3][20] = { "enemy3\\1.bmp", "enemy3\\2.bmp", "enemy3\\3.bmp" };
char enemyfive[4][20] = { "enemy4\\1.bmp", "enemy4\\2.bmp", "enemy4\\4.bmp","enemy4\\9.bmp" };
int planeX = 100, planeY = 350;
char goldCoin[10][20] = { "goldcoin\\1.bmp", "goldcoin\\2.bmp", "goldcoin\\3.bmp", "goldcoin\\4.bmp", "goldcoin\\5.bmp", "goldcoin\\6.bmp", "goldcoin\\7.bmp", "goldcoin\\8.bmp", "goldcoin\\9.bmp", "goldcoin\\10.bmp" };
struct habijabi{
	int plane_x;
	int plane_y;
	int planeIndex;
	bool planeShow;
};

habijabi enemy[enemynumber];

struct goldcoins
{
	int goldcoin_x;
	int goldcoin_y;
	int goldcoinIndex;
	bool goldcoinShow;
};
struct goldcoins gold[3];

void gsetcoinsVariables()
{
	for (int i = 0; i < gcoinsNumber; i++)
	{
		gold[i].goldcoin_x = rand() % 1428;
		gold[i].goldcoin_y = rand() % 300;
		gold[i].goldcoinIndex = rand() % 10;
		gold[i].goldcoinShow = true;
	}
}
//enemy movement
void enemymovement()
{
	if (level1 == true && level2 == false){
		for (int i = 0; i < enemynumber; i++)
		{
			if (enemy[i].planeShow)
			{
				iShowBMP2(enemy[i].plane_x, enemy[i].plane_y, enemyone[enemy[i].planeIndex], 0);
			}
		}
	}
	else if (level2 == true){
		for (int i = 0; i < enemynumber; i++)
		{
			if (enemy[i].planeShow)
			{
				iShowBMP2(enemy[i].plane_x, enemy[i].plane_y, enemytwo[enemy[i].planeIndex], 0);
			}
		}
	}
	else if (level3 == true){
		for (int i = 0; i < enemynumber; i++)
		{
			if (enemy[i].planeShow)
			{
				iShowBMP2(enemy[i].plane_x, enemy[i].plane_y, enemythree[enemy[i].planeIndex], 0);
			}
		}
	}
	else if (level4 == true){
		for (int i = 0; i < enemynumber; i++)
		{
			if (enemy[i].planeShow)
			{
				iShowBMP2(enemy[i].plane_x, enemy[i].plane_y, enemyfour[enemy[i].planeIndex], 0);
			}
		}
	}
	else if (level5 == true){
		for (int i = 0; i < enemynumber; i++)
		{
			if (enemy[i].planeShow)
			{
				iShowBMP2(enemy[i].plane_x, enemy[i].plane_y, enemyfive[enemy[i].planeIndex], 0);
			}
		}
	}



}
bool checkCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) {
	// Check if the rectangles are overlapping
	if (x1 + w1 >= x2 && x1 <= x2 + w2 && y1 + h1 >= y2 && y1 <= y2 + h2) {
		return true; // Collision detected
	}
	return false; // No collision
}



void change()
{

	for (int i = 0; i<enemynumber; i++)
	{
		enemy[i].plane_x -= 10;
		if (enemy[i].plane_x <= 0)
		{
			enemy[i].plane_x = 1428 + 5;
			enemy[i].plane_y = rand() % (770 - 150);
		}
		enemy[i].planeIndex++;
		if (enemy[i].planeIndex >= 3)
		{
			enemy[i].planeIndex = 0;
		}
	}

	for (int i = 0; i < gcoinsNumber; i++)
	{
		gold[i].goldcoin_x -= 15;

		if (gold[i].goldcoin_x <= 0)
		{
			gold[i].goldcoin_x = 1428 + 5;
			gold[i].goldcoin_y = rand() % (770 - 160);
		}
		gold[i].goldcoinIndex++;

		if (gold[i].goldcoinIndex >= 10)
		{
			gold[i].goldcoinIndex = 0;
		}
	}
	for (int i = 0; i < enemynumber; i++) {
		if (enemy[i].planeShow && checkCollision(planeX, planeY, 200, 80, enemy[i].plane_x, enemy[i].plane_y, 400, 150)) {
			// Collision detected between player plane and enemy[i]
			collided = true;
			life--; // Decrease player's health/life
			enemy[i].planeShow = false; // Hide the collided enemy
			if (!enemy[i].planeShow){
				enemy[i].plane_x = screenwidth + rand() % 500;
				enemy[i].plane_y = rand() % (770 - 150);
				enemy[i].planeShow = true;
			}
		}
	}
	for (int i = 0; i < gcoinsNumber; i++) {
		if (gold[i].goldcoinShow && checkCollision(planeX, planeY, 200, 80, gold[i].goldcoin_x, gold[i].goldcoin_y, 300, 300)) {
			// Collision detected between player plane and gold[i]
			coincount++; // Increase the coin count
			cout << coincount << endl;
			if (coincount <= 5)
			{
				coin = 11;

			}

			if (coincount <= 10 && coincount>5)
			{
				coin = 10;
				//play = false;
				
			}

			if (coincount <=15 && coincount>10)
			{
				coin = 9;
				level1 = false;
				level2 = true;
			}

			if (coincount <= 20 && coincount>15)
			{
				coin = 8;
				
			}

			if (coincount <= 25  && coincount>20)
			{
				coin = 7;
				level2 = false;
				level3 = true;
			}

			if (coincount <= 30 && coincount>25)
			{
				coin = 6;

			}

			if (coincount <= 35 && coincount>30)
			{
				coin = 5;
			}

			if (coincount <= 40 && coincount>35)
			{
				coin = 4;
				level3 = false;
				level4 = true;
			}

			if (coincount <= 45 && coincount>40)
			{
				coin = 3;
			}

			if (coincount <= 60 && coincount>45)
			{
				coin = 2;
				level4 = false;
				level5 = true;

			}

			if (coincount <= 70 && coincount>60)
			{
				coin = 1;
				gameover=true;
			}
			//pointdisplay();
			gold[i].goldcoinShow = false; // Hide the collected gold coin

			// Respawn the gold coin at a new position
			if (!gold[i].goldcoinShow){
				gold[i].goldcoin_x = rand() % 1428;
				gold[i].goldcoin_y = rand() % 300;
				gold[i].goldcoinShow = true;
			}
		}
	}
}
void setEnemyVariable()
{
	for (int i = 0; i<enemynumber; i++)
	{

		enemy[i].plane_x = screenwidth + rand() % 500;
		enemy[i].plane_y = screenwidth + rand() % 500;
		enemy[i].planeIndex = +rand() % 10;
		enemy[i].planeShow = true;
	}
}


void gcoinsMovement()
{
	for (int i = 0; i < gcoinsNumber; i++)
	{
		if (gold[i].goldcoinShow)
		{
			iShowBMP2(gold[i].goldcoin_x, gold[i].goldcoin_y, goldCoin[gold[i].goldcoinIndex], 0);
		}
	}
}




int backgroundImage[4];//level 1
int backgroundImage2[4];//level 2
int backgroundImage3[4];//level 3
int backgroundImage4[4];//level 4
int backgroundImage5[4];//level 5
struct backgroundCoordinate{
	int x;
	int y;
};
backgroundCoordinate bg[4];
int plane;


//int planeex=1100,planeey=350;

void healthdisplay()
{
	if (life == 10)
	{
		iShowImage(0, 640, 230, 70, lf[0]);
	}


	if (life == 9)
	{
		iShowImage(0, 640, 230, 70, lf[0]);
	}

	if (life == 8)
	{
		iShowImage(0, 640, 230, 70, lf[1]);
	}

	if (life == 7)
	{
		iShowImage(0, 640, 230, 70, lf[1]);
	}

	if (life == 6)
	{
		iShowImage(0, 640, 230, 70, lf[2]);
	}

	if (life == 5)
	{
		iShowImage(0, 640, 230, 70, lf[2]);
	}

	if (life == 4)
	{
		iShowImage(0, 640, 230, 70, lf[3]);
	}

	if (life == 3)
	{
		iShowImage(0, 640, 230, 70, lf[3]);
	}

	if (life == 2)
	{
		iShowImage(0, 640, 230, 70, lf[4]);
	}

	if (life == 1)
	{
		iShowImage(0, 640, 230, 70, lf[4]);
	}
}
void pointdisplay()
{



	if (coin == 11)
	{
		iShowImage(950, 650, 300, 60, coinber[0]);
	}

	if (coin == 10)
	{
		iShowImage(950, 650, 300, 60, coinber[1]);
	}

	if (coin == 9)
	{
		iShowImage(950, 650, 300, 60, coinber[2]);
	}

	if (coin == 8)
	{
		iShowImage(950, 650, 300, 60, coinber[3]);
	}

	if (coin == 7)
	{
		iShowImage(950, 650, 300, 60, coinber[4]);
	}

	if (coin == 6)
	{
		iShowImage(950, 650, 300, 60, coinber[5]);
	}

	if (coin == 5)
	{
		iShowImage(950, 650, 300, 60, coinber[6]);
	}

	if (coin == 4)
	{
		iShowImage(950, 650, 300, 60, coinber[7]);
	}

	if (coin == 3)
	{
		iShowImage(950, 650, 300, 60, coinber[8]);
	}

	if (life == 2)
	{
		iShowImage(950, 650, 300, 60, coinber[9]);
	}

	if (coin == 1)
	{
		iShowImage(950, 650, 300, 60, coinber[10]);
	}
}


void iDraw()
{
	//place your drawing codes here
	iClear();
	//iClear();


	if (gameover)
	{
		iShowBMP(0, 0, "images//levelup.bmp");
	}
	else{




		if (landingPage) displayLandingPage();
		if (mainMenu) displayMainMenu();
		if (storyLine) displayStoryLine();
		if (arena) displayArena();
		if (controls) displayControls();
		if (highscore)displayhighscore();
		if (play){
			if (level1 == true){
				for (int i = 0; i < 4; i++){
					iShowImage(bg[i].x, bg[i].y, 600, 800, backgroundImage[i]);
				}
			}
			if (level2 == true){
					for (int i = 0; i < 4; i++){
						iShowImage(bg[i].x, bg[i].y, 600, 800, backgroundImage2[i]);
				}
			}

			if (level3 == true){
				for (int i = 0; i < 4; i++){
					iShowImage(bg[i].x, bg[i].y, 600, 800, backgroundImage3[i]);
				}
			}

			if (level4 == true){
				for (int i = 0; i < 4; i++){
					iShowImage(bg[i].x, bg[i].y, 600, 800, backgroundImage4[i]);
				}
			}
			if (level5 == true){
				for (int i = 0; i < 4; i++){
					iShowImage(bg[i].x, bg[i].y, 600, 800, backgroundImage5[i]);
				}
			}


			iShowImage(planeX, planeY, 200, 80, plane);

			//iShowImage(planeex,planeey,300,300,enemy[0]);
			enemymovement();
			gcoinsMovement();
			healthdisplay();
			pointdisplay();

		}
		else if (level2){
			enemymovement();
			gcoinsMovement();
			healthdisplay();
			pointdisplay();
		}
	}

}

void iPassiveMouse(int mx, int my)
{
	if (mainMenu)
	{
		mainMenuOptionChooseWithPassiveMouse(mx, my);
	}
}


/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{

	//place your codes here
}

/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		if (mainMenu)
		{
			mainMenuOptionChooseWithMouse(mx, my);
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
	if (key == 'o')
	{
		if (landingPage)
		{
			landingPage = false;
			mainMenu = true;
		}
	}
	if (key == 'x')
	{
		if (mainMenu)
		{
			exit(0);
		}
	}
	if (key == 27)
	{
		mainMenu = true;
		controls = false;
		storyLine = false;
		highscore = false;
		play = false;
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
	if (key == GLUT_KEY_RIGHT)
	{
		if (planeX <= 1100)
			planeX += 10;
	}
	if (key == GLUT_KEY_LEFT)
	{
		if (planeX >= 0)
			planeX -= 10;
	}
	if (key == GLUT_KEY_UP)
	{
		if (planeY <= 650)
			planeY += 10;
	}
	if (key == GLUT_KEY_DOWN)
	{
		if (planeY >= 0)
			planeY -= 10;
	}
	//place your codes for other keys here
}
void displayLandingPage()
{
	iClear();
	iShowBMP(0, 0, "pic\\landingpage.bmp");
	iSetColor(255, 255, 255);

}
void displayMainMenu()
{
	iClear();
	iShowBMP(0, 0, "pic\\menu.bmp");
	iShowBMP(150, 600, "pic\\play.bmp");
	iShowBMP(150, 540, "pic\\story.bmp");
	iShowBMP(150, 480, "pic\\controls.bmp");
	iShowBMP(150, 420, "pic\\highscore.bmp");
	iSetColor(255, 255, 255);


	//display rectangle around the option while hovering

	iSetColor(0, 0, 0);
	if (play) iRectangle(150, 600, 150, 50);
	if (story) iRectangle(150, 540, 150, 50);
	if (control) iRectangle(150, 480, 150, 50);
	if (hignscoreshow)iRectangle(150, 420, 150, 50);
}
void mainMenuOptionChooseWithMouse(int mx, int my)
{
	if (mx >= 150 && mx <= 300 && my >= 600 && my <= 650)
	{
		play = true;
		story = false;
		control = false;
		mainMenu = false;
		hignscoreshow = false;

	}
	if (mx >= 150 && mx <= 300 && my >= 540 && my <= 590)
	{
		storyLine = true;
		mainMenu = false;
	}
	if (mx >= 150 && mx <= 300 && my >= 480 && my <= 530)
	{
		controls = true;
		mainMenu = false;
	}
	if (mx >= 150 && mx <= 300 && my >= 420 && my <= 530)
	{
		highscore = true;
		mainMenu = false;
	}


}
void mainMenuOptionChooseWithPassiveMouse(int mx, int my)
{

	if (mx >= 150 && mx <= 300 && my >= 540 && my <= 590)
	{
		play = false;
		story = true;
		control = false;
		hignscoreshow = false;
	}
	else if (mx >= 150 && mx <= 300 && my >= 480 && my <= 530)
	{
		play = false;
		story = false;
		control = true;
		hignscoreshow = false;
	}
	else if (mx >= 150 && mx <= 300 && my >= 420 && my <= 530)
	{
		play = false;
		story = false;
		control = false;
		hignscoreshow = true;
	}
	else
	{
		play = false;
		story = false;
		control = false;
		hignscoreshow = false;
	}
}

void displayhighscore()
{
	iClear();
	iShowBMP(0, 0, "pic\\highscoreshow.bmp");

}
void displayStoryLine()
{
	iClear();
	iShowBMP(0, 0, "pic\\storyline.bmp");
}

void displayControls()
{
	iClear();
	iShowBMP(0, 0, "pic\\control.bmp");
}

void displayArena()
{
	iClear();
	iShowBMP(0, 0, "pic\\arena.bmp");
	iShowBMP(256, 600, "pic\\life.bmp");
	iShowBMP(896, 600, "pic\\life.bmp");
	iRectangle(256, 600, 128, 50);
	iRectangle(896, 600, 128, 50);
	iSetColor(255, 128, 192);
	iText(280, 660, "Health", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(918, 660, "Health", GLUT_BITMAP_TIMES_ROMAN_24);
}
void setAll(){
	int sum = -100;
	for (int i = 0; i<4; i++){
		bg[i].y = 0;
		bg[i].x = sum;
		sum += 600;
	}
}
void bGround(){
	for (int i = 0; i<4; i++){
		bg[i].x -= 10;
		if (bg[i].x <= -700)
			bg[i].x = 1700;
	}
}

int main()
{
	if (musicOn)
	{
		PlaySound("music\\music.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	setEnemyVariable();
	gsetcoinsVariables();
	iSetTimer(20, change);
	//place your own initialization codes here.
	setAll();
	//iSetTimer(1000,planechangeindex);
	iSetTimer(25, bGround);
	iInitialize(1280, 720, "operation skywolf");
	///updated see the documentations

	plane = iLoadImage("images//Plane.png");
	lf[0] = iLoadImage("icons\\health_bar010.png");
	lf[1] = iLoadImage("icons\\health_bar007.png");
	lf[2] = iLoadImage("icons\\health_bar005.png");
	lf[3] = iLoadImage("icons\\health_bar003.png");
	lf[4] = iLoadImage("icons\\health_bar001.png");
	lf[4] = iLoadImage("icons\\health_bar000.png");
	coinber[0] = iLoadImage("points\\point1.png");
	coinber[1] = iLoadImage("points\\point2.png");
	coinber[2] = iLoadImage("points\\point3.png");
	coinber[3] = iLoadImage("points\\point4.png");
	coinber[4] = iLoadImage("points\\point5.png");
	coinber[5] = iLoadImage("points\\point6.png");
	coinber[6] = iLoadImage("points\\point7.png");
	coinber[7] = iLoadImage("points\\point8.png");
	coinber[8] = iLoadImage("points\\point9.png");
	coinber[9] = iLoadImage("points\\point10.png");


	//level 1
	backgroundImage[0] = iLoadImage("images//background 1.png");
	backgroundImage[1] = iLoadImage("images//background 2.png");
	backgroundImage[2] = iLoadImage("images//background 3.png");
	backgroundImage[3] = iLoadImage("images//background 4.png");
	//level 2
	backgroundImage2[0] = iLoadImage("backgound//1.png");
	backgroundImage2[1] = iLoadImage("backgound//2.png");
	backgroundImage2[2] = iLoadImage("backgound//3.png");
	backgroundImage2[3] = iLoadImage("backgound//4.png");
	//level 3
	backgroundImage3[0] = iLoadImage("backgound//5.png");
	backgroundImage3[1] = iLoadImage("backgound//6.png");
	backgroundImage3[2] = iLoadImage("backgound//7.png");
	backgroundImage3[3] = iLoadImage("backgound//8.png");

	//level4
	backgroundImage4[0] = iLoadImage("backgound//9.png");
	backgroundImage4[1] = iLoadImage("backgound//10.png");
	backgroundImage4[2] = iLoadImage("backgound//11.png");
	backgroundImage4[3] = iLoadImage("backgound//12.png");

	//level5
	backgroundImage5[0] = iLoadImage("backgound//17.png");
	backgroundImage5[1] = iLoadImage("backgound//18.png");
	backgroundImage5[2] = iLoadImage("backgound//19.png");
	backgroundImage5[3] = iLoadImage("backgound//20.png");
	iStart();


	return 0;
}

