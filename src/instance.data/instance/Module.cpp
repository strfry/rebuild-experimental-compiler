#include "Module.h"

#include "Node.h"

namespace instance {

namespace {

void fixTypes(Module& old, Module& cur) {
    for (auto& n : cur.locals.m) {
        n.second.visitSome([&](Type& t) {
            if (t.module == &old) t.module = &cur;
        });
    }
}

} // namespace

Module::Module(This&& o) noexcept
    : name(std::move(o.name))
    , flags(std::move(o.flags))
    , locals(std::move(o.locals)) {
    fixTypes(o, *this);
}

auto Module::operator=(This&& o) & noexcept -> This& {
    name = std::move(o.name);
    flags = std::move(o.flags);
    locals = std::move(o.locals);
    fixTypes(o, *this);
    return *this;
}

} // namespace instance
