void replace(const T& x, list<T>& y) {
  for (auto it = begin(); it != end();) {
    if (*it == x) {
      for (auto it2 = y.begin(); it2 != y.end(); it2++) insert(it, *it2);
      it = erase(it);
    }
    else it++;
  }

}
