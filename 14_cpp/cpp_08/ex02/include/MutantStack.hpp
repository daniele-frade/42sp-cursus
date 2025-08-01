#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP


# include <iostream>
# include <algorithm>
# include <stack>
# include <deque>

// MutantStack class template, inheriting publicly from std::stack
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
    // Define iterator types based on the underlying container's iterators
    // This allows MutantStack to expose the iterators of its internal container
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::reverse_iterator reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;

    // OCF:
    MutantStack() : std::stack<T, Container>() {}
    MutantStack(MutantStack const& other) : std::stack<T, Container>(other) {}
    MutantStack& operator=(MutantStack const& other) {
        if (this != &other) {
            std::stack<T, Container>::operator=(other);
        }
        return *this;
    }
    ~MutantStack() {}

    iterator begin() {
        return this->c.begin();
    }

    const_iterator begin() const {
        return this->c.begin();
    }

    iterator end() {
        return this->c.end();
    }

    const_iterator end() const {
        return this->c.end();
    }
};

#endif