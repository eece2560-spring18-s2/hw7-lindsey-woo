#include "member.h"

#include <queue>

#include "database.h"

#include <limits>

namespace algdb {

void Member::DumpConnections() {
  std::cout << "(" << member_id << ")";
  for (auto &m : connecting_members) {
    auto conn = m.second;
    std::cout << "->" << conn.dst->member_id << 
      "(" << conn.group->group_id << ")";
  }
  std::cout << "\n";
}

void Member::PathToMemberBFS(uint64_t dst_member_id) {
  // Fill in your code here.
  // for (auto member : members) {
  //   member->color = COLOR_WHITE;
  //   member->parent = NULL;
  // }
  this->color = COLOR_GRAY;
  this->parent = NULL;
  std::queue<Member *> Q;
  Q.push(this);
  while (!Q.empty()) {
    Member * mem = Q.front();
    Q.pop();
    for (auto &cm : mem->connecting_members) {
      auto conn = cm.second;
      MemberConnection mc;
      mc = conn;
      if (conn.dst->member_id == dst_member_id) {
        mem->PrintPath(mc.dst);
      }
      if (mc.dst->color == COLOR_WHITE) {
        mc.dst->color = COLOR_GRAY;
        mc.dst->parent = mem;
        Q.push(mc.dst);
      }
    }
    mem->color = COLOR_BLACK;
  }
}

void Member::PathToMemberIDDFS(uint64_t dst_member_id) {
  // Fill in your code here
  int depth = 0;
  for (depth = 0; depth < std::numeric_limits<int>::max(); depth++) {
    Member * found = DLS(this, depth, dst_member_id);  
    if (found != NULL) {
      this->PrintPath(found);
      return;
    }
  }
 
}

Member * Member::DLS(Member *node, int depth, uint64_t dst_member_id) {
  if (depth == 0 && (node->member_id == dst_member_id)) {
    return node;
  }
  if (depth > 0) {
    for (auto &cm : node->connecting_members) {
      auto conn = cm.second;
      Member * found = DLS(conn.dst, depth - 1, dst_member_id);
      if (found != NULL) {
        conn.dst->parent = node;
        return found;
      }
    }
  }
  return NULL;
}
  
void Member::PrintPath(Member* dst) {
  Member *curr = dst;
  while(curr && curr != this) {
    std::cout << curr->member_name << " <- ";
    curr = curr->parent;
  }
  std::cout << this->member_name << "\n";
}

}
