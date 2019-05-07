#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

#include "point_t.hpp"
#include "sky_t.hpp"
#include "greedy_t.hpp"

//A good code is like a good joke: it doesn't need to be explained with comments

using namespace std;


int main(void)
{
    CyA::sky_t sky;  // sky_t = vector<point_t>   point_t = pair<double, double>       ==> vector<double,double>
    sky.generate(1000, 1000, 600); //generamos 600 puntos con un max de 1000 y un  1000
    
    ofstream os("CyA.tsp"); //Crea un documento llamado CyA.tsp

    os << sky << endl;  //guarda dentro del documento todos los datos de sky

    os.close(); //cierra el documento
    
    CyA::greedy_t G(sky);
    
    vector<CyA::point_t> sequence;
    
    cout << G.NN(sequence) << endl;




    return 0;
}