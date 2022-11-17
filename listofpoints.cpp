//Name: Aarham Haider
//Student ID: 301462422
//Computing ID: aah13

#include "listofpoints.hpp"


ListOfPoints::ListOfPoints() {
  //implement me
}

void ListOfPoints::addAfter(Point& newPt, string name) {
  int pointIndex = 0;
  //loops through vector, searches for name of the index
  for(unsigned int i=0;i<m_points.size();i++){
    if(m_points[i].getName() == name){
      pointIndex = i;
    }
  }
  //inserts point at index+1 to add after point
  m_points.insert(m_points.begin()+pointIndex+1,newPt);

}

void ListOfPoints::addPoint(Point& newPt)  {
  m_points.push_back(newPt);
}

Point& ListOfPoints::getPointAt(unsigned int i) {
  return m_points[i];
}

int ListOfPoints::getSize() const {
  int size = m_points.size();
  return size;
}

void ListOfPoints::printList() const {
  //loops through vector, printing each point on a separate line
  for(unsigned int i=0;i<m_points.size();i++){
    cout<<m_points[i]<<endl;
  }
}


void ListOfPoints::draw() const {
  //creates a 20x20 grid
  //checks points vector if point is in the grid
  //if point is found, print the point at the index, otherwise, print box
  int index = 0;
  for(int col=20; col>=0;col--){
    for(int row=0; row<=20; row++){
      int found = 0;
      for(unsigned int i=0;i<m_points.size();i++){
        if(m_points[i].getY() == col && m_points[i].getX() == row){
          found = 1;
          index = i;
        }
      }
      if(found){
        cout<<m_points[index].getName();
      }
      else{
        cout<<'-';
      }
    }
    cout<<endl;
  }
}
