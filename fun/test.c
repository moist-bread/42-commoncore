# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#include <ctype.h>

#define reset "\e[0m"
#define BRED "\e[1;31m"
#define WHT "\e[0;37m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define COLOR_RED     "\x1b[31m"
#define COLOR_RESET   "\x1b[0m"


void	picker(const char *landmark)
{
	printf("%s", landmark);
}

int inputprompt(void)
{
	int ret_value;

	printf(WHT "Please enter your choice (0-6): " reset);
	scanf("%d", &ret_value);
	return(ret_value);
}

void switchcase(void)
{
	int ret_value;
	ret_value = inputprompt();
	switch (ret_value)
	{
		case  0:
		case  1:
		case  2:
			break;
		case  3:
			picker("torre_de_belem");
			break;
		case  4:
			picker("torre_de_belem");
			break;
		case  5:
			picker("torre_de_belem");
			break;
		case  6:
			picker("torre_de_belem");
			break;	
		default:
			printf(WHT "That option doesn't exist\n" reset);
			switchcase();
	}

}
void greetings(void)
{
	printf(BRED "╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\n\n");
	printf("║" WHT "\t\tWELCOME TO THE 42 POSTAL SERVICE\t\t" BRED "║\n\n");
	printf("╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n\n");
	printf(WHT "We offer the most unique postcards from " YEL "Lisbon" WHT " and " BLU "Seoul" WHT "!!\n");
	printf(WHT "You simply pick from the available landmarks in our " BRED "POSTCARD GENERATOR" WHT ".\n\n");
	printf(BRED "\t╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\n\n");
	printf("\t║" WHT "\tPostcard Generator\t" BRED "║\n\n");
	printf("\t╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n\n");
	printf("\t║      " YEL "1. Belem Tower           " BRED "║\n");
	printf(YEL "\t       2. 25 de Abril Bridge   \n");
	printf(BRED "\t║      " YEL "3. Pena Palace           " BRED "║\n");
	printf("\t       " BLU "4. Cheongye River       \n");
	printf(BRED "\t║      " BLU "5. Gyeongbok Palace      " BRED "║\n");
	printf("\t       " BLU "6. N Seoul Tower        \n");
	printf(BRED "\t║                               ║\n");
	printf("\t╔ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\n");
	printf("\t║      " WHT "0. Exit                  " BRED "║\n");
	printf("\t╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n\n" reset);
}

int	main(void)
{
	greetings();
	switchcase();
	return (0);
}