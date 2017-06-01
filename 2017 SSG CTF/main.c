#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

void initPan();

void gotoxy(int x,int y);

void putOnStone(int x, int y, int turn);

int blackwc(int y,int z);

int whitewc(int y,int z);

int do_omok();

void write_comment();

int choose_developer();

void readFile(char filename[20]);

void howToPlay();

int black[22][22];
int white[22][22];
char temp_pan[22][45];
char pan[22][45];

int main(void)
{
	int choose;
	int i;
	int flag=1;
	
	readFile("./hint");

	for(i=0;i<25;i++) {
		memset(pan[i],NULL,sizeof(pan[i]));
	}

	while(flag)
	{
		setvbuf(stdout, NULL, _IONBF, 0);
			
		printf("\n\n\n\n\t\t1. play omok\n\t\t2. how to play\n\t\t3. write comment to developer\n\t\t4. exit\n\n\t\t>");
		scanf("%d",&choose);
		switch(choose)
		{
		case 1:do_omok(); break;
		case 2:howToPlay();break;
		case 3:write_comment(); break;                                                                                                                                                                                                                                                    
		case 4:
		default:flag=0; break;
		};
	}
	printf("goodbye!");
}

void write_comment()
{
	int developer;	
	char comment[30];
	developer=choose_developer();
	scanf("%s",comment);
	printf("\n\t\tsend success\n\n\n\n");
}

int choose_developer()
{
	char name[3][16]={"ssgskid","ssgkmd","eyeball"};
	int num;

	printf("\n\n\n\n\t\tchoose developer to send comment\n\n\n\t\t>");
	scanf("%d",&num);
	if(num>6||num<1) {
		printf("no!");
		exit(1);
	}
	else {
		printf("\n\n\t\tsend comment to %s!\n\n\t\t>",name[num-1]);
	}
	return num;
}

int do_omok()
{
	int turn=0,x=11,y=11;
	int winFlag=0;
	int hi;
	char ch;

	for (hi = 0 ;  hi < 22 ; hi++)
	{
		memset(black[hi],0,sizeof(int)*21);
		memset(white[hi],0,sizeof(int)*21);
	}

	initPan();
	gotoxy(x,y);

	while(1){
		scanf("%c",&ch);
		switch(ch)
		{
		case 'w':
			x-=1;
			//if((x+1)<=0) break;
			gotoxy(x,y);
			break;//아래
		case 's':
			if((x-1)>=20) break;
			x+=1;
			gotoxy(x,y);
			break;//위
		case 'a':
			y-=1;
			//if((y+1)<=0) break;
			gotoxy(x,y);
			break;//왼쪽
		case 'd':
			if((y-1)>=20) break;
			y+=1;
			gotoxy(x,y);
			break;//오른쪽
		case 32:
			if(white[x][y]==1633771873||black[x][y]==1633771873)
				break;
			turn++;
			putOnStone(x,y,turn);   //돌 색칠
			if(turn%2==1){
				black[x][y]=1633771873;
				if(blackwc(x,y)==1){
					winFlag=1;
					break;
				}
			}
			else{
				white[x][y]=1633771873;
				if(whitewc(x,y)==1){
					winFlag=1;
					break;
				}
			}
			break;
		default:break;
		}//스페이스바
		if(winFlag==1) break;
	}
	if(turn%2==1){
		printf("검은돌 승리!\n");
	}
	else{
		printf("흰돌 승리!\n");
	}

	return 0;
}

void initPan(){
	int i,j;

	strcpy(pan[0],"┌┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┐");
	for(i=1;i<21;i++) {
		strcpy(pan[i],"├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤");
	}
	strcpy(pan[21],"└┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┘");

	for(i=0;i<22;i++) {
		strcpy(temp_pan[i],pan[i]);
	}
}

void gotoxy(int x, int y)
{
	int i;

	if(white[x][y]!=1633771873&&black[x][y]!=1633771873)   //돌이 놓여있다면 현재 위치 표시x
	{
		if(x==0) {
			temp_pan[0][y*2]=0x5f;
			temp_pan[0][y*2+1]=0x5f;
		}
		else if(x>=0&&x<=20) {
			temp_pan[x][y*2]=0x5f;
			temp_pan[x][y*2+1]=0x5f;
		}
		else {
			temp_pan[21][y*2]=0x5f;
			temp_pan[21][y*2+1]=0x5f;
		}
	}
	
	printf("\n\n");
	for(i=0;i<22;i++) {
		printf("%s\n",temp_pan[i]);
	}
	printf(" > ");

	for(i=0;i<22;i++) {
		strcpy(temp_pan[i],pan[i]);
	}
}

void putOnStone(int x, int y, int turn)
{
	int i;
	int stone1;
	int stone2;

	if(turn%2==1) {
		stone1=0xa1;
		stone2=0xdc;
	} else {
		stone1=0xa1;
		stone2=0xdb;
	}

	if(x==0) {
		pan[0][y*2]=stone1;
		pan[0][y*2+1]=stone2;
	}
	else if(x>=0&&x<=20) {
		pan[x][y*2]=stone1;
		pan[x][y*2+1]=stone2;
	}
	else {
		pan[21][y*2]=stone1;
		pan[21][y*2+1]=stone2;
	}

	printf("\n\n");
	for(i=0;i<22;i++) {
		printf("%s\n",pan[i]);
	}
	printf(" > ");

	for(i=0;i<22;i++) {
		strcpy(temp_pan[i],pan[i]);
	}
}

int blackwc(int i,int j)
{
	int check=0;
	int x=0,y=0;
	int p,q;

	for(x=i+1;x<=(i+4);x++){
		if(x>21) break;
		if(black[x][j]==0) break;
		check++;
	}
	for(x=i-1;x>=(i-4);x--){
		if(x<0) break;
		if(black[x][j]==0) break;
		check++;
	}
	if(check==4) return 1;
	check=0;//양옆

	for(y=j+1;y<=(j+4);y++){
		if(y>21) break;
		if(black[i][y]==0) break;
		check++;
	}
	for(y=j-1;y>=(j-4);y--){
		if(y<0) break;
		if(black[i][y]==0) break;
		check++;
	}
	if(check==4) return 1;
	check=0;//위아래

	for(x=i+1,y=j+1;x<=(i+4),y<=(j+4);x++,y++){
		if(x>21||y>21) break;
		if(black[x][y]==0) break;
		check++;
	}
	for(x=i-1,y=j-1;x>=(i-4),y>=(j-4);x--,y--){
		if(x<0||y<0) break;
		if(black[x][y]==0) break;
		check++;
	}
	if(check==4) return 1;
	check=0;//왼쪽 아래 대각선

	for(x=i+1,y=j-1;x<=(i+4),y>=(j-4);x++,y--){
		if(x>21||y<0) break;
		if(black[x][y]==0) break;
		check++;
	}
	for(x=i-1,y=j+1;x>=(i-4),y<=(j+4);x--,y++){
		if(x<0||y>21) break;
		if(black[x][y]==0) break;
		check++;
	}
	if(check==4) return 1;
	check=0;//오른쪽 아래 대각선
}

int whitewc(int i,int j)
{
	int check=0;
	int x=0,y=0;

	for(x=i+1;x<=(i+4);x++){
		if(x>21) break;
		if(white[x][j]==0) break;
		check++;
	}
	for(x=i-1;x>=(i-4);x--){
		if(x<0) break;
		if(white[x][j]==0) break;
		check++;
	}
	if(check==4) return 1;
	check=0;//양옆

	for(y=j+1;y<=(j+4);y++){
		if(y>21) break;
		if(white[i][y]==0) break;
		check++;
	}
	for(y=j-1;y>=(j-4);y--){
		if(y<0) break;
		if(white[i][y]==0) break;
		check++;
	}
	if(check==4) return 1;
	check=0;//위아래

	for(x=i+1,y=j+1;x<=(i+4),y<=(j+4);x++,y++){
		if(x>21||y>21) break;
		if(white[x][y]==0) break;
		check++;
	}
	for(x=i-1,y=j-1;x>=(i-4),y>=(j-4);x--,y--){
		if(x<0||y<0) break;
		if(white[x][y]==0) break;
		check++;
	}
	if(check==4) return 1;
	check=0;//왼쪽 아래 대각선

	for(x=i+1,y=j-1;x<=(i+4),y>=(j-4);x++,y--){
		if(x>21||y<0) break;
		if(white[x][y]==0) break;
		check++;
	}
	for(x=i-1,y=j+1;x>=(i-4),y<=(j+4);x--,y++){
		if(x<0||y>21) break;
		if(white[x][y]==0) break;
		check++;
	}
	if(check==4) return 1;
	check=0;//오른쪽 아래 대각선
}

void readFile(char filename[20])
{
	FILE *f;
	char content[20];

	f=fopen(filename,"r");
	if(f==NULL)
	{
		printf("\nfile open error\n");
		return;
	}
	fscanf(f,"%s",content);
	printf("%s",content);
	return;
}

void howToPlay()
{
	printf("\n\n\t\t\tHOW TO PLAY");

	printf("\n\n\n\n\t\t1. move with w, a, s, d.\n");
	printf("\t\t2. input space bar when put stone.\n");
	printf("\t\t3. Enter each time you type one key.\n");
	printf("\t\t4. Play with your friend!\n\n\n\n");
}