#pragma once
template<template<typename...>typename _T_Template>
struct MetaFunction{
    template<typename... _Arguments>
    using apply=_T_Template<_Arguments...>;
};
