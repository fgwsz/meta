#pragma once
#include"size_type.hpp"
#include"sequence.hpp"
template<size_type... _values>
using index_sequence=Sequence<size_type,_values...>;
