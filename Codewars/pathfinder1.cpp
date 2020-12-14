//path finder
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cmath>

bool is_neigh(const std::string &maze, const int pos, const int direction,
              const int N) {
    auto ld = N + 1;
    switch (direction) {
    case 0:
        return (pos != maze.size() - 1 && maze[pos + 1] == '.');
    case 1:
        return (pos / ld != N - 1 && maze[pos + ld] == '.');
    case 2:
        return (pos % ld != 0 && maze[pos - 1] == '.');
    case 3:
        return (pos / ld != 0 && maze[pos - ld] == '.');
    default:
        return false;
    }
}

int get_id(const std::string &maze, const int id, const int pos,
           const int direction, const int N) {
    auto ld = N + 1;
    if (direction == 0)
        return id + 1;
    if (direction == 2)
        return id - 1;
    if (direction == 1) {
        int dis = 0;
        for (int i = 0; i < ld; i++)
            if (maze[i + pos] == '.')
                dis++;
        return id + dis;
    }
    if (direction == 3) {
        int dis = 0;
        for (int i = 1; i <= ld; i++)
            if (maze[pos - i] == '.')
                dis++;
        return id - dis;
    }
    return -1;
}

int path_finder(std::string maze) {
    const auto N = static_cast<int>(sqrt(maze.size()));
    std::vector<int> pos;
    std::vector<int> col_idx;
    std::vector<int> col;
    pos.reserve(maze.size());
    col_idx.reserve(maze.size());
    col_idx.push_back(0);
    for (int i = 0; i < maze.size(); i++) {
        if (maze[i] == '.')
            pos.push_back(i);
    }

    for (int i = 0; i < pos.size(); i++) {
        for (int d = 0; d < 4; d++) {
            if (is_neigh(maze, pos[i], d, N))
                col.push_back(get_id(maze, i, pos[i], d, N));
        }
        col_idx.push_back(col.size());
    }

    std::vector<bool> visited(pos.size(), false);
    visited[0] = true;

    std::stack<int> stack;
    stack.push(0);
    while (!stack.empty()) {
        auto curr = stack.top();
        stack.pop();
        for (int i = col_idx[curr]; i < col_idx[curr + 1]; i++) {
            auto id = col[i];
            if (id == pos.size()-1) return true;
            if (!visited[id]) {
                visited[id] = true;
                stack.push(id);
            }
        }
    }
    return false;
}