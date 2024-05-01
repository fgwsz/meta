#pragma once
template<template<typename...>typename _T_Template>
struct MetaFunction{
    using type=MetaFunction<_T_Template>;
    template<typename... _Arguments>
    using apply=_T_Template<_Arguments...>;
};
