#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>
# include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int value) { // The container of integers to search within
    // Use std::find to search for the value within the container's range
    // std::find returns an iterator to the first occurrence or container.end() if not found
    typename T::iterator it = std::find(container.begin(), container.end(), value);

    // If std::find returns the end iterator, the value was not found
    if (it == container.end()) {
        throw std::out_of_range("Value not found in container.");
    }
    return it;
}

#endif