void splitList(list<T>& list1, list<T>& list2) {
    auto it = begin().ptr, i = 0;
    for (int i = 0; i < mSize; ++i) {
        auto nxt = it->next;
        if (i < (mSize+1)/2) {
            it->prev = list1.end().ptr->prev;
            it->next = list1.end().ptr;
            list1.end().ptr->prev->next = it;
            list1.end().ptr->prev = it;
            list1.mSize++;
        }
        else {
            it->prev = list2.end().ptr->prev;
            it->next = list2.end().ptr;
            list2.end().ptr->prev->next = it;
            list2.end().ptr->prev = it;
            list2.mSize++;
        }
        it = nxt;
    }
    mSize = 0;
    mHeader->next = mHeader->prev = mHeader;
}
