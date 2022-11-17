//Name: Aarham Haider
//Student ID: 301462422
//Computing ID: aah13

#include "tspsolver.hpp"

TSPSolver::TSPSolver(ListOfPoints &list) {
  int size = list.getSize();
  //create cycle starting with 3 elements
  for (int i = 0; i<3;i++) {
    m_solution.addPoint(list.getPointAt(i));
  }
  //store rest of the points starting from 4th element
  for(int j=3;j<size;j++){
    m_list.addPoint(list.getPointAt(j));
  }
}

void TSPSolver::solve() {
  float smallestIncrease = 99999999999999;
  float initialDistance, insertDistance;
  int index = 0;


  //use smallest heuristic method to check the minimum distance when point is inputted
  //outer loop: inserts points given the index for minimum added length
  //inner loop: checks for with smallest increase, determines index
  for(int i=0;i<m_list.getSize();i++){
    int size = m_solution.getSize();
    Point insertPoint = m_list.getPointAt(i);

    for(int j=1;j<m_solution.getSize();j++){
      Point currentPoint = m_solution.getPointAt(j-1);
      Point nextPoint = m_solution.getPointAt(j);

      initialDistance = currentPoint.getDistance(nextPoint);
      insertDistance = insertPoint.getDistance(currentPoint) + insertPoint.getDistance(nextPoint);

      if(insertDistance-initialDistance < smallestIncrease){
        smallestIncrease = insertDistance-initialDistance;
        index = j-1;
      }
    }

    //checks if smallest distance is between begining and end of cycle
    //if condition is met, index is at end of cycle
    Point beginPoint = m_solution.getPointAt(0);
    Point endPoint = m_solution.getPointAt(size-1);

    initialDistance = beginPoint.getDistance(endPoint);
    insertDistance = insertPoint.getDistance(beginPoint) + insertPoint.getDistance(endPoint);

    if(insertDistance-initialDistance < smallestIncrease){
      smallestIncrease = insertDistance-initialDistance;
      index = size-1;
    }
    m_solution.addAfter(m_list.getPointAt(i),m_solution.getPointAt(index).getName());
  }
}

TSPCycle& TSPSolver::getSolution() {
  // implement me

  // currently returns an empty cycle
  return m_solution;
}
