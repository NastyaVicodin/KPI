void menu()
	{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (WORD) ((6 << 4) | 15));
  	system("color 70");	
	system("cls");
    printf("\n\n\n\n\n\n                               *******************************************************\n");
	printf("                               *       Technology Collective Software Development    *\n");
	printf("                               *                Structures and Validation            *\n");
	printf("                               *              Author: Anastasia Lukyanenko           *\n");
	printf("                               *                      Group: KM-51                   *\n");
	printf("                               *******************************************************\n\n\n\n\n");
	cout << "           Choose the action:\n\n";
	cout << "         | 1 - student structure\n";
	cout << "         | 2 - teacher structure\n";
	cout << "         | 3 - laboratory work structure\n";
	cout << "         | 4 - quit\n";
	cout << "\n\n\n\n";
	cout << " Your choice: ";
	}
