#ifndef CPP2_S21_CONTAINERS_1_SRC_QUEUE_S21_QUEUE_H_
#define CPP2_S21_CONTAINERS_1_SRC_QUEUE_S21_QUEUE_H_

#include <iostream>

namespace S21 {
template <typename T>
class Queue {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  Queue() noexcept;
  Queue(std::initializer_list<value_type> const &items) noexcept;
  Queue(const Queue &other);
  Queue(Queue &&other) noexcept;

  ~Queue();

  Queue &operator=(const Queue &other) noexcept;
  Queue &operator=(Queue &&other) noexcept;

  const_reference Front();
  const_reference Back();
  void Pop();
  void Push(const_reference value) noexcept;
  bool Empty() const noexcept;
  size_type Size() const noexcept;
  void Swap(Queue<T> &other) noexcept {
    Node_ *tmp_head = head_;
    Node_ *tmp_tail = tail_;
    size_t tmp_size = other.size_;
    if (head_ && other.head_) {
      head_ = other.head_;
      other.head_ = tmp_head;
    }
    if (tail_ && other.tail_) {
      tail_ = other.tail_;
      other.tail_ = tmp_tail;
    }
    other.size_ = size_;
    size_ = tmp_size;
  };

 private:
  typedef struct Node_ {
    value_type value_;
    Node_ *ptr_prev_;

    explicit Node_(value_type value) noexcept
        : value_(value), ptr_prev_(nullptr) {}
  } Node_;

  Node_ *head_;
  Node_ *tail_;
  size_type size_;
  void Clear_();
  value_type At_(int i) const;
};

template <typename T>
inline Queue<T>::Queue() noexcept : head_(nullptr), tail_(nullptr), size_(0) {}

template <typename T>
inline Queue<T>::Queue(const std::initializer_list<value_type> &items) noexcept
    : head_(nullptr), tail_(nullptr), size_(0) {
  for (value_type i : items) {
    Push(i);
  }
}

template <typename T>
inline Queue<T>::Queue(const Queue<T> &other)
    : head_(nullptr), tail_(nullptr), size_(0) {
  *this = other;
}

template <typename T>
inline Queue<T>::Queue(Queue<T> &&other) noexcept
    : head_(nullptr), tail_(nullptr), size_(0) {
  *this = std::move(other);
}

template <typename T>
inline Queue<T>::~Queue() {
  Clear_();
}

template <typename T>
inline Queue<T> &Queue<T>::operator=(const Queue<T> &other) noexcept {
  if (this != &other) {
    Clear_();
    size_type i = 0;
    while (i < other.size_) {
      Push(other.At_(i));
      i++;
    }
  }
  return *this;
}

template <typename T>
inline Queue<T> &Queue<T>::operator=(Queue<T> &&other) noexcept {
  if (this != &other) {
    Clear_();
    head_ = other.head_;
    tail_ = other.tail_;
    size_ = other.size_;
    other.tail_ = nullptr;
    other.head_ = nullptr;
    other.size_ = 0;
  }
  return *this;
}

template <typename T>
inline void Queue<T>::Pop() {
  if (!head_) throw std::logic_error("Queue is empty");
  Node_ *prev_node = head_->ptr_prev_;
  delete head_;
  head_ = prev_node;
  --size_;
}

template <typename T>
inline void Queue<T>::Push(const_reference value) noexcept {
  Node_ *new_node = new Node_(value);
  if (!head_) {
    head_ = new_node;
  } else if (!tail_) {
    head_->ptr_prev_ = new_node;
    tail_ = new_node;
  } else {
    tail_->ptr_prev_ = new_node;
    tail_ = new_node;
  }
  ++size_;
}

template <typename T>
inline bool Queue<T>::Empty() const noexcept {
  return size_ == 0;
}

template <typename T>
inline typename Queue<T>::const_reference Queue<T>::Front() {
  if (!head_) throw std::logic_error("Queue is empty");
  return head_->value_;
}

template <typename T>
inline typename Queue<T>::const_reference Queue<T>::Back() {
  if (!tail_) throw std::logic_error("Queue is empty");
  return tail_->value_;
}

template <typename T>
inline typename Queue<T>::value_type Queue<T>::At_(int i) const {
  if (i < 0 || i >= (int)size_) throw std::out_of_range("Index out of range");
  value_type result = T();
  Node_ *tmp_head = head_;
  for (int j = 0; j < i; j++) {
    tmp_head = tmp_head->ptr_prev_;
  }
  result = tmp_head->value_;
  return result;
}

template <typename T>
inline void Queue<T>::Clear_() {
  while (head_) {
    Pop();
  }
  if (tail_) tail_ = nullptr;
}

template <typename T>
inline typename Queue<T>::size_type Queue<T>::Size() const noexcept {
  return size_;
}
}  // namespace S21

#endif  // CPP2_S21_CONTAINERS_1_SRC_QUEUE_S21_QUEUE_H_
