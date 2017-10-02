#pragma once

#include <iostream>
#include <string>

namespace petri {
  
  using poolIdf = unsigned int;

  class Pool {
  public:

    std::string pool_name;
    unsigned int nb_tokens;

    Pool(const std::string& pool_name, unsigned int nb_tokens);

  };
}
