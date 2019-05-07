#include "sky_t.hpp"

namespace CyA
{
        void sky_t::write(ostream& os) const
        {
            os << "NAME: CyA"<< size() << endl;  //imprime datos relativos a la ejecucion de sky
            os << "TYPE: TSP" << endl;
            os << "COMMENT: Testing problem from CyA of " << size() << "-city TSP" << endl;
            os << "DIMENSION: " << size() << endl;
            os << "EDGE_WEIGHT_TYPE: EUC_2D" << endl;
            os << "DISPLAY_DATA_TYPE: COORD_DISPLAY" << endl;
            os << "NODE_COORD_SECTION" << endl;

            const int sz = size();
            
            for(int i = 0; i < sz; i++)     //imprime todos los puntos de sky
                os << setw(4) << i + 1 << " " << at(i) << endl;

            os << "EOF" << endl;  //imprime final de documento
        }
        
        void sky_t::generate(int x_sz, int y_sz, int sz) //generar  tantos puntos como sz con un tamaño max de x_sz por y_sz
        {
            default_random_engine generator(1);
            uniform_real_distribution<double> distribution_x(0, x_sz);  //marcamos los limites de x
            uniform_real_distribution<double> distribution_y(0, y_sz);  //marcamos los limites de x
            
            clear();
            
            for(int i = 0; i < sz; i++) {
                
                const double x = distribution_x(generator); //crea un punto aleatorio x dentro de los limites
                const double y = distribution_y(generator); //crea un punto aleatorio y dentro de los limites
                
                push_back(point_t(x, y));  //guarda el punto dentro de la funcion llamante
            }
        }
}

ostream& operator<<(ostream& os, const CyA::sky_t& a) //sobrecarga de operador << para la imprecion de elementos
{
    a.write(os);
    return os;
}