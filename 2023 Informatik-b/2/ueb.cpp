#include <iostream>
#include <vector>
#include <string>

int main() {

    // 1.

    int eingabe0 = -1;

    std::cout << "Aufgabe (1) oder (2)?" << std::endl;
    std::cin >> eingabe0;
    
    if (eingabe0 == 1){
        int eingabe1 = -1;
        std::vector<int> zahlenfolge;
        int min = 0;
        int max = 0;
        
        while (true) {
        

            std::cout << "Geben Sie eine Zahl der Zahlenfolge ein, mit 0 geben sie MIN und MAX aus, mit 9999 geben sie den Mittelwert aus: " << std::endl;
            std::cin >> eingabe1;

            if (eingabe1 == 0) {
                
                for (unsigned i = 0; i < zahlenfolge.size(); i++){
                
                    if (zahlenfolge[i] < min){
                        min = zahlenfolge[i];
                    }
                    
                    if (zahlenfolge[i] > max){
                        max = zahlenfolge[i];
                    }

                }
                
                std::cout << "Das Maximum der Zahlenfolge ist: " << max << std::endl;
                std::cout << "Das Minimum der Zahlenfolge ist: " << min << std::endl;  

            break;

            }

            if (eingabe1 == 9999) {

                float summe = 0;

                for (unsigned i = 0; i < zahlenfolge.size(); i++){
                    summe += zahlenfolge[i];
                }

                double mittelwert = summe / zahlenfolge.size();

                std::cout << "Der Mittelwert der Zahlenfolge ist: " << mittelwert << std::endl;
                
                break;
            
            }

            zahlenfolge.push_back(eingabe1);

        }


    }

    // 2.

    if (eingabe0 == 2){


        char eingabe01;
        std::cout << "Teilaufgabe (a) oder (b) ?" << std::endl;
        std::cin >> eingabe01;

        // 2 a)
        if (eingabe01 == 'a'){

            int eingabe2 = -1;
            std::cout << "Geben Sie eine Zahl größer 0 ein, von der die Quersumme berechnet werden soll" << std::endl;
            std::cin >> eingabe2;

            int eingabe3 = -1;
            std::cout << "Soll die Quersumme mit einer while (0) oder for (1) Schleife berechnet werden?" << std::endl;
            std::cin >> eingabe3;

            if (eingabe3 == 0){
            
                int quersummewhile = 0;

                while (eingabe2 > 0){
                    quersummewhile += eingabe2 % 10;
                    eingabe2 /= 10;
                }
                
                std::cout << "Die Quersumme der Zahl ist: " << quersummewhile << std::endl;
            
            }

            if (eingabe3 == 1){

                int quersummefor = 0;

                for (quersummefor; eingabe2 > 0; eingabe2 /= 10){
                    quersummefor += eingabe2 % 10;
                }

                std::cout << "Die Quersumme der Zahl ist: " << quersummefor << std::endl;

            }

        }

        // 2 b)
        if (eingabe01 == 'b'){
            int n;
            std::cout << "Geben Sie eine Zahl größer 0 ein: " << std::endl;
            std::cin >> n;

            for (int i = 0; i <= n; i++) {
                std::string output = "";
                if (i % 3 == 0) {
                    std::cout << "bli" << std::endl;
                }
                if (i % 5 == 0) {
                    std::cout << "bla" << std::endl;
                }
                if (i % 7 == 0) {
                    std::cout << "blub" << std::endl;
                }
            }
        }
    }
}


