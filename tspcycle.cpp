//Name: Aarham Haider
//Student ID: 301462422
//Computing ID: aah13

#include <iostream>

#include "tspcycle.hpp"

TSPCycle::TSPCycle() {
  // implement me
//  cout << "default TSPCycle constructor" << endl;
}

// returns the length of the cycle
float TSPCycle::getLength() const {
  int size = m_points.size();
  float totalLength = 0;

  //loops through vector, finds the distance of the current point and next point
  for(int i=0;i<size-1;i++){
    int j = i+1;
    float distance = m_points[j].getDistance(m_points[i]);
    totalLength +=distance;
    j++;
    //if the next point is the end of the vector, find distance from end and start points
    //completes cycle
    if(j == size-1){
      float endLength = m_points[size-1].getDistance(m_points[0]);
      totalLength += endLength;
    }
  }

  return totalLength;

}
