#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char file1[32];
	char file2[32];
	FILE *pF1;
	FILE *pF2;
	int k1 = 0, k2 = 0;

	if (argc != 3)
	{
		printf("\nERROR!\n");
		return 1;
	}

	if (sscanf(argv[1], "%s", &file1) < 1)
	{
		printf("\nerror!!!\n");
		return 1;
	}
	if (sscanf(argv[2], "%s", &file2) < 1)
	{
		printf("\nerror!\n");
		return 1;
	}

	fopen_s(&pF1, file1, "a+");
	fopen_s(&pF2, file2, "a+");

	int ent1 = 0; // количество строк в первом файле
	int ent2 = 0; // количество строк во втором файле
	char strsr[10]; // сравниваемая строка
	char str[10];

	int k = 0;

	for (int i = 0; i < 10; i++)
	{
		strsr[i] = '\0';
		str[i] = '\0';
	}

	while (!feof(pF1))
	{
		if (fgetc(pF1) == '\n')
		{
			ent1++;
		}
		else
		{
			k1++;
		}
	}
	ent1++;
	rewind(pF1);


	while (!feof(pF2))
	{
		if (fgetc(pF2) == '\n')
		{
			ent2++;
		}
		else
		{
			k2++;
		}
	}
	ent2++;
	rewind(pF2);

	for (int i = 0; i < ent1; i++)
	{
		fgets(strsr, 10, pF1);
		int len = strlen(strsr);
		if (i == ent1 - 1)
		{
			strsr[len] = '\0';
		}
		else
		{
			strsr[len - 1] = '\0';
		}

		for (int j = 0; j < ent2; j++)
		{

			fgets(str, 10, pF2);
			int len2 = strlen(str);
			if (j == ent2 - 1)
			{
				str[len2] = '\0';
			}
			else
			{
				str[len2 - 1] = '\0';
			}

			if (strcmp(strsr, str) == 0)
			{
				k++;
			}
		}
		if (k == 0)
		{
			printf_s("\nfile1.txt %d '%s'", i + 1, strsr);
		}
		rewind(pF2);
		k = 0;
	}
	rewind(pF1);

	for (int i = 0; i < ent2; i++)
	{
		fgets(strsr, 10, pF2);
		int len = strlen(strsr);
		if (i == ent2 - 1)
		{
			strsr[len] = '\0';
		}
		else
		{
			strsr[len - 1] = '\0';
		}

		for (int j = 0; j < ent1; j++)
		{

			fgets(str, 10, pF1);
			int len1 = strlen(str);
			if (j == ent1 - 1)
			{
				str[len1] = '\0';
			}
			else
			{
				str[len1 - 1] = '\0';
			}

			if (strcmp(strsr, str) == 0)
			{
				k++;
			}
		}
		if (k == 0)
		{
			printf_s("\nfile2.txt %d '%s'", i + 1, strsr);
		}
		rewind(pF1);
		k = 0;
	}
	fclose(pF1);
	fclose(pF2);
	return 0;
}
