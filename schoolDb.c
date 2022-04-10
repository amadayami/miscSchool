#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "addMenu.h"
#include "editMenu.h"
#include "deleteMenu.h"
#include "viewMenu.h"
/*The top of the three interfaces can be found by typing
FIND: and the type */


/* FIND: custom environment interface
The rest of this is for my sake
*/
void environment()
{
//taken from the class website
	char c;
	char *in = malloc( 1000 );
	int i;
	int index = 0;
	int num_args = 1;
	int curr_arg = 0;
	int inc = 0;

	printf( "What would you like to do? " );

	while( ( c = getchar() ) != '\n' )
	{
		if ( c == ' ' )
			num_args++;

		in[index] = c;
		index++;
	}

	printf( "%s\n", in );

	index = 0;

	char **strs = malloc( sizeof( char * ) * num_args );

	while ( curr_arg <= num_args )
	{
		if( in[index] == ' ' || in[index] == '\0' )
		{
			strs[curr_arg] = malloc( index - inc + 1 );
			for ( i = inc; i < index; i++ )
			{
				strs[curr_arg][i - inc] = in[i];
			}
			strs[curr_arg][i - inc] = '\0';

			inc = index + 1;
			curr_arg++;
		}

		index++;
	}

	if ( num_args == 1 )
	{
		if ( strcmp( strs[0], "exit" ) == 0 )
			return;
	}
	
	if(strcmp(strs[0], "add") == 0){
		if(strcmp(strs[1], "student") == 0){
			char *first = strs[2];
			char *last = strs[3];
			char *ssn = strs[4];
			student_Create(first, last, ssn);
		}
		else if(strcmp(strs[1], "class") == 0){
			char *title = strs[2];
			class_Create(title);
		}
		else if(strcmp(strs[1], "assignment") == 0){
			int class_id = atoi(strs[2]);
			char *title = strs[3];
			int pointVal = atoi(strs[4]);
			assignment_Create(title, pointVal, class_id);
		}
		else if(strcmp(strs[1], "grade") == 0){
			int class_id = atoi(strs[2]);
			int assign_id = atoi(strs[3]);
			char *ssn = strs[4];
			int points = atoi(strs[5]);
			grade_Create(class_id, assign_id, ssn, points);
		}
		else{
			printf("I don't recognize what you want to add\n");
			printf("Enter new information or type exit\n");
			environment();
		}
	}
	else if(strcmp(strs[0], "enroll") == 0){
		int class_id = atoi(strs[1]);
		char *ssn = strs[2];
		enroll_Student(class_id, ssn);
	}
	else if(strcmp(strs[0], "edit") == 0){
		if(strcmp(strs[1], "student") == 0){
			char *ssn = strs[2];
			char *first = strs[3];
			char *last = strs[4];
			edit_Student(ssn, first, last);
		}
		else if(strcmp(strs[1], "class") == 0){
			int class_id = atoi(strs[2]);
			char *title = strs[3];
			edit_Class(class_id, title);
		}
		else if(strcmp(strs[1], "assignment") == 0){
			int class_id = atoi(strs[2]);
			int assignment_id = atoi(strs[3]);
			char *title = strs[4];
			int points = atoi(strs[5]);
			edit_Assignment(class_id, assignment_id, title, points);
		}
		else if(strcmp(strs[1], "grade") == 0){
			int class_id = atoi(strs[2]);
			int assignment_id = atoi(strs[3]);
			char *ssn = strs[4];
			int points = atoi(strs[5]);
			edit_Grade(class_id, assignment_id, ssn, points);
		}
		else{
			printf("I don't recognized what you want to add\n");
			printf("Enter new information or type exit\n");
			environment();
		}
	}
	else if(strcmp(strs[0], "delete") == 0){
		if(strcmp(strs[1], "student") == 0){
			char *ssn = strs[2];
			delete_Student(ssn);
		}
		else if(strcmp(strs[1], "class") == 0){
			int class_id = atoi(strs[2]);
			delete_Class(class_id);
		}
		else if(strcmp(strs[1], "assignment") == 0){
			int class_id = atoi(strs[2]);
			int assignment_id = atoi(strs[3]);
			delete_Assignment(class_id, assignment_id);
		}
		else if(strcmp(strs[1], "grade") == 0){
			int class_id = atoi(strs[2]);
			int assignment_id = atoi(strs[3]);
			char *ssn = strs[4];
			delete_Grade(class_id, assignment_id, ssn);
		}
		else{
			printf("I don't recognize what you want to delete\n");
			printf("Enter new information or type exit\n");
			environment();
		}
	}
	else if(strcmp(strs[1], "drop") == 0){
		int class_id = atoi(strs[2]);
		char *ssn = strs[3];
		drop_Student(class_id, ssn);
	}
	else if(strcmp(strs[0], "view") == 0){
		if(strcmp(strs[1], "students") == 0){
			view_Students();
		}
		else if(strcmp(strs[1], "classes") == 0){
			view_Classes();
		}
		else if(strcmp(strs[1], "assignments") == 0){
			int class_id = atoi(strs[2]);
			view_AssignProv(class_id);
		}
		else if(strcmp(strs[1], "grades") == 0){
			//need to account for two different ways
			//of gathering the information
		}
		else if(strcmp(strs[1], "average") == 0){
			int class_id = atoi(strs[3]);
			int assignment_id = atoi(strs[4]);
			//view grades
		}
		else{
			printf("I don't recognize what you want to view\n");
			printf("Enter new information or type exit\n");
			environment();
		}
	}
	else{
		printf("I do not recognize that command\n");
		printf("Enter new information or type exit\n");
		environment();
	}
	
	environment();
}


/* FIND: menu interface
I'm including this multiline comment to distinguish 
between the three interfaces, for my sake */
void main_menu(){
	int choice = 0;
	printf("What would you like to do?\n");
	printf("1. Add data\n");
	printf("2. Edit data\n");
	printf("3. Delete data\n");
	printf("4. View data\n");
	printf("5. Use command line environment\n");
	printf("6. Exit\n");
	choice = getchar() - '0';
	printf("You chose %d\n", choice);
	if( choice == 1 ){
		add_Data();
	}
	else if( choice == 2){
		//edit data
	}
	else if(choice == 3){
		//delete data
	}
	else if(choice == 4){
		view_Data();
	}
	else if( choice == 5 ){
		//this is the name of the method that opens
		//the custom environment, so keep an eye on this
		environment();
	}
	else if(choice == 6){
		return;
	}
	else{
		printf("Invalid selection! Exiting...\n");
		return;
	}
}

/*FIND: command line arguments interface
FIND: CLI interface
*/

int main(int argc, char *argv[]){
if(argc == 1){
	main_menu();
	return 0;
}
else{
	if( strcmp(argv[1], "-add-student") == 0 ){
		printf("ADD STUDENT\n");
		if(argc != 8) printf("Invalid number of arguments\n");
		else{
			int i;
			char *firstName;
			char *lastName;
			char *ssn;
			for(i = 2; i < 7; i = i + 2){
				if( strcmp(argv[i], "--f") == 0 ){
					if( strcmp(argv[i + 1], "--l") == 0 ){
						printf("Incorrect order!!\n");
						return 0;
					}
					if( strcmp(argv[i + 1], "--s") == 0 ){
						printf("Incorrect order!!\n");
						return 0;
					}
					else{
						firstName = argv[i + 1];
					}	
				}
				else if( strcmp(argv[i], "--l") == 0 ){
					if( strcmp(argv[i + 1], "--f") == 0 ){
						printf("Incorrect order!!\n");
						return 0;
					}
					if( strcmp(argv[i + 1], "--s") == 0 ){
						printf("Incorrect order!!\n");
						return 0;
					}
					else{
						lastName = argv[i + 1];
					}	
				}
				else if( strcmp(argv[i], "--s") == 0 ){
					if( strcmp(argv[i + 1], "--f") == 0 ){
						printf("Incorrect order!!\n");
						return 0;
					}
					if( strcmp(argv[i + 1], "--l") == 0 ){
						printf("Incorrect order!!\n");
						return 0;
					}
					else{
						ssn = argv[i + 1];
					}	
				}
				else{
					printf("Unrecognized flag!!\n");
					return 0;
				}	
			}
			student_Create(firstName, lastName, ssn);
		}	
	}
	else if( strcmp(argv[1], "-add-class") == 0){
		printf("ADD CLASS\n");
		if(argc != 4) printf("Invalid number of arguments\n");
		else{
			char *title;
			if( strcmp(argv[2], "--t") == 0 ){
				title = argv[3];
			}	
			else{
				printf("Unrecognized flag!!\n");
				return 0;
			}
			class_Create(title);
		}
	}
	else if( strcmp(argv[1], "-add-assignment") == 0){
		printf("ADD ASSIGNMENT\n");
		if(argc != 8) printf("Invalid number of arguments\n");
		else{
			int i;
			int class_id;
			char *title;
			int points;
			for(i = 2; i < 7; i = i + 2){
				if( strcmp(argv[i], "--cid") == 0 ){
					if( strcmp(argv[i + 1], "--t") == 0 ){
						printf("Incorrect order!!\n");
						return 0;
					}
					if( strcmp(argv[i + 1], "--p") == 0 ){
						printf("Incorrect order!!\n");
						return 0;
					}
					else{
						class_id = atoi(argv[i + 1]);
					}	
				}
				else if( strcmp(argv[i], "--t") == 0 ){
					if( strcmp(argv[i + 1], "--cid") == 0 ){
						printf("Incorrect order!!\n");
						return 0;
					}
					if( strcmp(argv[i + 1], "--p") == 0 ){
						printf("Incorrect order!!\n");
						return 0;
					}
					else{
						title = argv[i + 1];
					}	
				}
				else if( strcmp(argv[i], "--p") == 0 ){
					if( strcmp(argv[i + 1], "--t") == 0 ){
						printf("Incorrect order!!\n");
						return 0;
					}
					if( strcmp(argv[i + 1], "--cid") == 0 ){
						printf("Incorrect order!!\n");
						return 0;
					}
					else{
						points = atoi(argv[i + 1]);
					}	
				}
				else{
					printf("Unrecognized flag!!\n");
					return 0;
				}
			}
			assignment_Create(title, points, class_id);
		}	
	}
	else if( strcmp(argv[1], "-add-grade") == 0){
		printf("ADD GRADE\n");
		if(argc != 10) printf("Invalid number of arguments\n");
		else{
			int i;
			int class_id;
			int assign_id;
			char *ssn;
			int points;
			for(i = 2; i < 9; i = i + 2){
				if( strcmp(argv[i], "--cid") == 0){
					if(strcmp(argv[i + 1], "--aid") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}	
					if(strcmp(argv[i + 1], "--s") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}	
					if(strcmp(argv[i + 1], "--p") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else{
						class_id = atoi(argv[i + 1]);
					}	
				}
				else if(strcmp(argv[i], "--aid") == 0){
					if(strcmp(argv[i + 1], "--cid") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}	
					if(strcmp(argv[i + 1], "--s") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}	
					if(strcmp(argv[i + 1], "--p") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else{
						assign_id = atoi(argv[i + 1]);
					}	
				}
				else if(strcmp(argv[i], "--s") == 0){
					if(strcmp(argv[i + 1], "--aid") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}	
					if(strcmp(argv[i + 1], "--cid") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}	
					if(strcmp(argv[i + 1], "--p") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else{
						ssn = argv[i + 1];
					}	
				}
				else if(strcmp(argv[i], "--p") == 0){
					if(strcmp(argv[i + 1], "--aid") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}	
					if(strcmp(argv[i + 1], "--s") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}	
					if(strcmp(argv[i + 1], "--cid") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else{
						points = atoi(argv[i + 1]);
					}	
				}
				else{
					printf("Unrecognized flag!!\n");
					return 0;
				}	
			}
			grade_Create(class_id, assign_id, ssn, points);
		}
	}
	else if( strcmp(argv[1], "-enroll") == 0){
		printf("ENROLL\n");
		if(argc != 6) printf("Invalid number of arguments\n");
		else{
			int i;
			int class_id;
			char *ssn;
			for(i = 2; i < 5; i = i + 2){
				if(strcmp(argv[i], "--cid") == 0){
					if(strcmp(argv[i + 1], "--s") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else{
						class_id = atoi(argv[i + 1]);
					}
				}
				else if(strcmp(argv[i], "--s") == 0){
					if(strcmp(argv[i + 1], "--cid") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else{
						ssn = argv[i + 1];
					}
				}
				else{
					printf("Unrecognized flag!!\n");
					return 0;
				}
			}
			enroll_Student(class_id, ssn);
		}
	}
	else if( strcmp(argv[1], "-edit-student") == 0 ){
		printf("EDIT STUDENT\n");
		if(argc != 8) printf("Invalid number of arguments\n");
		else{
			int i;
			char *ssn;
			char *first;
			char *last;
			for(i = 2; i < 7; i = i + 2){
				if(strcmp(argv[i], "--s") == 0){
					if(strcmp(argv[i + 1], "--f") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					if(strcmp(argv[i + 1], "--l") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else{
						ssn = argv[i + 1];
					}
				}
				else if(strcmp(argv[i], "--f") == 0){
					if(strcmp(argv[i + 1], "--s") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					if(strcmp(argv[i + 1], "--l") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else{
						first = argv[i + 1];
					}
				}
				else if(strcmp(argv[i + 1], "--l") == 0){
					if(strcmp(argv[i + 1], "--f") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					if(strcmp(argv[i + 1], "--s") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else{
						last = argv[i + 1];
					}
				}
				else{
					printf("Unrecognized flag!!\n");
					return 0;
				}
			}
			edit_Student(ssn, first, last);
		}	
	}
	else if( strcmp(argv[1], "-edit-class") == 0){
		printf("EDIT CLASS\n");
		if(argc != 6) printf("Invalid number of arguments\n");
		else{
			int i;
			int class_id;
			char *title;
			for(i = 2; i < 5; i = i + 2){
				if(strcmp(argv[i], "--cid") == 0){
					if(strcmp(argv[i + 1], "--t") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else{
						class_id = atoi(argv[i + 1]);
					}
				}
				else if(strcmp(argv[i], "--t") == 0){
					if(strcmp(argv[i + 1], "--cid") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else{
						title = argv[i + 1];
					}
				}
				else{
					printf("Unrecognized flag!!\n");
					return 0;
				}
			}
			edit_Class(class_id, title);
		}
	}
	else if( strcmp(argv[1], "-edit-assignment") == 0){
		printf("EDIT ASSIGNMENT\n");
		if(argc != 10) printf("Invalid number of arguments\n");
		else{
			int i;
			int class_id;
			int assign_id;
			char *title;
			int points;
			for(i = 2; i < 9; i = i + 2){
				if(strcmp(argv[i], "--cid") == 0){
					if(strcmp(argv[i + 1], "--aid") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else if(strcmp(argv[i + 1], "--t") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else if(strcmp(argv[i + 1], "--p") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else{
						class_id = atoi(argv[i + 1]);
					}
				}
				else if(strcmp(argv[i], "--aid") == 0){
					if(strcmp(argv[i + 1], "--cid") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else if(strcmp(argv[i + 1], "--t") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else if(strcmp(argv[i + 1], "--p") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else{
						assign_id = atoi(argv[i + 1]);
					}
				}
				else if(strcmp(argv[i], "--t") == 0){
					if(strcmp(argv[i + 1], "--aid") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else if(strcmp(argv[i + 1], "--cid") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else if(strcmp(argv[i + 1], "--p") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else{
						title = argv[i + 1];
					}
				}
				else if(strcmp(argv[i], "--p") == 0){
					if(strcmp(argv[i + 1], "--aid") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else if(strcmp(argv[i + 1], "--t") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else if(strcmp(argv[i + 1], "--cid") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else{
						points = atoi(argv[i + 1]);
					}
				}
				else{
					printf("Unrecognized flag!!\n");
					return 0;
				}
			}
			edit_Assignment(class_id, assign_id, title, points);
		}
	}
	else if( strcmp(argv[1], "-edit-grade") == 0){
		printf("EDIT GRADE\n");
		if(argc != 10) printf("Invalid number of arguments\n");
		else{
			int i;
			int class_id;
			int assign_id;
			char *ssn;
			int points;
			for(i = 2; i < 9; i = i + 2){
				if(strcmp(argv[i], "--cid") == 0){
					if(strcmp(argv[i + 1], "--aid") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else if(strcmp(argv[i + 1], "--s") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else if(strcmp(argv[i + 1], "--p") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else{
						class_id = atoi(argv[i + 1]);
					}
				}
				else if(strcmp(argv[i], "--aid") == 0){
					if(strcmp(argv[i + 1], "--cid") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else if(strcmp(argv[i + 1], "--s") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else if(strcmp(argv[i + 1], "--p") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else{
						assign_id = atoi(argv[i + 1]);
					}
				}
				else if(strcmp(argv[i], "--s") == 0){
					if(strcmp(argv[i + 1], "--aid") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else if(strcmp(argv[i + 1], "--cid") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else if(strcmp(argv[i + 1], "--p") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else{
						ssn = argv[i + 1];
					}
				}
				else if(strcmp(argv[i], "--p") == 0){
					if(strcmp(argv[i + 1], "--aid") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else if(strcmp(argv[i + 1], "--s") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else if(strcmp(argv[i + 1], "--cid") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else{
						points = atoi(argv[i + 1]);
					}
				}
				else{
					printf("Unrecognized flag!!\n");
					return 0;
				}
			}
			edit_Grade(class_id, assign_id, ssn, points);
		}	
	}	
	else if( strcmp(argv[1], "-delete-student") == 0){
		printf("DELETE STUDENT\n");
		if(argc != 4) printf("Invalid number of arguments\n");
		else{
			char *ssn;
			if(strcmp(argv[2], "--s") == 0){
				ssn = argv[3];
				delete_Student(ssn);
			}
			else{
				printf("Unrecognized flag!!\n");
				return 0;
			}
		}	
	}
	else if( strcmp(argv[1], "-delete-class") == 0){
		printf("DELETE CLASS\n");
		if(argc != 4) printf("Invalid number of arguments\n");
		else{
			int class_id;
			if(strcmp(argv[2], "--cid") == 0){
				class_id = atoi(argv[3]);
				delete_Class(class_id);
			}
			else{
				printf("Unrecognized flag!!\n");
				return 0;
			}
		}	
	}
	else if( strcmp(argv[1], "-delete-assignment") == 0){
		printf("DELETE ASSIGNMENT\n");
		if(argc != 6) printf("Invalid number of arguments\n");
		else{
			int i;
			int class_id;
			int assign_id;
			for(i = 2; i < 5; i = i + 2){
				if(strcmp(argv[i], "--cid") == 0){
					if(strcmp(argv[i + 1], "--aid") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else{
						class_id = atoi(argv[i + 1]);
					}
				}
				else if(strcmp(argv[i], "--aid") == 0){
					if(strcmp(argv[i + 1], "--cid") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else{
						assign_id = atoi(argv[i + 1]);
					}
				}
				else{
					printf("Unrecognized flag!!\n");
					return 0;
				}
			}
			delete_Assignment(class_id, assign_id);
		}	
	}
	else if( strcmp(argv[1], "-delete-grade") == 0){
		printf("DELETE GRADE\n");
		if(argc != 8) printf("Invalid number of arguments\n");
		else{
			int i;
			int class_id;
			int assign_id;
			char *ssn;
			for(i = 2; i < 7; i = i + 2){
				if(strcmp(argv[i], "--cid") == 0){
					if(strcmp(argv[i + 1], "--aid") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					if(strcmp(argv[i + 1], "--s") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else{
						class_id = atoi(argv[i + 1]);
					}
				}
				else if(strcmp(argv[i], "--aid") == 0){
					if(strcmp(argv[i + 1], "--aid") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					if(strcmp(argv[i + 1], "--s") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else{
						assign_id = atoi(argv[i + 1]);
					}
				}
				else if(strcmp(argv[i], "--s") == 0){
					if(strcmp(argv[i + 1], "--aid") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					if(strcmp(argv[i + 1], "--cid") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else{
						ssn = argv[i + 1];
					}
				}
				else{
					printf("Unrecognized flag!!\n");
					return 0;
				}
			}
			delete_Grade(class_id, assign_id, ssn);
		}	
	}
	else if( strcmp(argv[1], "-drop") == 0 ){
		printf("DROP STUDENT\n");
		if(argc != 6) printf("Invalid number of arguments\n");
		else{
			int i;
			int class_id;
			char *ssn;
			for(i = 2; i < 5; i = i + 2){
				if(strcmp(argv[i], "--cid") == 0){
					if(strcmp(argv[i + 1], "--s") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else{
					class_id = atoi(argv[i + 1]);
					}	
				}
				else if(strcmp(argv[i], "--s") == 0){
					if(strcmp(argv[i + 1], "--cid") == 0){
						printf("Incorrect order!!\n");
						return 0;
					}
					else{
						ssn = argv[i + 1];
					}	
				}
				else{
					printf("Unrecognized flag!!\n");
					return 0;
				}
			}
			drop_Student(class_id, ssn);
		}
	}
	else if( strcmp(argv[1], "-view-s") == 0 ){
		printf("VIEW STUDENTS\n");
		if(argc != 2){
			printf("Extra arguments, ignoring...\n");
		}
		view_Students();
	}
	else if( strcmp(argv[1], "-view-c") == 0){
		printf("VIEW CLASS LIST\n");
		if(argc != 2){
			printf("Extra arguments, ignoring...\n");
		}
		view_Classes();
	}
	else if( strcmp(argv[1], "-view-a") == 0){
		printf("VIEW ASSIGNMENTS\n");
		if(argc != 4) printf("Invalid number of arguments\n");
		else{
			int class_id;
			if( strcmp(argv[2], "-cid") == 0 ){
				class_id = atoi( argv[3] );
				view_AssignProv(class_id);
			}	
			else{
				printf("Unrecognized flag!!\n");
				return 0;
			}
		}
	}
	else if( strcmp(argv[1], "-view-g") == 0){
		printf("VIEW GRADES\n");
		//need to accomodate for class/student/average
	}
	else{
		printf("Unrecognized argument\n");
	}
	return 0;
}
}