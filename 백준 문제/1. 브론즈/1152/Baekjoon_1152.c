#include<stdio.h>


int main()
{
	char text[1000002];
	int i = 0, count = 0, textCount = 0;
	fgets(text, sizeof(text), stdin);


	while (text[i] != '\n')
	{
		if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
		{
			textCount++;
		}

		if ((text[i] == '\0' || text[i] == ' ') && textCount != 0)
		{
			textCount = 0;
			count++;
		}
		i++;
	}

	if (textCount != 0)
	{
		count++;
	}


	printf_s("%d \n",count);

	return 0;
}