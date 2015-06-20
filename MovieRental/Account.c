#include "Account.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Account* InitAccount (const char* last, const char* first, int nMovies) {
  if (last[0] == '\0' || first[0] == '\0' || strlen (last) > MAX_NAME_LEN || strlen (first) > MAX_NAME_LEN) {
    printf ("name needs to be valid\n");
    return NULL;
  }
  if (nMovies < 0) {
    printf ("number of movies must be greater than 0\n");
    return NULL;
  }

  //allocate memory for a instance
  struct Account* account = (struct Account*) malloc (sizeof (struct Account) );
  account->ID = accountID++;
  strcpy (account->lastname, last);
  strcpy (account->firstname, first);
  account->nMovies = nMovies;
  //newly opened account
  account->flag.new = 1;
  account->flag.closed = 0;
  account->flag.reopened = 0;
  account->flag.delinquent = 0;
  //get current time
  account->time = time (0);
  return account;
}

void DestAccount (struct Account* acc)
{
  if (acc != NULL)
    free (acc);
}

int CheckFlag (struct Flag flag)
{
  //check for mutual exclusive flags
  if ( (flag.new & flag.closed == 1) || (flag.closed & flag.reopened == 1) || (flag.new & flag.reopened == 1) )
    return -1;
  return 1;
}

void ChangeStatu (struct Account* acc, struct Flag flag)
{
  if (CheckFlag (flag) < 0) {
    printf ("invalid flag combinaiton\n");
    return;
  }
  //turn on
  acc->flag.new = flag.new;
  acc->flag.closed = flag.closed;
  acc->flag.reopened = flag.reopened;
  acc->flag.delinquent = flag.delinquent;
}

void SetnMovies (struct Account* acc, int n)
{
  if (n < 0) {
    printf ("number of movies must be greater than 0\n");
    return;
  }
  acc->nMovies = n;
}

void PrintAccountTime (struct Account* acc)
{
  struct tm* timeinfo = gmtime (&acc->time);
  printf ("Current local time and date: %s", asctime (timeinfo) );
}



