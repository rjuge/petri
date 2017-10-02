#include <iostream>
#include <vector>
#include <petriNetwork.hpp>
#include <petriPool.hpp>

bool petri::Network::operator()() {
  std::cerr << "petri::Network::operator()() : to be done" << std::endl;
  
  std::vector<petri::tranIdf> trans_act;
  int cpt = 0;  
  int randId = 0;

  for (auto elem : trans_vect)
    if(elem)
      trans_act.push_back(cpt);
    cpt++;

  if(trans_act.size()>0)
    randId = rand() % trans_act.size();
    trans_vect[randId]();
    return true; 
       
  return false;
}

petri::poolIdf petri::Network::makePool(const std::string& pool_name, unsigned int nb_tokens) {
  std::cerr << "petri::Network::makePool(\"" << pool_name
	    << "\", " << nb_tokens << ") : to be done" << std::endl;

  
  petri::Pool p(pool_name, nb_tokens);
  pool_vect.push_back(p);


  std::cout << "Pool done" << std::endl;
  return 0;
}
    
petri::tranIdf petri::Network::makeTransition(const std::string& transition_name) {
  std::cerr << "petri::Network::makeTransition(\"" << transition_name
	    << "\") : to be done" << std::endl;
  

  petri::Transition t(transition_name, this); 
  trans_vect.push_back(t);

  std::cout << "Transition done" << std::endl;

  return (trans_vect.size() - 1);
}

void petri::Network::linkIn(tranIdf      transition,
			    poolIdf      pool,
			    unsigned int nb_tokens_in) {
  std::cerr << "petri::Network::linkIn (" << transition
	    << ", " << pool
	    << ", " << nb_tokens_in
	    << ") : to be done" << std::endl;

  trans_vect[transition].addInput(pool, nb_tokens_in);

}

void petri::Network::linkOut(tranIdf      transition,
			     poolIdf      pool,
			     unsigned int nb_tokens_out) {
  std::cerr << "petri::Network::linkOut(" << transition
	    << ", " << pool
	    << ", " << nb_tokens_out
	    << ") : to be done" << std::endl;
  
  trans_vect[transition].addOutput(pool, nb_tokens_out);

}

    
