/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <algorithm>

using namespace std;

#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
	if ( curDim >= Dim || curDim < 0) {
    return false;
  }
  if (first[curDim] == second[curDim]) {
    bool set = first < second;
    return set;
  }
  bool fin = first[curDim] < second[curDim];
  return fin;
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    double cdist = 0;
    double pdist = 0;

    for (int i = 0; i < Dim; i++) {
       	pdist += ((target[i]-potential[i])*(target[i]-potential[i]));
        cdist += ((target[i]-currentBest[i])*(target[i]-currentBest[i]));
    }
    if (cdist == pdist) {
      return potential < currentBest;
    }
    bool fin = pdist < cdist;
    return fin;
}

template <int Dim>
unsigned KDTree<Dim>::quickSelectposition(vector<Point<Dim>>& list, int dimension, unsigned left, unsigned right, unsigned pivotIndex) {

  	Point<Dim> pivotValue = list[pivotIndex];
  	Point<Dim> temp = list[pivotIndex];

  	list[pivotIndex] = list[right];
  	list[right] = temp;

  	unsigned storeIndex = left;
  	
  	for (unsigned i = left;i < right; i++) {
    	if (smallerDimVal(list[i], pivotValue, dimension)) {
      		temp = list[storeIndex];
      		list[storeIndex] = list[i];
      		list[i] = temp;
      		storeIndex += 1;
    	}
  	}
  	temp = list[storeIndex];
  	list[storeIndex] = list[right];
  	list[right] = temp;
  	return storeIndex;
}

template <int Dim>
Point<Dim>& KDTree<Dim>::quickSelect(vector<Point<Dim>>& list, int dimension, unsigned left, unsigned right, unsigned k){
  	if (left == right) {
      return list[left];
    }
  	unsigned pivot = k;
  	pivot = quickSelectposition(list, dimension, left, right, pivot);
  	if (k == pivot) {
      return list[k];
    }
  	if (k < pivot) {
      return quickSelect(list, dimension, left, pivot - 1, k);
    }
  	else {
      return quickSelect(list, dimension, pivot + 1, right, k);
    }
}

template <int Dim>
typename KDTree<Dim>::KDTreeNode* KDTree<Dim>::ctorHelper(vector<Point<Dim>>& points_, int dimension, unsigned left, unsigned right){
  	if (left < 0 || right < 0 || left >= points_.size() || right >= points_.size() || points_.empty()) {
      return NULL;
    }
    
  	if (left > right) {
      return NULL;
    }
  	unsigned med = (left + right) / 2;

  	KDTreeNode* subroot_ = new KDTreeNode(quickSelect(points_, dimension % Dim, left, right, med));

  	size += 1;
  	dimension += 1;

  	subroot_->left = ctorHelper(points_, dimension,left, med - 1);
  	subroot_->right = ctorHelper(points_, dimension, med + 1, right);

 	  return subroot_;
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    size = 0;

    vector<Point<Dim>> points_;

    points_.assign(newPoints.begin(), newPoints.end());
    root = ctorHelper(points_, size, size, points_.size() - 1);
}

template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
	copy(this->root, other.root);
	size = other.size;
}

template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  	if (this != NULL) {
      clear(root);
    }
  	copy(this->root, rhs.root);

  	size = rhs.size;

  	return *this;
}

template <int Dim>
KDTree<Dim>::~KDTree() {
  	clear(root);
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const {
    return findNearestNeighbor(root, query, 0);
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(KDTreeNode * subroot, const Point<Dim>& query, int dimension) const {
	Point<Dim> currBest = subroot->point;
	bool c;

	if (subroot->left == NULL && subroot->right == NULL) {
    return subroot->point;
  }

	if (smallerDimVal(query, subroot->point, dimension) == true) {
		if (subroot->left == NULL)  {
      currBest = findNearestNeighbor(subroot->right, query, (dimension + 1) % Dim);
    }
		else {
      currBest = findNearestNeighbor(subroot->left, query, (dimension + 1) % Dim);
    }
		c = true;
	}
	else {
		if (subroot->right == NULL) {
      currBest = findNearestNeighbor(subroot->left, query, (dimension + 1) % Dim);
    }
		else {
      currBest = findNearestNeighbor(subroot->right, query, (dimension + 1) % Dim);
    }
		c = false;
	}

	if (shouldReplace(query, currBest, subroot->point) == true) {
    currBest = subroot->point;
  }
	
	double rad = 0;

	for (int i = 0; i < Dim; i++) {
		rad += (query[i] - currBest[i]) * (query[i] - currBest[i]);
	}

	double dist = subroot->point[dimension] - query[dimension];
	dist = dist * dist;

	if (dist <= rad) {
		KDTreeNode * need_to_check = c ? subroot->right : subroot->left;

		if (need_to_check != NULL) {
			Point<Dim> nextBest = findNearestNeighbor(need_to_check, query, (dimension + 1) % Dim);

			if (shouldReplace(query, currBest, nextBest)) {
        currBest = nextBest;
      }
		}
	}
	return currBest;
}


template <int Dim>
void KDTree<Dim>::clear(KDTreeNode * subroot) {
	if (subroot == NULL) {
    return;
  }
	if (subroot->left != NULL) {
    clear(subroot->left);
  }
	if (subroot->right != NULL) {
    clear(subroot->right);
  }

	delete subroot;
	subroot = NULL;
}

template <int Dim>
void KDTree<Dim>::copy(KDTreeNode * subroot, KDTreeNode * othersubroot) {

	subroot = new KDTreeNode();
	subroot->point = othersubroot->point;
	copy(subroot->left, othersubroot->left);
	copy(subroot->right, othersubroot->right);
}