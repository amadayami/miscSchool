#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "addMenu.h"
#include "editMenu.h"
#include "deleteMenu.h"
#include "viewMenu.h"
#include "pStructs.h"

void main_menu(){
	int *choice;
	printf("What would you like to do?\n");
	printf("1. Add data\n");
	printf("2. Edit data\n");
	printf("3. Delete data\n");
	printf("4. View data\n");
	printf("5. Use command line environment\n");
	printf("6. Exit\n");
	scanf("%d", &choice);
	switch(choice){
		case 1:
			add_Data();
			break;
		case 2:
			edit_Data();
			break;
		case 3:
			delete_Data();
			break;
		case 4:
			view_Data();
			break;
		case 5:
			//call custom environment start function
			break;
		case 6:
			//this needs to be tested!!
			printf("Exiting...\n");
			exit;
	}	
}

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
			//do stuff
		}
	}
	else if( strcmp(argv[1], "-add-class") == 0){
		printf("ADD CLASS\n");
		if(argc != 4) printf("Invalid number of arguments\n");
		else{
			//do stuff
		}
	}
	else if( strcmp(argv[1], "-add-assignment") == 0){
		printf("ADD ASSIGNMENT\n");
		if(argc != 8) printf("Invalid number of arguments\n");
		else{
			//do stuff
		}	
	}
	else if( strcmp(argv[1], "-add-grade") == 0){
		printf("ADD GRADE\n");
		if(argc != 10) printf("Invalid number of arguments\n");
		else{
			//do stuff
		}
	}
	else if( strcmp(argv[1], "-enroll") == 0){
		printf("ENROLL\N");
		if(argc != 6) printf("Invalid number of arguments\n");
		else{
			//do stuff
		}
	}
	else if( strcmp(argv[1], "-edit-student") == 0 ){
		printf("EDIT STUDENT\n");
		if(argc != 8) printf("Invalid number of arguments\n");
		else{
			//do stuff
		}	
	}
	else if( strcmp(argv[1], "-edit-class") == 0){
		printf("EDIT CLASS\n");
		if(argc != 6) printf("Invalid number of arguments\n");
		else{
			//do stuff
		}
	}
	else if( strcmp(argv[1], "-edit-assignment") == 0){
		printf("EDIT ASSIGNMENT\n");
		if(argc != 10) printf("Invalid number of arguments\n");
		else{
			//do stuff
		}
	}
	else if( strcmp(argv[1], "-edit-grade") == 0){
		printf("EDIT GRADE\n");
		if(argc != 10) printf("Invalid number of arguments\n");
		else{
			//do stuff
		}	
	}	
	else if( strcmp(argv[1], "-delete-student") == 0){
		printf("DELETE STUDENT\n");
		if(argc != 4) printf("Invalid number of arguments\n");
		else{
			//do stuff
		}	
	}
	else if( strcmp(argv[1], "-delete-class") == 0){
		printf("DELETE CLASS\n");
		if(argc != 4) printf("Invalid number of arguments\n");
		else{
			//do stuff
		}	
	}
	else if( strcmp(argv[1], "-delete-assignment") == 0){
		printf("DELETE ASSIGNMENT\n");
		if(argc != 6) printf("Invalid number of arguments\n");
		else{
			//do stuff
		}	
	}
	else if( strcmp(argv[1], "-delete-grade") == 0){
		printf("DELETE GRADE\n");
		if(argc != 8) printf("Invalid number of arguments\n");
		else{
			//do stuff
		}	
	}
	else if( strcmp(argv[1], "-drop") == 0 ){
		printf("DROP STUDENT\n");
		if(argc != 6) printf("Invalid number of arguments\n");
		else{
			//do stuff
		}
	}
	else if( strcmp(argv[1], "-view-s") == 0 ){
		printf("VIEW STUDENTS\n");
		if(argc != 2){
			printf("Extra arguments, ignoring...\n");
		}
		//do stuff
	}
	else if( strcmp(argv[1], "-view-c") == 0){
		printf("VIEW CLASS LIST\n");
		if(argc != 2){
			printf("Extra arguments, ignoring...\n");
		}
		//do stuff
	}
	else if( strcmp(argv[1], "-view-a") == 0){
		printf("VIEW ASSIGNMENTS\n");
		if(argc != 4) printf("Invalid number of arguments\n");
		else{
			//do stuff
		}
	}
	else if( strcmp(argv[1], "-view-g") == 0){
		printf("VIEW GRADES\n");
		//need to accomodate for class/student/average
	}
	else{
		printf("Unrecognized argument\n");
	}
	}
}
return 0;
}