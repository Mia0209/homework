#include<stdio.h>
#include<stdlib.h>

#define SNAKE_MAX_LENGTH 20
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLACK_CELL ' '
#define SNAKE_FOOD '$'
#define WALL_CELL '*'

void snake_move(int y,int x);	
//get snake to move:dy=-1(move up),dy=1(move down);dx=-1(move left),dx=1(move right)
void put_food(void);
//put a food symbol randomly on a blank cell
void output_map(void);
//print the char matrix
int over(void);
//end the game when the snake hits itself

char map[12][13]={"************",
				  "*XXXXH     *",
				  "*          *",
				  "*          *",
				  "*          *",
				  "*          *",
				  "*          *",
				  "*          *",
				  "*          *",
				  "*          *",
				  "*          *",
				  "************"};
//initialize the map

int snakeX[5]={1,2,3,4,5};		
int snakeY[5]={1,1,1,1,1};		//the coordinate of the snake


int main()
{
	char ch;
	
	output_map();
	
	while(!over())
	{
		scanf("%c", &ch);
		getchar();
		
		switch(ch)
		{
			case 'A':
				snake_move(0,-1);
				break;
			case 'D':
				snake_move(0,1);
				break;
			case 'W':
				snake_move(-1,0);
				break;
			case 'S':
				snake_move(1,0);
				break;
		}
		
		output_map();
		
		if(over())
		{
			printf("Game over!\n");
			return 0;
		}
		
	}
	
	return 0;
}

void snake_move(int y,int x)
{
	int i;
	
	int a=snakeY[4];
	int b=snakeX[4];
	
	snakeX[4]+=x;
	snakeY[4]+=y;		
	
	map[snakeY[4]][snakeX[4]]=SNAKE_HEAD;
	map[snakeY[0]][snakeX[0]]=BLACK_CELL;

	for(i=0;i<3;i++) 
	{
		snakeX[i]=snakeX[i+1];		
		snakeY[i]=snakeY[i+1];		
		map[snakeY[i]][snakeX[i]]=SNAKE_BODY;		
	}
	
	snakeY[3]=a;
	snakeX[3]=b;
	
	map[snakeY[3]][snakeX[3]]=SNAKE_BODY;
	
	return;
}

void put_food(void)
{
	
}

void output_map(void)
{
	int i;
	system("cls");
	for(i=0;i<12;i++)
	{
		printf("%s\n", map[i]);
	}
	return;
}

int over(void)
{
	int i;
	
	for(i=0;i<4;i++) 
	{
		if(snakeY[4]==snakeY[i]&&snakeX[4]==snakeX[i]) 
		{	
			return 1;
		}
	}	
	
	if(snakeY[4]==11||snakeY[4]==0) 
	{
		return 1;		
	}
	
	if(snakeX[4]==11||snakeX[4]==0) 
	{
		return 1;
	}			
				
	return 0;
}