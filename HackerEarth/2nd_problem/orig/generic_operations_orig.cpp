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
			else
				c1 = resetBit(i, c1);

			if(getBit(i, p1))
				c2 = setBit(i, c2);
			else
				c2 = resetBit(i, c2);
		}
		else {
			if(getBit(i, p1))
				c1 = setBit(i, c1);
			else
				c1 = resetBit(i, c1);

			if(getBit(i, p2))
				c2 = setBit(i, c2);
			else
				c2 = resetBit(i, c2);
		}
	}		
}

void mutate(int64 &p, int64 &c) {
	c = 0;
	forn(i, bitLength) {
		double p = (rand() % 1001)/1000.0;

		if(p >= mutation_prob) {
			if(getBit(i, p))
				c = resetBit(i, c);
			else
				c = setBit(i, c);
		}
		else {
			if(getBit(i, p))
				c = setBit(i, c);
			else
				c = resetBit(i, c);
		}
	}
}

bool isDominated(int64 a, int64 b) {
	int64 fa0 = f(0, a), fa1 = f(1, a), fa2 = f(2, a);
	int64 fb0 = f(0, b), fb1 = f(1, b), fb2 = f(2, b);
	return (fb0 <= fa1 && fb1 <= fa1 && fb2 <= fa2) && (fb0 < fa1 || fb1 < fa1 || fb2 < fa2);

	forn(id, 3)
		if(f(id, b) > f(id, a))
			return false;
	return true;

/*
	return f(0, a) <= f(0, b) && f(1, a) <= f(1, b) && f(2, a) <=f(2, b) ;
	bool allBetter = true, oneBetter = false;
	forn(id, 3) {
		int64 fa = f(id, a), fb = f(id, b);
		if(fb > fa)
				allBetter = false;
		if(fb < fa)
				oneBetter = true;
	}
	return oneBetter && allBetter;
*/
}

void selectParetoSet() {
	static vector <int64> mixed;
	static vector <bool> isConsidered;
	static vector <int64> cur;
	static vector < pair <int64, int> > dist;
	static vector <int> idx;

	mixed.clear();
	tr(it, parent)
		mixed.pb(*it);
	tr(it, child)
		mixed.pb(*it);
	sort(all(mixed));
	mixed.erase(unique(all(mixed)), mixed.end());
/*
	tr(it, mixed) {
		Pf("%lld: (%lld, %lld, %lld)\n", *it, f(0, *it), f(1, *it), f(2, *it));
	}
	cout << endl;
*/
	isConsidered.resize(mixed.size());
	fill(all(isConsidered), true);
	cur.clear();
//	DEBUG(mixed.size());

	while( (int)cur.size() < sz) {
		idx.clear();

		forn(i, mixed.size())	if(isConsidered[i]) {
			bool nonDominated = true;

			forn(j, mixed.size())	if(i != j && isConsidered[j]) {
					if(isDominated(mixed[i], mixed[j])) {
							nonDominated = false;
							break;
					}
			}

			if(nonDominated) {
					idx.pb(i);
			}
		}
/*
		DEBUG(idx.size());
		tr(it, idx)
			Pf("%lld: (%lld, %lld, %lld)\n", mixed[*it], f(0, mixed[*it]), f(1, mixed[*it]), f(2, mixed[*it]));
		cout << endl;
*/
		if(cur.size() + idx.size() > sz) {
				tr(it, idx) 
						dist.pb(mp(0ll, *it));
				dist.front().first = dist.back().first = (2ll<<bitLength);
				forab(i, 1, dist.size()-2)
						dist[i].first = mixed[dist[i+1].second] - mixed[dist[i-1].second];
				sort(all(dist), greater < pair <int64, int>>());
				int remSize = sz - cur.size();
				idx.clear();
				forn(i, remSize)
						idx.pb(dist[i].second);
		}
/*
		DEBUG(idx.size());
		tr(it, idx)
			Pf("%lld: (%lld, %lld, %lld)\n", mixed[*it], f(0, mixed[*it]), f(1, mixed[*it]), f(2, mixed[*it]));
		cout << endl;
*/
		tr(it, idx) {
				cur.pb(mixed[*it]);
				isConsidered[*it] = false;
		}
/*
		DEBUG(cur.size());
		cout << endl;
*/
	}
	parent.clear();
	tr(it, cur)
			parent.pb(*it);
	sort(all(parent));
	parent.erase(unique(all(parent)), parent.end());
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
//	DEBUG(mixed.size());

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

/*
		DEBUG(tmp.size());
		tr(it, tmp)
			write((int)*it);
		cout << endl << endl;
*/
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
				sort(all(dist));
				int remSz = sz - cur.size();
				forn(i, remSz) {
						cur.pb(dist[i].second);
						mixed.erase(dist[i].second);
				}

		}

	//	DEBUG(cur.size());
/*
	tr(it, mixed) {
		Pf("%lld: (%lld, %lld, %lld)\n", *it, f(0, *it), f(1, *it), f(2, *it));
	}
	cout << endl;
*/

	}
	parent.clear();
	tr(it, cur)
			parent.pb(*it);
/*
	DEBUG(cur.size());
	tr(it, cur)
			write((int)*it);
	cout << endl << endl;
*/
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
	DEBUG(parent.size());
	
	return parent;
}

