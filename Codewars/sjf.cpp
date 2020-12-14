// Shortest job first sjf

int get_shortest_job_index(std::vector<int> jobs){
  int sj_idx = 0;
  for (size_t i = 0; i < jobs.size(); i++)
  {
    if (jobs[i] > 0)
    {
      sj_idx = i;
      break;
    }
  }
  for (size_t i = 0; i < jobs.size(); i++)
  {
    if (jobs[i] > 0 && jobs[i] < jobs[sj_idx])
    {
      sj_idx = i;
    }
  }

  return sj_idx;
}

int SJF(std::vector <int> jobs, int index){
  int cc = 0;
  while (jobs[index] > 0)
  {
    int idx = get_shortest_job_index(jobs);
    cc += jobs[idx];
    jobs[idx] = 0;
  }

  return cc;
}