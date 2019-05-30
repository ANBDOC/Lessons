/* https://opensource.com/article/19/5/how-write-good-c-main-function
* Look at https://twitter.com/JnyJny author of article 
* main.c - the complete listing 
*/

/* main_boilerplate.c */
/* 0 copyright/licensing */

#include <stdio.h>      /* stdin stdout stderr ffprint  */
#include <stdlib.h>     /* malloc, calloc, realloc      */
#include <unistd.h>     /* EXIT_FAILURE, EXIT_SUCSESS   */
#include <libgen.h>     /* basename() function          */
#include <errno.h>      /* errno vars and values        */
#include <string.h>     /* memcpy(), memset(), strlen() */
#include <getopt.h>     /* optarg, opterr, optind, getopt */
#include <sys/types.h>  /* typedef uint32_t uint64_t    */

/* 2 defines */

#define OPTSTR "vi:o:f:h"
#define USAGE_FMT  "%s [-v] [-f hexflag] [-i inputfile] [-o outputfile] [-h]"
#define ERR_FOPEN_INPUT  "fopen(input, r)"
#define ERR_FOPEN_OUTPUT "fopen(output, w)"
#define ERR_DO_THE_NEEDFUL "do_the_needful blew up"
#define DEFAULT_PROGNAME "george"

/* 3 external declarations */

extern int errno;
extern char *optarg;
extern int opterr, optind;

/* 4 typedefs */

typedef struct {
  int           verbose;
  u_int32_t      flags;
  FILE         *input;
  FILE         *output;
} options_t;

/* 5 global variable declarations */
/* DEPRECATED AT ALL */

/* 6 function prototypes */

void usage(char *progname, int opt);
int  do_the_needful(options_t *options);

int main(int argc, char *argv[]) {

/* 7 command-line parsing */

    int opt;

    options_t options = { 0, 0x0, stdin, stdout };

    opterr = 0;

    while ((opt = getopt(argc, argv, OPTSTR)) != EOF)
       switch(opt) {
           case 'i':
              if (!(options.input = fopen(optarg, "r")) ){
                 perror(ERR_FOPEN_INPUT);
                 exit(EXIT_FAILURE);
                 /* NOTREACHED */
              }
              break;

           case 'o':
              if (!(options.output = fopen(optarg, "w")) ){
                 perror(ERR_FOPEN_OUTPUT);
                 exit(EXIT_FAILURE);
                 /* NOTREACHED */
              }    
              break;
             
           case 'f':
              options.flags = (uint32_t )strtoul(optarg, NULL, 16);
              break;

           case 'v':
              options.verbose += 1;
              break;

           case 'h':
           default:
              usage(basename(argv[0]), opt);
              /* NOTREACHED */
              break;
       }

    if (do_the_needful(&options) != EXIT_SUCCESS) {
       perror(ERR_DO_THE_NEEDFUL);
       exit(EXIT_FAILURE);
       /* NOTREACHED */
    }

    return EXIT_SUCCESS;
/*
 ./a.out -h
a.out [-v] [-f hexflag] [-i inputfile] [-o outputfile] [-h]
*/

}

/* 8 function declarations */
void usage(char *progname, int opt) {
   fprintf(stderr, USAGE_FMT, progname?progname:DEFAULT_PROGNAME);
   exit(EXIT_FAILURE);
   /* NOTREACHED */
}

int do_the_needful(options_t *options) {

   if (!options) {
     errno = EINVAL;
     return EXIT_FAILURE;
   }

   if (!options->input || !options->output) {
     errno = ENOENT;
     return EXIT_FAILURE;
   }

   /* XXX do needful stuff */

   return EXIT_SUCCESS;
}
