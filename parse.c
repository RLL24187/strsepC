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
  char ** pointers = malloc(5 * sizeof(char *)); //allocate memory for 5 pointers (b/c at most 5 args)
  int i = 0;
  while (curr){
    pointers[i] = malloc(strlen(line)+1);    // allocate desired memory to each pointer
    token = strsep(&curr, " ");
    // Returns the beginning of the original string,
    // sets source to the string starting at 1 index past the location of the new NULL
    pointers[i] = token;
    // printf("iteration %d | curr: %s | token: %s\n", i, curr, token);
    i++;
  }
  return pointers;
}

int main(){
  char * line = strdup("ls -a -l");
  printf("Testing parse_args (run 'ls -a -l'):\n");
  char ** args = parse_args( line );
  execvp(args[0], args);

  line = strdup("ls -a -l -r -d");
  printf("Testing parse_args (run ls -a -l -r -S)\n");
  args = parse_args( line );
  execvp(args[0], args);
  return 0;
}
