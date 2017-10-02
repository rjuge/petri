#include "petriPool.hpp"

using namespace std;

petri::Pool::Pool(const std::string& pool_name, unsigned int nb_tokens)
  : pool_name(pool_name), nb_tokens(nb_tokens) {
}
