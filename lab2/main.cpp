#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void doxygen(FILE *F)
{
	bool func = true;
	bool end = false;
	bool comment_begun = false;
	int  func_num = 0;
	char sym = '\0';
	char sym1 = '\0';
	char sym2 = '\0';
	char c[5] = { 'f', 'u', 'n', 'c', '\0' };
	char ch = '\0';
	char ch1 = '\0';
	rewind(F);
	while (!feof(F))
	{
		sym = fgetc(F);
		switch (sym)
		{
		case '/':
			sym1 = fgetc(F);
			sym2 = fgetc(F);
			if ((sym1 == '*') && (sym2 == '*'))
			{
				while (fgetc(F) != '\\');
				func = true;
				for (int i = 0; i < 4; i++)
				{
					if (fgetc(F) != c[i])
					{
						func = false;
					}
				}
			}
			while (func == true)
			{
				func_num++;
				printf_s("\n%d)", func_num);
				end = false;
				while (end == false)
				{
					ch = fgetc(F);
					if (ch == '*')
					{
						ch1 = fgetc(F);
						if (ch1 == '/')
						{
							end = true;
							func = false;
						}
						else
						{
							printf_s("%c%c", ch, ch1);
							end = false;
						}
					}
					else if (ch == '\n')
					{
						end = true;
						func = false;
					}
					else
					{
						printf_s("%c", ch);
						end = false;
					}
				}
				break;
			}
			break;
		default:
			break;
		}
	}
	return;
}

int main(int argc, char *argv[])
{
	FILE *pF;
	char ch = '\0';
	pF = fopen(argv[1], "r");

	doxygen(pF);
	return 0;
}
