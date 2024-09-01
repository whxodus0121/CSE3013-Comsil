#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int WIDTH,HEIGHT;
int **maze;
int *line;
int *ver;
FILE *fp;

void init_maze(void);
void print_line(int h);
void print_ver(int h);
void cal_line(int h);
void cal_ver(int h);

void print_line(int h){

	int i,x,y;
	for(i=0;i<WIDTH;i++){
		if(line[i]) {
			for(x=0;x<HEIGHT;x++){
				for(y=0;y<WIDTH;y++){
					if(maze[x][y]==maze[h+1][i])
						maze[h+1][i]=maze[h][i];
				}
			}
			fprintf(fp,"+ ");
		}
		else fprintf(fp,"+-");
	}
	fprintf(fp,"+\n");
}

void print_ver(int h){
	
	int i,x,y;
	fprintf(fp,"| ");
	for(i=0;i<WIDTH-1;i++){

		if(ver[i]) {
			
			for(x=0;x<HEIGHT;x++){
                                 for(y=0;y<WIDTH;y++){
                                         if(maze[x][y]==maze[h][i+1])
                                                 maze[x][y]=maze[h][i];
                                 }
                         }

			fprintf(fp,"  ");
		}
		else{
			fprintf(fp,"| ");
		}
	}
	fprintf(fp,"|\n");
}	

void init_maze(void){
	
	int i,j;

	maze = (int**)malloc(HEIGHT * sizeof(int*));
    	for(i = 0; i < HEIGHT; i++) {
        	maze[i] = (int*)malloc(WIDTH * sizeof(int));
    	}
    	line = (int*)malloc(WIDTH * sizeof(int));
    	ver = (int*)malloc((WIDTH - 1) * sizeof(int));
	for(i=0;i<WIDTH;i++) line[i]=0;
	for(i=0;i<WIDTH-1;i++) ver[i]=0;
	for(i=0;i<HEIGHT;i++){
        	for(j=0;j<WIDTH;j++) maze[i][j]=i*WIDTH+j;
        }
}

void cal_line(int h){

	int i,cnt,change=0;
	int flag=0;

	for(i=0;i<WIDTH;i++){
		
		line[i]=rand()%2;
		if(line[i]==1) flag=1;
		
		if(i<WIDTH-1 && maze[h][i]!=maze[h][i+1]){
			
			if(flag==0)line[change+rand()%(i-change+1)]=1;	
			change=i+1;
			flag=0;		
		}
	}
	if(flag==0&&change!=WIDTH-1)line[change+rand()%(i-change+1)]=1;
	if(change==WIDTH-1) line[WIDTH-1]=1;
	
}

void cal_ver(int h){

	int i;
	for(i=0;i<WIDTH-1;i++){

		ver[i]=rand()%2;
	}
	for(i=0;i<WIDTH-1;i++){

		if(maze[h][i]==maze[h][i+1]) ver[i]=0;
	}
}


int main(void){
	
	int i,j,temp=10;

	fp=fopen("created_maze.maz","wt");
	
	srand(time(NULL));

	printf("Enter WIDTN : ");
	scanf("%d",&WIDTH);
	printf("Enter HEIGHT : ");
	scanf("%d",&HEIGHT);
	
	init_maze();
	print_line(0);	
	
	for(i=0;i<HEIGHT-1;i++){
		cal_ver(i);
		print_ver(i);
		cal_line(i);
		print_line(i);			
	}

	for(i=0;i<WIDTH-1;i++){
		if(maze[HEIGHT-1][i]!=maze[HEIGHT-1][i+1]) {
			
			ver[i]=1;
			/*if(maze[HEIGHT-1][i]<maze[HEIGHT-1][i+1]){
				if(temp>maze[HEIGHT-1][i])temp=maze[HEIGHT-1][i];		
			}
			else{
				if(temp>maze[HEIGHT-1][i+1]) temp=maze[HEIGHT-1][i+1];
			}*/
		}
		else ver[i]=0;
	}
	print_ver(HEIGHT-1);
	
	for(i=0;i<WIDTH;i++){

		fprintf(fp,"+-");
	}
	fprintf(fp,"+\n");

	/*for(i=0;i<HEIGHT;i++){
		for(j=0;j<WIDTH;j++) maze[i][j]=temp; 
	}*/
	if(fp!=NULL) printf("result file: created_maze.maz\n");
	free(maze);
	free(line);
	free(ver);
	fclose(fp);
	return 0;
}
