#include "common.hpp"

class Graph {

public:
  void addInfoNNGraphToPGraph(std::string NNode,
                              std::string NNodeOp,
                              std::string type);
  void checkInfo(void);

private:
  struct NNGraphToPGraphInfo {
    std::string NNode;
    std::string NNodeOp;
    std::string type;
  };

  std::vector<NNGraphToPGraphInfo> infoNNGraphToPGraph;
  std::map<std::string, std::vector<NNGraphToPGraphInfo>> NNGraphToPGraphmap;
};

void Graph::addInfoNNGraphToPGraph(std::string NNode,
                                   std::string NNodeOp,
                                   std::string type)
{
  infoNNGraphToPGraph.push_back({NNode, NNodeOp, type});
}

void Graph::checkInfo()
{
  for (int i = 0; i < infoNNGraphToPGraph.size(); i++) {
    std::cout << infoNNGraphToPGraph[i].NNode << " : "
              << infoNNGraphToPGraph[i].NNodeOp << " : "
              << infoNNGraphToPGraph[i].type << " : "
              << std::endl;
  }
}

void fillNNGraphToPGraphInfo(void) {
  Graph graph;
  graph.addInfoNNGraphToPGraph("NNodeA", "NNodeAOpA", "TypeA");
  graph.addInfoNNGraphToPGraph("NNodeA", "NNodeAOpB", "TypeB");
  graph.addInfoNNGraphToPGraph("NNodeB", "NNodeBOpA", "TypeC");
  graph.addInfoNNGraphToPGraph("NNodeC", "NNodeCOpA", "TypeD");

  std::cout << std::endl << "Approach Class" << std::endl;
  graph.checkInfo();
}

int main() {

  /************************************************
   *  Map of Vectors Approach
   ************************************************/

  std::map<std::string, std::vector<std::string>> NNodetoOpNNode;
  /*
  {
    {"NNodeA", "NNodeAOpA"},
    {"NNodeA", "NNodeAOpB"},
    {"NNodeB", "NNodeBOpA"},
    {"NNodeC", "NNodeCOpA"}
  };
  */

  NNodetoOpNNode["NNodeA"].push_back("NNodeAOpA");
  NNodetoOpNNode["NNodeA"].push_back("NNodeAOpB");
  NNodetoOpNNode["A"].push_back("NNodeAOpA");
  NNodetoOpNNode["NNodeB"].push_back("NNodeBOpA");
  NNodetoOpNNode["NNodeC"].push_back("NNodeCOpA");

  std::cout << std::endl << "Approach Vector" << std::endl;
  for (auto& pair : NNodetoOpNNode) {
    for (int i = 0; i < pair.second.size(); i++) {
      std::cout << pair.first << ":" << pair.second[i] << std::endl;
    }
  }

  /************************************************
   *  MultiMap Approach
   ************************************************/

  std::multimap<std::string, std::string> mNNodetoOpNNode;

  /*
  mNNodetoOpNNode["NNodeA"] = "NNodeAOpA";
  mNNodetoOpNNode["NNodeA"] = "NNodeAOpB";
  mNNodetoOpNNode["NNodeB"] = "NNodeBOpA";
  mNNodetoOpNNode["NNodeC"] = "NNodeCOpA";
  */

  mNNodetoOpNNode.insert({"NNodeA", "NNodeAOpA"});
  mNNodetoOpNNode.insert({"NNodeA", "NNodeAOpB"});
  mNNodetoOpNNode.insert({"NNodeB", "NNodeBOpA"});
  mNNodetoOpNNode.insert({"NNodeC", "NNodeCOpA"});


  std::cout << std::endl << "Approach Multimap" << std::endl;

  for (auto pair = mNNodetoOpNNode.begin();
       pair != mNNodetoOpNNode.end(); ++pair) {
    std::cout << pair->first << ":" << pair->second << std::endl;
  }

  for (auto& pair : mNNodetoOpNNode) {
    std::cout << pair.first << ":" << pair.second << std::endl;
  }

  /************************************************
   *  Class Approach
   ************************************************/

  fillNNGraphToPGraphInfo();
}
