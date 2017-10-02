#include "petriPool.hpp"

using namespace std;

petri::Pool::Pool(const std::string& pool_name, unsigned int nb_tokens){
  
  this->pool_name = pool_name;
  this->nb_tokens = nb_tokens;
  

}
