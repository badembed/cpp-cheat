#include "common.hpp"

struct Node
{
  std::string value;
  Node *next;
};

std::vector<Node> fillGraph() {
  std::vector<Node> nodes;

  nodes.push_back({"NodeA", nullptr});
  nodes.push_back({"NodeA", nullptr});
  nodes.push_back({"NodeB", nullptr});
  nodes.push_back({"NodeC", nullptr});
  nodes.push_back({"NodeC", nullptr});
  nodes.push_back({"NodeC", nullptr});
  nodes.push_back({"NodeD", nullptr});
  nodes.push_back({"NodeE", nullptr});

  nodes[0].next = &nodes[3];
  nodes[1].next = &nodes[3];

  nodes[3].next = &nodes[2];
  nodes[4].next = &nodes[2];
  nodes[5].next = &nodes[2];

  nodes[2].next = &nodes[6];

  nodes[6].next = &nodes[7];

  return nodes;
}

int main() {
  std::vector<Node> nodes = fillGraph();

  /* Check the vectors */
  for (auto &node : nodes) {
    std::cout << node.value << std::endl;
  }
  std::cout << std::endl;
  for (auto &node : nodes) {
    if (node.next != nullptr)
      std::cout << node.next->value << std::endl;
  }

  /* multymap as a graph */
  std::multimap<std::string, Node> map;
  std::cout << std::endl;
  for (auto node : nodes) {
    map.insert({node.value, node});
    std::cout << node.value << std::endl;
  }

  std::cout << std::endl;
  for (auto &el: map) {
    auto node = el.second;
    auto type = el.first;
    std::cout << type << std::endl;
  }

  std::cout << std::endl;
  for (auto el = map.begin(), end = map.end();
      el != end;
      el = map.upper_bound(el->first))
  {
    std::cout << el->first << std::endl;
  }

  /* for each next el */
  std::cout << std::endl;
  for (auto &el: map) {
    auto node = el.second;
    auto type = el.first;

    if (node.next == nullptr)
      continue;

    auto succType = node.next->value;
    auto succNodePair = map.find(succType);
    auto succNode = succNodePair->second;

    std::cout << "pred: " << node.value
              << ", succ: " << succNode.value << std::endl;
  }

  /* for each next el in multimap */
  std::cout << std::endl;
  for (auto el = map.begin(), end = map.end();
       el != end;
       el = map.upper_bound(el->first))
  {
    auto subNode = el->second;
    auto type = el->first;

    auto cnt = map.count(type);
    if (cnt > 1)
    {
      auto subEl = map.find(el->first);
      for (int i = 0; i < (cnt - 1); i++)
      {
        std::cout << "pred: " << (subEl++)->first
              << ", succ: " << (subEl)->first << std::endl;
      }
      subNode = subEl->second;
    }

    if (subNode.next == nullptr)
      continue;

    auto succType = subNode.next->value;
    auto succNodePair = map.find(succType);
    auto succNode = succNodePair->second;
    std::cout << "pred: " << subNode.value
              << ", succ: " << succNode.value << std::endl;
  }
}
