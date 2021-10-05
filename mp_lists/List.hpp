/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */

template <class T>
List<T>::List() { 
  // @TODO: graded in MP3.1
    head_ = NULL;
    tail_ = NULL;
    length_ = 0;
}

/**
 * Returns a ListIterator with a position at the beginning of
 * the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::begin() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(head_);
}

/**
 * Returns a ListIterator one past the end of the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::end() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(NULL);
}


/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <typename T>
void List<T>::_destroy() {
  /// @todo Graded in MP3.1

  ListNode* curr = head_;
  while (curr != NULL) {
    ListNode* next = curr->next;
    delete curr;
    curr = next;
  }
  head_ = NULL;
  tail_ = NULL;
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertFront(T const & ndata) {
  /// @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata);

  if ((head_ == NULL && tail_ == NULL)) {
    head_ = newNode;
    tail_ = newNode;
    length_ = 1;
    return;
  }
  head_ -> prev = newNode;
  newNode -> next = head_;
  newNode -> prev = NULL;

  head_ = newNode;

  length_++;

}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertBack(const T & ndata) {
  /// @todo Graded in MP3.1

  ListNode* backNode = new ListNode(ndata);
  if (head_ == NULL && tail_ == NULL) {
    tail_ = backNode;
    head_ = backNode;
    length_ = 1;
    return;
  }

  tail_->next = backNode;
  backNode->prev = tail_;
  backNode->next = NULL;
  tail_ = backNode;
  length_++;

}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List or ListNode objects!
 *
 * This function is also called by the public split() function located in
 * List-given.hpp
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <typename T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {
  /// @todo Graded in MP3.1

  if (splitPoint == 0 || splitPoint >= length_ || start == NULL || start->next == NULL) {
    return start;
  }

  ListNode* curr = start;

  for (int i = 0; i < splitPoint; i++) {
    if (curr->next != NULL) {
      curr = curr->next;
    } else {
      return start;
    }
  }

  if (curr != NULL) {
      tail_ = curr->prev;
      curr->prev->next = NULL;
      curr->prev = NULL;
      return curr;
  }

  return NULL;
}

/**
  * Modifies List using the rules for a TripleRotate.
  *
  * This function will to a wrapped rotation to the left on every three 
  * elements in the list starting for the first three elements. If the 
  * end of the list has a set of 1 or 2 elements, no rotation all be done 
  * on the last 1 or 2 elements.
  * 
  * You may NOT allocate ANY new ListNodes!
  */
template <typename T>
void List<T>::tripleRotate() {
  // @todo Graded in MP3.1

  ListNode* curr = head_;

  int threes = length_/3;

  if (threes > 0) {
    head_ = head_->next;
    head_->prev = NULL;
  }

  
  for (int i = 0; i < threes; i++) {
    if (curr->prev != NULL) {
      curr->prev->next = curr->next;
      curr->next->prev = curr->prev;
    } else {
      curr->next->prev = NULL;
    }
    if (curr->next->next->next == NULL) {
      curr->prev = curr->next->next;
      curr->prev->next = curr;
      
      curr->next = NULL;
    } else {
      curr->next = curr->next->next->next;
      curr->prev = curr->next->prev;
      curr->next->prev = curr;
      curr->prev->next = curr;
    }
    curr = curr->next;
  
  }
}


/**
 * Reverses the current List.
 */
template <typename T>
void List<T>::reverse() {
  reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */

template <typename T>
void List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {
  /// @todo Graded in MP3.1
  if (startPoint == endPoint){
    return;
  }

  ListNode* curr;
  ListNode* temp;
  ListNode* l;
  ListNode* r;
  ListNode* start;
  ListNode* end;
  start = startPoint;
  end = endPoint;

  l = startPoint->prev;
  r = endPoint->next;
  temp = NULL;
  curr = startPoint;

  while (curr != endPoint){
    temp = curr->prev;
    curr->prev = curr->next;
    curr->next = temp;
    curr = curr->prev;
  }

  curr->next = curr->prev;
  curr->prev = l;
  startPoint->next = r;

  if (l != NULL){
    l->next = endPoint;
  }
  else {
    head_ = endPoint;
  }

  if (r != NULL){
    r->prev = startPoint;
  }
  else {
    tail_ = startPoint;
  }
  endPoint = start;
  startPoint = end;
  return;
}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <typename T>
void List<T>::reverseNth(int n) {
  /// @todo Graded in MP3.1

  if (n <= 1 || head_ == NULL) {
    return;
  }
  ListNode *start, *end;
  start = head_;
  end = head_;
  int ys = n - 1;

  while (start != NULL){
    end = start;
    for(int i = 0; i < ys; i++) {

      if (end->next != NULL) {

        end = end->next;
      }
    }
    reverse(start, end);
    start = end->next;
  }

}

/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <typename T>
void List<T>::mergeWith(List<T> & otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <typename T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode* second) {
  /// @todo Graded in MP3.2
  if (first == NULL) {
    return second;
  }
  if (second == NULL) {
    return first;
  }
  if (first == NULL && second == NULL) {
    return NULL;
  }
  ListNode* temp;
  ListNode* curr1;
  ListNode* curr2;
  ListNode* next1;
  ListNode* next2;


  if (second->data < first->data) {
    temp = second;
    second = first;
    first = temp;
    if (first != NULL) {
      first->prev = NULL;
    }
  }
  curr2 = second;
  curr1 = first;
  while (curr2 != NULL) {
    next2 = curr2->next;
    while (curr1 != NULL){
      next1 = curr1->next;
      if (curr2->data < curr1->data){
        curr2->next = curr1;
        curr1->prev->next = curr2;
        curr2->prev = curr1->prev;
        curr1->prev = curr2;
        break;
      }
      else if (next1 == NULL && curr2 != NULL){ //first reaches the end but second still has nodes
          curr1->next = curr2;
          curr2->prev = curr1;
          break;
      }
      else {
        curr1 = next1;
      }
    }

    if (curr2->prev == curr1 && curr1->next == curr2) {
      break;
    }
    curr2 = next2;
  }
  return first;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <typename T>
typename List<T>::ListNode* List<T>::mergesort(ListNode * start, int chainLength) {
  /// @todo Graded in MP3.2
  if (chainLength == 1) {
    start->next = NULL;
    start->prev = NULL;
    return start;
  }
  else {
    int breakp;
    breakp = int(chainLength / 2);
    ListNode* temp = start;
    for (int i = 1; i <= breakp; i++) {
      temp = temp->next;
    }
    if (temp != NULL) {
      temp->prev->next = NULL;
      temp->prev = NULL;
    }
    temp = mergesort(temp, chainLength - breakp);
    start = mergesort(start, breakp);
    start = merge(start, temp);
    return start;
  }

}