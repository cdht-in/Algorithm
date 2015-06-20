#ifndef ACCOUNT_H
#define ACCOUNT_H

/*
  this file holds the movie rental record
*/

#include <time.h>

//current only support 128 bytes names
#define MAX_NAME_LEN 128
typedef unsigned int uint32;

//account status flag
struct Flag {
  uint32 new : 1;
  uint32 closed : 1;
  uint32 reopened : 1;
  uint32 delinquent : 1;
};

struct Account {
  //user  ID
  uint32 ID;
  //renter lastname
  char lastname[MAX_NAME_LEN];
  //renter firstname
  char firstname[MAX_NAME_LEN];
  //# of movies rented
  uint32 nMovies;
  //account status
  struct Flag flag;
  //account open time
  time_t time;
};

static uint32 accountID = 0;

struct Account* InitAccount (const char* last, const char* first, int nMovies);

void DestAccount (struct Account* acc);

static int CheckFlag (struct Flag flag);

void ChangeStatu (struct Account* acc, struct Flag flag);

void SetnMovies (struct Account* acc, int n);

void PrintAccountTime (struct Account* acc);


#endif
