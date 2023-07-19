#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/

graphNode *cloneGraphHelper(graphNode *node, unordered_map<graphNode *, graphNode *> &copies)
{
	if (!node)
		return NULL;
	

	graphNode *copy = new graphNode(node->data);

	copies[node] = copy;

	queue<graphNode *> level;

	level.push(node);

	while (!level.empty())
	{
		// Take the the front element from the queue.
		graphNode *cur = level.front();
		level.pop();

		// Go through all the neighbours.
		for (graphNode *neighbor : cur->neighbours)
		{
			// If it is not present in the HashMap.
			if (copies.find(neighbor) == copies.end())
			{
				copies[neighbor] = new graphNode(neighbor->data, {});
				level.push(neighbor);
			}

			copies[cur]->neighbours.push_back(copies[neighbor]);
		}
	}

	return copy;
}


graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.
	unordered_map<graphNode *, graphNode *> copies;

	return cloneGraphHelper(node, copies);
}
