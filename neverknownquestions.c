#include<stdio.h>
#include<string.h>
#include<time.h>

int main(){
	char one[] = "To show";
	char two[] = "Or to be shown";
	char three[] = "A question never";
	char four[] = "Never known not even by many to exist\n";
	int i, num;
	char asdf;
	srand(time(NULL));
	puts(one);
	puts(two);
	puts(three);
	puts(four);
	for(i = 0; i <= 10; i++){
		scanf("%c", &asdf);
		one[rand()%strlen(one)]++;
		puts(one);
		two[rand()%strlen(two)]++;
		puts(two);
		three[rand()%strlen(three)]++;
		puts(three);
		four[rand()%strlen(four)]++;
		puts(four);
	}
	puts("Opulent beginnings are seldom a dread; they help you relieve all the lies in your head.\nBut for the giving begits a sure vain; leave open a window and let in some rain.");
	return 0;
}
