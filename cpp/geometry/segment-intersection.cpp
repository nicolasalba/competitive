// LINE they are parallel
// They never be touched because
// other wise provise the point
// The correct name is segment
struct line {
    ld a, b; 
    ld x, y;
    

    ld m()  {
        return (a - x)/(b - y);
    }

    bool horizontal() {
        return b == y;
    }

    bool vertical() {
        return a == x;
    }

    void intersects(line &o) {

        
        if (horizontal() && o.horizontal()) {
            if (y == o.y) {
                cout << "LINE\n";
            } else {
                cout << "NONE\n";
            }
            return;
        }

        if (vertical() && o.vertical()) {
            if (x == o.x) {
                cout << "LINE\n";
            } else {
                cout << "NONE\n";
            }
            return;
        }

        if (!horizontal() && !o.horizontal()) { 
            ld ma = m();
            ld mb = o.m();

            if (ma == mb) {
                ld someY = (o.x - x)/ma + y;
                if (abs(someY - o.y) <= 0.000001) {
                    cout << "LINE\n";
                } else {
                    cout << "NONE\n";
                }
            } else {
                ld xx = (x*mb - o.x*ma + ma*mb*(o.y - y))/(mb - ma);
                ld yy = (xx - x)/ma + y;
                cout << "POINT " << fixed << setprecision(2) << xx << " " << yy << "\n";
            }
        } else {
            if (!horizontal()) {
                ld xx;
                if (x == a) {
                    xx = x;
                } else {
                    xx = (o.y - y)/m() + x;
                }
                ld yy = o.y;
                cout << "POINT "<< fixed << setprecision(2) << xx << " " << yy << "\n";
            } else {
                ld xx;
                if (x == a) {
                    xx = x;
                } else {
                    xx = (y - o.y)/o.m() + o.x;
                }
                ld yy = y;
                cout << "POINT "<< fixed << setprecision(2) << xx << " " << yy << "\n";
            }
        }
        
    }

};

void test_case() {
    line l[2];
    for (int i = 0; i < 2; i++) {
        ld x, y, a, b;
        cin >> x >> y >> a >> b;
        l[i].a = x;
        l[i].b = y;
        l[i].x = a;
        l[i].y = b;
    }

    l[0].intersects(l[1]);
}
