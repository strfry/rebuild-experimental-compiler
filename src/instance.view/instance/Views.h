#pragma once

namespace instance {

struct Module;
using ModuleView = const Module*;

struct Argument;
using ArgumentView = const Argument*;

struct Variable;
using VariableView = const Variable*;

struct Typed;
using TypedView = const Typed*;

struct Function;
using FunctionView = const Function*;

struct Scope;

} // namespace instance
