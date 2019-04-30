/* 
Practice name: Bar Graph by C language
Compiler: Vc*
Date: 30/04/2019
Author: Do Pan N
Email: dophan***c@gmail.com
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define INPUT_END -1

#define MAX 10
#define MIN 0

#define COL 10
#define ROW 10

int getData(char *prompt, int maxValue, int minValue);
int getInputKey(char *array);
void dispGraph(int *ptr, int toNum);

/*+++++Main function+++++
Get data and store in array then put it into display function,
Maximum of num of data is 10 and depend on number of input.
*/
int main(int argc, char const *argv[])
{
	int dispData[8];
	int i;
	int inputData;
	char mesg_input[] = "input =>";
	
	printf("Please enter integer number within range 1 ~ 10:");
	for (i = 0; i < 10; ++i)
	{
		inputData = getData(mesg_input, MAX, MIN);
		if (inputData == -1)
		{
			break;
		}else{
			dispData[i] = inputData;
		}
	}
	printf("\n\n");
	dispGraph(dispData, i);
	return 0;
}

/*+++++Get Appropriate Data Function+++++
	Convert string number to integer number,
	Return integer number within 0~10 if still input data,
	Return -1 number if no more input data.
*/
int getData(char *prompt, int maxValue, int minValue)
{
	char charData[8] = {'\0'};
	int i, numData, getInput;

	printf("\n%s", prompt);
	getInput = getInputKey(charData);
	if (getInput == INPUT_END)
		numData = getInput;
	else{
		numData = atoi(charData);
		while (numData > MAX || numData < MIN){
			printf("\nRe-enter number within range 0 ~ 10:");
			printf("\n%s", prompt);
			memset(charData, '\0', sizeof(charData));
			getInput = getInputKey(charData);
			numData = atoi(charData);
		}
	}
	return numData;
}

/*+++++Get Keyboard Input Function+++++
	If enter without input key, it returns -1
	else it returns 0, string number will be stored in
	array which the poiter is pointing at. Support with
	Backspace, only accept digit input.
*/
int getInputKey(char *array)
{
	char c;
	int ifdigit;
	int i = 0;
	while(TRUE)
	{
		c = getch();
		ifdigit = isdigit(c);
		if (ifdigit == 0)
		{
			if (c == '\b')
			//Backspace key
			{
				if (i == 0)
					putch('\a');		//Error sound
				else {
					putch('\b');		//Move ctl key to left
					putch(' ');
					putch('\b');
					i -= 1;
					array[i] = '\0';	//Clear left character
				}
				continue;
			} else if (c == '\r')			//Enter key
			{
				if (i == 0)
					return INPUT_END; 
				break;
			} else {
				putch('\a');
				continue;
			}
		} else {
			//The max input characters is eight
			if (i > 7)
			{
				putch('\a');
				continue;
			} else {
				putch(c);
				array[i] = c;
				i++;
			}
		}
	}

	return 0;
}

/*+++++Display Bar Graph Function+++++
	Showing n data (toNum) of an array up as a Bar Chart,
	The value column is describling in "*"
*/
void dispGraph(int *ptr, int toNum)
{
	char arr[ROW][COL];
	int i, j;
	for (i = 0; i <  COL; ++i)
	{
		if (i == 0)
			printf("10|");
		else if (i == 5 )
			printf(" 5|");
		else if (i == 9 )
			printf(" 1|");
		else
			printf("  |");
		for (j = 0; j < toNum; ++j)
		{
			printf(" ");
			if ((i + ptr[j]) >= 10)
			{
				printf("*");
			}else
				printf(" ");
		}
		printf("\n");
	}
	printf("  +---------------------\n");
	printf("    1 2 3 4 5 6 7 8 9 10\n");
	printf("\n  ===End of program===\n");
}
