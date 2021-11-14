#include "dsets.h"

using namespace std;

void DisjointSets::addelements(int num) {

	for (int i = 0; i < num; i++)
		_elems.push_back(-1);
}

int DisjointSets::find(int elem) {
    
	if (_elems[elem] < 0) {
        return elem;
    } else {
		_elems[elem] = find(_elems[elem]);
		return _elems[elem];
	}
}

void DisjointSets::setunion(int a, int b) {
	
    int a_set = find(a);
    int b_set = find(b);
    int new_size = _elems[a_set] + _elems[b_set];
    if (a_set == b_set) {
        return;
    }

	if (a_set < b_set) {
		_elems[a_set] = new_size;
		_elems[b_set] = a_set;
	}

	else {
		_elems[a_set] = b_set;
        _elems[b_set] = new_size;
	}
}

int DisjointSets::size(int elem) {
    
    int elem_s = find(elem);
	return (_elems[elem_s] * -1);
}