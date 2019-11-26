// #include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// #include <errno.h>
#include <unistd.h>
// #include <sys/stat.h>
// #include <time.h>
// #include <dirent.h>

// Write a function that uses strsep to parse a line of arguments
// Use the following header: char ** parse_args( char * line );
// It should take a string with the command line invocation of a program (like "ls -a -l")
// Note that there is a " " between each argument
// Return an array of pointers to each individual argument in the parameter string, that could be used for execvp()
// For example, the following code should work (assuming all variables are declared appropriately:
// char ** args = parse_args( line );
// execvp(args[0], args);
// You can make the following assumptions:
// There is only 1 space between each argument in the original string
// The original string contains no more than 5 arguments
// The original string is correctly formatted
char ** parse_args( char * line ){
  char * curr = line;
  char * token;
  char ** pointers = malloc(5 * sizeof(char *) * sizeof(char *)); //allocate memory for pointers
  int i = 0;
  while (curr){
    // Returns the beginning of the original string,
    // sets source to the string starting at 1 index past the location of the new NULL
    token = strsep(&curr, " ");
    pointers[i] = token;
    printf("iteration %d | curr: %s | token: %s\n", i, curr, token);
    i++;
  }
  return pointers;
}

int main(){
  char * line = strdup("ls -l -a");
  printf("Testing parse_args (run 'ls -l -a'):\n");
  char ** args = parse_args( line );
  execvp(args[0], args);

  return 0;
}
