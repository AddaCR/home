//n linear

uint32_t min_val_index(const std::vector<uint32_t>& val, 
                       std::vector<uint32_t>& index) {
  auto min_index = std::min_element(val.begin(), val.end());
  for (auto it = 0; it < val.size(); it++) {
    if (val[it] == *min_index){
      index[it]++;
    }
  }
  return *min_index;
}


uint32_t n_linear(const std::set<uint32_t>& m, size_t n)
{ 
  std::vector<uint32_t> u(n + 1, 1);
  std::vector<uint32_t> m_vec(m.begin(), m.end());
  int m_size = m.size();
  std::vector<uint32_t> value(m_size, 0);
  std::vector<uint32_t> indices(m_size, 0);
  
  
  for (uint32_t i = 0; i < n; i++) {
    auto count = 0;
    for (auto j = m_vec.begin(); j != m_vec.end(); j++) {
      value[count] = (*j) * u[indices[count]] + 1;
      count++;
    }
    count = 0;
    auto val = min_val_index(value, indices);
    u[i + 1] = val;
  }
  return u[n];
}