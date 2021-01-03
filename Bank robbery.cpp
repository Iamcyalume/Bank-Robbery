#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>

int main(void){
	
	char *name = (char*)malloc(sizeof(char)*256); 
	char *serial = (char*)malloc(sizeof(char)*256);
	char *input = (char*)malloc(sizeof(char)*256);
	
	int rtn, enter;
	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); 
	printf("\n\ncyalume's first crackme!\n\n"); //회색으로 출력  
	
	printf("Your name must be at least 7 characters long\n\n");
	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); 
	printf("==============================================\n\n"); //회색으로 출력 
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("Log in to use this banking service\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		
	start:
	 
	printf("==============================================\n\n"); //회색으로 출력 	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			
			
	printf("Enter your name : ");
	gets(name);
	printf("\n\n");
	
	rtn = strlen(name);


	if(strlen(name)>256){
		
		printf("Too Long!\n\n");
		goto start; //처음부터  
		
	}else if(strlen(name)<7){ 
		
		printf("Too short!\n\n");
		goto start; //처음부터  
		
	}

	
	printf("Enter your Password : ");
	gets(input);
	
	
	if(rtn!=strlen(input)){
		
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  
		printf("\n\nWrong Password!\n\n"); //붉은색으로 출력  
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); 
		
		goto ret;
		
	}
	
	
	for(int i=0; i<rtn; i++){
		
		serial[i] = name[rtn-1-i]^i;
		
		if(serial[i]!=input[i]){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);   
			printf("\n\nWrong Password!\n\n"); //붉은색으로 출력  
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);   
			goto ret;
			
		}
		
	}
	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("\n\nRight Password!\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); 
	printf("==============================================\n\n"); //회색으로 출력
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	
	printf("Welcome, Mr.billionare!\n\n\n");
	printf("Auth your name at probgame.com\n\n\n");
	printf("Wanna go probgame.com? [Y/n] ");
	
	scanf("%c", &enter);
	
	if(enter == 'Y' || enter == 'y'){
		
		sleep(1);
		system("\n\n\nstart chrome http://probgame.com/");
		
	}else goto ret;
	
	printf("\n\n\n");
	
	ret:
	
	system("pause");
	
	free(name);
	free(serial);
	free(input);
		
	return 0;
	
}
