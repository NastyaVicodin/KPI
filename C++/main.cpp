#include <iostream>
#include <string>
#include <conio.h>

#include "structures.h"
#include "get_choice.h"
#include "get_course.h"
#include "get_int.h"
#include "get_char.h"
#include "menu.h"

int main()
	{	
	student_info student;
	teacher_info teacher;
	laboratory_work_info laboratory_work;
	int choice;	
	
	do
		{
		menu();
		while (scanf("%d",&choice)!=1){ menu(); fflush(stdin);}
	
		if (choice == 1)
			{
			system("cls");
			get_char(&student.name, ">> Enter student's name (Example: Katty; *max length = 20; *first letter - capital):"); system("cls");
			get_char(&student.last, ">> Enter student's surname (Example: Smith; *max length = 20; *first letter - capital):"); system("cls");
			get_course(&student.course, ">> Enter student's course (Example: 1; *1 <= course <=6):"); system("cls"); 
			cout << ("\n");
			cout << (" >> Student: " + student.name + " " + student.last); cout << (" from "); cout << (student.course); cout << (" course");
			cout << "\n\n\n\n"; 
	    	system("pause");
			}
	
		if (choice == 2)
			{
			system("cls");
			get_char(&teacher.name, ">> Enter teacher's name (Example: Katty; *max length = 20; *first letter - capital):"); system("cls"); 	
			get_char(&teacher.last, ">> Enter teacher's surname (Example: Smith; *max length = 20; *first letter - capital):");	 system("cls"); 
			cout << ("\n");
			cout << (" >> Teacher: " + teacher.name + " " + teacher.last); cout << "\n\n\n\n"; 
	 		system("pause");
			}
		
		if (choice == 3)
			{
			system("cls");
			get_int(&laboratory_work.variant, ">> Enter variant of laboratory work (Example: 15; *max number = 99):\n"); system("cls");
			get_int(&laboratory_work.count_of_done_tasks, ">> Enter student's surname (Example: 10; *max number = 99):\n"); system("cls"); 	
			cout << ("\n");
			cout << (" >> Laboratory work:\n");
			cout << ("    -variant "); cout << (laboratory_work.variant); cout << ("\n");
			cout << ("    -count of done tasks "); cout << (laboratory_work.count_of_done_tasks);cout << "\n\n\n\n"; system("pause");
			}
				 
		if (choice == 4)
			{
			break;
			}
			
		} while (choice != 4);
	return 0;
	}
