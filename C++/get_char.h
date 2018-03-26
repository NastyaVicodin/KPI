void get_char(std::string* arg, const char* message)
	{
	printf("%s\n> ", message);
	char* letter = (char *)malloc(2*sizeof(char*));
	int string_length = 0;
	char pressed_key;
	
	do
		{
		pressed_key = _getch();
		if (pressed_key == '\b')
			{
			if (string_length > 0) string_length--;
			system("cls");
			printf("%s\n> ", message);
		
			int i;
			for (i = 0; i < string_length; i++)
				printf("%c",letter[i]);
			}
		else
			{
			if (('A' <= pressed_key && pressed_key <= 'Z') || ('a' <= pressed_key && pressed_key <= 'z'))
				{
				if (('a' <= pressed_key && pressed_key <= 'z') && (string_length >= 1) && (string_length < 20))
					{
					letter[string_length] = pressed_key;
					printf("%c",pressed_key);
					string_length++;
					} 
				else if (((pressed_key != 13) && (pressed_key != '\b')) && ((string_length >= 1) && ('A' <= pressed_key && pressed_key <= 'Z')))
					{ Beep(500, 500); }
			
		 		if (('A' <= pressed_key && pressed_key <= 'Z') && (string_length < 1))
				{
				letter[string_length] = pressed_key;
				printf("%c",pressed_key);
				string_length++;
				} 
				else if (((pressed_key != 13) && (pressed_key != '\b')) && ((string_length < 1) && ('a' <= pressed_key && pressed_key <= 'z')))
					{ Beep(500, 500); }
				}
				
			else if ((pressed_key != 13) && (pressed_key != '\b')) { Beep(500, 500); }
			}	
		}
		
	 while (pressed_key != 13 || string_length == 0);
	 
	cout << "\n\n"; 
	std::string word; word = "";
	int k;  
	std::string part_of_word;
	
	for (k = 0; k < string_length; k++)
		{
		part_of_word = letter[k];
		word = word + part_of_word;	
		}
		
	*arg = word;
	}