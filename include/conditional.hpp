#pragma once
template<bool _expr,typename _TrueCase,typename _FalseCase>
struct Conditional{
    using type=_TrueCase;
};
template<typename _TrueCase,typename _FalseCase>
struct Conditional<false,_TrueCase,_FalseCase>{
    using type=_FalseCase;
};
template<bool _expr,typename _TrueCase,typename _FalseCase>
using conditional_t=typename Conditional<_expr,_TrueCase,_FalseCase>::type;
