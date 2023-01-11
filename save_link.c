#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sqlite3.h>


//fenction to get print data
static int callback(void* data, int argc, char** argv, char** azColName) 
{ 

    int i;  
    for (i = 0; i < argc; i++) { 
        printf("- %s = %s \t \t",azColName[i], argv[i] ? argv[i] : "NULL"); 
       
       
        
    } 
    
    printf("\n"); 
    printf("-------------------------------------------\n"); 
    
printf("\n");
    return 0; 
} 








int main(int argc, char *argv[]) {
  
  sqlite3 *db;
  int rc ;
  
  
  //creat database
  char *err_msg = 0;
  rc = sqlite3_open("save_link.db", &db);
  
  if (rc != SQLITE_OK) {
      fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
      sqlite3_close(db);
      return 1;
  }
  
  
  
  
  
  
  
  //creat table
  //table links
  char *sql = "CREATE TABLE IF NOT EXISTS links ( name TEXT,         mylink TEXT);";
  rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
  
  if (rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", err_msg);
      sqlite3_free(err_msg);        
  }
  
  
  
  
  
  
  
  
  
  
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  
  
  
  
  char input[10];
  while (1) {
  	printf(" \n");
    printf("# ");
    scanf("%s", input);

    if (strcmp(input, "menu") == 0) {
      
      
      
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      
      printf("\t \t /menu \n");
      printf("\t \t /insert \n");
      printf("\t \t /select_all \n");
      printf("\t \t /select \n");
      printf("\t \t /delete \n");
      printf("\t \t /exit \n");
      
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      
      
      
      
      
      
      
      
      
      
      
} else if (strcmp(input, "insert") == 0) {
      
      
      
      
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      
       /* Get the user's input */
  
  char* zErrMsg = 0;  
  
  
   char name[100];
   char mylink[100];
   
   printf("\t \t # Enter name : ");
   scanf("%s", name);
   printf("\t \t # Enter link : ");
   scanf("%s", &mylink);
 
  
  /* Create SQL statement */
  char sqlinsert2[200];
  sprintf(sqlinsert2, "INSERT INTO links (name, mylink) VALUES ('%s', '%s');", name, mylink);

  /* Execute SQL statement */
  rc = sqlite3_exec(db, sqlinsert2, callback, 0, &zErrMsg);
  if( rc != SQLITE_OK ) {
    fprintf(stderr, "erreur r: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  }
  else {
  	
  	printf("\n");
    printf("\t \t +-+-+-+-+-+-+-+-+-+-\n");
    fprintf(stdout, "\t \t | successfully add |\n");
    printf("\t \t +-+-+-+-+-+-+-+-+-+-\n");
  }
  
  
      
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      
      
      
      
    } else if (strcmp(input, "select_all") == 0) {
      
      
      
      
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      
      printf("################################################\n");
      
  //select data
  char *sqls = "SELECT * FROM links";
  rc = sqlite3_exec(db, sqls,callback, 0, &err_msg);
  
  if (rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", err_msg);
      sqlite3_free(err_msg);        
  }
  
  
  printf("################################################\n");
  
  
  
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  
  
  
      
      
      
      
      
      
      
      
      
      
      
    } else if (strcmp(input, "select") == 0) {
      
      
      
      
      
      
     printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
     
     printf("################################################\n");
  
    	
  //select data with id
  
  char selectwname[100];
  
  printf("\t \t # entre name : ");
  scanf("%s",&selectwname);
  
  
  char sqlsid[100];
  sprintf(sqlsid, "SELECT * FROM links WHERE name = '%s'", selectwname);
  
  
  rc = sqlite3_exec(db, sqlsid,callback, 0, &err_msg);
  
  if (rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", err_msg);
      sqlite3_free(err_msg);        
  }
  
  
      printf("################################################\n");
  
      
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      
      
      
      
      
      
      
      
    } else if (strcmp(input, "delete") == 0) {
      
      
        
      
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  //delete data with id
  
  char linksdelete[100];
  
  printf("\t \t # entre name : ");
  scanf("%s",&linksdelete);
  
  
  char sqldeleteid[100];
  sprintf(sqldeleteid, "DELETE FROM links WHERE name = '%s'", linksdelete);
  
  
  rc = sqlite3_exec(db, sqldeleteid,callback, 0, &err_msg);
  
  if (rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", err_msg);
      sqlite3_free(err_msg);        
  }else
  {
  	
  	
  	printf("\n");
    printf("\t \t +-+-+-+-+-+-+-+-+-+-+-+\n");
    fprintf(stdout, "\t \t | successfully delete |\n");
    printf("\t \t +-+-+-+-+-+-+-+-+-+-+-+\n");
  	
  	
  	
  	
  }
  
  
      
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  
  
      
      
      
      
      
    } else if (strcmp(input, "exit") == 0) {
      break;
      
      
    } else {
    	
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
      printf("#write menu \n");
    	
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    	
    	
    }
  }
  
  
  
  

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  

  
  
  
  
  
  
  
  
  
  
  
  
  
  

  
  
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  sqlite3_close(db);
  
  return 0;
}
