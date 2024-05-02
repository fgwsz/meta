#pragma once
#include"auto_constant.hpp"
#include"type_identity.hpp"
#include"meta_function.hpp"
#include"meta_function_invoke.hpp"
namespace scheme{
template<auto _value>
using c=auto_constant<_value>;
template<typename _Type>
using t=TypeIdentity<_Type>;
template<template<typename...>typename _T_Template>
using f=MetaFunction<_T_Template>;
template<
    typename _TI_MetaFunction
    ,typename... _Arguments
>
using _=MetaFunctionInvoke<_TI_MetaFunction,_Arguments...>;
}//namespace scheme