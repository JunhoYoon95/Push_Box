#include "sokoban.h"
#define distance(a, b) (fabs(a.x - b.x) + fabs(a.y - b.y))




/**
 * mark all places that are reachable
 */

 /**
  * detecting simple deadlocks
  */

void showGround(vector<string> &ground)
{
	for (int i = 0; i < ground.size(); ++i) {
		cout << ground[i] << endl;
	}
}



struct AState {
	int gcost;
	int hcost;
	State state;
	AState() { gcost = 0; }
	bool operator < (const AState &b) const
	{
		return (gcost + hcost) > (b.gcost + b.hcost);
	}
};

/**
 * evaluate the cost of the current state
 */
void evaluate(vector<Position> &goal, AState &s)
{
	int cost = 0;
	for (int i = 0; i < goal.size(); ++i) {
		int mindis = 0x7fffffff;
		int p = 0;
		for (int j = 0; j < s.state.box.size(); ++j) {
			if (mindis > distance(goal[i], s.state.box[j])) {
				mindis = distance(goal[i], s.state.box[j]);
				p = j;
			}
		}
		cost += mindis;
	}
	s.hcost = cost;
}

/**
 * A Star search
 */
void AStar(const vector<string> &ground)
{
	int time1 = clock();
	Statistics stat;
	StateMap rec;
	priority_queue<AState>q;
	vector<Position>goal;
	getGoalPosition(ground, goal);
	AState init;
	initState(ground, init.state);
	vector<State>stateVector;
	stateVector.push_back(init.state);
	rec[init.state] = init.gcost;
	q.push(init);
	AState result;
	while (!q.empty()) {
		AState tmp = q.top();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			AState now = tmp;
			now.state.person.x += direction[i][0];
			now.state.person.y += direction[i][1];
			int s = validState(direction[i][0], direction[i][1], now.state, ground);
			now.state.move = step[i];
			now.state.previousStateNum = now.state.currentStateNum;
			stat.anodes++;
			if (s == -1) {
				evaluate(goal, now);
				result = now;
				goto end;
			}
			else if (s) {
				if (rec.count(now.state) && rec[now.state] <= now.gcost) {
					stat.bnodes++;
					continue;
				}
				now.state.currentStateNum = stateVector.size();
				evaluate(goal, now);
				now.gcost += 1;
				stateVector.push_back(now.state);
				q.push(now);
				rec[now.state] = now.gcost;
			}
		}
	}
end:
	stat.cnodes = q.size();
	stat.dnodes = rec.size() + 1;
	stat.runtime = (clock() - time1) * 1.0 / CLOCKS_PER_SEC;
	outputStat(stat);
	outputSolution1(stateVector, result.state);
}


