// Human readble duration format
#include <string>
#include <vector>

std::string format_duration(int seconds) {
  if (seconds == 0) return "now";
  
  std::vector<std::string> times;
  auto add = [&] (auto text, auto time) {
    if (time == 0) return;
    times.push_back(std::to_string(time) + text + (time > 1 ? "s" : ""));
  };
  add(" year",    seconds / 31536000);    
  add(" day",    (seconds / 86400) % 365);    
  add(" hour",   (seconds / 3600) % 24);    
  add(" minute", (seconds / 60) % 60);    
  add(" second",  seconds % 60);    
  
  std::string result = times[0];
  for (auto i = 1; i < times.size() - 1; i ++) result.append(", " + times[i]);
  if (times.size() > 1) result.append(" and " + times.back());
  
  return result;
}