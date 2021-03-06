#ifndef WORDCOUNT_H
#define WORDCOUNT_H

#include <stdio.h>
#include <string.h>

#include <ctype.h>

/*
// declare a structure type key - (arrays are parallel)
struct key {
  char* word;
  int count;
};
*/
/*
//1. define an array keytab of structures
struct key keytab[] =
{
    "auto", 0,
    "break",0,
    "case", 0,
    "char", 0,
    "const",0,
    "continue",0,
    "default",0,
    "unsigned",0,
    "void", 0,
    "while",0
};
*/

// use the binary tree instead of array for the sort
// if the list of words isn't known in advance.
struct tnode    /* the tree node */
{
  char* word;          /* points to the text */
  int count;           /* number of occurrences */
  struct tnode *left;  /* left child; left to be a pointer to a tnode, not a tnode itself */
  struct tnode *right; /* right child */
};

//NKEYS is the number of keywords in keytab
//2. the advantage here using keytab[0] is that it does not need to be changed if the type key changes
// define NEKYS (sizeof keytab / sizeof(struct key))
//#define NKEYS (sizeof keytab  / sizeof keytab[0])

//#define MAXWORD 100


//#define BUFSIZE 100 // buffer for ungetch

int getword(char*, int);
//struct key *binsearch(char*, struct key *, int);
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);

#endif
