#include <stdio.h>  // stdio : stands for : standard input and output ( data streaming ) 
#include <stdlib.h>  // stdlid : stands for : standard library ... it can included in c++ by write ( using namespace std )
#include <string.h>
#include <time.h>

typedef struct student {
	
	long int ssn ;            // all data that belong to the student 
	
	int number ;
	
	char name [40] , status   ;

	float arab , eng , math , scien  , sum;
	
	float percent  ;
	
} st ;           // typedef : make a shortcut to the long words to be shortest ; so  struct student become st ;


void get_choise ();  //  get the user choise 

void add_student (FILE *f , char * file_name);  // add  a number of students and acceppt their data 

void calc (st * students , int num ,  FILE *f ,char  *file_name);  // make a mathmatics operations on the student data 

void write_file(st  *students , int num , FILE *f , char * file_name);  // file stream : print the data of the student in a text file ;

void search_student(FILE *f , char * file_name);  //  search about a student whose data is written in the file 

void  delete_student(FILE *f , char * file_name); // delete a student,s data from the text file

void  update_student(FILE *f , char * file_name); // update a student data ;

/* ARGUMENTES THAT THE FUNCTION NEED :
 
 students : is a variable whose data type is struct . hold the entire data of the student ;
 
 num : is the number of the students ;
 
 f : is a file pointer that is needed to open the file , stream the data to file and close it ;
 
 file name : is the file name to open and write the data into it ;
 */

int main(void){

	// keep track the time that the user spent using the program ;
	
    time_t start = time(0); // calc number of secondes from 1970 to now ;
	
	get_choise();
	
	time_t end = time(0);    //calc number of secondes from 1970 to now : of course after excution of the program .
	
	int result = difftime(end , start) +3.8 ; // 3.8 is an error ratio ;
	
	if( result > 50)
	
	printf("YOU HAVE TOKE %d SECONDES (PROPAGATION DELAY TIME). SO LONG .." , result);
	
    else

    printf("YOU HAVE TOKE %d SECONDES (PROPAGATION DELAY TIME). SO FAST  .." , result);

     system("pause");
     
	 return 0;
}
void get_choise (){

         FILE *f ;
         
    char file_name [20] = "Studentes Data.txt"; // two lines belong to creating the file and needed by all functions ;

   char choise [8] = "" ;
   
   printf( "                       _____________________SCHOOL MANAGEMENT PROGRAM______________________\n\n");

loop:
   
   printf(" WRITE WHAT DO YOU WANT TO DO [ADD , SEARCH , UPDATE , DELETE] DATA OF STUDENT OR WRITE EXIT TO CLOSE ! : ");
   
   scanf("%s" , choise);
   
   if(strcmp(choise , "add")== 0)  // strcmp : string compare function : return a zero if the argumentes are equal ;
   
    add_student(f , file_name);
   
   else if (strcmp(choise , "search") == 0)
   
    search_student(f , file_name);
   
   else if (strcmp (choise ,"update") == 0)
   
    update_student(f , file_name);
    
   else if (strcmp (choise , "delete") == 0)
   
    delete_student(f , file_name);
   
   else if(strcmp(choise , "exit")==0)
   
   exit(0);
   
   else
   {
   
   printf("ERROR : WRITE A SPECIFIC CHOISE ! \n");	

	goto loop;
	
	}
}
void add_student (FILE *f , char *file_name){
	
	int num ;
	
	printf(" OK___ENTER THE NUMBER OF STUDENTES YOU WANT TO ADD THEM : \n\n");
	
	scanf("%d" , &num);
	
	if(num <= 0)
	
	printf("LOGIC ERROR : NUMBER OF STUDENTS MUST BE GREATER THAN 0 !! \n");
	
	else
	{      // make a dynamic memorey allocation using the malloc function : to reserve a memorey space for the student,s data ;
	 
	st * students = (st *) malloc (sizeof(st)*num);
	
	if (students == NULL)
	{
		
		printf("ERROR : CAN NOT RESERVE A MEMOREY SPACE FOR THE STUDENTES !\n");
		
		exit(0);
	}
	else{
	
	printf("______ENTER THE DATA ( SSN , NAME , SUBJECTS MARKS ) FOR %d STUDENTES_______\n" , num);
	
	printf("______________________________________________________\n");
	
	for(int i=0 ; i < num ; i++){        // acceppt the data of the students ;
		
		if(i== 0)
		
		printf("DATA OF THE %d st STUDENT .\n" , i+1);           // it,s good to handle the data to save it correct 
		
		else if (i == 1)
		
		printf("DATA OF THE %d cd STUDENT .\n" , i+1);
		
		else if (i == 2)
		
		printf("DATA OF THE %d rd STUDENT .\n" , i+1);
		
		else
		
		printf("DATA OF THE %d th STUDENT .\n" , i+1);
		
		printf(" SSN :  ");
		
		scanf("%d" , &students[i].ssn);
		
		if(students[i].ssn <= 0)
		{
			printf("ERROR : SSN MUST BE POSITIVE !___ WILL BE 0 __\n");
			
			students[i].ssn = 0;
			
		}
		printf(" NAME :  ");
		
		scanf("%s" , &students[i].name);
		
		// marks
		printf(" _____MARKS______\n");
		
		printf("ARABIC : ");
		
		scanf("%f" , &students[i].arab);
		
		if(students[i].arab >100)
		{
			printf("THE MARKS THAT LARGER THAN 100 WILL BE 100 .!\n");
		
		    students[i].arab = 100 ;
		}
		else if(students[i].arab <0){
			
			printf("THE MARKS THAT SMALLER THAN 0 WILL BE 0 .!\n");
			
			students[i].arab = 0;
		}
	    printf("MATH : ");
		
		scanf("%f" , &students[i].math);
			
		if(students[i].math >100)
		{
			printf("THE MARKS THAT LARGER THAN 100 WILL BE 100 .!\n");
		
		    students[i].math = 100 ;
		}
		else if(students[i].math <0){
			
			printf("THE MARKS THAT SMALLER THAN 0 WILL BE 0 .!\n");
			
			students[i].math = 0;
		}
		printf("ENGLISH : ");
		
		scanf("%f" , &students[i].eng);
		
		if(students[i].eng >100)
		{
			printf("THE MARKS THAT LARGER THAN 100 WILL BE 100 .!\n");
		
		    students[i].eng = 100 ;
		}
		else if(students[i].eng <0){
			
			printf("THE MARKS THAT SMALLER THAN 0 WILL BE 0 .!\n");
			
			students[i].eng = 0;
		}
		printf("SCIENCE : ");
		
		scanf("%f" , &students[i].scien);
		
	    if(students[i].scien >100)
		{
			printf("THE MARKS THAT LARGER THAN 100 WILL BE 100 .!\n");
		
		    students[i].scien = 100 ;
		}
		else if(students[i].scien <0){
			
			printf("THE MARKS THAT SMALLER THAN 0 WILL BE 0 .!\n");
			
			students[i].scien = 0;
		}
		printf("__________________________________________________________\n");

	}	
	// calculate the sum and the percent and status ;
	
	calc (students , num , f , file_name);
	
	printf(" THIS DATA WILL BE STORED IN THE FILE WITH THIS FORM !\n");
	
	// print data on screen 
	
	printf( " NUMBER | SSN | NAME | ARABIC | ENGLISH | MATH | SCIENCE | SUM | PERCENT | STATUS | \n");
	
		   for(int i= 0 ; i< num ; i++)
	   	
	   	printf( "  %d \t| %d \t| %s \t| %.1f \t| %.1f \t| %.1f \t| %.1f \t| %.1f \t| %.1f \t| %c \t|\n",students[i].number , students[i].ssn , students[i].name ,  
		   
		students[i].arab , students[i].eng ,students[i].math , students[i].scien , 
		
		students[i].sum , students[i].percent , students[i].status);
		    
	   	// call the function write file to store these data in the file ;
	   	
		 write_file( students , num  , f , file_name);
	}          
	
}

  get_choise();
}
void calc (st * students , int num ,FILE *f , char *file_name ){
	
	// mathmatics operation on marks to calculate the sum , percent and the status of the student ;
	
	for (int i = 0 ; i< num ; i++){
		
		students[i].sum = students[i].arab+students[i].eng+students[i].math+students[i].scien ;
		
		students[i].percent = ((students[i].sum *100)/400);
		
		if(students[i].percent>=85 && students[i].percent <= 100)
		
		students[i].status = 'A';
		
		
		else if(students[i].percent>=75 && students[i].percent <= 85)
		
		students[i].status = 'B';
		
		
		else if(students[i].percent>=65 && students[i].percent <= 75)
		
		students[i].status = 'C' ;
		
		
		else if(students[i].percent>=50 && students[i].percent <= 65)
		
		students[i].status = 'D';
		
		else
		
		students[i].status = 'F';
	}
	// of course we append to store this data under an old data : so we should know the last student,s number ; 
	
	// go to file and get the number of the last student ;
	
	int first_num  , total_lines = 0;
	
	f = fopen (file_name , "a+");
	
	if( fscanf(f , "%d" , &first_num) == EOF )
	{

	first_num = 0 ;

    printf("NOTE : THE FILE IS EMPTY . THERE ARE NO STUDENTS YET !...\n");
    
    for (int i = 1 ; i<=num ; i++)
    
    students[i-1].number = i ;
    
  }
  else
  {
      rewind(f) ;  // the function rewind () : return the pointer or the cursor to the start point (begining) of the file 
      
      fscanf(f , "%d" , &first_num) ;
      
	char ch ;
	
	while (fscanf(f ,"%c" , &ch) != (EOF)){
		
		if((ch == '\n'))  // count the number of lines that the file contain ;
		
		total_lines ++ ;
	}
	
	total_lines += (first_num-1) ;
	
	printf("THE FILE CONTAIN %d STUDENT ..." , total_lines++);
	
	// assign numbers to students ;
	
	int i = 0 ;
	
	while (i < num){
		
		students[i].number = total_lines ;
		
		i++;
		
		total_lines++;
	}
	
	fclose(f) ;  // function fclose : to close the file ;
 }
}
void write_file(st  *students , int num , FILE *f  , char *file_name) {
	
	
// mode is : a ( appending ) to write the new student,s data under the old data ;
	
	 f = fopen(file_name , "a+");
	
	if(f == NULL){
		
		printf("CAN NOT CREATE THE FILE TO STORE THE DATA OF THE STUDENTES ! \n");
		
		free(students);  // function free () : is a memorey allocation tool it,s used to free a reserved memorey space ;
		
		exit(0);
		
	}
	else{
		
		char choise[5];
		
		printf("DELETE THE OLD DATA (yes) . OR APPEND TO STORE THIS DATA UNDER THE OLD DATA (no)\n");
		
		printf("ENTER YOUR CHOISE : ");
		
		scanf("%s" , choise);
	
	loop :
		
	if(strcmp(choise , "yes")==0){
		
   f = fopen(file_name , "w+");    // w+ mode : causes to remove the exist data and start writing . using it instead of remove() function ;
	
	printf("DONE : THE OLD DATA ARE REMOVED \n");
	
	
				for(int i= 0 ; i< num ; i++)
			   	
			   	fprintf( f , " %d \t| %d \t| %s \t| %.1f \t| %.1f \t| %.1f \t| %.1f \t| %.1f \t| %.1f \t| %c \t|\n", students[i].number , students[i].ssn , students[i].name ,  
				   
				students[i].arab , students[i].eng ,students[i].math , students[i].scien , 
				
				students[i].sum , students[i].percent , students[i].status);
		        
// function fprintf() : to print the formatted data to the file ;
    
	}
		else if (strcmp(choise , "no")==0)
		{
		
	printf("OK : THE OLD DATA ARE STILL STORED \n");
	
		for(int i= 0 ; i< num ; i++)
	   	
	   	fprintf( f , " %d \t| %d \t| %s \t| %.1f \t| %.1f \t| %.1f \t| %.1f \t| %.1f \t| %.1f \t| %c \t|\n",students[i].number , students[i].ssn , students[i].name ,  
		   
		students[i].arab , students[i].eng ,students[i].math , students[i].scien , 
		
		students[i].sum , students[i].percent , students[i].status);

// printing the data without removing the old data ; 
}
	else
	{
	
	printf("ERROR : WRITE YES OR NO TO DELETE THE OLD DATA \n");	
     
     scanf("%s" , choise);
     
     goto loop ;
 }
	   fclose(f);

	free(students);
	
	get_choise(); // go to the begining of the program ;
}
}
void search_student( FILE * f ,  char * file_name){
	
	f = fopen(file_name , "r");       // open the file in the reading mode ;
	
	char  str [160]  , choise [8];  char  temp [15] , name [15] ;     

	loop: // str :  to hold the entire line from file and print it ;
	
	// name , temp : to read the number or the name of the student and search about it . it,s ok string (array of character) can hold an integer values  
            
            int result = 0;  // increase  the result if the student is exist ;
            
       printf("YOU CAN SEARCH BY NAME OR NUMBER OF STUDENTS WRITE YOUR WAY : ");
       
       scanf("%s" , choise);  // two ways to search ;
       
       if(strcmp(choise , "name") == 0)
       {
	      
	      
		printf ("OK ENTER THE NAME OF THE STUDENT : ");
	
		scanf("%s" , name);
		
		while (fscanf(f , "%s" , temp) != EOF){
			
			if(strcmp(name, temp ) == 0)
			{
				printf(" THE STUDENT IS FOUND ..\n");
				
				printf( "        |ARABIC | ENGLISH| MATH | SCIENCE| SUM    | PERCENT| STATUS | \n");
				
				fgets(str , 160 , f);
			
				puts(str);  // print the data of the student on the screen ;
			
				result ++ ; 

			}
		}
		
		if(result == 0)
		
		printf("THE STUDENT IS NOT EXIST !\n");	
	
}

         else if(strcmp(choise , "number") == 0)
         {
         	      
		printf ("OK ENTER THE NUMBER OF THE STUDENT : ");         // as before
	
		scanf("%s" , name);
		
		while( fscanf(f , "%s" , temp) != EOF )           
		{
          
          
			if(strcmp (name , temp) == 0)
			{	
				printf(" THE STUDENT IS FOUND ..\n");
				
				printf( "        |SSN   | NAME | ARABIC | ENGLISH| MATH | SCIENCE| SUM    | PERCENT| STATUS | \n");
			
				fgets(str , 160 , f);
			
				puts(str); 
				
				result ++ ;
				
			}
		}
		
		if(result == 0)
		
		printf("THE STUDENT IS NOT EXIST !\n");
}                                                                // end
    char again [5] ;

   printf("SEARCH AGAIN : ");
   
   scanf("%s" , again);
   
   if(strcmp(again , "yes" ) == 0 )
   
  goto loop ;
  	
  	else if (strcmp(again , "no" ) == 0)
  {
  
     fclose (f);
     
     get_choise();
}
    else
    {
	
    printf ("INCORRECT CHOISE ... MAIN MENU : \n");
    
     fclose (f);
     
     get_choise();
}
}
void  delete_student(FILE *f , char * file_name){
	
	loop :
		
	int choise ;
	
	printf("____ TO DELETE THE ENTIRE FILE PRESS 1 . IF A SPECIFIC STUDENT PRESS 2 _____ :");
	
	scanf("%d" , &choise);
	
	if(choise == 1)
	{
		f = fopen (file_name , "w+");   // as said . w+ mode : remove the exist data from th file and staet writing ;
		
		printf("DONE : THE ENTIRE DATA ARE REMOVED\n");
		
		fclose(f);
	}
	else if (choise == 2){
	
	
	f = fopen (file_name , "r");
	 	
		printf("OK ..FIRST SEARCH FOR THE STUDENT \n");
		
	char  str [160] ;      int result = 0;            // search about the student

         	char  temp [15] ,num [15] ;
         		      
		printf ("OK ENTER THE NUMBER OF THE STUDENT YOU WANT TO DELETE : ");
	
		scanf("%s" , num);
		
		while ( (fscanf(f , "%s" , temp)) != (EOF) ){
			
			
			if(strcmp(num , temp) == 0 )
			{
				printf(" THE STUDENT IS FOUND ..\n");
				
				printf( "        | SSN   | NAME | ARABIC | ENGLISH| MATH | SCIENCE| SUM    | PERCENT| STATUS | \n");
				
				fgets(str , 160 , f);
			
				puts(str);
				
				FILE *f_ = fopen ( "STUDENTS_DATA.txt", "a+"); // create another file to move the data to it except the student we want to delete
				
				rewind(f); // go to the start of the file
				
				strcpy(temp, "null");
				
		//	fprintf( f_ , " ARABIC \t| ENGLISH \t| MATH \t| SCIENCE \t| SUM \t| PERCENT \t| STATUS \t| \n");
				
						while (((fscanf(f , "%s" , temp) )!= EOF))
						{  
									if (strcmp (num , temp) == 0)
									{
									
									fgets(str , 160 , f);
									
									continue ;   // skip the student we want to delete ;
									
						            }
			                 fgets(str , 160 , f);
			                 
				             fputs(str , f_);    // if other students .. move them 
					
							
						}
				result ++ ;
				
				f = fopen (file_name , "w+");  // at the end remove the file whose data is only the student we want to delete ;
				
				fclose (f);
				
				fclose (f_);
				
	            printf("THE STUDENT IS SUCCESSFULLY DELETED ! \n");
				
				break ;
				
			}
		}
		
		if(result == 0)
		
		printf("THE STUDENT IS NOT EXIST !\n");
		
	
}				
			char again [5] ;
			
			printf("YOU WANT TO DELETE ANOTHER STUDENT : ");
			
			scanf("%s" , again);
			
			if(strcmp (again , "yes") == 0)
			
			goto loop ;
			
			else
			
			get_choise();
		
	}
	
void update_student(FILE *f , char * file_name){
		
		loop :
			
			f = fopen (file_name , "r");
	 	
		printf("___FIRST SEARCH FOR THE STUDENT____ \n");
		
	char  str [160] ;      int result = 0;

         	char  num [8] , temp[8] ;
         		      
		printf ("OK ENTER THE NUMBER OF THE STUDENT YOU WANT TO UPDATE : ");
	
		scanf("%s" , num);

          while ((fscanf(f , "%s" , temp)) != (EOF))
          {
          	
          	if (strcmp (num , temp) == 0){
          		
          		printf ("THE STUDENT IS EXIST :\n");
          		
          		printf( "        | SSN   | NAME | ARABIC | ENGLISH| MATH | SCIENCE| SUM    | PERCENT| STATUS | \n");
          		
          		fgets(str , 160 , f);
          		
          		puts(str);
          		
          		// move the entire data of the file to another one ;
          		
          		rewind(f);
          		
          		strcpy (temp , "null") ;
          		
          		FILE *f_ = fopen("STUDENTS_DATA.txt" , "a+");  // open the seconed file to move the data ;
          		
	          		while ((fscanf(f , "%s" , temp)) != (feof(f)) && (strcmp (num , temp) != 0))
	          		{
	          			fgets(str , 160 , f);
	          			
	          			fputs(str , f_);
	          			
					  }
					  
					  f = fopen (file_name , "w+");  //  at the end remove the file whose data is only the student we want to update : like delete operation  
					  
					  fclose(f);
					  
					  st * student = (st *) malloc (sizeof(st)*1);  // reserve a memorey space for one student whose data will be update 
					  
	printf("OK .. ENTER THE NEW DATA OF THE STUDENT ..\n");
				// acceppt his data again ;
								  	
					printf(" SSN :  ");
					
					scanf("%d" , &student[0].ssn);
					
					if(student[0].ssn <= 0)
					{
						printf("ERROR : SSN MUST BE POSITIVE !___ WILL BE 0 __\n");
						
						student[0].ssn = 0;
						
					}
					printf(" NAME :  ");
					
					scanf("%s" , &student[0].name);
					
					// marks
					printf(" _____MARKS______\n");
					
					printf("ARABIC : ");
					
					scanf("%f" , &student[0].arab);
					
					if(student[0].arab >100)
					{
						printf("THE MARKS THAT LARGER THAN 100 WILL BE 100 .!\n");
					
					    student[0].arab = 100 ;
					}
					else if(student[0].arab <0){
						
						printf("THE MARKS THAT SMALLER THAN 0 WILL BE 0 .!\n");
						
						student[0].arab = 0;
					}
				    printf("MATH : ");
					
					scanf("%f" , &student[0].math);
						
					if(student[0].math >100)
					{
						printf("THE MARKS THAT LARGER THAN 100 WILL BE 100 .!\n");
					
					    student[0].math = 100 ;
					}
					else if(student[0].math <0){
						
						printf("THE MARKS THAT SMALLER THAN 0 WILL BE 0 .!\n");
						
						student[0].math = 0;
					}
					printf("ENGLISH : ");
					
					scanf("%f" , &student[0].eng);
					
					if(student[0].eng >100)
					{
						printf("THE MARKS THAT LARGER THAN 100 WILL BE 100 .!\n");
					
					    student[0].eng = 100 ;
					}
					else if(student[0].eng <0){
						
						printf("THE MARKS THAT SMALLER THAN 0 WILL BE 0 .!\n");
						
						student[0].eng = 0;
					}
					printf("SCIENCE : ");
					
					scanf("%f" , &student[0].scien);
					
				    if(student[0].scien >100)
					{
						printf("THE MARKS THAT LARGER THAN 100 WILL BE 100 .!\n");
					
					    student[0].scien = 100 ;
					}
					else if(student[0].scien <0){
						
						printf("THE MARKS THAT SMALLER THAN 0 WILL BE 0 .!\n");
						
						student[0].scien = 0;
					}
					printf("__________________________________________________________\n");
					
					calc (student , 1 , f_ , "STUDENTS_DATA.txt");
					
					write_file(student , 1 , f_ , "STUDENTS_DATA.txt");
					
					// as before  .. like the function add()
					
					free(student); // free the memorey space 
					
					fclose(f);
					
					fclose(f_);
					
					result++;

break ;
			  }
		  }
        
        if (result == 0)
        
        printf("THIS STUDENT IS NOT EXIST !\n");
        
        char * again ;
        
        printf ("YOU WANT TO UPDATE ANY OTHER STUDENT : ");
        
        scanf("%s" , again);
        
        if(strcmp(again , "yes") == 0)
        
        goto loop ;
        
        else 
        
        get_choise();
        
}
