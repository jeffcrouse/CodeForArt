#include <iostream>
using namespace std;

int add(int x, int y) { 
  return x+y;
} 

void swap(int *x, int *y) { 
  int temp; 
  temp = *x;
  *x = *y;
  *y = temp;
} 

void dec(int &x) { 
  x--;
} 

int inc(int x) { 
  return x+1;
} 


int main() { 
  int num1, num2; 
  int result; 
  cout << "\nEnter two numbers separated by a space: " << endl; 
  cin >> num1 >> num2;
  cout << "\n num1 is " << num1 << ", num2 is " << num2 << endl;

  result = add(num1, num2);
  cout << "add() result is " << result << endl;
  
  swap(&num1, &num2);
  cout << "after swap() num1=" << num1 << " and num2=" << num2 << endl;
  
  dec(num1);
  cout << "after dec() num1=" << num1 << endl;
  
  result = inc(num2);
  cout << "after inc() num2=" << result << endl;

} 
