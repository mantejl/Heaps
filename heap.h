#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <utility>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> items; 
  PComparator compare; 
  int n; 

  // trickle down function 
  void trickleDown(int index); 

  // trickle up function 
  void trickleUp(int index); 

};

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) {
  compare = c; 
  n = m;  
  //items.push_back(NULL); 
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() {
}

// Add implementation of member functions here
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
  return items.size(); 
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
  // bool empty = false; 
  // if (items.size() == 1) {
  //   empty = true; 
  // }
  //return empty; 
  return items.empty(); 
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) {
  items.push_back(item); 
  trickleUp(items.size()-1);  
}



// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("The Heap is Empty"); 
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return items.front(); 
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("The Heap is Empty"); 
  }
  items[0] = items.back(); 
  items.pop_back(); 
  trickleDown(0); 
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleDown(int index) {
  int left = (index * n) + 1;
  int right = (index * n) + 2; 
  if (left > items.size() && right > items.size()) { 
    return; 
  }
  int smaller = left; 
  for ( int i = 0; i < n; i++) {
    if ((smaller+1) + i < items.size()) {
      int r = smaller + 1 + i;  
      if (compare(items[r], items[smaller])) {
        smaller = r; 
        }
      }
    }
  if (compare(items[smaller], items[index])) {
    std::swap(items[index], items[smaller]); 
    trickleDown(smaller); 
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int index) {
  int parent = (index-1)/n; 
  while (parent >= 0 && compare(items[index], items[parent]) ) {
    std::swap(items[parent],items[index]); 
    index = parent; 
    parent = (index-1)/n; 
  }
}

#endif
