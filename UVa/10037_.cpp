// =====================================================================================
//
//       Filename:  10037-bridge.cpp
//
//    Description:  UVA 10037
//                  Pensei em utilizar um set, pois ele ordena sozinho. Mas poder acessar
//                  as posições direto, sem iterators é mais simples.
//
//        Version:  1.0
//        Created:  04/02/2011 08:36:58 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), juliob91(at)gmail.com
//        Company:  UFSCar
//
// =====================================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned short int USI;

int main() {
    USI casos,pessoas,tempo,t1,t2;
    int i,tempo_total;

    vector<USI> tempos;
    vector<USI> saida;

    cin>>casos;
    cin.ignore(2);

    while(casos--) {
        cin>>pessoas;

        for(i=0;i<pessoas;i++) {
            cin>>tempo;
            tempos.push_back(tempo);
        }

        // Ordena o vetor
        sort(tempos.begin(),tempos.end());

        // Caso só exista uma pessoa
        if(pessoas==1)
            cout<<tempos.at(0)<<endl<<tempos.at(0)<<endl;
        else {
        // Caso só existam duas pessoas
            if(pessoas==2)
                cout<<tempos.at(1)<<endl<<tempos.at(0)<<" "<<tempos.at(1)<<endl;

            // Mais de duas pessoas
            else {
                tempo_total=0;
                i=pessoas-1;

                while(i>2) {
                    t1=2*tempos.at(0)+tempos.at(i)+tempos.at(i-1);
                    t2=2*tempos.at(1)+tempos.at(0)+tempos.at(i);

                    if(t1<t2) {
                        tempo_total+=t1;

                        saida.push_back(tempos.at(0));saida.push_back(tempos.at(i));
                        saida.push_back(tempos.at(0));
                        saida.push_back(tempos.at(0));saida.push_back(tempos.at(i-1));
                        saida.push_back(tempos.at(0));
                    } else {
                        tempo_total+=t2;

                        saida.push_back(tempos.at(0));saida.push_back(tempos.at(1));
                        saida.push_back(tempos.at(0));
                        saida.push_back(tempos.at(i-1));saida.push_back(tempos.at(i));
                        saida.push_back(tempos.at(1));
                    }
                    i-=2;
                }

                // Tinha um número par de pessoas i==1
                // Os dois mais rápidos voltam juntos
                if(pessoas%2==0) {
                    tempo_total+=tempos.at(1);
                    saida.push_back(tempos.at(0));saida.push_back(tempos.at(1));
                }
                // Tinha um número ímpar de pessoas
                // Tem que atravessar os 3 mais rápidos
                if(pessoas%2==1) {
                    tempo_total+=tempos.at(0)+tempos.at(1)+tempos.at(2);

                    saida.push_back(tempos.at(0));saida.push_back(tempos.at(1));
                    saida.push_back(tempos.at(0));
                    saida.push_back(tempos.at(0));saida.push_back(tempos.at(2));
                }

                cout<<tempo_total<<endl;
                cout<<saida.at(0)<<" "<<saida.at(1)<<endl;
                for(i=4;i<saida.size();i+=3) {
                    cout<<saida.at(i-2)<<endl<<saida.at(i-1)<<" "<<saida.at(i)<<endl;
                }
            }
        }

        if(casos)
            cout<<endl;

        saida.clear();
        tempos.clear();
    }

    return 0;
}
