//Name: Aarham Haider
//Student ID: 301462422
//Computing ID: aah13

#include "point.hpp"

float Point::getDistance(const Point &other) const {
  //get x and y coordinates from argument point
  float paramX = other.getX();
  float paramY = other.getY();
  //use 2d distance formula to find the length, which will be returned
  float distance = sqrt(pow(m_x-paramX,2)+pow(m_y-paramY,2));

  return distance;
}

string Point::toString() const {
  // examples how to create string from small parts
  string str(m_name);
  str += " = (";
  str += std::to_string(m_x);
  str.append(",").append(std::to_string(m_y)).append(")");
  return str;
}


void Point::printPoint() const {
  cout << toString() << endl;
}

// used for printing Point using << operator.
// For example, the following code will work
// Point origin(0,0,'O');
// cout << origin;
ostream& operator<<(ostream &os, const Point &p) {
  return os << p.toString();
}
