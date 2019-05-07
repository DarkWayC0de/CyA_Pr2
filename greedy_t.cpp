#include "greedy_t.hpp"

#include "point_t.hpp"

#include <set>


namespace CyA {

double greedy_t::NN(vector<point_t>& sequence)
{
    set<point_t> pending;          //crea una variable del tipo set que se ordena sigiendo un orden especifico
 
    for(const point_t& p: sky_)    // guarda en pe el valor del punto e itera tantos puntos como posiciones tiene sky recorriendolos
        pending.insert(p);        //guarda los valores de sky_ ordenados crecientemente sobre x
    
    point_t last = sky_[0];       //guarda el primer punto de sky_
    
    pending.erase(last);          // extrae el punto last de pending
    sequence.push_back(last);     // guarda el punto last en sequence
    
    double tour_length = 0;
    
    do {
        point_t best_point    = *pending.begin();  //suponemos el primer valor de pending
        double  best_distance = last.distance(best_point);  //calculamos la distancia con el punto supuesto
        
        for(const point_t& current: pending) {  //recorre los elemento de pendin
            
            const double current_distance = last.distance(current);  //cojemos la posion actual y calculamos la distacia a last
            
            if (current_distance < best_distance) { //verificamos que distancia es menor
                                                        //En caso de ser mejor la distacia cambiamos best_distance y best_point
                best_distance = current_distance;
                best_point    = current;
            }
        }
        
        tour_length += best_distance;    //añade la mejor distancia al contador de distancia
        
        last = best_point;  //sutitulle la mejor distancia calculada por last
        
        pending.erase(last);         // extrae el punto last de pending
        sequence.push_back(last);     // guarda el punto last en sequence

    } while(!pending.empty());  //terminamos cando pendin quede basio
    
    tour_length += last.distance(sequence[0]); //Calculamos  y añadimos la distancia del ultimo punto al primero
    
    return tour_length;
} 

}
