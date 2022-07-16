#ifndef GETOPT_H
#define GETOPT_H

extern char* optarg;
extern int opterr;
extern int optind;
extern int optopt;
extern int optreset;

int getopt(int nargc, char* const nargv[], const char* ostr);
#endif