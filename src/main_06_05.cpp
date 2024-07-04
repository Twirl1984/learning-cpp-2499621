#include <iostream>

char zeichenWandler(int in)
{
  char out=' ';
  switch (in)
  {
  case 1:
    out='X';
    break;
  case 2: 
    out='O';
    break;
  default:
    out=' ';
    break;
  }
  return out;
}

void ausgabeSpielfeld(int array[])
{
  std::cout <<"|"<< zeichenWandler(array[0]) << "|" << zeichenWandler(array[1]) << "|" << zeichenWandler(array[2]) << "|" << std::endl;
  std::cout << "|" << zeichenWandler(array[3]) << "|" << zeichenWandler(array[4]) << "|" << zeichenWandler(array[5]) << "|" << std::endl;
  std::cout << "|" << zeichenWandler(array[6]) << "|" << zeichenWandler(array[7]) << "|" << zeichenWandler(array[8]) << "|" << std::endl;
}


int main()
{
  int array[9]={};

  ausgabeSpielfeld(array);

  return 0;
}