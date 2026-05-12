#include "searchable_bag.hpp"
#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"
#include "set.hpp"



#include <iostream>

int main(int argc, char **argv) {
  if (argc == 1)
    return 1;
  searchable_bag *t = new searchable_tree_bag;
  searchable_bag *a = new searchable_array_bag;

  for (int i = 1; i < argc; i++) {
    t->insert(atoi(argv[i]));
    a->insert(atoi(argv[i]));
  }
  t->print();
  a->print();

  for (int i = 1; i < argc; i++) {
    std::cout << t->has(atoi(argv[i])) << std::endl;
    std::cout << a->has(atoi(argv[i])) << std::endl;
    std::cout << t->has(atoi(argv[i]) - 1) << std::endl;
    std::cout << a->has(atoi(argv[i]) - 1) << std::endl;
  }

  t->clear();
  a->clear();

  const searchable_array_bag tmp(static_cast<searchable_array_bag &>(*a));
  tmp.print();
  tmp.has(1);

  std::cout<< "================ Set part =============" << std::endl;
  set sa(*a);
  set st(*t);
  for (int i = 1; i < argc; i++) {
    st.insert(atoi(argv[i]));
  std::cout<< "================ insert =============" << std::endl;

    sa.insert(atoi(argv[i]));
  std::cout<< "================ insert =============" << std::endl;

    sa.has(atoi(argv[i]));
  std::cout<< "================ has =============" << std::endl;

    sa.print();
  std::cout<< "================ print =============" << std::endl;

    sa.get_bag().print();
  std::cout<< "================ print 2 =============" << std::endl;

    st.print();
  std::cout<< "================ print 3 =============" << std::endl;

    sa.clear();
  std::cout<< "================clear =============" << std::endl;

    sa.insert(
        (int[]){
            1,
            2,
            3,
            4,
        },
        4);
  std::cout<< "================ insert [] =============" << std::endl;
      
    std::cout << std::endl;
  }

  return 0;
}
