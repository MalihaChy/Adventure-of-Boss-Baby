# include "iGraphics.h"
# include <stdlib.h>

int level=1;
int score=0;

int t1,t2,t3,t4;
int temp_screen;


int food_x;
int food_y;

int a;

bool food;

void Food()
{
	if(food==true)
	{
		if(level==1)
		{
			if((score%100==0 || score%100<=30) && score>30 )
			{
				iShowBMP2(food_x,food_y,"strawberry.bmp",0);
				a=100;
			}
			
		}
		if(level==3)
		{
			if((score%100==0 || score%100<=30) && score>550 )
			{
				iShowBMP2(food_x,food_y,"strawberry.bmp",0);
				a=100;
			}
		}
	}
}

			
void FoodFlag()
{
	if(food==true)
	{
		food=false;
	}
	else
	{
		food=true;
	}
	food_x=rand()%900;
	food_y=rand()%540;
}


/////////////////////////////////////// OBSTACLE 1 comes from the right side
int obstacle1_x=1000,obstacle1_y;
bool vanish1;
bool flag1=true;
void Obstacle1()
{
	if(level==1)
	{
		int obstacle1_speed=10;
		obstacle1_x-=obstacle1_speed;
		if(obstacle1_x<=0 || vanish1==false ) 
		{
			obstacle1_x=1000;
			if(flag1==true)
			{
				obstacle1_y=rand()%220;
			}
			if(flag1==false)
			{
				obstacle1_y=rand()%315+225;
			}
			vanish1=true;
		}
	}
	if(level==2)
	{
		int obstacle1_speed=13;
		obstacle1_x-=obstacle1_speed;
		if(obstacle1_x<=0 || vanish1==false )
		{
			obstacle1_x=1000;
			if(flag1==false)
			{
				obstacle1_y=rand()%315+225;
			}
			if(flag1==true)
			{
				obstacle1_y=rand()%220;
			}
			vanish1=true;
		}
	}
	if(level==3)
	{
		int obstacle1_speed=15;
		obstacle1_x-=obstacle1_speed;
		if(obstacle1_x<=0 || vanish1==false ) 
		{
			obstacle1_x=1000;
			if(flag1==true)
			{
				obstacle1_y=rand()%220;
			}
			if(flag1==false)
			{
				obstacle1_y=rand()%315+225;
			}
			vanish1=true;
		}
	}
}




/////////////////////////OBSTACLE 2 comes from the left side

int obstacle2_x=0,obstacle2_y;
bool vanish2,flag2=false;
void Obstacle2()
{
	if(level==1)
	{
		int obstacle2_speed=10;
		obstacle2_x+=obstacle2_speed;
		if(obstacle2_x>=1000 || vanish2==false )
		{
			obstacle2_x=0;
			if(flag2==false)
			{
				obstacle2_y=rand()%315+225;
			}
			if(flag2==true)
			{
				obstacle2_y=rand()%220;
			}
			vanish2=true;
		}
	}

	if(level==2)
	{
		int obstacle2_speed=14;
		obstacle2_x+=obstacle2_speed;
		if(obstacle2_x>=1000 || vanish2==false )
		{
			obstacle2_x=0;
			if(flag2==true)
			{
				obstacle2_y=rand()%315+225;
			}
			if(flag2==false)
			{
				obstacle2_y=rand()%220;
			}
			vanish2=true;
		}
	}
	if(level==3)
	{
		int obstacle2_speed=16;
		obstacle2_x+=obstacle2_speed;
		if(obstacle2_x>=1000 || vanish2==false )
		{
			obstacle2_x=0;
			if(flag2==true)
			{
				obstacle2_y=rand()%315+225;
			}
			if(flag2==false)
			{
				obstacle2_y=rand()%220;
			}
			vanish2=true;
		}
	}	
}


////////////////// Making bullets
struct BulletRight 
{
	int x;
	int y;
	bool Shot;             
}bullet_right[50];

int NoOfBulletsRight=0;

void Shooting_Right()
{
	for(int i = 0 ; i < NoOfBulletsRight ; i++)
	{
		if(bullet_right[i].Shot)
		{
			bullet_right[i].x += 30;
		}
		if(bullet_right[i].x > 1000 )
		{
				bullet_right[i].Shot = false;	
		}
	}
}



struct BulletLeft 
{
	int x;
	int y;
	bool Shot;             
}bullet_left[50];

int NoOfBulletsLeft=0;

void Shooting_Left()
{
	for(int i = 0 ; i < NoOfBulletsLeft ; i++)
	{
		if(bullet_left[i].Shot)
		{
			bullet_left[i].x -= 30;
		}
		if(bullet_left[i].x < 0 )
		{
			bullet_left[i].Shot = false;
		}
	}
}



struct BulletUp 
{
	int x;
	int y;
	bool Shot;             
}bullet_up[50];

int NoOfBulletsUp=0;

void Shooting_Up()
{
	for(int i = 0 ; i < NoOfBulletsUp ; i++)
	{
		if(bullet_up[i].Shot)
		{
			bullet_up[i].y += 30;
		}
		if(bullet_up[i].x < 0 )
		{
			bullet_up[i].Shot = false;
		}
	}
}




int BabyPos_x=450,BabyPos_y=157;
int life=10;

void Collision()
{
	for(int i=0;i<NoOfBulletsRight;i++)
	{
		if(((bullet_right[i].x+100)>=obstacle1_x)&&((bullet_right[i].x+100)<=(obstacle1_x+100))&&((bullet_right[i].y+100)>=obstacle1_y)&&((bullet_right[i].y)<=(obstacle1_y+100)))
		{
			vanish1=false;
			score+=10;
			if(flag1==true)
			{
				flag1=false;
			}
			else
			{
				flag1=true;
			}
		}	
	}
	for(int i=0;i<NoOfBulletsRight;i++)
	{
		if(((bullet_right[i].x+100)>=obstacle2_x)&&((bullet_right[i].x+100)<=(obstacle2_x+100))&&((bullet_right[i].y+100)>=obstacle2_y)&&((bullet_right[i].y)<=(obstacle2_y+100)))
		{
			vanish2=false;
			score+=10;
			if(flag2==true)
			{
				flag2=false;
			}
			else
			{
				flag2=true;
			}
		}	
	}
	if(((BabyPos_x+100)>=obstacle1_x)&&((BabyPos_x+100)<=(obstacle1_x+100))&&((BabyPos_y+100)>=obstacle1_y)&&(BabyPos_y<=(obstacle1_y+100)))
	{
		vanish1=false;
		life--;
	}
	if(((BabyPos_x+100)>=obstacle2_x)&&((BabyPos_x+100)<=(obstacle2_x+100))&&((BabyPos_y+100)>=obstacle2_y)&&(BabyPos_y<=(obstacle2_y+100)))
	{
		vanish2=false;
		life--;
	}
	
	for(int i=0;i<NoOfBulletsLeft;i++)
	{
		if((bullet_left[i].x<=(obstacle1_x+100))&&((bullet_left[i].x+100)>=(obstacle1_x+100))&&(bullet_left[i].y<=(obstacle1_y+100))&&((bullet_left[i].y+100)>=obstacle1_y))
		{
			vanish1=false;
			score+=10;
			if(flag1==true)
			{
				flag1=false;
			}
			else
			{
				flag1=true;
			}
		}
	}
	for(int i=0;i<NoOfBulletsLeft;i++)
	{
		if((bullet_left[i].x<=(obstacle2_x+100))&&((bullet_left[i].x+100)>=(obstacle2_x+100))&&(bullet_left[i].y<=(obstacle2_y+100))&&((bullet_left[i].y+100)>=obstacle2_y))
		{
			vanish2=false;
			score+=10;
			if(flag2==true)
			{
				flag2=false;
			}
			else
			{
				flag2=true;
			}
		}
	}
	
	if((BabyPos_x<=(obstacle2_x+100))&&((BabyPos_x+100)>=(obstacle2_x+100))&&(BabyPos_y<=(obstacle2_y+100))&&((BabyPos_y+100)>=obstacle2_y))
	{
		vanish2=false;
		life--;
	}
	if((BabyPos_x<=(obstacle1_x+100))&&((BabyPos_x+100)>=(obstacle1_x+100))&&(BabyPos_y<=(obstacle1_y+100))&&((BabyPos_y+100)>=obstacle1_y))
	{
		vanish1=false;
		life--;
	}
	
	for(int i=0;i<NoOfBulletsUp;i++)
	{
		if(((bullet_up[i].x+100)>=obstacle1_x)&&(bullet_up[i].x<=(obstacle1_x+100))&&((bullet_up[i].y+100)>=obstacle1_y)&&((bullet_up[i].y)<=(obstacle1_y+100)))
		{
			
			vanish1=false;
			score+=10;
			if(flag1==true)
			{
				flag1=false;
			}
			else
			{
				flag1=true;
			}
		}
	}
	for(int i=0;i<NoOfBulletsUp;i++)
	{
		if(((bullet_up[i].x+100)>=obstacle2_x)&&(bullet_up[i].x<=(obstacle2_x+100))&&((bullet_up[i].y+100)>=obstacle2_y)&&((bullet_up[i].y)<=(obstacle2_y+100)))
		{
			
			vanish2=false;
			score+=10;
			if(flag2==true)
			{
				flag2=false;
			}
			else
			{
				flag2=true;
			}
		}
	}
	if(food==true && (level==1 || level==3))
	{
		if(((BabyPos_x+100)>=food_x)&&(BabyPos_x<=(food_x+100))&&((BabyPos_y+100)>=food_y)&&(BabyPos_y<=(food_y+100)))
		{
			if(a==100 && ( score%100==0 || score%100<=30) && score>=100)
			{
				score+=50;
			}
		}
	}
}




int mode,len;
int screen=1;
int bgPos_x=0,bgPos_y=0;
bool flipRight=true;
bool flipLeft=false;
bool flipUp=false;




void Screen1()    //////////////// Poster
{
	iClear();
	iShowBMP(bgPos_x,bgPos_y,"screen1.bmp");
}

void Screen2()       /////////// Main Menu
{
	iClear();
	life=3;
	level=1;
	score=0;
	iShowBMP(bgPos_x,bgPos_y,"bg24.bmp");
	iShowBMP(380,440,"play1.bmp");
	iShowBMP(400,360,"help1.bmp");
	iShowBMP(380,280,"score.bmp");
	iShowBMP(400,200,"credits1.bmp");
	iShowBMP(380,120,"exit1.bmp");
}

void Screen3()     /////// Levels
{
	iClear();
	if(level==1)
	{
		iShowBMP(bgPos_x,bgPos_y,"bg22.bmp");
	}
	if(level==2)
	{
		iShowBMP(bgPos_x,bgPos_y,"bg27.bmp");
	}

	if(level==3)
	{
		iShowBMP(bgPos_x,bgPos_y,"bg20.bmp");
	}

	Food();
	if(flipRight==true)
		{
			iShowBMP2(BabyPos_x,BabyPos_y,"babyRight.bmp",0);
		}
		else
		{
			if(flipUp==true)
			{
				iShowBMP2(BabyPos_x,BabyPos_y,"babyUp.bmp",0);
			}
			else
			{
				if(flipLeft==true)
				{
					iShowBMP2(BabyPos_x,BabyPos_y,"babyLeft.bmp",0);
				}
			}

		}
	////(right obstacle appear+vanish, right bullet appear)
		if(vanish1==true)
		{
			if(flag1==true)
			{
				iShowBMP2(obstacle1_x,obstacle1_y,"NiasaRight.bmp",0);
			}
			if(flag1==false)
			{
				iShowBMP2(obstacle1_x,obstacle1_y,"NiasaRight.bmp",0);
			}
			
		}
		else
		{
			iShowBMP(2000,700,"NiasaRight.bmp");
		}
			
		for(int i = 0; i < NoOfBulletsRight ; i++)
		{
			if(bullet_right[i].Shot == true)
			{
				iShowBMP2(bullet_right[i].x,bullet_right[i].y,"Fireball.bmp",0);
			}
			
		}
			



		////(left obstacle appear+vanish, left bullet appear)
		if(vanish2==true)
		{
			iShowBMP2(obstacle2_x,obstacle2_y,"NiasaLeft.bmp",0);
		}
		else
		{
			iShowBMP(1700,200,"NiasaLeft.bmp");
			
		}
		for(int i = 0; i < NoOfBulletsLeft ; i++)
		{
			if(bullet_left[i].Shot == true)
			{
				iShowBMP2(bullet_left[i].x,bullet_left[i].y,"FireballLeft.bmp",0);
			}
		}




		//// shoot upwards
		
		for(int i = 0; i < NoOfBulletsUp ; i++)
		{
			if(bullet_up[i].Shot == true)
			{
				iShowBMP2(bullet_up[i].x,bullet_up[i].y,"FireballUp.bmp",0);
			}
		}
		char SCORE[100];
		_itoa(score,SCORE,10);
		iSetColor(0,0,0);
		iRectangle(890,600,100,30);
		iSetColor(255,255,255);
		iFilledRectangle(891,601,98,28);
		iSetColor(0,0,0);
		char scoreBox[200];
		strcpy(scoreBox,"Score :");
		strcat(scoreBox,SCORE);
		iText(895,610,scoreBox);
		if(life==3)
		{
			iShowBMP2(890,565,"life.bmp",0);
			iShowBMP2(925,565,"life.bmp",0);
			iShowBMP2(960,565,"life.bmp",0);
		}
		if(life==2)
		{
			iShowBMP2(890,565,"life.bmp",0);
			iShowBMP2(925,565,"life.bmp",0);
		}
		if(life==1)
		{
			iShowBMP2(890,565,"life.bmp",0);
		}
		if(life==0)
		{
			screen=7;   ///// screen 7 is game over screen
		}
		if(score>=200 && level==1)
		{
			level=2;
			screen=9;
		}
		if(score>=545 && level==2)
		{
			level=3;
			screen=11;
		}
}


FILE *input,*output;
char str[100], str2[100], name[5][20], hscore[5][200];
int highscore[5],hs=1;


void Screen5()   //// Leaderboard
{
	
	input = fopen("Highscore.txt", "r");
	for(int j=0; j<5; j++)
	{
		fscanf(input,"%d %s", &highscore[j], name[j]);
		sprintf(hscore[j], "Name: %s Score: %d", name[j], highscore[j]);
	}
	fclose(input);
	

	iShowBMP(bgPos_x,bgPos_y,"highscore.bmp");
	iShowBMP(790,10,"back.bmp");

	if(hs)
	{
		char tempName[20];
		int temp;
		for(int i=0;i<5;i++)
		{
			for(int j=i+1;j<5;j++)
			{
				if(highscore[j]>highscore[i])
				{
					temp=highscore[j];
					highscore[j]=highscore[i];
					highscore[i]=temp;
					strcpy(tempName,name[j]);
					strcpy(name[j],name[i]);
					strcpy(name[i],tempName);
				}
			}
		}
		hs=0;
		
		output = fopen("Highscore.txt", "w");
		for(int j=0; j<5; j++)
		{
			fprintf(output,"%d %s\n", highscore[j], name[j]);
			sprintf(hscore[j], "Name: %s Score: %d", name[j], highscore[j]);
		}
		fclose(output);
	}
	iShowBMP(364,374,"plate.bmp");
	iShowBMP(364,324,"plate.bmp");
	iShowBMP(364,274,"plate.bmp");
	iShowBMP(364,224,"plate.bmp");
	iShowBMP(364,174,"plate.bmp");
	iText(444, 389, hscore[0],GLUT_BITMAP_8_BY_13);
	iText(444, 339, hscore[1],GLUT_BITMAP_8_BY_13);
	iText(444, 289, hscore[2],GLUT_BITMAP_8_BY_13);
	iText(444, 239, hscore[3],GLUT_BITMAP_8_BY_13);
	iText(444, 189, hscore[4],GLUT_BITMAP_8_BY_13);


}

void drawTextBox()
{
	iSetColor(150, 150, 150);
	iRectangle(380, 340, 250, 30);
}


void highscoreChange()
{
	hs=1;
	output = fopen("Highscore.txt", "w");
	drawTextBox();
	if(mode == 1)
	{
		iSetColor(255, 255, 255);
		iText(400, 350, str);
	}
	
	iText(10, 590, "Click to activate the box, enter to finish.",GLUT_BITMAP_TIMES_ROMAN_24 );

	
	
	iSetColor(0,0,0);

	strcpy(name[4], str2);
	fprintf(output, "%d %s\n", highscore[0], name[0]);
	fprintf(output, "%d %s\n", highscore[1], name[1]);
	fprintf(output, "%d %s\n", highscore[2], name[2]);
	fprintf(output, "%d %s\n", highscore[3], name[3]);
	fprintf(output, "%d %s\n", score, name[4]);
	fclose(output);
	
	
	
}



void Screen7()   ///////// Game Over
{
	iClear();
	iShowBMP(bgPos_x,bgPos_y,"over.bmp");
	char SCORE[1000];
	_itoa(score,SCORE,10);
	iShowBMP(400,150,"greenB.bmp");
	iText(470,185,SCORE,GLUT_BITMAP_TIMES_ROMAN_24);
	if(score>highscore[4])
		highscoreChange();
	iShowBMP(750,10,"back.bmp");
}

void Screen4()    //// Instructions
{
	iClear();
	iShowBMP(bgPos_x,bgPos_y,"help.bmp");
	iShowBMP(750,10,"back.bmp");
}

void Screen6()    //// Credits
{
	iClear();
	iShowBMP(bgPos_x,bgPos_y,"credits2.bmp");
	iShowBMP(750,10,"back.bmp");
}


void Screen8()     ///// Level 1 Image
{
	iClear();
	iShowBMP(bgPos_x,bgPos_y,"level1.bmp");
}

void Screen9()     ///// Level 1 Completed
{
	iClear();
	iShowBMP(bgPos_x,bgPos_y,"level1C.bmp");
	iShowBMP(10,10,"menuR.bmp");
	iShowBMP(790,10,"level2B.bmp");

}

void Screen10()    //// Level 2 Image
{
	iClear();
	iShowBMP(bgPos_x,bgPos_y,"level2.bmp");
}

void Screen11()    //// Level 2 Completed
{
	iClear();
	iShowBMP(bgPos_x,bgPos_y,"level2C.bmp");
	iShowBMP(10,10,"menuR.bmp");
	iShowBMP(790,10,"level3B.bmp");
}

void Screen12()    //// Level 3 Image
{
	iClear();
	iShowBMP(bgPos_x,bgPos_y,"level3.bmp");
}

void Screen13()   //// Pause Screen
{
	iClear();
	iShowBMP(bgPos_x,bgPos_y,"pause.bmp");
	iShowBMP(400,205,"Quit.bmp");
	iShowBMP(400,285,"Restart.bmp");
	iShowBMP(400,365,"Resume.bmp");
}

void pause()
{
	iPauseTimer(t1);
	iPauseTimer(t2);
	iPauseTimer(t3);
	iPauseTimer(t4);
	
}

void resume()
{
	iResumeTimer(t1);
	iResumeTimer(t2);
	iResumeTimer(t3);
	iResumeTimer(t4);
}



void iDraw()
{
	iClear();

	if(screen==1)     /////// Poster
	{
		Screen1();
	}

	if(screen==2)    ////// Main Menu
	{
		Screen2();
	}

	if(screen==3)
	{
		Screen3();   ///// Levels
	}

	if(screen==4)
	{
		Screen4();   //// Instructions
	}

	if(screen==5)
	{
		Screen5();   ////// Leader Board
	}

	if(screen==6)     ////// Credits
	{
		Screen6();
	}

	if(screen==7)
	{
		Screen7();    //// Game over 
	}
	if(screen==8)
	{
		Screen8();   //// Level 1 Image
	}
	if(screen==9)
	{
		Screen9();   //// Level 1 Completed
	}
	if(screen==10)
	{
		Screen10();   //// Level 2 Image
	}
	if(screen==11)
	{
		Screen11();   //// Level 2 Completed
	}
	if(screen==12)
	{
		Screen12();   //// Level 3 Image
	}
	if(screen==13)
	{
		Screen13();   //// Pause Image
	}
	if(screen==3)
	{
		resume();
	}
	else
	{
		pause();
	}
}


void iMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(screen==1)
		{
			screen=2;
		}
		else
		{
		
			if(screen==8)
			{
				screen=3;
				
			}
			if(screen==10)
			{
				screen=3;
				
			}
			if(screen==12)
			{
				screen=3;
				
			}
			if(screen==2 && mx>=380 && mx<=620 && my>=440 && my<=510)
			{
				screen=8;///play
			}
			
			if(screen==2 && mx>=400 && mx<=600 && my>=360 && my<=430)
			{
				screen=4; //help
			}
			if(screen==4 && mx>=750 && mx<=990 && my>=10 && my<=80) ////back conditions)
			{
				screen=2;
			}
			if(screen ==2 && mx>=380 && mx<=620 && my>=280 && my<=350)
			{
				screen=5; ///highscore
			}
			if(screen==5 && mx>=750 && mx<=990 && my>=10 && my<=80) //back conditions)
			{
				screen=2;
			}
			if(screen==7 && mx>=350 && mx<=600 && my>=340 && my<=370)
			{
				mode=1;
			}
			if(screen==2 && mx>=400 && mx<=600 && my>=200 && my<=270)
			{
				screen=6; ///credits
			}
			if(screen==6 && mx>=750 && mx<=990 && my>=10 && my<=80)/// back conditions)
			{
				screen=2;
			}
			if(screen==2 && mx>=380 && mx<=620 && my>=120 && my<=190)
			{
				exit(0); ///exit
			}
			if(screen==9 && mx>=10 && mx<=210 && my>=10 && my<=80)
			{
				screen=2;
			}
			if(screen==9 && mx>=790 && mx<=990 && my>=10 && my<=80)
			{
				screen=10;
			}
			if(screen==11 && mx>=10 && mx<=210 && my>=10 && my<=80)   /// Level 2 completed -> Main Menu
			{
				screen=2;
			}
			if(screen==11 && mx>=790 && mx<=990 && my>=10 && my<=80)   /// Level 2 completed -> Level 3 Image
			{
				screen=12;
			}
			if(screen==7 && mx>=790 && mx<=990 && my>=10 && my<=80)
			{
				screen=2;
			}

			if(screen==13 && mx>=400 && mx<=600 && my>=205 && my<=275)
			{
				exit(0);
			}
			if(screen==13 && mx>=400 && mx<=600 && my>=285 && my<=355)
			{
				screen=1;
			}
			if(screen==13 && mx>=400 && mx<=600 && my>=365 && my<=435)
			{
				screen=temp_screen;
				resume();
			}
		}			
	}
}

void iPassiveMouseMove(int mx,int my)
{
	
}
	
	
void iKeyboard(unsigned char key)
{
	
		if (key == 'a')
		{
			if(NoOfBulletsRight < 50)
				NoOfBulletsRight++;
			else if (NoOfBulletsRight == 50)
				NoOfBulletsRight = 0;

			bullet_right[NoOfBulletsRight-1].Shot = true;
			bullet_right[NoOfBulletsRight-1].y = BabyPos_y ;
			bullet_right[NoOfBulletsRight-1].x = BabyPos_x+50 ;
			flipUp=false;
			flipLeft=false;
			flipRight=true;
			
		}
		if (key == 'd')
		{
			if(NoOfBulletsLeft < 50)
				NoOfBulletsLeft++;
			else if (NoOfBulletsLeft == 50)
				NoOfBulletsLeft = 0;

			bullet_left[NoOfBulletsLeft-1].Shot = true;
			bullet_left[NoOfBulletsLeft-1].y = BabyPos_y ;
			bullet_left[NoOfBulletsLeft-1].x = BabyPos_x - 50;
			flipUp=false;
			flipRight=false;
			flipLeft=true;
		}
		if (key == 'w')
		{
			if(NoOfBulletsUp < 50)
				NoOfBulletsUp++;
			else if (NoOfBulletsUp == 50)
				NoOfBulletsUp = 0;

			bullet_up[NoOfBulletsUp-1].Shot = true;
			bullet_up[NoOfBulletsUp-1].y = BabyPos_y + 100;
			bullet_up[NoOfBulletsUp-1].x = BabyPos_x ;
			flipRight=false;
			flipLeft=false;
			flipUp=true;
		}

		if(key=='p')
		{
			temp_screen=screen;
			pause();
			screen=13;
		}

		if(mode == 1 || screen==7)
		{
			if(key == '\r')
			{
				mode = 0;
				strcpy(str2, str);
				printf("%s\n", str2);
				for(int i = 0; i < len; i++)
					str[i] = 0;
				len = 0;
			}
			else
			{
				str[len] = key;
				len++;
			}
		}
}



void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_UP)
	{
		if(BabyPos_y+100<630)
		{
			BabyPos_y+=10;
		}
		
	}
	if(key == GLUT_KEY_DOWN)
	{
		if(BabyPos_y>=10)
		{
			BabyPos_y-=10;
		}
	}
	if(key == GLUT_KEY_RIGHT)
	{
		if(BabyPos_x+100<1000)
		{
			BabyPos_x+=10;
		}
	}
	if(key == GLUT_KEY_LEFT)
	{
		if(BabyPos_x>0)
		{
			BabyPos_x-=10;
		}
		
	}
}


int main()
{
	iSetTimer(100,Shooting_Right);
	iSetTimer(100,Shooting_Left);
	iSetTimer(100,Shooting_Up);

	t1=iSetTimer(100,Obstacle1);
	t2=iSetTimer(100,Obstacle2);
	t3=iSetTimer(100,Collision);
	t4=iSetTimer(5000,FoodFlag);
	
	iInitialize(1000, 640, "Adventure_of_Boss_Baby");
	return 0;
}	