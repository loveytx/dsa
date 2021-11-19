#include<iostream>
using namespace std;


//------bitsift----
int main(){
    int x =14;
   int y = x<<2;//adds 2 zero bits to the left side of the number 14(1110) and 56(111000) as we can see two bits have been added in 14 to make it 56 
   cout<<y<<"\n";

   int z =  x>>2;  //two bits have been removed from the 14(1110) and it converted into 3(11).
   cout<<z<<"\n";

//------bitoperators----
   int a = 22 & 26;  //we can use or(|) ,xor(^),not(~) and other operators too
   cout<<a<<"\n";
   
//------bitmasks----

   for (int k = 31; k >= 0; k--) {//this code will print exact representation of x in 32 bits
   if (x&(1<<k)) cout << "1";  
   else cout << "0";
   }

    return 0;
}