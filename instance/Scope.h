#pragma once
#include "LocalScope.h"
#include "Node.h"

namespace instance {

struct Scope {
    using This = Scope;

    const This* parent{};
    LocalScope locals;

    Scope() = default;
    ~Scope() = default;
    explicit Scope(const This* parent)
        : parent(parent) {}

    // move enabled
    Scope(This&&) = default;
    auto operator=(This &&) -> This& = default;

    // no copy
    Scope(const This&) = delete;
    auto operator=(const This&) -> This& = delete;

public:
    auto operator[](const Name& name) const& -> const Node* {
        auto node = locals[name];
        if (!node && parent) return (*parent)[name];
        return node;
    }

    template<class T, class... Ts>
    bool emplace(T&& arg, Ts&&... args) & {
        return locals.emplace(std::forward<T>(arg), std::forward<Ts>(args)...);
    }
};

} // namespace instance