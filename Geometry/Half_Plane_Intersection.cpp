// Rewrited from waynedisonitau123
// Not checked
// TODO : unfinished

struct Plane {
	Line line;
	Plane() {}
	Plane(Line l, Point p) {
		int tmp = PL_position(p, l);
		assert(tmp);
		if (tmp == -1) line = Line(l.pb, l.pa);
		else line = l;
	}
	bool operator < (const Plane &b) const {
		return same(line.theta, b.line.theta) ? (((b.line.pb - b.line.pa) ^ (line.pb - b.line.pa)) > kEps) : line.theta < b.line.theta;
	}
};

vector<Point> Half_Plane_Intersection(vector<Plane> planes) {
	sort(planes.begin(), planes.end());
	vector<Plane> pls(1, planes[0]);
	
	int planes_size = int(planes.size());
	for (int i = 0; i < planes_size; i++) if (!same(planes[i].theta, pls.back().theta)) pls.push_back(planes[i]);
	
	deque<int> dq; dq.push_back(0); dq.push_back(1);
#define meow(a,b,c) while(dq.size()>1u && jizz(pls[a],pls[b],pls[c]))
	
	int pls_size = int(pls.size());
	for (int i = 2; i < pls_size; i++) {
		meow(i, dq.back(), dq[dq.size() - 2]) dq.pop_back();
		meow(i, dq[0], dq[1]) dq.pop_front();
		dq.push_back(i);
	}
	meow(dq.front(), dq.back(), dq[dq.size() - 2]) dq.pop_back();
	meow(dq.back(), dq[0], dq[1]) dq.pop_front();
	if(dq.size() < 3u) return vector<P>(); // no solution or solution is not a convex
	vector<P> rt;
	for(int i=0;i<(int)dq.size();++i)rt.push_back(Intersect(pls[dq[i]],pls[dq[(i+1)%dq.size()]]));
	return rt;
}
