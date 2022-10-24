#include <cmath>
#include <cstdlib>
#include <iostream>

// Prototype functions
double forwardDiff(double &h, double x);
double centerDiff(double &h, double x);

int main(int argc, char *argv[]) {
  const double pi_4 = 0.25 * 3.141592653589793;
  double h , dy_F, dy_C;
  // get h from command line
  h = std::atof(argv[1]);
  
  // compute forward difference
  dy_F = forwardDiff(h, pi_4);

  // compute center difference
  dy_C = centerDiff(h, pi_4);

  // compare the errors
  // print results
  std::cout << "Forward difference = " << dy_F << std::endl;
  std::cout << "Center difference = " << dy_C << std::endl;

  return 0;
}

double forwardDiff(double &h, double x)
{
  return (sin(x + h) - sin(x))/h;
}

double centerDiff(double &h, double x)
{
  return (sin(x + h) - sin(x - h))/(2*h);
}