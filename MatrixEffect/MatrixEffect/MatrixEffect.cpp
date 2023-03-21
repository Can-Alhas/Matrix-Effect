#include <iostream>
#include <Windows.h>



int Modulus(int iN, int iMod) {
    int iQ = (iN / iMod);
    return iN - (iQ * iMod);
}
char GetChar(int iGenerator, char cBase, int iRange) {
    return (cBase + Modulus(iGenerator, iRange));
}





int main()
{
    
    // Color Code
    // 1 BLUE
    // 2 GREEN  
    // 3 CYAN
    // 4 YELLOW
    

    HANDLE hConsole;
  
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 2); // Color Code
    // 1=BLUE
    // 2=GREEN  
    // 3=CYAN
    // 4=YELLOW
    //....

    char caRow[80] = { ' ' };

    int j{ 7}, k{ 2 }, l{ 5 }, m{ 1 };

    
    while (true) {
         
        //output a random row of characters
        for (int i = 0; i < 88; ++i) {
            int colorCodePick = (i*i % 10 == 5) ? 3 : 2;

            if (caRow[i] != ' ') {
                caRow[i] = GetChar(j + i * i, 33, 30);
                if (((i * i + k) %71) == 0) {
                    SetConsoleTextAttribute(hConsole, colorCodePick);
                }
                else {
                    SetConsoleTextAttribute(hConsole, colorCodePick);
                }
            }
            std::cout << caRow[i];
            SetConsoleTextAttribute(hConsole, 2);
        }
       
        j += 31;
        k += 17;
        l += 47;
        m += 67;
        caRow[Modulus(j, 80)] = ' ';
        caRow[Modulus(k, 80)] = '+';
        caRow[Modulus(l, 80)] = '-';
        caRow[Modulus(m, 80)] = '+';

        

        // DELAY
        Sleep(10);
        
    }
    
    return 0;
}
