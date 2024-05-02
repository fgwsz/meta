#pragma once
template<
    typename _TI_MetaFunction
    ,typename... _Arguments
>
struct MetaFunctionInvoke{
    using type=typename _TI_MetaFunction::type::template apply<
        typename _Arguments::type...
    >::type;
};
template<
    typename _TI_MetaFunction
    ,typename... _Arguments
>
using meta_function_invoke_t=typename MetaFunctionInvoke<
    _TI_MetaFunction
    ,_Arguments...
>::type;
template<
    typename _TI_MetaFunction
    ,typename... _Arguments
>
static constexpr auto meta_function_invoke_v=MetaFunctionInvoke<
    _TI_MetaFunction
    ,_Arguments...
>::type::value;
