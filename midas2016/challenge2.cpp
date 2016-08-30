#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef struct __COORD__ {
    float X;
    float Y;
} Coord;

bool TryYToX(Coord APoint1, Coord APoint2, int Y, int& X)
{
	if (APoint1.Y == APoint2.Y) {
		return false;
	}
    if (APoint1.X == APoint2.X) {
		if ((APoint1.Y <= Y && Y <= APoint2.Y)
			|| (APoint2.Y <= Y && Y <= APoint1.Y)) {
			X = APoint1.X;
			return true;
		}
	}
    float a = std::abs(APoint1.Y - APoint2.Y) / std::abs(APoint1.X - APoint2.X);
	float b = APoint1.Y - (APoint1.X * a);
	float x = (Y - b) / a;
	return ((APoint1.X <= x && x <= APoint2.X) || (APoint2.X <= x && x <= APoint1.X));
}

int main()
{
    int n;
    Coord Point;
    Coord input;
    std::vector<Coord> Polygon[2];
    std::vector<int> XList;
    bool bPtInPolygon = false;

    std::cin >> Point.X >> Point.Y;
    for (int i = 0, a = 2; a-- > 0; i++) {
        std::cin >> n;
        for (; n-- > 0; Polygon[i].push_back(input)) {
            std::cin >> input.X >> input.Y;
			if (Point.X == input.X && Point.Y == input.Y) {
				bPtInPolygon = true;
			}
        }
		Polygon[i].push_back(Polygon[i][0]);
    }
    if (bPtInPolygon == false) {
		int X;
		for (int i = 0, a = 2; bPtInPolygon == false && a-- > 0; i++) {
			for (int j = 0, b = Polygon[i].size() - 1; b-- > 0; j++) {
				Coord &c1 = Polygon[i][j];
				Coord &c2 = Polygon[i][j + 1];
				if (c1.X == c2.X && c1.X == Point.X) {
					if ((c1.Y <= Point.Y && Point.Y <= c2.Y)
						|| (c2.Y <= Point.Y && Point.Y <= c1.Y)) {
						bPtInPolygon = true;
						break;
					}
				}
				if (c1.Y == c2.Y && c1.Y == Point.Y) {
					if ((c1.X <= Point.X && Point.X <= c2.X)
						|| (c2.X <= Point.X && Point.X <= c1.X)) {
						bPtInPolygon = true;
						break;
					}
				}
				if (TryYToX(c1, c2, Point.Y, X)) {
					XList.push_back(X);
				}
			}
		}
        std::sort(XList.begin(), XList.end(), [](int a, int b) { return a < b; });
        for (int i = 0, a = (XList.size() >> 1); a-- > 0; i += 2) {
            if (XList[0] <= Point.X && Point.X <= XList[1]) {
                bPtInPolygon = true;
                break;
            }
        }
    }
    std::cout << (bPtInPolygon? "True": "False") << std::endl;
    return 0;
}
