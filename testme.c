#include <stdio.h>
#include <string.h>
int main(void){
    //int x; printf("Enter count then values: ");  fscanf(stdin, "%d", &x); int values[x];    for (int i =0;i<x;i++) fscanf(stdin, "%d", &values[i]); 
   // printf("%d\n",values[3]);
   // double z = 8.0;
   // printf("%d",(z==(int)z));
   //char name[64];
    // Safer multi-word input (reads a whole line)
    //fgets(name, sizeof(name), stdin);
    // fgets includes the trailing '\n' — strip it if needed:
    //name[strcspn(name, "\n")] = '\0';
    //printf("now its %s",name);

    /*
    Files let us persist data between runs

    Your process    ->      fopen()     ->      FILE *fp       ->       fprintf()/fscnaf()      ->      fclose()
    fopen() opens a channel to file pointer *fp
    FILE is a struct of information about the file
    Think of FILE * like a tv remote of controlling the device

    
    fprintf(stderr,"an error has not occured\n");

    FILE *fp = NULL;
    //remember fp is just a pointer, and fp is a generic name
    FILE *fopen(
        const char *path,
        const char *mode
    );
    // r = read w = write  a = append  r+ = read and write     w+ read and writes truncates    b = binary append to any mode
    // w makes the assumption you are always making a new file, if a file with that name already exists it destroys the old file
    fp = fopen("data.txt","r");

    if (fp == NULL){
        perror("fopen failed");
        return 1;
    }
    fclose(fp);
    */

    // checks open files in a open files table
    //reading and writing from the console,screen, and errors are files
    // console, screen, and errors are the first 3 files, with an id and name
    // usually stdin is the keyboard to console
    // ex:  fscanf(stdin,%s,string); uses stdin as the file
    //the screen is typically stdout
    //fprintf can specify stdout
    //perror invokes standard error
    //gives the programmer the option to take error messages outside of the error file

    //this allows stdin of a second program to be stdout from the first program
    //errno is the numeric code of the error
    //fclose() closes and sets to NULL
    //tmpfile() is a unique temporary file, that are dangerous for security vurnerabilities
    //doesn't persist on reboot
    //  fputs(variable,stdout) prints a new line of variable to stdout
    




    /*
    everything after the program name is a command-line arguments
    shell splits on whitespace and passes to main
    input.txt
    output.txt
    the command-line arguments are the .txt
    arguments always arrive as strings
    name of program and arguments are passed

    $ ./myprogram input.txt output.txt

    int main(int argc, char *argv[])
    argc-> argument count, always >=1
    argv-> argument vector, array of strings
    argc = 3

    argv[0] = "./myprogram\0"
    argv[1] = input.txt
    argv[2] = output.txt
    argv[3] = NULL   //sentinel
    argv[0] is program name
    argv[argc] is NULL

    always check argc for the proper count
    always print usage to stderr, not stdout

    atoi (ascii to integer)
    int n = atoi(argv[1]);
    atoi only returns alphanumerics
    long v = strtol("42abc", &end,10);  10 is lenght of integer
    if *end != '\0' then an error in the input


    ./sort -r -n input.txt

    == works with numbers and individual characters


    #include <unistd.h>

    scripts can chain with ./prog and ./next
    macros insure portability

    atexit() tells the program to do something at exit or return


    getenv() gets an environment variable that are set in memory

    never trust argv, always validate it
    don't assume file name has no spaces
    allways code defensively
    argc includes program name and sentinel
    

    */
   int EXIT_SUCCESS = 0;
    return 0;
    exit(EXIT_SUCCESS);

}