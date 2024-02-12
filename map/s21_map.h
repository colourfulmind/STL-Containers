#ifndef CPP2_S21_CONTAINERS_1_SRC_MAP_S21_MAP_H_
#define CPP2_S21_CONTAINERS_1_SRC_MAP_S21_MAP_H_

#include "../tree/s21_tree.h"

namespace S21 {
template <typename K, typename V>
class Map : public Tree<K, V> {
 public:
  // CONSTRUCTORS
  Map() : Tree<K, V>(){};
  Map(std::initializer_list<typename Tree<K, V>::value_type> const& items)
      : Tree<K, V>(items){};
  Map(const Map& m) : Tree<K, V>(m){};
  Map(Map&& m) noexcept : Tree<K, V>(std::move(m)){};

  // DESTRUCTOR
  ~Map() = default;

  // OVERLOAD OPERATORS
  Map& operator=(Map&& m) noexcept {
    Tree<K, V>::operator=(std::move(m));
    return *this;
  }
  V& operator[](const K& key) {
    auto it = this->Begin();
    if (!this->Contains(key)) {
      std::pair<K, V> el{key, it->second};
      std::pair<typename Tree<K, V>::Iterator, bool> res_it = this->Insert(el);
      return res_it.first->second;
    } else {
      for (; it != this->End(); ++it)
        if (it->first == key) return it->second;
    }
    return it->second;
  }

  // BASIC METHODS
  const V& At(const K& key) const {
    V& res = (V&)fake;
    auto tmp = this;
    At_(key, res, (Map<K, V>*)tmp);
    return res;
  }
  std::pair<typename Tree<K, V>::Iterator, bool> Insert(
      const typename Tree<K, V>::value_type& value) noexcept override {
    return Tree<K, V>::Insert(value);
  }
  std::pair<typename Tree<K, V>::Iterator, bool> Insert(const K& key,
                                                        const V& obj) {
    typename Tree<K, V>::Iterator it;
    bool is_inserted = false;
    std::pair<K, V> elem{key, obj};
    this->Insert_(elem, it, is_inserted);
    std::pair<typename Tree<K, V>::Iterator, bool> res = {it, is_inserted};
    return res;
  }
  std::pair<typename Tree<K, V>::Iterator, bool> InsertOrAssign(const K& key,
                                                                const V& obj) {
    std::pair<typename Tree<K, V>::Iterator, bool> res_it;
    res_it = Insert(key, obj);
    if (!res_it.second) {
      auto it = this->Begin();
      while (it->first != key) ++it;
      res_it.first.SetTree(it.GetTree());
      res_it.first->second = obj;
    }
    return res_it;
  }

 private:
  V fake = V();
  void At_(const K& key, V& res, Map<K, V>* tr) const {
    if (!tr->root_ ||
        (!tr->left_ && !tr->right_ && tr->root_->element_.first != key))
      throw std::out_of_range("Key does not exist");

    if (key < tr->root_->element_.first) {
      Map<K, V>::At_(key, res, (Map<K, V>*)tr->left_);
    } else if (key > tr->root_->element_.first) {
      Map<K, V>::At_(key, res, (Map<K, V>*)tr->right_);
    } else {
      res = tr->root_->element_.second;
    }
  }
};
}  // namespace S21

#endif  // CPP2_S21_CONTAINERS_1_SRC_MAP_S21_MAP_H_
