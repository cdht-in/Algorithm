#include "FlightReservation.h"
#include <locale>
#include <iostream>

Passager::Passager () {}

Passager::Passager (string name, PassClass c) : name (name), c (c) {}

BusinessPassager::BusinessPassager (string name, PassClass c, unsigned int mile) : mile (mile)
{
  this->name = name;
  this->c = c;
}

Seat::Seat() : row(), col() {}

Seat::Seat (unsigned int row, unsigned char col) : row (row), col (col) {}

AirFrame::AirFrame (string name, unsigned int row, string col) : name (name), row (row), col (col)
{
  seats = new Seat*[row];
  for (int i = 0; i < row ; i++) {
    seats[i] = new Seat[col.size()];
  }
}

AirFrame::~AirFrame()
{
  if (row > 0 && col != "") {
    for (int i = 0; i < row ; i++) {
      delete[] seats[i];
    }
    delete[] seats;
  }
}

Flight::Flight (unsigned int number,
                AirFrame* airframe,
                string orig,
                string takeoff,
                string dest,
                string landing) : number (number), airframe (airframe), orig (orig), takeoff (takeoff), dest (dest), landing (landing) {}

Flight::~Flight() {}

Reservation::Reservation() : passager (0), flight (0), seat (0) {}

Reservation::~Reservation()
{
  if (passager != 0)
    delete passager;
  if (flight != 0)
    delete flight;
  if (seat != 0)
    delete seat;
}

Itinerary::Itinerary (string name, unsigned int nRes) : nRes (nRes), name (name), res (new Reservation[nRes] ), p() {}

Itinerary::~Itinerary()
{
  if (res != 0)
    delete[] res;
}

void Itinerary::CreateReservation (
  PassClass passclass,
  unsigned int seatrow,
  unsigned char seatcol,
  unsigned int flightnumber,
  AirFrame* airframe,
  string orig,
  string takeoff,
  string dest,
  string landing)
{
  if (p < nRes) {
    //init pass
    if (passclass == economy)
      res[p].passager = new Passager (name, passclass);
    else
      //initially assign 1000 business miles, could be changed later
      res[p].passager = new BusinessPassager (name, passclass, 1000);
    //init flight
    res[p].flight = new Flight (flightnumber, airframe, orig, takeoff, dest, landing);
    //init seat
    res[p].seat = new Seat (seatrow, seatcol);
    p++;
  }
  else
    cout << "too much researvation" << endl;
}

void Itinerary::PrintItinerary()
{
  cout << name << "'s Itinerary:" << endl;
  for (int i = 0; i < nRes; i++) {
    if (res[i].passager->c == economy)
      cout << "class: economy" << endl;
    else
      cout << "class: business" << endl;
    cout << "seat: " << res[i].seat->row << res[i].seat->col <<  endl;
    cout << "flight: " << res[i].flight->number << endl;
    cout << "plane: " << res[i].flight->airframe->name << endl;
    cout << "from " << res[i].flight->orig << " at " << res[i].flight->takeoff << " to " << res[i].flight->dest << " at " << res[i].flight->landing << endl;
  }
  cout << endl;
}

int main()
{
  //there are two planes
  AirFrame airbus ("airbus", 70, "abcdefg");
  AirFrame boeing737 ("boeing737", 50, "abcde");
  //jow with 2 reservations
  Itinerary joei ("Joe", 2);
  //joe's trip from houston to atlanta
  joei.CreateReservation (economy, 40, 'c', 7, &airbus, "IAH", "9:00:00 Apr 1 2012", "ATL", "11:00:00 Apr 1 2012");
  joei.CreateReservation (economy, 30, 'd', 9, &boeing737, "ATL", "14:00:00 Apr 1 2012", "BOS", "17:00:00 Apr 1 2012");
  Itinerary jilli ("Jill", 2);
  //jill's trip from houston to atlanta
  jilli.CreateReservation (business, 4, 'a', 7, &airbus, "IAH", "9:00:00 Apr 1 2012", "ATL", "11:00:00 Apr 1 2012");
  //jill's trip from atlanta to boston
  jilli.CreateReservation (business, 3, 'b', 9, &boeing737, "ATL", "14:00:00 Apr 1 2012", "BOS", "17:00:00 Apr 1 2012");
  joei.PrintItinerary();
  jilli.PrintItinerary();
}
