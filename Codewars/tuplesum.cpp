//tuple sum

#include <tuple>

template <class Tuple, class F, std::size_t... I>
constexpr F for_each_impl(Tuple&& t, F&& f, std::index_sequence<I...>)
{
  return (void)std::initializer_list<int>{(std::forward<F>(f)(std::get<I>(std::forward<Tuple>(t))),0)...}, f;
}

template <class Tuple, class F>
constexpr F for_each(Tuple&& t, F&& f)
{
  return for_each_impl(std::forward<Tuple>(t), std::forward<F>(f),
    std::make_index_sequence<std::tuple_size<std::remove_reference_t<Tuple>>::value>{});
}

template<class T>
void Sum(T v, double& sum)
{
}

void Sum(double v, double& sum)
{
  sum += v;
}

void Sum(int v, double& sum)
{
  sum += v;
}


void Sum(float v, double& sum)
{
  sum += v;
}

template <typename... Ts> 
double tuple_sum(const std::tuple<Ts...>& tpl)
{

  double sum = 0.0;
  for_each( tpl, [&]( auto&& value )
  {
    Sum(value, sum);
  });

  return sum;
}