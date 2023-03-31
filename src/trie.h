#ifndef TRIE_H
#define TRIE_H

#include <map>
#include <iterator>
#include <iostream>
#include <list>
#include <optional>


template <typename T>
class Trie {
public:
    template <typename It>
    void Insert(It it, It endIt) {
        if (it == endIt) {
            return;
        }
        tries_[*it].Insert(std::next(it), endIt);
    }

    template <typename C>
    void Insert(const C& container) {
        Insert(std::begin(container), std::end(container));
    }

    void Insert(const std::initializer_list<T>& initList) {
        Insert(std::begin(initList), std::end(initList));
    }

    void Print(std::list<T>& lst) const {
        if (tries_.empty()) {
            copy(std::begin(lst), std::end(lst), std::ostream_iterator<T>{std::cout, " "});
            std::cout << std::endl;
        }
        for (const auto& pair : tries_) {
            lst.push_back(pair.first);
            pair.second.Print(lst);
            lst.pop_back();
        }
    }

    void Print() const {
        std::list<T> lst;
        Print(lst);
    }

    template <typename It>
    std::optional<std::reference_wrapper<const Trie>> Subtrie(It it, It endIt) const {
        if (it == endIt) {
            return std::ref(*this);
        }

        auto found (tries_.find(*it));
        if (found == std::end(tries_)) {
            return {};
        }
        return found->second.Subtrie(std::next(it), endIt);
    }

    template<typename C>
    auto Subtrie(const C& container) const {
        return Subtrie(std::begin(container), std::end(container));
    }

private:
    std::map<T, Trie> tries_;
};

#endif // TRIE_H
