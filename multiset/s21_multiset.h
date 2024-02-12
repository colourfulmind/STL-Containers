#ifndef CPP2_S21_CONTAINERS_1_SRC_MULTISET_S21_MULTISET_H_
#define CPP2_S21_CONTAINERS_1_SRC_MULTISET_S21_MULTISET_H_

#include "../set/s21_set.h"

namespace S21 {
template <typename K>
class MultiSet : public Set<K> {
 public:
  using key_type = typename Set<K>::key_type;
  using value_type = typename Set<K>::value_type;

  MultiSet() : Set<K>() {}
  MultiSet(std::initializer_list<value_type> const &items) : Set<K>(items) {}
  MultiSet(const MultiSet &s) : Set<K>(s){};
  MultiSet(MultiSet &&s) noexcept : Set<K>(std::move(s)){};
  ~MultiSet() = default;

  MultiSet &operator=(MultiSet &&s) noexcept {
    Set<K>::operator=(std::move(s));
    return *this;
  }

  std::pair<typename Set<K>::iterator, bool> Insert(
      const value_type &value) noexcept {
    std::pair<key_type, value_type> tmp_el{value, value};
    typename Tree<K, K>::iterator tree_it;
    bool is_inserted = false;
    std::pair<K, K> val{value, value};
    this->MultiSetInsert_(val, tree_it, is_inserted);
    typename Set<K>::SetIterator set_it(tree_it);
    std::pair<typename Set<K>::SetIterator, bool> res{set_it, is_inserted};
    return res;
  }
};
}  // namespace S21

#endif  // CPP2_S21_CONTAINERS_1_SRC_MULTISET_S21_MULTISET_H_
