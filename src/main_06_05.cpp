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
  std::cout << zeichenWandler(array[0]) << " | " << zeichenWandler(array[1]) << " | " << zeichenWandler(array[2]) << std::endl;
  std::cout << "---------" << std::endl;
  std::cout << zeichenWandler(array[3]) << " | " << zeichenWandler(array[4]) << " | " << zeichenWandler(array[5]) << std::endl;
  std::cout << "---------" << std::endl;
  std::cout << zeichenWandler(array[6]) << " | " << zeichenWandler(array[7]) << " | " << zeichenWandler(array[8]) << std::endl;
}

bool gameOver(int array[])
{
  if ((array[0] == 1 && array[1] == 1 && array[2] == 1) ||
      (array[3] == 1 && array[4] == 1 && array[5] == 1) ||
      (array[6] == 1 && array[7] == 1 && array[8] == 1) ||
      (array[0] == 1 && array[3] == 1 && array[6] == 1) ||
      (array[1] == 1 && array[4] == 1 && array[7] == 1) ||
      (array[2] == 1 && array[5] == 1 && array[8] == 1) ||
      (array[0] == 1 && array[4] == 1 && array[8] == 1) ||
      (array[2] == 1 && array[4] == 1 && array[6] == 1)){
        std::cout << "Spieler 1 hat gewonnen!" << std::endl;
        std::cout << "Game Over" << std::endl;
        return true; 
      }
      else if ((array[0] == 2 && array[1] == 2 && array[2] == 2) ||
               (array[3] == 2 && array[4] == 2 && array[5] == 2) ||
               (array[6] == 2 && array[7] == 2 && array[8] == 2) ||
               (array[0] == 2 && array[3] == 2 && array[6] == 2) ||
               (array[1] == 2 && array[4] == 2 && array[7] == 2) ||
               (array[2] == 2 && array[5] == 2 && array[8] == 2) ||
               (array[0] == 2 && array[4] == 2 && array[8] == 2) ||
               (array[2] == 2 && array[4] == 2 && array[6] == 2))
      {
        std::cout << "Spieler 2 hat gewonnen!" << std::endl;
        std::cout << "Game Over" << std::endl;
        return true;
      }else{
        return false;
      }
}

void eingabeprüfung(int* array, int spieler)
{
  int feld;
  bool eingabe_gueltig=false;
  while(eingabe_gueltig==false)
  {
    std::cout << "Spieler " << spieler << ", bitte wähle ein freies Feld (0-8): ";
    std::cin >> feld;

    if (array[feld] != 1 && array[feld] != 2 && feld>=0 && feld<=8)
    {
      // Eingabe gültig
      array[feld]=spieler;
      eingabe_gueltig=true;
    }else{
      eingabe_gueltig = false;
      std::cout << "Eingabe war nicht gültig! Feld ist bereits besetzt oder Eingabe außerhalb des Spielfeldes! " << std::endl;
    }
  }
  

}

int togglespieler(int spieler){
  switch (spieler)
  {
  case 1:
    return 2;
    break;
  case 2:
    return 1;
     break;
  default:
    return 1;
    break;
  }

}

int main()
{
  int array[9]={0,0,0,0,0,0,0,0,0};

  bool gameover=false;

  int spieler=1;

  while (gameover==false)
  {
    eingabeprüfung(array,spieler);
    spieler=togglespieler(spieler);

    ausgabeSpielfeld(array);

    gameover=gameOver(array);
  }

  return 0;
}