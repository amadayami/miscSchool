/*  Name: Amadaya Michael
	Date: February 13, 2019
*/
#include <stdio.h>
int main(){
	int input;
	int number = 0;
	int outputI = 0;
	int outputJ = 1;
	printf("Which number in the sequence?\n");
	input = getchar();
	while(input != '\n'){
		number = (number * 10) + (input - '0');
		input = getchar();
	}
	if(number == 1) printf("%d\n", 0);
	else{
		int i;
		for(i = 1; i < number; i++){
			int temp = outputJ;
			outputJ = outputI + outputJ;
			outputI = temp;
		}
		printf("%d\n", outputI);
	}
	return 0;
}