#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "list.h"

template <typename T>
void CP::list<T>::block_swap(iterator a1, iterator a2, iterator b1, iterator b2) {
	if (a1 == a2 && b1 == b2) return;
	if (a1 == a2 || b1 == b2) {
		if (b1 == b2) std::swap(a1, b1), std::swap(a2, b2);
		a1--;
		auto pa1 = a1.ptr->prev;
		auto pa2 = a2.ptr->prev;
		auto pb1 = b1.ptr->prev;
		auto pb2 = b2.ptr->prev;

		pb1->next = b2.ptr;
		b2.ptr->prev = pb1;

		pb2->next = a1.ptr->next;
		a1.ptr->next->prev = pb2;

		a1.ptr->next = b1.ptr;
		b1.ptr->prev = a1.ptr;
		return;
	}
	if (a1 == b2) std::swap(a1, b1), std::swap(a2, b2);
	auto pa1 = a1.ptr->prev;
	auto pa2 = a2.ptr->prev;
	auto pb1 = b1.ptr->prev;
	auto pb2 = b2.ptr->prev;
	
	pa1->next = b1.ptr;
	b1.ptr->prev = pa1;

	pa2->next = b2.ptr;
	b2.ptr->prev = pa2;

	if (a2 != b1) {
		pb2->next = a2.ptr;
		a2.ptr->prev = pb2;
		
		pb1->next = a1.ptr;
		a1.ptr->prev = pb1;
	}
	else {
		pb2->next = a1.ptr;
		a1.ptr->prev = pb2;
	}
}

#endif
