#include <iostream> 
 
using namespace std; 
 
void printBinInt(int a) { 
 
 unsigned int order = 32; 
 unsigned int mask = 1 << (order - 1); 
 
 for (int i = 1; i <= order; i++) { 
  putchar(a & mask ? '1' : '0'); 
  a <<= 1; 
  if (i % 8 == 0) 
   putchar(' '); 
  if (i % order - 1 == 0) 
   putchar(' '); 
 } 
 cout << "Binary"; 
 cout << "\n"; 
} 
 
void printBinFloat(float b) { 
 
 union { 
  float f; 
  int h; 
 }; 
 f = b; 
 cout << "Float " << b << " is "; 
 unsigned int order = 32; 
 unsigned int mask = 1 << (order - 1); 
 
 for (int i = 1; i <= order; i++) { 
  putchar(h & mask ? '1' : '0'); 
  h <<= 1; 
  if (i % 8 == 0) 
   putchar(' '); 
  if (i % order - 1 == 0) 
   putchar(' '); 
 } 
 cout << "Binary"; 
 cout << "\n"; 
 
  
} 
 
void printBinDouble(double c) { 
 union { 
  double d; 
  int h[2]; 
 }; 
 d = c; 
 unsigned int mask = 1 << 31; 
 cout << "Double " << double(c) << " is "; 
 for (int j = 0; j < 2; j++) { 
  for (int i = 0; i < 32; i++, mask >>= 1) { 
   putchar(h[1 - j] & mask ? '1' : '0'); 
   if (i % 8 == 0) 
    putchar(' '); 
   if (j == 0 && i == 0) { 
    putchar(' '); 
   } 
  } 
  mask = 1 << 31; 
 } 
 cout << " Binary" << endl; 
} 
 
int main() 
{ 
 int a; 
 float b; 
 double c; 
 int i;  

 cout << sizeof(int) << " " << sizeof(short int) <<  " "  << sizeof(long int) << " " << sizeof(float) << " " << sizeof(double) << " " << sizeof(long double) << " " << sizeof(char) << " " << sizeof(bool) << endl; 
 
 cin >> a; 
 cout << "Int " << a << " is "; 
 printBinInt(a); 
 
 cin >> b; 
 printBinFloat(b); 
 
 cin >> c; 
 printBinDouble(c); 
 
}
