#ifndef ALGLIB_INCLUDE_SORTING_H_
#define ALGLIB_INCLUDE_SORTING_H_

namespace alglib {

template <typename T>
void BubbleSort(T *begin, T *end) {
  for (T *i{begin}; i != end; ++i) {
    for (T *j{begin}; j != end - 1; ++j) {
      if (*j > *(j + 1)) {
        std::swap(*j, *(j + 1));
      }
    }
  }
}

template <typename T>
void InsertionSort(T *begin, T *end) {
  for (T *i{begin + 1}; i != end; ++i) {
    T key{*i};
    T *j{i - 1};
    while (j >= begin && *j > key) {
      *(j + 1) = *j;
      --j;
    }
    *(j + 1) = key;
  }
}

template <typename T>
void SelectionSort(T *begin, T *end) {
  for (T *i{begin}; i != end; ++i) {
    T *min{i};
    for (T *j{i + 1}; j != end; ++j) {
      if (*j < *min) {
        min = j;
      }
    }
    std::swap(*i, *min);
  }
}

template <typename T>
void CombSort(T *begin, T *end) {
  auto length{end - begin};
  size_t gap{length};
  bool swapped{true};

  while (gap > 1 || swapped) {
    gap = (gap * 10) / 13;
    if (gap < 1) gap = 1;

    swapped = false;

    for (T *i{begin}; i + gap < end; ++i) {
      if (*i > *(i + gap)) {
        std::swap(*i, *(i + gap));
        swapped = true;
      }
    }
  }
}

template <typename T>
void ShellSort(T *begin, T *end) {
  size_t n{static_cast<size_t>(end - begin)};

  for (size_t gap{n / 2}; gap > 0; gap /= 2) {
    for (T *i = begin + gap; i < end; ++i) {
      T temp{*i};
      T *j{i};

      while (j >= begin + gap && *(j - gap) > temp) {
        *j = *(j - gap);
        j -= gap;
      }
      *j = temp;
    }
  }
}

namespace {

template <typename T>
T *Partition(T *begin, T *end) {
  T pivot = *(end - 1);
  T *i = begin - 1;

  for (T *j = begin; j < end - 1; ++j) {
    if (*j <= pivot) {
      ++i;
      std::swap(*i, *j);
    }
  }

  ++i;
  std::swap(*i, *(end - 1));
  return i;
} 

}  // namespace

template <typename T>
void QuickSort(T *begin, T *end) {
  if (end - begin <= 1) {
    return;
  }

  T *pivotPos = Partition(begin, end);
  QuickSort(begin, pivotPos);
  QuickSort(pivotPos + 1, end);
}

}
#endif  // ALGLIB_INCLUDE_SORTING_H_