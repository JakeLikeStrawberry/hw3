#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
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
void heapTrickleUp(int loc);
void heapTrickleDown(int loc);
std::vector<T> heapVect;
PComparator compy;
int maxChildren;

};

// Add implementation of member functions here

//TrickleUp
template <typename T, typename PComparator>
void Heap<T, PComparator>::heapTrickleUp(int loc){
  int pNode = (loc-1)/maxChildren;
  while (compy(heapVect[loc], heapVect[pNode])){
    std::swap(heapVect[pNode], heapVect[loc]);
    if (pNode == 0){
      break;
    }
    loc = pNode;
    pNode = (loc-1)/maxChildren;
  }
}


//TrickleDown
template <typename T, typename PComparator>
void Heap<T, PComparator>::heapTrickleDown(int fNode){

  unsigned int smallChild = (fNode * maxChildren) + 1;
  //unsigned int rChild = (fNode * maxChildren) + 2;
  unsigned int rChild;
    
    if (smallChild >= heapVect.size()) {      //ensuring that the function can run, checks if each child exist/greater than heap size
      return;
    }

    // int i = 0;
    // while (i < maxChildren){
    //   if (rChild+i < heapVect.size()){
    //     if(compy(heapVect[rChild+i], heapVect[smallChild])){
    //       smallChild = rChild+i;
    //     }
    //   }
    //   i++;
    // }

    for(int i = 0; i < maxChildren; i++){
      rChild = (fNode * maxChildren) + i + 1;
      if (rChild >= heapVect.size()){ 
        break; 
       } //loops through, uses i for aryness of heap
        //rChild + i
        if (compy(heapVect[rChild], heapVect[smallChild])){       //compares them accordingly using functor
        
          //smallChild = rChild +i;   
          smallChild = rChild;           
        }
      
    }
    

  
  if (compy(heapVect[smallChild], heapVect[fNode])){
    std::swap(heapVect[smallChild], heapVect[fNode]);                 //compares them w current node and both childs, swaps accoridngly   
    heapTrickleDown(smallChild);  
  }
}


//Constructor
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c){

maxChildren = m;            //set data members
compy = c;


}

//Destructor
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){
    
 }

//Push
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){

  heapVect.push_back(item);                 //add item
  heapTrickleUp(heapVect.size()-1);         //call trickleup
}


//Empty
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{

  return heapVect.size() == 0;            //returns bool
  
}


//Size
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{

//size_t ans = heapVect.size();
//return ans
return heapVect.size();          //returns size

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

      throw std::underflow_error("Empty Heap");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return heapVect[0];       //returns top element (first in vector)

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
      throw std::underflow_error("Empty Heap");

  }
  heapVect[0] = heapVect.back();        //sets first item to last item
  heapVect.pop_back();
  heapTrickleDown(0);     //calls trickledown


}





#endif

