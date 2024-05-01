#pragma once
#include"constant.hpp"
template<auto _value>
using auto_constant=Constant<decltype(_value),_value>;