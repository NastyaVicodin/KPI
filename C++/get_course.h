void get_course(int* n, const char *message)
	{
	printf("%s ", message);
	char *number = (char *)malloc(2*sizeof(char*));
	int string_length = 0;
	char pressed_key;
	
	do
		{
		pressed_key = _getch();
		if (pressed_key == '\b')
			{
			if (string_length > 0)string_length--;
				system("cls");
			printf("%s\n> ", message);
			int i;
			for (i = 0; i < string_length; i++)
				printf("%c", number[i]);
			}
		else
			{
			if ('1' <= pressed_key && pressed_key <= '6' && string_length < 1)
				{
				number[string_length] = pressed_key;
				string_length++;
				printf("%c", pressed_key);
				}	
			else if ((pressed_key != 13) && (pressed_key != '\b')) { Beep(500, 500); }
			}
	
		} while (pressed_key != 13 || string_length == 0);
		
	number[string_length] = '\0';
	*n = atoi(number);

	}