
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "Event.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "EmptyDataCollectionException.h"

using std::cin;
using std::cout;
using std::ifstream;

// PriorityQueue<Event> * wait = new PriorityQueue<Event>();
// Queue<Event> * line = new Queue<Event>();
  string aLine = "";
  string arr = "";
  string tra = "";
  string delimiter = " ";
  size_t pos = 0;
  // bool isTellerAvaliable = true;
  // int total_arrival = 0;
  // int total_processing = 0;
  // int total_departure = 0;
  // int ave_time = 0;
  // unsigned int departureTime = 0;
  // int currentTime = 0;
  // int ppl = 0;

void addToPQ(PriorityQueue<Event> &wait){
  //int count = 0;
  while(cin >> arr >> tra)
   {
      //cout << aLine << '\n';   // For debugging purposes
      // pos = aLine.find(delimiter);
      // arr = aLine.substr(0, pos);
      // aLine.erase(0, pos + delimiter.length());
      // tra = aLine;
      // if(count == 3)
      //   break;
      // count++;
      char arrival = 'A';
      int aTime = stoi(arr);
      int aLength = stoi(tra);
      Event *event = new Event(arrival, aTime, aLength);  // in the stackframe in stack memory
      

      try {
            //int t = (*event).getTime();
            wait.enqueue(*event);
            
       }
       catch (EmptyDataCollectionException& anException) {
         // cout << anException.what( ) << " => " <<  aWordPair; // For debugging purposes
        
       }
   }

}

int main(int argc, char *argv[]){
PriorityQueue<Event> *wait = new PriorityQueue<Event>();
Queue<Event> *line = new Queue<Event>();
bool isTellerAvaliable = true;
  int total_arrival = 0;
  int total_processing = 0;
  int total_departure = 0;
  double ave_time = 0;
  unsigned int departureTime = 0;
  int currentTime = 0;
  int ppl = 0;

  addToPQ(*wait);
  while(!wait->isEmpty()){
    Event newEvent = wait->peek();
    currentTime = newEvent.getTime();
    if(newEvent.isArrival()){
      Event c = newEvent;
      wait->dequeue();
      if(line->isEmpty() && isTellerAvaliable){
      departureTime = currentTime + c.getLength();
      Event customer('D', departureTime, 0);
      wait->enqueue(customer);
      isTellerAvaliable = false;
      }else{
        line->enqueue(c);
        cout<<"enque"<<endl;
        
      }
      total_arrival += c.getTime();
      total_processing = c.getLength();

    }else {
      wait->dequeue();
      if(!(line->isEmpty()))
      {
        Event customer = line->peek();
        line->dequeue();
        ppl++;
        departureTime = currentTime + customer.getLength();
        Event nn('D', departureTime, 0);
        wait->enqueue(nn);
      }
      else
      {
        isTellerAvaliable = true;
        
      }
      total_departure += currentTime;
    }

  }
  ave_time = (double)(total_departure - total_processing - total_arrival) / ppl;

  cout << "Total number of people processed: " << ppl << endl;
  cout << "Average amount of time spent waiting: " <<  ave_time  << endl;

system("pause");
return 0;

}