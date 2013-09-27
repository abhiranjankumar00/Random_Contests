//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include "header.h"

const double mutation_prob = 0.7;
const double crossover_prob = 0.6;
vector <int64> parent, child;

void initialiseParent() {
	set <int64> st;

	while((int)st.size() < sz)
		st.insert((rand()*1ll) % (1ll << bitLength));

	parent.clear();
	child.resize(sz);
	tr(it, st)
		parent.pb(*it);
}

void crossOver(int64 &p1, int64 &p2, int64 &c1, int64 &c2) {
	c1 = c2 = 0;
	forn(i, bitLength) {
		double p = (rand() % 1001)/1000.0;	
		if(p >= crossover_prob) {
			if(getBit(i, p2))
				c1 = setBit(i, c1);

			if(getBit(i, p1))
				c2 = setBit(i, c2);
		}
		else {
			if(getBit(i, p1))
				c1 = setBit(i, c1);

			if(getBit(i, p2))
				c2 = setBit(i, c2);
		}
	}		
}

void mutate(int64 &p, int64 &c) {
	c = 0;
	forn(i, bitLength) {
		double p = (rand() % 1001)/1000.0;

		if(p >= mutation_prob) {
			if(getBit(i, p) == 0)
				c = setBit(i, c);
		}
		else {
			if(getBit(i, p))
				c = setBit(i, c);
		}
	}
}

bool isDominated(int64 a, int64 b) {
	int64 fa0 = f(0, a), fa1 = f(1, a), fa2 = f(2, a);
	int64 fb0 = f(0, b), fb1 = f(1, b), fb2 = f(2, b);
	return (fb0 <= fa1 && fb1 <= fa1 && fb2 <= fa2) && (fb0 < fa1 || fb1 < fa1 || fb2 < fa2);
}

void selectParetoSet1() {
	static set <int64> mixed;
	static vector <int64> cur;
	static vector <int64> tmp;
	static vector < pair <int64, int64> >dist;

	mixed.clear();
	tr(it, parent)
		mixed.insert(*it);
	tr(it, child)
		mixed.insert(*it);

	cur.clear();

	while((int)cur.size() < sz) {
		tmp.clear();

		for(auto it = mixed.begin(); it != mixed.end();it++) {
			bool nonDominated = true;

			tr(jt, mixed)	if(it != jt) {
				if(isDominated(*it, *jt)) {
					nonDominated = false;
					break;
				}
			}

			if(nonDominated) 
				tmp.pb(*it);
		}

		assert(tmp.size() > 0);

		if(cur.size() + tmp.size() <= sz) {
			tr(it, tmp) {
					cur.pb(*it);
					mixed.erase(*it);
			}
		}
		else {
			dist.clear();
			tr(it, tmp)
				dist.pb(mp(0, *it));

			dist.front().first = dist.back().first = (2ll<<bitLength);
			forab(i, 1, dist.size()-2)
				dist[i].first = dist[i+1].second - dist[i-1].second;
			sort(all(dist), greater < pair <int64, int64> >());
			int remSz = sz - cur.size();
			forn(i, remSz) {
				cur.pb(dist[i].second);
				mixed.erase(dist[i].second);
			}
		}
	}

	parent.clear();
	tr(it, cur)
		parent.pb(*it);
}

vector <int64> createSolutionSet()
{
	initialiseParent();
	assert(sz % 4 == 0);

	forn(iterate, 100) {
		for(int i = 0; i < sz/2; i+=2)
			crossOver(parent[i], parent[i+1], child[i], child[i+1]);
		for(int i = sz/2; i < sz; i++)
			mutate(parent[i], child[i]);

		selectParetoSet1();
	}
	
	return parent;
}

