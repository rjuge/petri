#include "petriTransition.hpp"
#include "petriNetwork.hpp"

using namespace std;

bool petri::Transition::verbose = true;

petri::Transition::Transition(const std::string& transition_name, petri::Network* net)
  : transition_name(transition_name), net(net) {
}

void petri::Transition::addInput(petri::poolIdf input_pool, unsigned int nb_token_required){

  pool_in.push_back(std::make_pair(input_pool, nb_token_required));

}

void petri::Transition::addOutput(petri::poolIdf output_pool, unsigned int nb_token_produced){

  pool_out.push_back(std::make_pair(output_pool, nb_token_produced));

}

petri::Transition::operator bool() const {

  for (auto elem : pool_in) 
    if(net->pool_vect[elem.first].nb_tokens < elem.second)
      return false;
  return true;  
}

void petri::Transition::operator()() const {
  for(auto elem : pool_in)  net->pool_vect[elem.first].nb_tokens -= elem.second;
  for(auto elem : pool_out) net->pool_vect[elem.first].nb_tokens += elem.second;
  if(verbose)
    std::cout << transition_name << std::endl;

}
