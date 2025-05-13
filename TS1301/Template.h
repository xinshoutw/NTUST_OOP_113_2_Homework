#ifndef TEMPLATE_H
#define TEMPLATE_H

template <typename T>
void ItrBinarySearch(const T a[], int first, int last, T key, bool& found, int& location) {
    found = false;
    while (first != last) {
        int mid = (first + last) / 2;

        if (a[mid] < key) {
            first = mid + 1;
        } else if (a[mid] > key) {
            last = mid - 1;
        } else {
            found = true;
            location = mid;
            return;
        }
    }

    if (a[first] == key) {
        found = true;
        location = first;
    }
}

template <typename T>
void RecBinarySearch(const T a[], int first, int last, T key, bool& found, int& location) {
    int mid = (first + last) / 2;

    if (first != last) {
        if (a[mid] < key) {
            return RecBinarySearch(a, mid + 1, last, key, found, location);
        }

        if (a[mid] > key) {
            return RecBinarySearch(a, first, mid - 1, key, found, location);
        }

        found = true;
        location = mid;
        return;
    }

    if (a[first] == key) {
        found = true;
        location = first;
    }
}

#endif // TEMPLATE_H
