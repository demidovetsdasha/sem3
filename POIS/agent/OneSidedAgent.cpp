#include <cstdint>
#include <iostream>
#include <memory>
#include <sc-memory/sc_memory.hpp>
#include <sys/types.h>
#include <unordered_map>

#include <sc-agents-common/utils/AgentUtils.hpp>
#include <sc-agents-common/utils/IteratorUtils.hpp>

#include "OneSidedAgent.hpp"
#include "sc-memory/sc_addr.hpp"
#include "sc-memory/sc_iterator.hpp"

using namespace utils;
using namespace std;

namespace exampleModule {

void DFS(unique_ptr<ScMemoryContext>& con, ScAddr graphNode,ScAddr beginV, ScAddr curV, unordered_map<uint64_t, unordered_map<uint64_t, bool>>& visited) {
	visited[beginV.Hash()][curV.Hash()] = true;

	ScIterator5Ptr edges_iter = con->Iterator5(curV, ScType::EdgeDCommonConst, ScType::NodeConst, ScType::EdgeAccessConstPosPerm, graphNode);
	while (edges_iter->Next()) {
		ScAddr adjNode = edges_iter->Get(2); edges_iter->Get(2);
		if (!visited[beginV.Hash()][adjNode.Hash()]) 
			DFS(con, graphNode, beginV, adjNode, visited);
	}
}

SC_AGENT_IMPLEMENTATION(OneSidedAgent) {
	SC_LOG_INFO("OneSidedAgent started");
	ScAddr graphNode = otherAddr;

	unordered_map<uint64_t, unordered_map<uint64_t, bool>> visited;
	ScIterator3Ptr nodes_iter = ms_context->Iterator3(graphNode, ScType::EdgeAccessConstPosPerm, ScType::NodeConst);
	while (nodes_iter->Next()) {
		ScAddr node = nodes_iter->Get(2);
		ScIterator3Ptr nodes1_iter = ms_context->Iterator3(graphNode, ScType::EdgeAccessConstPosPerm, ScType::NodeConst);
		while (nodes1_iter->Next()) {
			ScAddr node1 = nodes1_iter->Get(2);
			visited[node.Hash()][node1.Hash()] = false;
		}
	}

	nodes_iter = ms_context->Iterator3(graphNode, ScType::EdgeAccessConstPosPerm, ScType::NodeConst);
	while (nodes_iter->Next()) {
		ScAddr beginNode = nodes_iter->Get(2);
		DFS(ms_context, graphNode, beginNode, beginNode, visited);
	}

	for(auto& nodesCouple : visited) {
		for (auto& wayBetweenNodes : nodesCouple.second) {
			if (!wayBetweenNodes.second) {
				if (!visited[wayBetweenNodes.first][nodesCouple.first]) {
					ScAddr Class = ms_context->HelperResolveSystemIdtf("Not a one-sided graph", ScType::NodeConstClass);
					ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, Class, graphNode);

					utils::AgentUtils::finishAgentWork(ms_context.get(), graphNode, true);
					SC_LOG_INFO("OneSidedAgent finished");
					return SC_RESULT_OK;
				}
			}
		}
	}

	
	ScAddr Class = ms_context->HelperResolveSystemIdtf("One-sided graph", ScType::NodeConstClass);
	ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, Class, graphNode);

	utils::AgentUtils::finishAgentWork(ms_context.get(), graphNode, true);
	SC_LOG_INFO("OneSidedAgent finished");
	return SC_RESULT_OK;
}

}
