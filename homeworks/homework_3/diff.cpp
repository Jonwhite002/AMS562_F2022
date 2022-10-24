#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>

// Prototype functions
double forwardDiff(double h, double x);
double centerDiff(double h, double x);
double errPercent(double x, double y);

int main(int argc, char *argv[]) {
  const double pi_4 = 0.25 * 3.141592653589793;
  double h , val, dy_F, dy_C;

  // get h from command line
  h = std::atof(argv[1]);
  val = pi_4;

  if (argc < 2 || std::isnan(h))
  {
    std::cerr << "ERROR: The value of h is either missing or is not a number!" << std::endl;
  } else if (h >= 1.0 || h <= 0.0) {
    std::cerr << "ERROR: Please choose a value of h that is less than 1 and greater than 0!" << std::endl;
  }

  // compute forward difference
  dy_F = forwardDiff(h, val);

  // compute center difference
  dy_C = centerDiff(h, val);

  // compare the errors
  // print results
  std::cout << "Actual value = " << cos(val) << std::endl;
  std::cout << "Forward difference = " << dy_F << " (Error = " << errPercent(dy_F, cos(val)) << " %)" << std::endl;
  std::cout << "Center difference = " << dy_C << " (Error = " << errPercent(dy_C, cos(val)) << " %)" << std::endl;

  return 0;
}

double forwardDiff(double h, double x)
{
  return (sin(x + h) - sin(x))/h;
}

double centerDiff(double h, double x)
{
  return (sin(x + h) - sin(x - h))/(2*h);
}

double errPercent(double x, double y)
{ // x is value observed
  // y is value expected

  return fabs((x - y)/y)*100.0;
}