#include "scheme.h"
#include "dynload.h"
#include "scheme-private.h"

#include <string.h>
#include <stdlib.h>

#define BANNER "Playground Scheme 0.1"

#ifndef INITFILE
#define INITFILE "init.scm"
#endif

#if STANDALONE


static void usage()
{
     printf("Usage: scheme -?\n\n");

     printf("or:    scheme [<file1> <file2> ...]\n");
     printf("followed by\n");
     printf("          -1 <file> [<arg1> <arg2> ...]\n");
     printf("          -c <Scheme commands> [<arg1> <arg2> ...]\n");
     printf("assuming that the executable is named scheme.\n");
     printf("Use - as filename for stdin.\n");
}


int main(int argc, char **argv) 
{
     scheme sc;
     FILE *fin;
     char *file_name = INITFILE;
     int isfile = 1;
     
     if (argc == 1) {
          printf(BANNER);
     }

     if (argc == 2 && strcmp(argv[1], "-?") == 0) {
          usage();

          return 1;
     }

     if (!scheme_init(&sc)) {
          fprintf(stderr, "Could not initialize!\n");

          return 2;
     }

     scheme_set_input_port_file(&sc, stdin);
     scheme_set_output_port_file(&sc, stdout);

#if USE_DL
     scheme_define(&sc, sc.global_env, 
                   mk_symbol(&sc, "load-extension"), 
                   mk_foreign_func(&sc, scm_load_ext));
#endif

     argv++;

     if (access(file_name, 0) != 0) {
          char *p = getenv("TINYSCHEMEINIT");

          if (p != 0) {
               file_name = p;
          }
     }

     do {
          if (strcmp(file_name, "-") == 0) {
               fin = stdin;
          } else if (strcmp(file_name, "-1") == 0 || 
                     strcmp(file_name, "-c") == 0) {
               pointer args = sc.NIL;

               isfile = file_name[1] == '1';
               file_name = *argv++;

               if (strcmp(file_name, "-") == 0) {
                    fin = stdin;
               } else if (isfile) {
                    fin = fopen(file_name, "r");
               }

               for (; *argv; argv++) {
                    pointer value = mk_string(&sc, *argv);

                    args = cons(&sc, value, args);
               }

               args = reverse_in_place(&sc, sc.NIL, args);
               scheme_define(&sc, sc.global_env, 
                             mk_symbol(&sc, "*args*"), args);
               
          } else {
               fin = fopen(file_name, "r");
          }

          if (isfile && fin == 0) {
               fprintf(stderr, "Could not open file %s\n", file_name);
          } else {
               if (isfile) {
                    scheme_load_named_file(&sc, fin, file_name);
               } else {
                    scheme_load_string(&sc, file_name);
               }

               if (!isfile || fin != stdin) {
                    if (sc.retcode != 0) {
                         fprintf(stderr, "Errors encountered reading %s\n", file_name);
                    }

                    if (isfile) {
                         fclose(fin);
                    }
               }
          }

          file_name = *argv++;

     } while (file_name != 0);

     if (argc == 1) {
          scheme_load_named_file(&sc, stdin, 0);
     }

     scheme_deinit(&sc);
     
     return sc.retcode;
}

#endif

