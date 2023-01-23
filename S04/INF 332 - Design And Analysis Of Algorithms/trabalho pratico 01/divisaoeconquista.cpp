#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

const int INF = 987654321;

typedef std::pair<int, int> Point;
typedef std::list<Point>::iterator pt_iter;

struct Edge {
  double cost;
  Point start, end;
};

struct Cycle {
  int cost;
  list<Point> path;
};

double getDistance(Point p1, Point p2) {
  return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

Cycle CombinaCiclos(Cycle cy1, Cycle cy2) {

  list<Point>::iterator a, b, c, d;
  double min1 = INF, min2 = INF;
  Cycle cy;
  int i = 0;
  // Loop the cycles using iterators
  for (list<Point>::iterator it1 = cy1.path.begin(); it1 != --cy1.path.end();
       it1++) {
    cout << ++i << endl;
    int j = 0;
    for (list<Point>::iterator it2 = cy2.path.begin(); it2 != --cy2.path.end();
         it2++) {

      cout << ++j << endl;
      // dist(a, d) + dist(b, c) – dist(a, b) – dist(c, d)
      double dist1 =
          getDistance(*it1, *next(it2)) + getDistance(*next(it1), *it2) -
          getDistance(*it1, *next(it1)) - getDistance(*it2, *next(it2));
      // dist(a, c) + dist(b, d) – dist(a, b) – dist(c, d)
      double dist2 =
          getDistance(*it1, *it2) + getDistance(*next(it1), *next(it2)) -
          getDistance(*it1, *next(it1)) - getDistance(*it2, *next(it2));

      if (dist1 < min1) {
        min1 = dist1;
        cout << "dist1: " << dist1 << endl;
        a = it1;
        b = next(it1);
        c = it2;
        d = next(it2);
        cout << "points" << a->first << " " << a->second << endl;
        cout << "points" << b->first << " " << b->second << endl;
        cout << "points" << c->first << " " << c->second << endl;
        cout << "points" << d->first << " " << d->second << endl;
      }
      if (dist2 < min2) {
        min2 = dist2;
        cout << "dist2: " << dist2 << endl;
        a = it1;
        b = next(it1);
        c = it2;
        d = next(it2);
        cout << "points" << a->first << " " << a->second << endl;
        cout << "points" << b->first << " " << b->second << endl;
        cout << "points" << c->first << " " << c->second << endl;
        cout << "points" << d->first << " " << d->second << endl;
      }
    }
  }
  // Print both cycles
  cout << "Ciclo 1: ";
  for (list<Point>::iterator it = cy1.path.begin(); it != cy1.path.end();
       it++) {
    cout << "(" << it->first << ", " << it->second << ") ->";
  }
  cout << "\n\n";

  cout << "Ciclo 2: ";
  for (list<Point>::iterator it = cy2.path.begin(); it != cy2.path.end();
       it++) {
    cout << "(" << it->first << ", " << it->second << ") ->";
  }
  cout << "\n\n";

  cout << min1 << " " << min2 << "\n\n";
  // Combining the cycles
  if (min1 <= min2) {
    cout << "TEI";
    cy.path.splice(cy.path.end(), cy1.path, cy1.path.begin(), next(a));
    cy.path.splice(cy.path.end(), cy2.path, d, cy2.path.end());
    // TODO: This is not working
    cy.path.splice(cy.path.end(), cy2.path, cy.path.begin(), next(c));
    // cy.path.splice(cy.path.end(), cy1.path, b, cy1.path.end());
    // cy.cost = cy1.cost + cy2.cost + min1;
  } else {
    cout << "TEII";
    // cy.path.splice(cy.path.end(), cy1.path, cy1.path.begin(), next(a));
    //
    // // Podemos inverter o ciclo 2
    // // Dessa forma o d viria antes de c, na forma begin ... d -> c ... end
    // cy2.path.reverse();
    // cy.path.splice(cy.path.end(), cy2.path, c, cy2.path.end());
    // cy.path.splice(cy.path.end(), cy1.path, cy2.path.begin(), next(d));
    // cy.path.splice(cy.path.end(), cy2.path, b, cy2.path.end());
    // cy.cost = cy1.cost + cy2.cost + min2;
  }
  return cy;
}

Cycle DivConqPCV(vector<Point> &points, int l, int r) {
  if (r - l <= 2) {
    if (r - l == 1) {
      Cycle c;
      int cost = getDistance(points[l], points[r]);
      c.cost = 2 * cost;
      c.path.push_back(points[l]);
      c.path.push_back(points[r]);
      c.path.push_back(points[l]);
      return c;
    }
    if (r - l == 2) {
      Cycle c;
      int c1 = getDistance(points[l], points[l + 1]);
      int c2 = getDistance(points[l + 1], points[r]);
      int c3 = getDistance(points[r], points[l]);

      c.cost = c1 + c2 + c3;
      c.path.push_back(points[l]);
      c.path.push_back(points[l + 1]);
      c.path.push_back(points[r]);
      c.path.push_back(points[l]);
      return c;
    }
  }

  int m = (l + r) / 2;
  Cycle left = DivConqPCV(points, l, m);
  Cycle right = DivConqPCV(points, m + 1, r);
  Cycle result = CombinaCiclos(left, right);

  return result;
}

int main() {
  int n;

  cin >> n;

  vector<int> p(n - 1);
  for (int i = 0; i < n - 1; i++) {
    p[i] = i + 1;
  }

  vector<Point> points(n);

  int x, y;
  for (int t = 0; t < n; t++) {
    cin >> x >> y;
    points[t] = std::make_pair(x, y);
  }

  // ordetando os pontos do vetor de points
  sort(points.begin(), points.end(), [](Point a, Point b) {
    return a.first < b.first;
  }); // Odenamos pela coordenada x

  // for (auto &&p : points) {
  //   cout << p.first << " " << p.second << endl;
  // }

  Cycle c = DivConqPCV(points, 0, n - 1);

  cout << "Custo: " << c.cost << endl;
  cout << "Caminho: " << endl;
  // for (auto &&e : c.path) {
  //   cout << e.start.first << " " << e.start.second << " -> " << e.end.first
  //        << " " << e.end.second << endl;
  // }

  return 0;
}