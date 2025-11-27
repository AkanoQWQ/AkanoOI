#include<bits/stdc++.h>
using namespace std;

int nodeCount, queryCount;
unordered_map<string, int> nameToIdMap;
int currentId;
const int MAX_NODES = 201000;
string nodeNames[MAX_NODES];
bool isRegularNode[MAX_NODES];
int visited[MAX_NODES], visitMarker;

struct Rectangle {
	int left, right, top, bottom;
} nodeRectangles[MAX_NODES];

int lastYCoordinate;
vector<int> children[MAX_NODES];
int parent[MAX_NODES];

void computeLayout(int nodeId) {
	if(nodeId == 1) {
		nodeRectangles[nodeId].left = 0;
		nodeRectangles[nodeId].right = 50;
		nodeRectangles[nodeId].top = 0;
		nodeRectangles[nodeId].bottom = 10;
		lastYCoordinate = 10;
	}
	for(int childId : children[nodeId]) {
		nodeRectangles[childId].left = nodeRectangles[nodeId].left + 10;
		nodeRectangles[childId].right = nodeRectangles[nodeId].right + 10;
		nodeRectangles[childId].top = lastYCoordinate;
		nodeRectangles[childId].bottom = lastYCoordinate + 10;
		lastYCoordinate += 10;
		computeLayout(childId);
	}
}
int findNodeAtPosition(int nodeId, int x, int y) {
	if(nodeRectangles[nodeId].top <= y && nodeRectangles[nodeId].bottom >= y) {
		if(y == nodeRectangles[nodeId].bottom || y == nodeRectangles[nodeId].top) {
			return 0;
		}
		if(x <= nodeRectangles[nodeId].left || x >= nodeRectangles[nodeId].right) {
			return 0;
		}
		return nodeId;
	}
	for(int childId : children[nodeId]) {
		int foundNode = findNodeAtPosition(childId, x, y);
		if(foundNode) {
			return foundNode;
		}
	}
	return 0;
}

bool hasCycle(int nodeId) {
	if(visited[nodeId] == visitMarker) {
		return true;
	}
	visited[nodeId] = visitMarker;
	
	for(int childId : children[nodeId]) {
		if(!isRegularNode[childId]) {
			string originalName = nodeNames[childId];
			originalName.pop_back();
			originalName.pop_back();
			originalName.pop_back();
			originalName.pop_back();
			originalName.pop_back();
			originalName.pop_back();
			childId = nameToIdMap[originalName];
		}
		bool cycleFound = hasCycle(childId);
		if(cycleFound) {
			return cycleFound;
		}
	}
	visited[nodeId] = 0;
	return false;
}

int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	
	cin >> nodeCount >> queryCount;
	char ch = getchar();
	while(ch != '\n') {
		ch = getchar();
	}
	
	for(int i = 1; i <= nodeCount; i++) {
		string line;
		getline(cin, line);
		string currentToken = "";
		bool isFirstToken = false;
		
		for(int j = 0; j < (int)line.size(); j++) {
			ch = line[j];
			if(ch != 32 && ch != 10) {
				currentToken += line[j];
			}
			if(ch == 32 || j == (int)line.size() - 1) {
				if(nameToIdMap.find(currentToken) == nameToIdMap.end() || currentToken[currentToken.size()-1] == ')') {
					if(!isFirstToken && currentToken[currentToken.size()-1] == ')') {
						continue;
					}
					nameToIdMap[currentToken] = ++currentId;
					nodeNames[currentId] = currentToken;
				}
				if(currentToken[currentToken.size()-1] == ')') {
					isRegularNode[nameToIdMap[currentToken]] = false;
				} else {
					isRegularNode[nameToIdMap[currentToken]] = true;
				}
				
				if(!isFirstToken) {
					isFirstToken = true;
					currentToken = "";
					continue;
				}
				
				children[i].push_back(nameToIdMap[currentToken]);
				parent[nameToIdMap[currentToken]] = i;
				currentToken = "";
				continue;
			}
		}
	}
	
	computeLayout(1);
	
	while(queryCount--) {
		char operationType;
		int input1,intput2,input3,input4;
		cin >> operationType >> input1 >> intput2 >> input3 >> input4;
		input1 -= 10;
		input3 -= 10;
		
		int sourceNode = findNodeAtPosition(1, input1, intput2);
		int targetNode = findNodeAtPosition(1, input3, input4);
		
		if(!sourceNode || !targetNode || sourceNode == targetNode) {
			cout << 1 << '\n';
			continue;
		}
		
		if(!isRegularNode[targetNode]) {
			cout << 2 << '\n';
			continue;
		}
		
		++visitMarker;
		int currentNode = targetNode;
		while(currentNode != 1) {
			currentNode = parent[currentNode];
			if(currentNode == sourceNode) {
				cout << 2 << '\n';
				goto next_query;
			}
		}
		
		if(operationType == 'L') {
			children[MAX_NODES-1].clear();
			children[MAX_NODES-1] = children[parent[sourceNode]];
			children[parent[sourceNode]].erase(remove(children[parent[sourceNode]].begin(), children[parent[sourceNode]].end(), sourceNode), children[parent[sourceNode]].end());
			
			children[targetNode].push_back(sourceNode);
			++visitMarker;
			if(hasCycle(1)) {
				children[parent[sourceNode]] = children[MAX_NODES-1];
				children[targetNode].pop_back();
				cout << 2 << '\n';
			} else {
				parent[sourceNode] = targetNode;
				cout << 0 << '\n';
				computeLayout(1);
			}
		} else {
			string newNodeName;
			if(!isRegularNode[sourceNode]) {
				newNodeName = nodeNames[sourceNode];
			} else {
				newNodeName = nodeNames[sourceNode] + "(link)";
			}
			nodeNames[++currentId] = newNodeName;
			children[targetNode].push_back(currentId);
			parent[currentId] = targetNode;
			++visitMarker;
			if(hasCycle(1)) {
				cout << 2 << '\n';
				children[targetNode].pop_back();
				currentId--;
			} else {
				cout << 0 << '\n';
				computeLayout(1);
			}
		}
		next_query:;
	}
	
	return 0;
}
