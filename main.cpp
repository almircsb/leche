/*
ID: almircs1
LANG: C++
TASK: milk2
*/
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main()
{
    ifstream finn("milk2.in");
    ofstream fout("milk2.out");
    int t,ini,fin,final=0,inicio=0,mayor=0,mayper=0,tiempo=0,tiempoper=0;
    map <int, int> tiempos;
    finn>>t;
    for(int i=0;i<t;i++){
        finn>>ini>>fin;
        tiempos.insert(pair<int, int>(ini,fin));
    }
    map<int, int>::iterator iti,itf;
    map<int, int>::iterator itinc=tiempos.begin();itinc++;
    for (iti=tiempos.begin(); iti!=tiempos.end(); iti++){
    //cout << it->first << " => " << it->second << '\n';
      inicio=(*iti).first;
      final=(*iti).second;
      if((itinc==tiempos.end())&&(iti==tiempos.begin())){ fout<<"saliendo";
        mayor=final-inicio;
        mayper=0;
        break;
      }
        //fout<<"inicio:"<<inicio<<" final:"<<final<<endl;
        for(itf=iti; itf!=tiempos.end(); itf++){
           //  fout<<"siguiente inicio:"<<(*itinc).first<<" menor a finactual:"<<(*itf).second<<endl;
             //fout<<"analizando fila itf.first:"<<(*itf).first<<" itinc:"<<(*itinc).first<<endl;
             //fout<<"siguiente inicio:"<<(*itinc).first<<" menor a finactual:"<<(*itf).second<<endl;

            if( (*itinc).first < (*itf).second ){//el tiempo final termino
            final=(*itinc).second;
            //fout<<"si es menor, entonces el nuevo final es:"<<final<<endl;
            itinc++;
            }else{//siguen ordeñando, continua
            tiempoper=(*itinc).first - (*itf).second;
                if(tiempoper>mayper)mayper=tiempoper;
            break;
            }/

        }
        tiempo=final-inicio;
        if(tiempo>mayor){mayor=tiempo;
      //  fout<<"nuevo tiempo:"<<tiempo<<"desde inicio:"<<inicio<<" hasta final:"<<final<<endl;
    }
    iti=itinc;iti--;
    //fout<<"iti esta apuntando a "<<(*iti).first<<(*iti).second<<"donde apunta itinc antes de++"<<endl;
    itinc++;

    //le damos al inicio el valor de final
    //fout<<endl;
    }
    //fout<<endl;
   fout<<mayor<<" "<<mayper<<endl;
    return 0;
}
