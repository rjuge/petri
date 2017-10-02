#pragma once
#include "petriPool.hpp"
#include <iostream>
#include <string>
#include <vector>

namespace petri {

  using tranIdf = unsigned int;

  class Network;

  class Transition {
  public:

    std::string transition_name;
    std::vector<std::pair<poolIdf,unsigned int>> pool_in;
    std::vector<std::pair<poolIdf,unsigned int>> pool_out;
    petri::Network* net;

    static bool verbose;

  Transition(const std::string& transition_name);  

  Transition(const std::string& transition_name, std::vector<std::pair<poolIdf,unsigned int>>& pool_in, std::vector<std::pair<poolIdf,unsigned int>>& pool_out, petri::Network* net);

  void addInput(petri::poolIdf input_pool, unsigned int nb_token_required);
                                                                            
  void addOutput(petri::poolIdf output_pool, unsigned int nb_token_produced); 
 
  operator bool()   const;
  
  void operator()() const;
  };

}

