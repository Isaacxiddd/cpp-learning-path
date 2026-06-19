#include <iostream> 
using namespace std;


// haz un programa que use un estruc que reciba una fecha y te diga si ese año era bisiesto

struct Fecha 
{ 
   int dia; 
   int mes; 
   int anio; 
}; 

Fecha fecha(int d,int m,int a) 
{ 
return {d,m,a}; 
}

Fecha f = {2,10,1970};



bool esDivisiblePor(int a, int b){
   bool divisible = false;
    if(a % b == 0){
     divisible = false;
    }
 }




 bool esAnioBisiesto(int anio)
{
   bool esBisiesto = false; 
 
   if( esDivisiblePor(anio,4) ) 
   { 
      esBisiesto=true; 
   }  
   else 
   { 
      if(esDivisiblePor(anio,400) && 
        !esDivisiblePor(anio,100))  
      { 
         esBisiesto=true; 
      } 
   }  
 
   return esBisiesto;

int main(){
   cout >> escribe un dia >>; 
   cin >> a;
   cout >> escribe un mes >>; 
   cin >> b;
   cout >> escribe un año >>; 
   cin >> c;
   Fecha f1 = fecha(a,b,c); 
   esAnioBisiesto (f1.mes);
   }
} 
