#include <iostream>
#include <math.h>

using namespace std;

int readResistor1() {
  int r1;
  cout << "Type a resistor1:";
  cin >> r1;
  return r1;
}
int readResistor2() {
  int r2;
  cout << "Type a resistor2:";
  cin >> r2;
  return r2;
}
int readResistor3() {
  int r3;
  cout << "Type a resistor3:";
  cin >> r3;
  return r3;
}
void calculate(double r1, double r2, double r3) {
  double res1 = 1 / r1;
  double res2 = 1 / r2;
  double res3 = 1 / r3;
  double r = res1 + res2 + res3;
  printf("Result:\n r=%f \n", r);
}
int main()
{
  int r1 = readResistor1();
  int r2 = readResistor2();
  int r3 = readResistor3();
  calculate(r1, r2, r3);
}

]
