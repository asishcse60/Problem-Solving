#include <iostream>
#include <cassert>
 
using namespace std;
 
double mysqrt(double x)
{
  assert(x >= 0);
 
  if (x < 1){
    double xinv = 1 / x;
    double xinv_sqrt = mysqrt(xinv);
    return 1 / xinv_sqrt;
  }
 
  double upperBound = x;
  double lowerBound = 0;
  double val = x / 2;
 
  while (abs(val * val - x) > 0.00000001){
    if (val * val > x){
      upperBound = val;
    }
    else{
      lowerBound = val;
    }
 
    val = (upperBound + lowerBound) / 2;
  }
   
  return val;
}
 
 
int main()
{
  cout << "mysqrt(0) = " << mysqrt(0) << endl;
  cout << "mysqrt(0.01) = " << mysqrt(0.01) << endl;
 
  cout << "mysqrt(2) = " << mysqrt(2) << endl;
  cout << "mysqrt(3) = " << mysqrt(3) << endl;
  cout << "mysqrt(5) = " << mysqrt(5) << endl;
  cout << "mysqrt(100) = " << mysqrt(100) << endl;
 
  return 0;
}