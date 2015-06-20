#ifndef FLIGHT_RESERVATION_H
#define FLIGHT_RESERVATION_H

#include <string>
#include <iostream>

using namespace std;

//Passsager class
enum PassClass {economy, business};

class Passager {
public:
  string name;
  PassClass c;
  Passager();
  Passager (string name, PassClass c);
};

class BusinessPassager : public Passager {
  unsigned int mile;
public:
  BusinessPassager (string name, PassClass c, unsigned int mile);
};

class Seat {
public:
  unsigned int row;
  unsigned char col;
  Seat();
  Seat (unsigned int row, unsigned char col);
};

class AirFrame {
  Seat** seats;
  unsigned int row;
  string col;
public:
  string name;
  AirFrame (string name, unsigned int row, string col);
  ~AirFrame();
};

class Flight {

public:
  unsigned int number;
  AirFrame* airframe;
  string orig;
  string takeoff;
  string dest;
  string landing;

  Flight (  unsigned int number,
            AirFrame* airframe,
            string Orig,
            string takeoff,
            string Dest,
            string landing);
  ~Flight();
};

class Reservation {
public:
  Passager* passager;
  Flight* flight;
  Seat* seat;
  Reservation();
  ~Reservation();
};

class Itinerary {
  string name;
  Reservation* res;
  unsigned int nRes;
  unsigned int p;
public:
  Itinerary (string name, unsigned int nRes);
  ~Itinerary();
  void CreateReservation (
    PassClass passclass,
    unsigned int seatrow,
    unsigned char seatcol,
    unsigned int flightnumber,
    AirFrame* airframe,
    string orig,
    string takeoff,
    string dest,
    string landing);
  void PrintItinerary();
};


#endif
